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

	size_t Read()
	{
		return 0;
	}

	template<typename T, typename... Args>
	size_t Read( T& t, Args&... args )
	{
		BinaryTypeReadRef dt(t);
		size_t totalRead = 0;
		if(fp!=nullptr)
		{
			if(dt.m_type != BinaryTypeReadRef::DTR_STRARRAY && dt.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && dt.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
			{
				size_t cnt = fread(dt.GetAddress(), dt.size, 1, fp);
				if(cnt==1)
					++totalRead;
			}
			else
			{
				dt.DeferredMake();
				size_t cnt = fread(dt.GetAddress(), dt.elementSize, dt.arraySize, fp);
				if(cnt == dt.arraySize)
					++totalRead;
			}

		}

		return totalRead + Read(args...);
	}

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
