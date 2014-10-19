#pragma once


#include "DataType.h"
#include "DataTypeRef.h"
#include "SplitStrategy.h"

namespace Elmax
{

class StrUtil
{
public:
	StrUtil(void);
	~StrUtil(void);

	static std::wstring Format( const wchar_t* fmt, DataType D1 );

	static std::wstring Format( const wchar_t* fmt, DataType D1, DataType D2 );

	static std::wstring Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3 );

	static std::wstring Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4 );

	static std::wstring Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
		DataType D5 );

	static std::wstring Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
		DataType D5, DataType D6 );

	static std::wstring Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
		DataType D5, DataType D6, DataType D7 );

	static std::wstring Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
		DataType D5, DataType D6, DataType D7, DataType D8 );

	static std::wstring Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
		DataType D5, DataType D6, DataType D7, DataType D8, DataType D9 );

	static std::wstring Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
		DataType D5, DataType D6, DataType D7, DataType D8, DataType D9, DataType D10 );

	static std::wstring ReplaceAll(const std::wstring& text, const std::wstring& find, const std::wstring& replace);
private:
	static std::wstring Replace( std::wstring& fmtstr, std::vector<std::wstring>& vs );

	static std::wstring Anchor( int i );
public:
	void SetSplitStrategy( ISplitStrategy* pSplitStrategy )
	{
		m_pSplitStrategy = pSplitStrategy;
	}

	size_t Split( const std::wstring& StrToExtract,	DataTypeRef D1 );

	size_t Split( const std::wstring& StrToExtract,	DataTypeRef D1, DataTypeRef D2 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9 );

	size_t Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
		DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10 );

	static std::string ConvToString(const std::wstring& text);

	static std::wstring ConvToWString(const std::string& text);

	static std::wstring TrimRight(const std::wstring& str, const std::wstring& trimChars = L" \t\r\n");

	static std::wstring TrimLeft(const std::wstring& str, const std::wstring& trimChars = L" \t\r\n");

	static std::wstring Trim(const std::wstring& str, const std::wstring& trimChars = L" \t\r\n");


private:
	ISplitStrategy* m_pSplitStrategy;

};

}