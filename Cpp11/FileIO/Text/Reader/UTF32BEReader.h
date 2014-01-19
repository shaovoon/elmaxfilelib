#pragma once

#include "BaseTextReader.h"

namespace Elmax
{

class UTF32BEReader : public BaseTextReader
{
public:
	UTF32BEReader(void);
	UTF32BEReader(const std::wstring& file);
	virtual ~UTF32BEReader(void);

	static bool IsValid(const std::wstring& file);

	virtual bool Open(const std::wstring& file);

	virtual bool Read( std::wstring& text, size_t len );

	virtual bool ReadAll( std::wstring& text );

	virtual bool ReadLine( std::wstring& text );

	virtual bool IsEOF();

private:
	UTF32BEReader(const UTF32BEReader&) {}
	UTF32BEReader& operator=(const UTF32BEReader&) { return* this; }

	void ReadBOM();
	
};

}