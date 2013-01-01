#pragma once

#include "../Utils/DataType.h"
#include "BaseTextWriter.h"
#include "../../Common/Enumeration.h"
#include "../Utils/StrUtilRef.h"

namespace Elmax
{


class xTextWriter
{
public:
	xTextWriter(void);
	~xTextWriter(void);

	bool Open(const std::wstring& file, FILE_TYPE ft, FILE_OP op);
	void Close();

	bool Write( const wchar_t* str );

	template<typename... Args>
	bool Write( const wchar_t* fmt, Args&... args )
	{
		std::wstring str = StrUtilRef::Format(std::wstring(fmt), 0, args...);

		if(pWriter!=nullptr)
		{
			return pWriter->Write(str);
		}

		return false;

	}


	bool WriteLine();

	bool WriteLine( const wchar_t* str );

	template<typename... Args>
	bool WriteLine( const wchar_t* fmt, Args&... args )
	{
		std::wstring str = StrUtilRef::Format(std::wstring(fmt), 0, args...);

		if(pWriter!=nullptr)
		{
			return pWriter->WriteLine(str);
		}

		return false;

	}


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
