#pragma once

#include "BaseTextReader.h"

namespace Elmax
{

class UnicodeReader : public BaseTextReader
{
public:
	UnicodeReader(void);
	UnicodeReader(const std::wstring& file);
	virtual ~UnicodeReader(void);

	static bool IsValid(const std::wstring& file);

	virtual bool Open(const std::wstring& file);

	virtual bool Read( std::wstring& text, size_t len );

	virtual bool ReadAll( std::wstring& text );

	virtual bool ReadLine( std::wstring& text );

	virtual bool IsEOF();

private:
	UnicodeReader(const UnicodeReader&) {}
	UnicodeReader& operator=(const UnicodeReader&) { return* this; }

	void ReadBOM();
	
};

}