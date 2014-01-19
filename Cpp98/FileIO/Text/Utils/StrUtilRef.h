#pragma once

#include "DataType.h"
#include "DataTypeRef.h"
#include "SplitStrategy.h"

namespace Elmax
{

class StrUtilRef
{
public:
	StrUtilRef(void);
	~StrUtilRef(void);

	static std::wstring Format( const wchar_t* fmt, DataType& D1 );

	static std::wstring Format( const wchar_t* fmt, DataType& D1, DataType& D2 );

	static std::wstring Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3 );

	static std::wstring Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4 );

	static std::wstring Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
		DataType& D5 );

	static std::wstring Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
		DataType& D5, DataType& D6 );

	static std::wstring Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
		DataType& D5, DataType& D6, DataType& D7 );

	static std::wstring Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
		DataType& D5, DataType& D6, DataType& D7, DataType& D8 );

	static std::wstring Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
		DataType& D5, DataType& D6, DataType& D7, DataType& D8, DataType& D9 );

	static std::wstring Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
		DataType& D5, DataType& D6, DataType& D7, DataType& D8, DataType& D9, DataType& D10 );
private:
	static std::wstring Replace( std::wstring& fmtstr, std::vector<std::wstring>& vs );

	static std::wstring Anchor( int i );
public:
	void SetSplitStrategy( ISplitStrategy* pSplitStrategy )
	{
		m_pSplitStrategy = pSplitStrategy;
	}

	size_t Split( const std::wstring& StrToExtract,	DataTypeRef& D1 );

	size_t Split( const std::wstring& StrToExtract,	DataTypeRef& D1, DataTypeRef& D2 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10 );
		
	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11	);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12	);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13	);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14	);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15	);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16	);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17	);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18	);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19	);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20	);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21		);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22		);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23		);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24		);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25		);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25, 
		DataTypeRef& D26		);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25, 
		DataTypeRef& D26, DataTypeRef& D27		);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25, 
		DataTypeRef& D26, DataTypeRef& D27, DataTypeRef& D28		);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25, 
		DataTypeRef& D26, DataTypeRef& D27, DataTypeRef& D28, DataTypeRef& D29		);

	size_t Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
		DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25, 
		DataTypeRef& D26, DataTypeRef& D27, DataTypeRef& D28, DataTypeRef& D29, DataTypeRef& D30		);


private:
	ISplitStrategy* m_pSplitStrategy;
};

}