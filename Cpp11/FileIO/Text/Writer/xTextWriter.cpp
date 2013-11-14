#include "xTextWriter.h"
#include "../Utils/StrUtilRef.h"

#include "UTF8Writer.h"
#include "UnicodeWriter.h"
#include "BEUnicodeWriter.h"
#include "AsciiWriter.h"
#include "../../Common/Enumeration.h"

using namespace Elmax;

xTextWriter::xTextWriter(void)
	: pWriter(nullptr),
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
	}

	return false;
}

void xTextWriter::Close()
{
	if(pWriter != nullptr)
	{
		pWriter->Close();
		delete pWriter;
		pWriter = nullptr;
		BOMWritten = false;
	}

	return;
}

bool xTextWriter::Write( const wchar_t* str )
{
	if(pWriter!=nullptr)
	{
		return pWriter->Write(std::wstring(str));
	}

	return false;
}

bool xTextWriter::WriteLine()
{
	if(pWriter!=nullptr)
	{
		return pWriter->Write(L"\n");
	}

	return false;
}

bool xTextWriter::WriteLine( const wchar_t* str )
{
	if(pWriter!=nullptr)
	{
		return pWriter->WriteLine(std::wstring(str));
	}

	return false;
}



void xTextWriter::Flush()
{
	if(pWriter!=nullptr)
		pWriter->Flush();
}

int xTextWriter::GetLastError(std::wstring& msg)
{
	if(pWriter!=nullptr)
	{
		return pWriter->GetLastError(msg);
	}

	msg = GetErrorMsg(ELMAX_NULL_POINTER);
	return ELMAX_NULL_POINTER;
}


void xTextWriter::ClearLastError()
{
	if(pWriter!=nullptr)
	{
		pWriter->ClearLastError();
	}
}

