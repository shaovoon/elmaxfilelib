#pragma once

#include <cstdio>
#include <string>
#include "../../Common/Common.h"
#include "../../Common/Platform.h"

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

	bool IsBigEndian() {return isBigEndian;}

	size_t ReadRawBytes(char* arr, size_t size);
	size_t ReadRaw(wchar_t* arr, size_t size, bool readBigEndian);
	size_t ReadRaw(unsigned int* arr, size_t size, bool readBigEndian);
	size_t ReadRaw(unsigned short* arr, size_t size, bool readBigEndian);


	FILE* fp;
	std::wstring contents;
	std::wstring filename;

	std::wstring err;
	int errNum;

	bool hasBOM;
	bool isBigEndian;

private:
	BaseTextReader(const BaseTextReader&) {}
};

}
