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

	if(f==nullptr)
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
	if(fp==nullptr)
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

	if(fp == nullptr)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
		throw std::runtime_error(StrUtil::ConvToString(file)+ ": file cannot be opened!");
	}

	ReadBOM();
	
	return fp != nullptr;
}

bool UnicodeReader::Read( std::wstring& text, size_t len )
{
	if(fp == nullptr)
		return false;

	RAII_Array<char> buf(len+2);

	size_t lenRead = fread(buf.GetPtr(), 1, len, fp);
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
	if(ContainsNewline(wp, len))
	{
		wchar_t* pszDest = nullptr;
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
		text = wp;
#endif

	return true;
}

bool UnicodeReader::ReadAll( std::wstring& text )
{
	size_t size = GetFileSize(filename);

	if(size==0)
		return false;

	if(fp == nullptr)
		return false;

	if(hasBOM)
		size -= 2;

	RAII_Array<char> buf(size+2);

	size_t lenRead = fread(buf.GetPtr(), 1, size, fp);
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
		wchar_t* pszDest = nullptr;
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
		text = wp;
		if(ContainsReturnCarriage(text))
			text = RemoveReturnCarriage(text);
	}
#endif

	return true;
}

bool UnicodeReader::ReadLine( std::wstring& text )
{
	if(fp == nullptr)
		return false;

	text = L"";
		
	if(sizeof(wchar_t)==4)
	{
		while (!feof(fp))
		{
			unsigned short sh = 0;
			if(fread(&sh, 2, 1, fp)==1)
			{
				wchar_t ch = (wchar_t)(sh);
				if(ch != L'\r' && ch != L'\n')
				{
					if(utf16::Is1stSurrogate(sh))
					{
						if(!feof(fp))
						{
							unsigned short sh2 = 0;
							if(fread(&sh2, 2, 1, fp)==1)
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
	if(fp!=nullptr)
	{
		return feof(fp) != 0; // not eof yet
	}

	return true;
}
