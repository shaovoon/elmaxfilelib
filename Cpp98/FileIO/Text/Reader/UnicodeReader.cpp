#include "UnicodeReader.h"
#include "../Utils/StrUtil.h"

using namespace Elmax;

UnicodeReader::UnicodeReader(void)
{
}

UnicodeReader::UnicodeReader(const std::wstring& file)
{
	Open(file);
}

UnicodeReader::~UnicodeReader(void)
{
}

bool UnicodeReader::IsValid(const std::wstring& file)
{
	FILE* f = FileOpen(file, L"rb");

	if(f==NULL)
		return false;

	unsigned char tt[2] = {0,0};

	fseek( f, 0, SEEK_SET );

	fread( tt, 1, 2, f );

	if( tt[0] != 0xff || tt[1] != 0xfe )
	{
		fclose( f );

		return false; // not a unicode file
	}

	fclose( f );
	
	return true;
}

void UnicodeReader::ReadBOM()
{
	if(fp==NULL)
		return;

	unsigned char tt[2] = {0,0};

	fseek( fp, 0, SEEK_SET );

	fread( tt, 1, 2, fp );

	if( tt[0] != 0xff || tt[1] != 0xfe ) // not the correct BOM, so reset the pos to beginning (file might not have BOM)
	{
		fseek( fp, 0, SEEK_SET );
		hasBOM = false;
	}
	else
		hasBOM = true;
}

bool UnicodeReader::Open(const std::wstring& file)
{
	filename = file;

	fp = FileOpen(file, L"rb");

	if(fp == NULL)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
	}

	ReadBOM();
	
	return fp != NULL;
}

bool UnicodeReader::Read( std::wstring& text, size_t len )
{
	if(fp == NULL)
		return false;

	RAII_Array<char> buf(len+2);

	size_t lenRead = ReadRawBytes(buf.GetPtr(), len);
	if(lenRead!=len)
	{
		errNum = ELMAX_READ_ERROR;
		std::wstring str = StrUtil::Format(L": Read {0} bytes out of {1} required!", lenRead, len);
		err = GetErrorMsg(errNum) + str;

		throw std::runtime_error(StrUtil::ConvToString(err));

		return false;
	}

	wchar_t* wp = (wchar_t*)(buf.GetPtr());

#ifdef _MICROSOFT
	if(isBigEndian)
		Platform::SwapOrder(wp, len/2);

	if(ContainsNewline(wp, len))
	{
		wchar_t* pszDest = NULL;
		size_t nDest = 0;
		if(FileToContents( wp, len, pszDest, nDest ))
		{
			text = pszDest;
			RAII_Array<wchar_t> dest = pszDest;
		}
	}
	else
	{
		text = wp;
	}
#else
	if(sizeof(wchar_t)==4)
	{
		unsigned short* sharr = (unsigned short*)(buf.GetPtr());
		if(isBigEndian)
			Platform::SwapOrder(sharr, len/2);

		size_t charLen = 0;
		if(utf16::ContainsSurrogate(sharr, len/2, charLen))
		{
			text = utf16::ConvertToWString(sharr, len/2);
		}
		else
		{
			text = L"";
			for(size_t i=0;i<len/2;++i)
			{
				text += sharr[i];
			}
		}
	}
	else
	{
		if(isBigEndian)
			Platform::SwapOrder(wp, len/2);

		text = wp;
	}
#endif

	return true;
}

bool UnicodeReader::ReadAll( std::wstring& text )
{
	size_t size = GetFileSize(filename);

	if(size==0)
		return false;

	if(fp == NULL)
		return false;

	if(hasBOM)
		size -= 2;

	RAII_Array<char> buf(size+2);

	size_t lenRead = ReadRawBytes(buf.GetPtr(), size);
	if(lenRead!=size)
	{
		errNum = ELMAX_READ_ERROR;
		std::wstring str = StrUtil::Format(L": Read {0} bytes out of {1} required!", lenRead, size);
		err = GetErrorMsg(errNum) + str;

		throw std::runtime_error(StrUtil::ConvToString(err));

		return false;
	}

	wchar_t* wp = (wchar_t*)(buf.GetPtr());

#ifdef _MICROSOFT
	size_t len = wcslen(wp);
	if(ContainsNewline(wp, len))
	{
		wchar_t* pszDest = NULL;
		size_t nDest = 0;
		if(FileToContents( wp, len, pszDest, nDest ))
		{
			text = pszDest;
			RAII_Array<wchar_t> dest = pszDest;
		}
	}
	else
	{
		text = wp;
	}
#else
	if(sizeof(wchar_t)==4)
	{
		unsigned short* sharr = (unsigned short*)(buf.GetPtr());
		if(isBigEndian)
			Platform::SwapOrder(sharr, size/2);

		size_t charLen = 0;
		if(utf16::ContainsSurrogate(sharr, size/2, charLen))
		{
			text = utf16::ConvertToWString(sharr, size/2);
			if(ContainsReturnCarriage(text))
				text = RemoveReturnCarriage(text);
		}
		else
		{
			text = L"";
			for(size_t i=0;i<size/2;++i)
			{
				if(sharr[i] != L'\r') // Remove return carriage
					text += sharr[i];
			}
		}
	}
	else
	{
		if(isBigEndian)
			Platform::SwapOrder(wp, size/2);

		text = wp;
		if(ContainsReturnCarriage(text))
			text = RemoveReturnCarriage(text);
	}
#endif

	return true;
}

bool UnicodeReader::ReadLine( std::wstring& text )
{
	if(fp == NULL)
		return false;

	text = L"";
		
	if(sizeof(wchar_t)==4)
	{
		while (!feof(fp))
		{
			unsigned short sh = 0;
			if(ReadRaw(&sh, 1, false)==1)
			{
				wchar_t ch = (wchar_t)(sh);
				if(ch != L'\r' && ch != L'\n')
				{
					if(utf16::Is1stSurrogate(sh))
					{
						if(!feof(fp))
						{
							unsigned short sh2 = 0;
							if(ReadRaw(&sh2, 1, false)==1)
							{
								if(utf16::Is2ndSurrogate(sh2))
								{
									ch = utf16::ConvertToWChar(sh, sh2);
									text += (wchar_t)(ch);
								}
								else
								{
									text += (wchar_t)(sh);
									text += (wchar_t)(sh2);
								}
							}
							else
								text += (wchar_t)(ch);
						}
						else
							text += (wchar_t)(ch);

					}
					else
						text += (wchar_t)(ch);
				}

				if(ch == L'\n')
					break;
			}
		}
	}
	else
	{
		wchar_t ch = L'\0';

		while (!feof(fp))
		{
			ch = fgetwc(fp);

			if(isBigEndian)
				ch = Platform::SwapOrder(ch);

			if(ch != L'\r' && ch != L'\n')
				text += ch;

			if(ch == L'\n')
				break;
		}
	}
	return true;
}

bool UnicodeReader::IsEOF()
{
	if(fp!=NULL)
	{
		return feof(fp) != 0; // not eof yet
	}

	return true;
}
