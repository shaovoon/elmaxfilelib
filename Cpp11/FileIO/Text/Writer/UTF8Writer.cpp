#include "UTF8Writer.h"
#include "../../UTF8Utils/utf8.h"
#include "../Utils/StrUtil.h"

using namespace Elmax;

UTF8Writer::UTF8Writer(void)
	: BOMWritten(false)
{
}

UTF8Writer::UTF8Writer(const std::wstring& file, FILE_OP op)
	: BOMWritten(false)
{
	Open(file, op);
}

UTF8Writer::~UTF8Writer(void)
{
}

bool UTF8Writer::Open(const std::wstring& file, FILE_OP op)
{
	if(op == APPEND)
	{
		fp = FileOpen(file, L"ab");
	}
	else
	{
		fp = FileOpen(file, L"wb");
	}

	if(fp == nullptr)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
	}

	return fp != nullptr;
}

bool UTF8Writer::WriteBOM()
{
	if( !fp )
		return false;

	unsigned char bom[3] = { 0xEF, 0xBB, 0xBF };

	size_t len = fwrite( bom, 1, 3, fp );
	if(len!=3)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = GetErrorMsg(errNum);
		throw std::runtime_error("Write BOM error");

		return false;
	}

	return true;
}

bool UTF8Writer::Write( const std::wstring& text )
{
	if(BOMWritten == false)
	{
		WriteBOM();
		BOMWritten = true;
	}

	return Write( text.c_str(), text.length() );
}

bool UTF8Writer::WriteLine( const std::wstring& text )
{
	if(BOMWritten == false)
	{
		WriteBOM();
		BOMWritten = true;
	}

	return WriteLine( text.c_str(), text.length() );
}

bool UTF8Writer::Write( const wchar_t* text, size_t nBufLen )
{
	if( !fp )
		return false;

	if( nBufLen == 0 )
		return true;

#ifdef _MICROSOFT

	if(ContainsNewline(text, nBufLen))
	{
		wchar_t* pszDest = nullptr;
		size_t nDest = 0;

		bool bRet = ContentsToFile( text, nBufLen, pszDest, nDest );
		RAII_Array<wchar_t> dest = pszDest;

		if( !bRet )
			return false;

		if( pszDest )
		{
			std::string utf8line; 
			utf8::utf16to8(pszDest, pszDest+nDest, std::back_inserter(utf8line));

			fwrite( utf8line.c_str(), 1, utf8line.length(), fp );
		}
	}
	else
	{
		std::string utf8line; 
		utf8::utf16to8(text, text+nBufLen, std::back_inserter(utf8line));

		fwrite( utf8line.c_str(), 1, utf8line.length(), fp );
	}
#else
	if( text )
	{
		if(sizeof(wchar_t)==4)
		{
			size_t arrLen = 0;
			if(utf16::ContainsUpperPlane(text, arrLen))
			{
				std::string utf8line; 
				utf8::utf32to8(text, text+nBufLen, std::back_inserter(utf8line));

				fwrite( utf8line.c_str(), 1, utf8line.length(), fp );
			}
			else
			{
				std::string utf8line; 
				utf8::utf16to8(text, text+nBufLen, std::back_inserter(utf8line));

				fwrite( utf8line.c_str(), 1, utf8line.length(), fp );
			}
		}
		else
		{
			std::string utf8line; 
			utf8::utf16to8(text, text+nBufLen, std::back_inserter(utf8line));

			fwrite( utf8line.c_str(), 1, utf8line.length(), fp );
		}
	}
#endif

	return true;
}

bool UTF8Writer::WriteLine( const wchar_t* text, size_t nBufLen )
{
	if( !fp )
		return false;

	if( nBufLen == 0 )
		return true;

#ifdef _MICROSOFT

	if(ContainsNewline(text, nBufLen))
	{
		wchar_t* pszDest = nullptr;
		size_t nDest = 0;

		bool bRet = ContentsToFile( text, nBufLen, pszDest, nDest );
		RAII_Array<wchar_t> dest = pszDest;

		if( !bRet )
			return false;

		if( pszDest )
		{
			std::string utf8line; 
			utf8::utf16to8(pszDest, pszDest+nDest, std::back_inserter(utf8line));

			fwrite( utf8line.c_str(), 1, utf8line.length(), fp );

			char newline[] = "\r\n";
			fwrite( newline, 1, strlen(newline), fp );
		}
	}
	else
	{
		std::string utf8line; 
		utf8::utf16to8(text, text+nBufLen, std::back_inserter(utf8line));

		fwrite( utf8line.c_str(), 1, utf8line.length(), fp );

		char newline[] = "\r\n";
		fwrite( newline, 1, strlen(newline), fp );

	}
#else
	if( text )
	{
		if(sizeof(wchar_t)==4)
		{
			size_t arrLen = 0;
			if(utf16::ContainsUpperPlane(text, arrLen))
			{
				std::string utf8line; 
				utf8::utf32to8(text, text+nBufLen, std::back_inserter(utf8line));

				fwrite( utf8line.c_str(), 1, utf8line.length(), fp );

				char newline[] = "\n";
				fwrite( newline, 1, strlen(newline), fp );
			}
			else
			{
				std::string utf8line; 
				utf8::utf16to8(text, text+nBufLen, std::back_inserter(utf8line));

				fwrite( utf8line.c_str(), 1, utf8line.length(), fp );

				char newline[] = "\n";
				fwrite( newline, 1, strlen(newline), fp );
			}
		}
		else
		{
			std::string utf8line; 
			utf8::utf16to8(text, text+nBufLen, std::back_inserter(utf8line));

			fwrite( utf8line.c_str(), 1, utf8line.length(), fp );

			char newline[] = "\n";
			fwrite( newline, 1, strlen(newline), fp );
		}
	}
#endif

	return true;
}
