#pragma once

#include <cstdio>
#include <string>
#include "../Utils/BinaryTypeRef.h"
#include "../../Common/Common.h"

namespace Elmax
{
class xBinaryWriter
{
public:
	xBinaryWriter(void);
	xBinaryWriter(const std::wstring& file);
	xBinaryWriter(const std::string& file);
	~xBinaryWriter(void);

	bool Open(const std::wstring& file);
	bool Open(const std::string& file);
	void Close();

	bool IsEOF();

	int Seek(long offset, int origin);

	long GetCurrPos();

	size_t Write( BinaryTypeRef D1 );

	size_t Write( BinaryTypeRef D1, BinaryTypeRef D2 );

	size_t Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3 );

	size_t Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4 );

	size_t Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5 );

	size_t Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5, 
		BinaryTypeRef D6 );

	size_t Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5, 
		BinaryTypeRef D6, BinaryTypeRef D7 );

	size_t Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5, 
		BinaryTypeRef D6, BinaryTypeRef D7, BinaryTypeRef D8 );

	size_t Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5, 
		BinaryTypeRef D6, BinaryTypeRef D7, BinaryTypeRef D8, BinaryTypeRef D9 );

	size_t Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5, 
		BinaryTypeRef D6, BinaryTypeRef D7, BinaryTypeRef D8, BinaryTypeRef D9, BinaryTypeRef D10 );

	int GetLastError(std::wstring& str);
	void ClearLastError();

private:
	xBinaryWriter(const xBinaryWriter&) {}
	xBinaryWriter& operator=(const xBinaryWriter& other) { return* this; }

	FILE* fp;
	std::wstring err;
	int errNum;
};

}
