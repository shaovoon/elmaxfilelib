#pragma once

#include "../Utils/DataType.h"
#include "BaseTextWriter.h"
#include "../../Common/Enumeration.h"

namespace Elmax
{


class xTextWriter
{
public:
	xTextWriter(void);
	~xTextWriter(void);

	bool Open(const std::wstring& file, FILE_TYPE ft, FILE_OP op);
	void Close();

	bool Write( const std::wstring& str );

	bool Write( const wchar_t* fmt, DataType D1 );

	bool Write( const wchar_t* fmt, DataType D1, DataType D2 );

	bool Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3 );

	bool Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4 );

	bool Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5 );

	bool Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
		DataType D6 );

	bool Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
		DataType D6, DataType D7 );

	bool Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
		DataType D6, DataType D7, DataType D8 );

	bool Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
		DataType D6, DataType D7, DataType D8, DataType D9 );

	bool Write( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
		DataType D6, DataType D7, DataType D8, DataType D9, DataType D10 );

	bool WriteLine();

	bool WriteLine( const std::wstring& str );

	bool WriteLine( const wchar_t* fmt, DataType D1 );

	bool WriteLine( const wchar_t* fmt, DataType D1, DataType D2 );

	bool WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3 );

	bool WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4 );

	bool WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5 );

	bool WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
		DataType D6 );

	bool WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
		DataType D6, DataType D7 );

	bool WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
		DataType D6, DataType D7, DataType D8 );

	bool WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
		DataType D6, DataType D7, DataType D8, DataType D9 );

	bool WriteLine( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, DataType D5, 
		DataType D6, DataType D7, DataType D8, DataType D9, DataType D10 );

	void Flush();

	int GetLastError(std::wstring& str);
	void ClearLastError();

private:
	xTextWriter(const xTextWriter&) {}
	xTextWriter& operator=(const xTextWriter& other) { return *this; }

	BaseTextWriter* pWriter;
	bool BOMWritten;

};

}
