#include "BEUnicodeReader.h"
#include "../../Common/Enumeration.h"
#include "../Utils/StrUtil.h"

using namespace Elmax;

BEUnicodeReader::BEUnicodeReader(void)
{
}

BEUnicodeReader::BEUnicodeReader(const std::wstring& file)
{
	Open(file);
}

BEUnicodeReader::~BEUnicodeReader(void)
{
}

bool BEUnicodeReader::IsValid(const std::wstring& file)
{
	FILE* f = FileOpen(file, L"rb");

	if(f==NULL)
		return false;

	unsigned char tt[2] = {0,0};

	fseek( f, 0, SEEK_SET );

	fread( tt, 1, 2, f );

	if( tt[0] != 0xfe || tt[1] != 0xff )
	{
		fclose( f );

		return false; // not a unicode file
	}

	fclose( f );

	return true;
}

void BEUnicodeReader::ReadBOM()
{
	if(fp==NULL)
		return;

	unsigned char tt[2] = {0,0};

	fseek( fp, 0, SEEK_SET );

	fread( tt, 1, 2, fp );

	if( tt[0] != 0xfe || tt[1] != 0xff ) // not the correct BOM, so reset the pos to beginning (file might not have BOM)
	{
		fseek( fp, 0, SEEK_SET );
		hasBOM = false;
	}
	else
		hasBOM = true;
}

bool BEUnicodeReader::Open(const std::wstring& file)
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

bool BEUnicodeReader::Read( std::wstring& text, size_t len )
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

#ifdef _MICROSOFT
	wchar_t* wp = (wchar_t*)(buf.GetPtr());
	if(!isBigEndian)
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
		unsigned short* shp = (unsigned short*)(buf.GetPtr());
		RAII_Array<wchar_t> arr = ConvToLittleEndianShort(shp, len/2);

		text = arr.GetPtr();
	}
	else
	{
		wchar_t* wp = (wchar_t*)(buf.GetPtr());
		ConvToLittleEndian(wp, len/2);

		text = wp;
	}
#endif

	return true;
}

bool BEUnicodeReader::ReadAll( std::wstring& text )
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

#ifdef _MICROSOFT
	wchar_t* wp = (wchar_t*)(buf.GetPtr());

	if(!isBigEndian)
		Platform::SwapOrder(wp, size/2);

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
		unsigned short* shp = (unsigned short*)(buf.GetPtr());
		if(!isBigEndian)
			Platform::SwapOrder(shp, size/2);

		text = utf16::ConvertToWString(shp, size/2);

		if(ContainsReturnCarriage(text))
			text = RemoveReturnCarriage(text);
	}
	else
	{
		wchar_t* wp = (wchar_t*)(buf.GetPtr());
		if(!isBigEndian)
			Platform::SwapOrder(wp, size/2);

		text = wp;

		if(ContainsReturnCarriage(text))
			text = RemoveReturnCarriage(text);
	}
#endif

	return true;
}

