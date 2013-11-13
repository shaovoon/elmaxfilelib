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

	size_t Write()
	{
		return 0;
	}

	template<typename T, typename... Args>
	size_t Write( T t, Args... args )
	{
		BinaryTypeRef dt(t);

		size_t totalWritten = 0;
		if(fp!=nullptr)
		{
			if(dt.m_type != BinaryTypeRef::DTR_STR && dt.m_type != BinaryTypeRef::DTR_WSTR && dt.m_type != BinaryTypeRef::DTR_BASEARRAY)
			{
				size_t len = fwrite(dt.GetAddress(), dt.size, 1, fp);
				if(len==1)
					++totalWritten;
			}
			else
			{
				size_t len = fwrite(dt.GetAddress(), dt.elementSize, dt.arraySize, fp);
				if(len==dt.arraySize)
					++totalWritten;
			}

		}

		return totalWritten + Write(args...);
	}


	int GetLastError(std::wstring& str);
	void ClearLastError();

private:
	xBinaryWriter(const xBinaryWriter&) {}
	xBinaryWriter& operator=(const xBinaryWriter&) { return* this; }

	FILE* fp;
	std::wstring err;
	int errNum;
};

}
