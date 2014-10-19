#pragma once

#include "BaseTextReader.h"

namespace Elmax
{

class UTF8Reader : public BaseTextReader
{
public:
	UTF8Reader(void);
	UTF8Reader(const std::wstring& file);
	virtual ~UTF8Reader(void);

	static bool IsValid(const std::wstring& file);

	virtual bool Open(const std::wstring& file);

	virtual bool Read( std::wstring& text, size_t len );

	virtual bool ReadAll( std::wstring& text );

	virtual bool ReadLine( std::wstring& text );

	virtual bool IsEOF();

private:
	UTF8Reader(const UTF8Reader&) {}
	UTF8Reader& operator=(const UTF8Reader&) { return* this; }

	void ReadBOM();

	size_t pos;
	std::wstring allText;
};

}