#pragma once

#include "BaseTextWriter.h"

namespace Elmax
{

class UTF8Writer : public BaseTextWriter
{
public:
	UTF8Writer(void);
	UTF8Writer(const std::wstring& file, FILE_OP op);
	virtual ~UTF8Writer(void);

	virtual bool Open(const std::wstring& file, FILE_OP op);

	virtual bool Write( const std::wstring& text );

	virtual bool WriteLine( const std::wstring& text );

private:
	UTF8Writer(const UTF8Writer&) {}
	UTF8Writer& operator=(const UTF8Writer&) { return *this; }

	bool WriteBOM();

	bool Write( const wchar_t* text, size_t nBufLen );

	bool WriteLine( const wchar_t* text, size_t nBufLen );

	bool BOMWritten;
};

}