bool BEUnicodeReader::ReadLine( std::wstring& text )
{
	if(fp == NULL)
		return false;

	text = L"";

	if(sizeof(wchar_t)==4)
	{
		while (!feof(fp))
		{
			unsigned short sh = 0;
			if(ReadRaw(&sh, 1, true)==1)
			{
				unsigned short conv1 = sh;
				wchar_t ch = (wchar_t)conv1;

				if(ch != L'\r' && ch != L'\n')
				{
					if(utf16::Is1stSurrogate(conv1))
					{
						if(!feof(fp))
						{
							unsigned short sh2 = 0;
							if(ReadRaw(&sh2, 1, true)==1)
							{
								unsigned short conv2 = sh2;

								if(utf16::Is2ndSurrogate(conv2))
								{
									ch = utf16::ConvertToWChar(conv1, conv2);
									text += (wchar_t)(ch);
								}
								else
								{
									text += (wchar_t)(conv1);
									text += (wchar_t)(conv2);
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

			if(!isBigEndian)
				ch = Platform::SwapOrder(ch);

			if(ch != L'\r' && ch != L'\n')
				text += ch;

			if(ch == L'\n')
				break;
		}
	}
	return true;
}

bool BEUnicodeReader::IsEOF()
{
	if(fp!=NULL)
	{
		return feof(fp) != 0; // not eof yet
	}

	return true;
}

void BEUnicodeReader::ConvToLittleEndian(wchar_t* p, size_t size)
{
	char swap[2];
	UnionText unionText;
	for(size_t i=0; i<size; ++i)
	{
		unionText.ch = p[i];
		swap[0] = unionText.arr[1];
		swap[1] = unionText.arr[0];

		unionText.arr[0] = swap[0];
		unionText.arr[1] = swap[1];

		p[i] = unionText.ch;
	}
}

wchar_t BEUnicodeReader::ConvToLittleEndian(wchar_t ch)
{
	char swap[2];
	UnionText unionText;

	unionText.ch = ch;
	swap[0] = unionText.arr[1];
	swap[1] = unionText.arr[0];

	unionText.arr[0] = swap[0];
	unionText.arr[1] = swap[1];

	return unionText.ch;
}

wchar_t* BEUnicodeReader::ConvToLittleEndianShort(unsigned short* p, size_t size)
{
	if(sizeof(wchar_t)==4)
	{
		char swap[2];
		UnionText unionText;
		RAII_Array<unsigned short> arr(size+1);

		for(size_t i=0; i<size; ++i)
		{
			unionText.ch = p[i];
			swap[0] = unionText.arr[1];
			swap[1] = unionText.arr[0];

			unionText.arr[0] = swap[0];
			unionText.arr[1] = swap[1];

			arr.GetPtr()[i] = unionText.ch;
		}
		size_t charLen = 0;
		if(utf16::ContainsSurrogate(arr.GetPtr(), size, charLen))
		{
			std::wstring str = utf16::ConvertToWString(arr.GetPtr(), size);
			RAII_Array<wchar_t> arrDest(str.size()+1);
			Wcscpy(arrDest.GetPtr(), str.c_str(), str.size()+1);

			return arrDest.Detach();
		}
		else
		{
			RAII_Array<wchar_t> arrDest(size+1);
			for(size_t i=0; i<size; ++i)
			{
				arrDest.GetPtr()[i] = arr.GetPtr()[i];
			}

			return arrDest.Detach();
		}
	}
	else
	{
		char swap[2];
		UnionText unionText;
		RAII_Array<wchar_t> arr(size+1);
		for(size_t i=0; i<size; ++i)
		{
			unionText.ch = p[i];
			swap[0] = unionText.arr[1];
			swap[1] = unionText.arr[0];

			unionText.arr[0] = swap[0];
			unionText.arr[1] = swap[1];

			arr.GetPtr()[i] = unionText.ch;
		}
		return arr.Detach();
	}
}

wchar_t BEUnicodeReader::ConvToLittleEndianShort(unsigned short ch1, unsigned short ch2)
{
	char swap[2];
	UnionText unionText1;
	UnionText unionText2;

	unionText1.ch = ch1;
	swap[0] = unionText1.arr[1];
	swap[1] = unionText1.arr[0];

	unionText1.arr[0] = swap[0];
	unionText1.arr[1] = swap[1];

	unionText2.ch = ch2;
	swap[0] = unionText2.arr[1];
	swap[1] = unionText2.arr[0];

	unionText2.arr[0] = swap[0];
	unionText2.arr[1] = swap[1];

	if(utf16::Is1stSurrogate(ch1)&&utf16::Is2ndSurrogate(ch2))
	{
		return utf16::ConvertToWChar(unionText1.ch, unionText2.ch);
	}

	return unionText1.ch;
}

unsigned short BEUnicodeReader::ConvToLittleEndianShort(unsigned short ch)
{
	char swap[2];
	UnionText unionText;

	unionText.ch = ch;
	swap[0] = unionText.arr[1];
	swap[1] = unionText.arr[0];

	unionText.arr[0] = swap[0];
	unionText.arr[1] = swap[1];

	return unionText.ch;
}
