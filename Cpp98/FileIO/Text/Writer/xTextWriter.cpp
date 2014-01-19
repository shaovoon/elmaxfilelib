#include "xTextWriter.h"
#include "../Utils/StrUtilRef.h"

#include "UTF8Writer.h"
#include "UTF32Writer.h"
#include "UTF32BEWriter.h"
#include "UnicodeWriter.h"
#include "BEUnicodeWriter.h"
#include "AsciiWriter.h"
#include "../../Common/Enumeration.h"

using namespace Elmax;

xTextWriter::xTextWriter(void)
	: pWriter(NULL),
	  BOMWritten(false)
{
}

xTextWriter::~xTextWriter(void)
{
	Close();
}

bool xTextWriter::Open(const std::wstring& file, FILE_TYPE ft, FILE_OP op)
{
	Close();

	switch(ft)
	{
	case FT_ASCII:
		pWriter = new AsciiWriter();
		return pWriter->Open(file, op);
	case FT_UTF8:
		pWriter = new UTF8Writer();
		return pWriter->Open(file, op);
	case FT_UNICODE:
		pWriter = new UnicodeWriter();
		return pWriter->Open(file, op);
	case FT_BEUNICODE:
		pWriter = new BEUnicodeWriter();
		return pWriter->Open(file, op);
	case FT_UTF32:
		pWriter = new UTF32Writer();
		return pWriter->Open(file, op);
	case FT_UTF32BE:
		pWriter = new UTF32BEWriter();
		return pWriter->Open(file, op);
	}

	return false;
}

void xTextWriter::Close()
{
	if(pWriter != NULL)
	{
		pWriter->Close();
		delete pWriter;
		pWriter = NULL;
		BOMWritten = false;
	}

	return;
}

bool xTextWriter::Write( const std::wstring& str )
{
	if(pWriter!=NULL)
	{
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::Write( const wchar_t* fmt, DataType D1 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1);
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::Write( const wchar_t* fmt, DataType D1, DataType D2 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2);
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3);
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4);
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5);
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
	DataType D6 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5, D6);
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
	DataType D6, DataType D7 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5, D6, D7);
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
	DataType D6, DataType D7, DataType D8 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5, D6, D7, D8);
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
	DataType D6, DataType D7, DataType D8, DataType D9 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5, D6, D7, D8, D9);
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
	DataType D6, DataType D7, DataType D8, DataType D9, DataType D10 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10);
		return pWriter->Write(str);
	}

	return false;
}

bool xTextWriter::WriteLine()
{
	if(pWriter!=NULL)
	{
		return pWriter->Write(L"\n");
	}

	return false;
}

bool xTextWriter::WriteLine( const std::wstring& str )
{
	if(pWriter!=NULL)
	{
		return pWriter->WriteLine(str);
	}

	return false;
}


bool xTextWriter::WriteLine( const wchar_t* fmt, DataType D1 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1);
		return pWriter->WriteLine(str);
	}

	return false;
}

bool xTextWriter::WriteLine( const wchar_t* fmt, DataType D1, DataType D2 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2);
		return pWriter->WriteLine(str);
	}

	return false;
}

bool xTextWriter::WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3);
		return pWriter->WriteLine(str);
	}

	return false;
}


bool xTextWriter::WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4);
		return pWriter->WriteLine(str);
	}

	return false;
}


bool xTextWriter::WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5);
		return pWriter->WriteLine(str);
	}

	return false;
}

bool xTextWriter::WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
	DataType D6 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5, D6);
		return pWriter->WriteLine(str);
	}

	return false;
}

bool xTextWriter::WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
	DataType D6, DataType D7 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5, D6, D7);
		return pWriter->WriteLine(str);
	}

	return false;
}

bool xTextWriter::WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
	DataType D6, DataType D7, DataType D8 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5, D6, D7, D8);
		return pWriter->WriteLine(str);
	}

	return false;
}

bool xTextWriter::WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
	DataType D6, DataType D7, DataType D8, DataType D9 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5, D6, D7, D8, D9);
		return pWriter->WriteLine(str);
	}

	return false;
}


bool xTextWriter::WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
	DataType D6, DataType D7, DataType D8, DataType D9, DataType D10 )
{
	if(pWriter!=NULL)
	{
		std::wstring str = StrUtilRef::Format(fmt, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10);
		return pWriter->WriteLine(str);
	}

	return false;
}

void xTextWriter::Flush()
{
	if(pWriter!=NULL)
		pWriter->Flush();
}

int xTextWriter::GetLastError(std::wstring& msg)
{
	if(pWriter!=NULL)
	{
		return pWriter->GetLastError(msg);
	}

	msg = GetErrorMsg(ELMAX_NULL_POINTER);
	return ELMAX_NULL_POINTER;
}


void xTextWriter::ClearLastError()
{
	if(pWriter!=NULL)
	{
		pWriter->ClearLastError();
	}
}

