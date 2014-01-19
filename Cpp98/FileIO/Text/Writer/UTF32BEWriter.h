#pragma once

#include "BaseTextWriter.h"

namespace Elmax
{

class UTF32BEWriter : public BaseTextWriter
{
public:
	UTF32BEWriter(void);
	UTF32BEWriter(const std::wstring& file, FILE_OP op);
	virtual ~UTF32BEWriter(void);

	virtual bool Open(const std::wstring& file, FILE_OP op);

	virtual bool Write( const std::wstring& text );

	virtual bool WriteLine( const std::wstring& text );

private:
	UTF32BEWriter(const UTF32BEWriter&) {}
	UTF32BEWriter& operator=(const UTF32BEWriter&) { return *this; }

	bool WriteBOM();

	bool Write( const wchar_t* text, size_t nBufLen );

	bool WriteLine( const wchar_t* text, size_t nBufLen );

	bool BOMWritten;
};

}