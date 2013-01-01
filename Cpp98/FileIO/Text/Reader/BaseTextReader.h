#pragma once

#include <cstdio>
#include <string>
#include "../../Common/Common.h"

namespace Elmax
{

class BaseTextReader
{
public:
	BaseTextReader(void);
	BaseTextReader(const std::wstring& file);
	virtual ~BaseTextReader(void);

	virtual bool Open(const std::wstring& file) = 0;
	void Close();

	virtual bool Read( std::wstring& text, size_t len ) = 0;

	virtual bool ReadAll( std::wstring& text ) = 0;

	virtual bool ReadLine( std::wstring& text ) = 0;

	size_t GetFileSize(const std::wstring& file);

	virtual bool IsEOF() = 0;

	int GetLastError(std::wstring& str);
	void ClearLastError();


protected:
	bool FileToContents( 
		const wchar_t* pszSource, 
		size_t nSource, 
		wchar_t*& pszDest,
		size_t& nDest	);

	bool ContainsNewline(const wchar_t* text, size_t len);
	
	bool ContainsReturnCarriage(const wchar_t* text, size_t len);
	bool ContainsReturnCarriage(const std::wstring& text);

	std::wstring RemoveReturnCarriage(const std::wstring& text);

	FILE* fp;
	std::wstring contents;
	std::wstring filename;

	std::wstring err;
	int errNum;

	bool hasBOM;

private:
	BaseTextReader(const BaseTextReader&) {}
};

}
