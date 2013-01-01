#include "BEUnicodeWriter.h"
#include "../../Common/Enumeration.h"
#include "../Utils/StrUtil.h"

using namespace Elmax;

BEUnicodeWriter::BEUnicodeWriter(void)
	: BOMWritten(false)
{
}

BEUnicodeWriter::BEUnicodeWriter(const std::wstring& file, FILE_OP op)
	: BOMWritten(false)
{
	Open(file, op);
}

BEUnicodeWriter::~BEUnicodeWriter(void)
{
}

bool BEUnicodeWriter::Open(const std::wstring& file, FILE_OP op)
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
		throw std::runtime_error(StrUtil::ConvToString(file)+ ": file cannot be opened!");
	}

	return fp != nullptr;
}

bool BEUnicodeWriter::WriteBOM()
{
	if( !fp )
		return false;

	unsigned char bom[2] = { 0xFE, 0xFF };

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

bool BEUnicodeWriter::Write( const std::wstring& text )
{
	if(BOMWritten == false)
	{
		WriteBOM();
		BOMWritten = true;
	}

	bool ret = Write( text.c_str() );
	if(ret==false)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = GetErrorMsg(errNum);
		throw std::runtime_error("Write error");
	}

	return ret;
}

bool BEUnicodeWriter::WriteLine( const std::wstring& text )
{
	if(BOMWritten == false)
	{
		WriteBOM();
		BOMWritten = true;
	}

	bool ret = WriteLine( text.c_str(), text.length() );
	if(ret==false)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = GetErrorMsg(errNum);
		throw std::runtime_error("Write error");
	}

	return ret;

}

bool BEUnicodeWriter::WriteLine( const wchar_t* text )
{
	return WriteLine( text, wcslen(text) );
}

bool BEUnicodeWriter::Write( const wchar_t* text )
{
	return Write( text, wcslen( text ) );
}

bool BEUnicodeWriter::Write( const wchar_t* text, size_t nBufLen )
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
			ConvToBigEndian(pszDest, nDest);
			fwrite( pszDest, 2, nDest, fp );
		}
	}
	else
	{
		RAII_Array<wchar_t> pszDest(nBufLen+1);

		Wcscpy(pszDest.GetPtr(), text, nBufLen+1);

		ConvToBigEndian(pszDest.GetPtr(), nBufLen);
		fwrite( pszDest.GetPtr(), 2, nBufLen, fp );
	}
#else
	if( text )
	{
		if(sizeof(wchar_t)==4)
		{
			size_t arrLen = 0;
			bool upperPlane = utf16::ContainsUpperPlane(text, arrLen);
			if(upperPlane)
			{
				std::wstring str =  utf16::ConvertToUTF16W(text);
				RAII_Array<unsigned short> sharr = ConvToBigEndianShort(str);
				fwrite( sharr.GetPtr(), 2, arrLen, fp );
			}
			else
			{
				RAII_Array<unsigned short> arr = ConvToBigEndianShort(text);
				fwrite( arr.GetPtr(), 2, nBufLen, fp );
			}
		}
		else
		{
			RAII_Array<wchar_t> pszDest(nBufLen+1);

			wcscpy(pszDest.GetPtr(), text);

			ConvToBigEndian(pszDest.GetPtr(), nBufLen);
			fwrite( pszDest.GetPtr(), 2, nBufLen, fp );
		}
	}
#endif

	return true;
}

bool BEUnicodeWriter::WriteLine( const wchar_t* text, size_t nBufLen )
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
			ConvToBigEndian(pszDest, nDest);
			fwrite( pszDest, 2, nDest, fp );
			wchar_t newline[] = L"\r\n";
			ConvToBigEndian(newline, 2);
			fwrite( newline, 2, wcslen(newline), fp );
		}
	}
	else
	{
		RAII_Array<wchar_t> pszDest(nBufLen+1);

		Wcscpy(pszDest.GetPtr(), text, nBufLen+1);

		ConvToBigEndian(pszDest.GetPtr(), nBufLen);
		fwrite( pszDest.GetPtr(), 2, nBufLen, fp );
		wchar_t newline[] = L"\r\n";
		ConvToBigEndian(newline, 2);
		fwrite( newline, 2, wcslen(newline), fp );
	}
#else
	if( text )
	{
		if(sizeof(wchar_t)==4)
		{
			size_t arrLen = 0;
			bool upperPlane = utf16::ContainsUpperPlane(text, arrLen);
			if(upperPlane)
			{
				std::wstring textWithNewline = text;
				textWithNewline += L"\n";
				std::wstring str =  utf16::ConvertToUTF16W(textWithNewline);
				RAII_Array<unsigned short> arr =  ConvToBigEndianShort(str);
				
				fwrite( arr.GetPtr(), 2, str.size(), fp );
			}
			else
			{
				std::wstring textWithNewline = text;
				textWithNewline += L"\n";
				RAII_Array<unsigned short> arr = ConvToBigEndianShort(textWithNewline);
				fwrite( arr.GetPtr(), 2, textWithNewline.size(), fp );
			}
		}
		else
		{
			RAII_Array<wchar_t> pszDest(nBufLen+1);

			wcscpy(pszDest.GetPtr(), text);

			ConvToBigEndian(pszDest.GetPtr(), nBufLen);
			fwrite( pszDest.GetPtr(), 2, nBufLen, fp );
			wchar_t newline[] = L"\n";
			ConvToBigEndian(newline, 1);
			fwrite( newline, 2, wcslen(newline), fp );
		}
	}
#endif

	return true;
}

void BEUnicodeWriter::ConvToBigEndian(wchar_t* p, size_t size)
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
unsigned short* BEUnicodeWriter::ConvToBigEndianShort(const std::wstring& text)
{
	char swap[2];
	UnionText unionText;
	RAII_Array<unsigned short> arr(text.size()+1);
	for(size_t i=0; i<text.size(); ++i)
	{
		unionText.ch = text[i];
		swap[0] = unionText.arr[1];
		swap[1] = unionText.arr[0];
 
		unionText.arr[0] = swap[0];
		unionText.arr[1] = swap[1];
 
		arr.GetPtr()[i] = (unsigned short)(unionText.ch);
	}
 
	return arr.Detach();
}

unsigned short* BEUnicodeWriter::ConvToBigEndianShort(unsigned short* arr, size_t len)
{
	char swap[2];
	UnionText unionText;
	memset(arr, 0, sizeof(unsigned short)*(len+1));
	for(size_t i=0; i<len; ++i)
	{
		unionText.ch = arr[i];
		swap[0] = unionText.arr[1];
		swap[1] = unionText.arr[0];

		unionText.arr[0] = swap[0];
		unionText.arr[1] = swap[1];

		arr[i] = (unsigned short)(unionText.ch);
	}

	return arr;
}
