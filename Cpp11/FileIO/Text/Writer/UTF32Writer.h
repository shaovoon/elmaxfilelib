#pragma once

#include "BaseTextWriter.h"

namespace Elmax
{

class UTF32Writer : public BaseTextWriter
{
public:
	UTF32Writer(void);
	UTF32Writer(const std::wstring& file, FILE_OP op);
	virtual ~UTF32Writer(void);

	virtual bool Open(const std::wstring& file, FILE_OP op);

	virtual bool Write( const std::wstring& text );

	virtual bool WriteLine( const std::wstring& text );

private:
	UTF32Writer(const UTF32Writer&) {}
	UTF32Writer& operator=(const UTF32Writer&) { return *this; }

	bool WriteBOM();

	bool Write( const wchar_t* text, size_t nBufLen );

	bool WriteLine( const wchar_t* text, size_t nBufLen );

	bool BOMWritten;
};

}