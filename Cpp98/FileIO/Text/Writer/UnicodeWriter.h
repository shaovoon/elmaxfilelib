#pragma once

#include "BaseTextWriter.h"

namespace Elmax
{

class UnicodeWriter : public BaseTextWriter
{
public:
	UnicodeWriter(void);
	UnicodeWriter(const std::wstring& file, FILE_OP op);

	virtual ~UnicodeWriter(void);

	virtual bool Open(const std::wstring& file, FILE_OP op);

	virtual bool Write( const std::wstring& text );

	virtual bool WriteLine( const std::wstring& text );

private:
	UnicodeWriter(const UnicodeWriter&) {}
	UnicodeWriter& operator=(const UnicodeWriter&) { return *this; }

	bool WriteBOM();

	bool Write( const wchar_t* text );

	bool WriteLine( const wchar_t* text );

	bool Write( const wchar_t* text, size_t nBufLen );

	bool WriteLine( const wchar_t* text, size_t nBufLen );

	bool BOMWritten;
};

}