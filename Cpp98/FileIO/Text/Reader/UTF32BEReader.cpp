#include "UTF32BEReader.h"
#include "../Utils/StrUtil.h"
#include <iostream>

using namespace Elmax;

UTF32BEReader::UTF32BEReader(void)
{
}

UTF32BEReader::UTF32BEReader(const std::wstring& file)
{
	Open(file);
}

UTF32BEReader::~UTF32BEReader(void)
{
}

bool UTF32BEReader::IsValid(const std::wstring& file)
{
	FILE* f = FileOpen(file, L"rb");

	if(f==NULL)
		return false;

	unsigned char tt[4] = {0,0,0,0};

	fseek( f, 0, SEEK_SET );

	fread( tt, 1, 4, f );

	if( tt[0] != 0x0 || tt[1] != 0x0 || tt[2] != 0xfe || tt[3] != 0xff )
	{
		fclose( f );

		return false; // not a unicode file
	}

	fclose( f );
	
	return true;
}

void UTF32BEReader::ReadBOM()
{
	if(fp==NULL)
		return;

	unsigned char tt[4] = {0,0,0,0};

	fseek( fp, 0, SEEK_SET );

	fread( tt, 1, 4, fp );

	if( tt[0] != 0x0 || tt[1] != 0x0 || tt[2] != 0xfe || tt[3] != 0xff ) // not the correct BOM, so reset the pos to beginning (file might not have BOM)
	{
		fseek( fp, 0, SEEK_SET );
		hasBOM = false;
	}
	else
		hasBOM = true;
}

bool UTF32BEReader::Open(const std::wstring& file)
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

bool UTF32BEReader::Read( std::wstring& text, size_t len )
{
	if(fp == NULL)
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
	unsigned int* uip = (unsigned int*)(buf.GetPtr());
	text = utf16::ConvertFromUTF32BEToUTF16String(uip, lenRead>>2);
	if(ContainsNewline(text.c_str(), text.size()))
	{
		wchar_t* pszDest = NULL;
		size_t nDest = 0;
		if(FileToContents( text.c_str(), text.size(), pszDest, nDest ))
		{
			text = pszDest;
			RAII_Array<wchar_t> dest = pszDest;
		}
	}
#else
	if(sizeof(wchar_t)==4)
	{
		unsigned int* uip = (unsigned int*)(buf.GetPtr());
		text = utf16::ConvertFromUTF32BEToUTF16String(uip, lenRead>>2);
	}
	else
	{
		unsigned int* uip = (unsigned int*)(buf.GetPtr());
		text = utf16::ConvertFromUTF32BEToUTF16String(uip, lenRead>>2);
		
		if(ContainsReturnCarriage(text))
			text = RemoveReturnCarriage(text);
	}
#endif

	return true;
}

bool UTF32BEReader::ReadAll( std::wstring& text )
{
	size_t size = GetFileSize(filename);

	if(size==0)
		return false;

	if(fp == NULL)
		return false;

	if(hasBOM)
		size -= 4;

	RAII_Array<char> buf(size+4);

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
	unsigned int* uip = (unsigned int*)(buf.GetPtr());
	text = utf16::ConvertFromUTF32BEToUTF16String(uip, size>>2);
	if(ContainsNewline(text.c_str(), text.size()))
	{
		wchar_t* pszDest = NULL;
		size_t nDest = 0;
		if(FileToContents( text.c_str(), text.size(), pszDest, nDest ))
		{
			text = pszDest;
			RAII_Array<wchar_t> dest = pszDest;
		}
	}
#else
	if(sizeof(wchar_t)==4)
	{
		text = L"";
		unsigned int* uip = (unsigned int*)(buf.GetPtr());

		for(size_t i=0;i<size>>2;++i)
		{
			wchar_t ch = utf16::SwapEndian(uip[i]);
			if(ch != L'\r') // Remove return carriage
				text += ch;
		}
	}
	else
	{
		unsigned int* uip = (unsigned int*)(buf.GetPtr());
		text = utf16::ConvertFromUTF32BEToUTF16String(uip, size>>2);
		if(ContainsReturnCarriage(text))
			text = RemoveReturnCarriage(text);
	}
#endif

	return true;
}

bool UTF32BEReader::ReadLine( std::wstring& text )
{
	if(fp == NULL)
		return false;

	text = L"";
		
	if(sizeof(wchar_t)==4)
	{
		while (!feof(fp))
		{
			unsigned int ui= 0;
		
			if(fread(&ui, 4, 1, fp)==1)
			{
				wchar_t ch = utf16::SwapEndian(ui);
				if(ch != L'\r' && ch != L'\n')
				{
					text += ch;
				}

				if(ch == L'\n')
					break;
			}
		}
	}
	else
	{
		while (!feof(fp))
		{
			unsigned int ui= 0;
			if(fread(&ui, 4, 1, fp)==1)
			{
				wchar_t ch = utf16::SwapEndian(ui);
				if(ch != L'\r' && ch != L'\n')
				{
					std::vector<wchar_t> vec;
					utf16::ConvertFromUTF32BEToUTF16Char(ui, vec);
					for(size_t i=0; i<vec.size(); ++i)
						text += vec[i];
				}

				if(ch == L'\n')
					break;
			}
		}
	}
	return true;
}

bool UTF32BEReader::IsEOF()
{
	if(fp!=NULL)
	{
		return feof(fp) != 0; // not eof yet
	}

	return true;
}
