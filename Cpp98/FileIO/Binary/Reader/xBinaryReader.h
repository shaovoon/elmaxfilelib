#pragma once

#include <cstdio>
#include <string>
#include "../Utils/BinaryTypeReadRef.h"
#include "../../Common/Common.h"

namespace Elmax
{

class xBinaryReader
{
public:
	xBinaryReader(void);
	xBinaryReader(const std::wstring& file);
	xBinaryReader(const std::string& file);
	~xBinaryReader(void);

	bool Open(const std::wstring& file);
	bool Open(const std::string& file);
	void Close();

	bool IsEOF();

	int Seek(long offset, int origin);

	long GetCurrPos();

	size_t Read( BinaryTypeReadRef D1 );

	size_t Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2 );

	size_t Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3 );

	size_t Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4 );

	size_t Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5 );

	size_t Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5, 
		BinaryTypeReadRef D6 );

	size_t Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5, 
		BinaryTypeReadRef D6, BinaryTypeReadRef D7 );

	size_t Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5, 
		BinaryTypeReadRef D6, BinaryTypeReadRef D7, BinaryTypeReadRef D8 );

	size_t Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5, 
		BinaryTypeReadRef D6, BinaryTypeReadRef D7, BinaryTypeReadRef D8, BinaryTypeReadRef D9 );

	size_t Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5, 
		BinaryTypeReadRef D6, BinaryTypeReadRef D7, BinaryTypeReadRef D8, BinaryTypeReadRef D9, BinaryTypeReadRef D10 );

	int GetLastError(std::wstring& msg);
	void ClearLastError();

private:
	xBinaryReader(const xBinaryReader&) {}
	xBinaryReader& operator=(const xBinaryReader& other) { return *this; }

	FILE* fp;
	std::wstring err;
	int errNum;
};

}
