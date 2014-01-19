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

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
		DataTypeRef D21);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
		DataTypeRef D21, DataTypeRef D22);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
		DataTypeRef D21, DataTypeRef D22, DataTypeRef D23);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
		DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
		DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
		DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25, 
		DataTypeRef D26);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
		DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25, 
		DataTypeRef D26, DataTypeRef D27);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
		DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25, 
		DataTypeRef D26, DataTypeRef D27, DataTypeRef D28);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
		DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25, 
		DataTypeRef D26, DataTypeRef D27, DataTypeRef D28, DataTypeRef D29		);

	size_t ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
		DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
		DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
		DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
		DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25, 
		DataTypeRef D26, DataTypeRef D27, DataTypeRef D28, DataTypeRef D29, DataTypeRef D30		);

	bool ReadAll( std::wstring& text );

	int GetLastError(std::wstring& str);
	void ClearLastError();

private:
	xTextReader(const xTextReader&) {}
	xTextReader& operator=(const xTextReader&) { return* this; }

	BaseTextReader* pReader;
	ISplitStrategy* m_pSplitStrategy;

};

}
