#include "UTF32Writer.h"
#include "../../UTF16Utils/utf16.h"
#include "../Utils/StrUtil.h"

using namespace Elmax;

UTF32Writer::UTF32Writer(void)
	: BOMWritten(false)
{
}

UTF32Writer::UTF32Writer(const std::wstring& file, FILE_OP op)
	: BOMWritten(false)
{
	Open(file, op);
}

UTF32Writer::~UTF32Writer(void)
{
}

bool UTF32Writer::Open(const std::wstring& file, FILE_OP op)
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
	}

	return fp != NULL;
}

bool UTF32Writer::WriteBOM()
{
	if( !fp )
		return false;

	unsigned char bom[4] = { 0xFF, 0xFE, 0x0, 0x0 };

	size_t len = fwrite( bom, 1, 4, fp );
	if(len!=4)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = GetErrorMsg(errNum);
		throw std::runtime_error("Write BOM error");

		return false;
	}

	return true;
}

bool UTF32Writer::Write( const std::wstring& text )
{
	if(BOMWritten == false)
	{
		WriteBOM();
		BOMWritten = true;
	}

	return Write( text.c_str(), text.length() );
}

bool UTF32Writer::WriteLine( const std::wstring& text )
{
	if(BOMWritten == false)
	{
		WriteBOM();
		BOMWritten = true;
	}

	return WriteLine( text.c_str(), text.length() );
}

bool UTF32Writer::Write( const wchar_t* text, size_t nBufLen )
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
			std::vector<unsigned int> vec;
			utf16::ConvertToUTF32(pszDest, nDest, vec);
			WriteRaw(&vec[0], vec.size(), false);
		}
	}
	else
	{
		std::vector<unsigned int> vec;
		utf16::ConvertToUTF32(text, vec);
		WriteRaw(&vec[0], vec.size(), false);
	}
#else
	if( text )
	{
		if(sizeof(wchar_t)==4)
		{
			WriteRaw(text, nBufLen, false);
		}
		else
		{
			std::vector<unsigned int> vec;
			utf16::ConvertToUTF32(text, vec);
			WriteRaw(&vec[0], vec.size(), false);
		}
	}
#endif

	return true;
}

bool UTF32Writer::WriteLine( const wchar_t* text, size_t nBufLen )
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
			std::vector<unsigned int> vec;
			utf16::ConvertToUTF32(pszDest, nDest, vec);
			vec.push_back((unsigned int)('\r'));
			vec.push_back((unsigned int)('\n'));
			WriteRaw(&vec[0], vec.size(), false);
		}
	}
	else
	{
		std::vector<unsigned int> vec;
		utf16::ConvertToUTF32(text, vec);
		vec.push_back((unsigned int)('\r'));
		vec.push_back((unsigned int)('\n'));
		WriteRaw(&vec[0], vec.size(), false);
	}
#else
	if( text )
	{
		if(sizeof(wchar_t)==4)
		{
			WriteRaw(text, nBufLen, false);

			wchar_t newline[1];
			newline[0] = '\n';
			WriteRaw(newline, 1, false);
		}
		else
		{
			std::vector<unsigned int> vec;
			utf16::ConvertToUTF32(text, vec);
			vec.push_back((unsigned int)('\n'));
			WriteRaw(&vec[0], vec.size(), false);
		}
	}
#endif

	return true;
}
