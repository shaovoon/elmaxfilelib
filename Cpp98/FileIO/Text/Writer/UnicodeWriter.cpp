#include "UnicodeWriter.h"
#include "../Utils/StrUtil.h"

using namespace Elmax;

UnicodeWriter::UnicodeWriter(void)
	: BOMWritten(false)
{
}

UnicodeWriter::UnicodeWriter(const std::wstring& file, FILE_OP op)
	: BOMWritten(false)
{
	Open(file, op);
}

UnicodeWriter::~UnicodeWriter(void)
{
}

bool UnicodeWriter::Open(const std::wstring& file, FILE_OP op)
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

bool UnicodeWriter::WriteBOM()
{
	if( !fp )
		return false;

	unsigned char bom[2] = { 0xFF, 0xFE };

	size_t len = fwrite( bom, 1, 2, fp );
	if(len!=2)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = GetErrorMsg(errNum);
		throw std::runtime_error("Write BOM error");

		return false;
	}

	return true;
}

bool UnicodeWriter::Write( const std::wstring& text )
{
	if(BOMWritten == false)
	{
		WriteBOM();
		BOMWritten = true;
	}

	return Write( text.c_str() );
}

bool UnicodeWriter::WriteLine( const std::wstring& text )
{
	if(BOMWritten == false)
	{
		WriteBOM();
		BOMWritten = true;
	}

	return WriteLine( text.c_str(), text.size() );
}

bool UnicodeWriter::WriteLine( const wchar_t* text )
{
	return WriteLine( text, wcslen(text) );
}

bool UnicodeWriter::Write( const wchar_t* text )
{
	return Write( text, wcslen( text ) );
}

bool UnicodeWriter::Write( const wchar_t* text, size_t nBufLen )
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
			WriteRaw(pszDest, nDest, false);
		}
	}
	else
	{
		WriteRaw(const_cast<wchar_t*>(text), nBufLen, false);
	}
#else
	if(sizeof(wchar_t)==4)
	{
		if( text )
		{
			size_t arrLen = 0;
			bool upperPlane = utf16::ContainsUpperPlane(text, arrLen);
			if(nBufLen>30||upperPlane)
			{
				if(upperPlane)
				{
					RAII_Array<unsigned short> sharr = utf16::ConvertToUTF16(text, arrLen);
					WriteRaw(sharr.GetPtr(), arrLen, false);
				}
				else
				{
					RAII_Array<unsigned short> sharr(nBufLen);
					for(size_t i=0;i<nBufLen;++i)
					{
						sharr.GetPtr()[i] = (unsigned short)(text[i]);
					}
					WriteRaw(sharr.GetPtr(), nBufLen, false);
				}
			}
			else if(nBufLen<=30&&upperPlane==false)
			{
				unsigned short sharrStack[31];
				memset(sharrStack, 0, sizeof(sharrStack));
				for(size_t i=0;i<nBufLen;++i)
				{
					sharrStack[i] = (unsigned short)(text[i]);
				}
				WriteRaw(sharrStack, nBufLen, false);
			}
		}
	}
	else
	{
		if( text )
		{
			WriteRaw(text, nBufLen, false);
		}
	}
#endif

	return true;
}

bool UnicodeWriter::WriteLine( const wchar_t* text, size_t nBufLen )
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
			WriteRaw(pszDest, nDest, false);

			wchar_t newline[] = L"\r\n";
			WriteRaw(newline, wcslen(newline), false);
		}
	}
	else
	{
		WriteRaw(const_cast<wchar_t*>(text), nBufLen, false);

		wchar_t newline[] = L"\r\n";
		WriteRaw(newline, wcslen(newline), false);
	}
#else
	if(sizeof(wchar_t)==4)
	{
		if( text )
		{
			size_t arrLen = 0;
			bool upperPlane = utf16::ContainsUpperPlane(text, arrLen);
			if(nBufLen>30||upperPlane)
			{
				if(upperPlane)
				{
					RAII_Array<unsigned short> sharr = utf16::ConvertToUTF16(text, arrLen);
					WriteRaw(sharr.GetPtr(), arrLen, false);
				}
				else
				{
					RAII_Array<unsigned short> sharr(nBufLen);
					for(size_t i=0;i<nBufLen;++i)
					{
						sharr.GetPtr()[i] = (unsigned short)(text[i]);
					}
					WriteRaw(sharr.GetPtr(), nBufLen, false);
				}
			}
			else if(nBufLen<=30&&upperPlane==false)
			{
				unsigned short sharrStack[31];
				memset(sharrStack, 0, sizeof(sharrStack));
				for(size_t i=0;i<nBufLen;++i)
				{
					sharrStack[i] = (unsigned short)(text[i]);
				}
				WriteRaw(sharrStack, nBufLen, false);
			}
			unsigned short newline[1];
			newline[0] = '\n';
			WriteRaw(newline, 1, false);
		}
	}
	else
	{
		if( text )
		{
			WriteRaw(text, nBufLen, false);

			wchar_t newline[] = L"\n";
			WriteRaw(newline, wcslen(newline), false);
		}
	}
#endif

	return true;
}
