#pragma once
#include "BaseTextReader.h"

namespace Elmax
{

class BEUnicodeReader : public BaseTextReader
{
public:
	BEUnicodeReader(void);
	BEUnicodeReader(const std::wstring& file);
	virtual ~BEUnicodeReader(void);

	static bool IsValid(const std::wstring& file);

	virtual bool Open(const std::wstring& file);

	virtual bool Read( std::wstring& text, size_t len );

	virtual bool ReadAll( std::wstring& text );

	virtual bool ReadLine( std::wstring& text );

	virtual bool IsEOF();

private:
	BEUnicodeReader(const BEUnicodeReader&) {}
	BEUnicodeReader& operator=(const BEUnicodeReader&) { return* this; }

	static void ConvToLittleEndian(wchar_t* p, size_t size);

	static wchar_t ConvToLittleEndian(wchar_t ch);

	// For Linux because wchar_t on Linux and Mac OSX is 4 bytes
	static wchar_t* ConvToLittleEndianShort(unsigned short* p, size_t size);
	// For Linux because wchar_t on Linux and Mac OSX is 4 bytes
	static wchar_t ConvToLittleEndianShort(unsigned short ch1, unsigned short ch2);

	static unsigned short ConvToLittleEndianShort(unsigned short ch);

	
	void ReadBOM();
};

}
