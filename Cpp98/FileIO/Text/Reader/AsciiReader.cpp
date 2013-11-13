#include "AsciiReader.h"
#include "../Utils/StrUtil.h"

#include <vector>

using namespace Elmax;

#define VECTOR_RESERVE 50000

AsciiReader::AsciiReader(void)
{
}

AsciiReader::AsciiReader(const std::wstring& file)
{
	Open(file);
}

AsciiReader::~AsciiReader(void)
{
	Close();
}

bool AsciiReader::IsValid(const std::wstring&)
{
	return true;
}

bool AsciiReader::Open(const std::wstring& file)
{
	filename = file;

	fp = FileOpen(file, L"rb");

	if(fp == NULL)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
	}

	return fp != NULL;
}

bool AsciiReader::Read( std::wstring& text, size_t len )
{
	if(fp == NULL)
		return false;

	RAII_Array<char> buf(len+1);

	size_t lenRead = fread(buf.GetPtr(), 1, len, fp);
	if(lenRead!=len)
	{
		errNum = ELMAX_READ_ERROR;
		std::wstring str = StrUtil::Format(L": Read {0} bytes out of {1} required!", lenRead, len);
		err = GetErrorMsg(errNum) + str;
		
		throw std::runtime_error(StrUtil::ConvToString(err));

		return false;
	}
	std::string str = buf.GetPtr();
	text = AsciiToWStr(str);

#ifdef _MICROSOFT
	if(ContainsNewline(text.c_str(), text.length()))
	{
		wchar_t* pszDest = NULL;
		size_t nDest = 0;

		if(FileToContents( text.c_str(), text.length(), pszDest, nDest ))
		{
			text = pszDest;
		}

		if( pszDest )
		{
			delete [] pszDest;
			pszDest = NULL;
		}
	}
#endif

	return true;
}

bool AsciiReader::ReadAll( std::wstring& text )
{
	size_t size = GetFileSize(filename);

	if(size==0)
		return false;

	if(fp == NULL)
		return false;

	RAII_Array<char> buf(size+1);
	size_t lenRead = fread(buf.GetPtr(), 1, size, fp);
	if(lenRead!=size)
	{
		errNum = ELMAX_READ_ERROR;
		std::wstring str = StrUtil::Format(L": Read {0} bytes out of {1} required!", lenRead, size);
		err = GetErrorMsg(errNum) + str;

		throw std::runtime_error(StrUtil::ConvToString(err));

		return false;
	}

	std::string str = buf.GetPtr();
	text = AsciiToWStr(str);

#ifdef _MICROSOFT
	if(ContainsNewline(text.c_str(), text.length()))
	{
		wchar_t* pszDest = NULL;
		size_t nDest = 0;

		if(FileToContents( text.c_str(), text.length(), pszDest, nDest ))
		{
			text = pszDest;
		}

		if( pszDest )
		{
			delete [] pszDest;
			pszDest = NULL;
		}
	}
#endif

	return true;
}

bool AsciiReader::ReadLine( std::wstring& text )
{
	if(fp == NULL)
		return false;

	std::string ctext = "";
	char ch = L'\0';

	while (!feof(fp))
	{
		ch = fgetc(fp);

		if(ch != '\r' && ch != '\n')
			ctext += ch;

		if(ch == '\n')
			break;
	}

	text = AsciiToWStr(ctext);

	return true;
}

std::wstring AsciiReader::AsciiToWStr(const std::string& str)
{
	std::wstring wstr = L"";
	for(size_t i=0; i<str.length(); ++i)
	{
		if(str[i] != '\r')
			wstr += (unsigned short)(str[i]);
	}

	return wstr;
}

bool AsciiReader::IsEOF()
{
	if(fp!=NULL)
	{
		return feof(fp) != 0; // not eof yet
	}

	return true;
}
