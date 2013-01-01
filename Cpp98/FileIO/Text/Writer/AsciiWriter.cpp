#include "AsciiWriter.h"
#include "../Utils/StrUtil.h"

using namespace Elmax;

AsciiWriter::AsciiWriter(void)
{
}

AsciiWriter::AsciiWriter(const std::wstring& file, FILE_OP op)
{
	Open(file, op);
}

AsciiWriter::~AsciiWriter(void)
{
	Close();
}

bool AsciiWriter::Open(const std::wstring& file, FILE_OP op)
{
	if(op == APPEND)
	{
		fp = FileOpen(file, L"ab");
	}
	else
	{
		fp = FileOpen(file, L"wb");
	}

	if(fp == NULL)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
		throw std::runtime_error(StrUtil::ConvToString(file)+ ": file cannot be opened!");
	}

	return fp != NULL;
}

bool AsciiWriter::Write( const std::wstring& text )
{
	bool ret = Write( text.c_str(), text.length() );
	if(ret==false)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = GetErrorMsg(errNum);
		throw std::runtime_error("Write error");
	}
	return ret;
}

bool AsciiWriter::WriteLine( const std::wstring& text )
{
	bool ret = WriteLine( text.c_str(), text.length() );
	if(ret==false)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = GetErrorMsg(errNum);
		throw std::runtime_error("Write error");
	}
	return ret;
}

bool AsciiWriter::Write( const wchar_t* text, size_t nBufLen )
{
	if( !fp )
		return false;

	if( nBufLen == 0 )
		return true;

#ifdef _MICROSOFT

	if(ContainsNewline(text, nBufLen))
	{
		wchar_t* pszDest = NULL;
		size_t nDest = 0;

		bool bRet = ContentsToFile( text, nBufLen, pszDest, nDest );
		RAII_Array<wchar_t> dest = pszDest;

		if( !bRet )
			return false;

		if( pszDest )
		{
			std::string ascii = WStrToAscii(pszDest);
			fwrite( ascii.c_str(), 1, ascii.length(), fp );
		}
	}
	else
	{
		std::string ascii = WStrToAscii(text);
		fwrite( ascii.c_str(), 1, ascii.length(), fp );
	}

#else
	if( text )
	{
		std::string ascii = WStrToAscii(text);
		fwrite( ascii.c_str(), 1, ascii.length(), fp );
	}
#endif

	return true;
}


bool AsciiWriter::WriteLine( const wchar_t* text, size_t nBufLen )
{
	if( !fp )
		return false;

	if( nBufLen == 0 )
		return true;

#ifdef _MICROSOFT

	if(ContainsNewline(text, nBufLen))
	{
		wchar_t* pszDest = NULL;
		size_t nDest = 0;

		bool bRet = ContentsToFile( text, nBufLen, pszDest, nDest );
		RAII_Array<wchar_t> dest = pszDest;

		if( !bRet )
			return false;

		if( pszDest )
		{
			std::string ascii = WStrToAscii(pszDest);
			fwrite( ascii.c_str(), 1, ascii.length(), fp );
			char newline[] = "\r\n";
			fwrite( newline, 1, strlen(newline), fp );
		}
	}
	else
	{
		std::string ascii = WStrToAscii(text);
		fwrite( ascii.c_str(), 1, ascii.length(), fp );
		char newline[] = "\r\n";
		fwrite( newline, 1, strlen(newline), fp );
	}

#else
	if( text )
	{
		std::string ascii = WStrToAscii(text);
		fwrite( ascii.c_str(), 1, ascii.length(), fp );
		char newline[] = "\n";
		fwrite( newline, 1, strlen(newline), fp );
	}
#endif

	return true;
}

std::string AsciiWriter::WStrToAscii(const std::wstring& str)
{
	std::string ascii = "";
	for(size_t i=0; i<str.length(); ++i)
	{
		if((int)(str[i])>255)
			ascii += '_';
		else
		{
			ascii += (char)(str[i]);
		}
	}

	return ascii;
}
