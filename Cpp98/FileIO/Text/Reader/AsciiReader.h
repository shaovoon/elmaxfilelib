#pragma once

#include "BaseTextReader.h"

namespace Elmax
{

class AsciiReader : public BaseTextReader
{
public:
	AsciiReader(void);
	AsciiReader(const std::wstring& file);

	virtual ~AsciiReader(void);

	static bool IsValid(const std::wstring& file);

	virtual bool Open(const std::wstring& file);

	virtual bool Read( std::wstring& text, size_t len );

	virtual bool ReadAll( std::wstring& text );

	virtual bool ReadLine( std::wstring& text );

	virtual bool IsEOF();

private:
	AsciiReader(const AsciiReader&) {}
	AsciiReader& operator=(const AsciiReader&) { return* this; }

	static std::wstring AsciiToWStr(const std::string& str);

};

}