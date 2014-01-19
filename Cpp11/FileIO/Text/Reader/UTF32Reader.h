#pragma once

#include "BaseTextReader.h"

namespace Elmax
{

class UTF32Reader : public BaseTextReader
{
public:
	UTF32Reader(void);
	UTF32Reader(const std::wstring& file);
	virtual ~UTF32Reader(void);

	static bool IsValid(const std::wstring& file);

	virtual bool Open(const std::wstring& file);

	virtual bool Read( std::wstring& text, size_t len );

	virtual bool ReadAll( std::wstring& text );

	virtual bool ReadLine( std::wstring& text );

	virtual bool IsEOF();

private:
	UTF32Reader(const UTF32Reader&) {}
	UTF32Reader& operator=(const UTF32Reader&) { return* this; }

	void ReadBOM();
	
};

}