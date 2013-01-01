#pragma once

#include "../Utils/SplitStrategy.h"
#include "../Utils/DataTypeRef.h"
#include "BaseTextReader.h"

namespace Elmax
{

class xTextReader
{
public:
	xTextReader(void);
	~xTextReader(void);

	bool Open(const std::wstring& file);
	bool Open(const std::wstring& file, FILE_TYPE ftype);
	void Close();

	void SetSplitStrategy( ISplitStrategy* pSplitStrategy )
	{
		m_pSplitStrategy = pSplitStrategy;
	}

	bool IsEOF();

	size_t Read( size_t len, DataTypeRef D1 );

	size_t Read( size_t len, DataTypeRef D1, DataTypeRef D2 );

	size_t Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3 );

	size_t Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4 );

	size_t Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5 );

	size_t Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6 );

	size_t Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7 );

	size_t Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8 );

	size_t Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9 );

	size_t Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10 );

	size_t ReadLine( DataTypeRef D1 );

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2 );

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3 );

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4 );

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5 );

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6 );

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7 );

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8 );

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9 );

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10 );

	bool ReadAll( std::wstring& text );

	int GetLastError(std::wstring& str);
	void ClearLastError();

private:
	xTextReader(const xTextReader&) {}
	xTextReader& operator=(const xTextReader& other) { return* this; }

	BaseTextReader* pReader;
	ISplitStrategy* m_pSplitStrategy;

};

}
