#pragma once
#include "BaseTextWriter.h"

namespace Elmax
{

class BEUnicodeWriter : public BaseTextWriter
{
public:
	BEUnicodeWriter(void);
	BEUnicodeWriter(const std::wstring& file, FILE_OP op);

	virtual ~BEUnicodeWriter(void);

	virtual bool Open(const std::wstring& file, FILE_OP op);

	virtual bool Write( const std::wstring& text );

	virtual bool WriteLine( const std::wstring& text );

private:
	BEUnicodeWriter(const BEUnicodeWriter&) {}
	BEUnicodeWriter& operator=(const BEUnicodeWriter&) { return *this; }

	bool WriteBOM();

	bool Write( const wchar_t* text );

	bool WriteLine( const wchar_t* text );

	bool Write( const wchar_t* text, size_t nBufLen );

	bool WriteLine( const wchar_t* text, size_t nBufLen );

	static void ConvToBigEndian(wchar_t* p, size_t size);

	static unsigned short* ConvToBigEndianShort(const std::wstring& text);

	static unsigned short* ConvToBigEndianShort(unsigned short* text, size_t len);
	
	bool BOMWritten;
};

}
