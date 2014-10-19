#pragma once

#include "BaseTextWriter.h"

namespace Elmax
{

class AsciiWriter : public BaseTextWriter
{
public:
	AsciiWriter(void);
	AsciiWriter(const std::wstring& file, FILE_OP op);

	virtual ~AsciiWriter(void);

	virtual bool Open(const std::wstring& file, FILE_OP op);

	virtual bool Write( const std::wstring& text );

	virtual bool WriteLine( const std::wstring& text );

private:
	AsciiWriter(const AsciiWriter&) {}
	AsciiWriter& operator=(const AsciiWriter&) { return *this; }

	bool Write( const wchar_t* text, size_t nBufLen );

	bool WriteLine( const wchar_t* text, size_t nBufLen );

	static std::string WStrToAscii(const std::wstring& str);

};

}