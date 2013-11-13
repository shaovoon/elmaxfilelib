#pragma once

#include "../../Common/Common.h"

namespace Elmax
{

class StrArray
{
public:
	StrArray()
	{
		Init();
	}

	StrArray(const size_t& cnt)
	{
		Init();
		MakeArray(cnt);
	}

	virtual ~StrArray(void)
	{
		Destroy();
	}

	void Init()
	{
		m_ptr = nullptr;
		m_nSize = 0;
		isDeferredMake = false;
		pDeferredCnt = nullptr;

	}

	void Destroy()
	{
		if(m_ptr!=nullptr)
		{
			delete [] m_ptr;
			m_ptr = nullptr;
			m_nSize = 0;
		}
	}

	StrArray& MakeArray(const size_t& cnt)
	{
		Destroy();

		size_t totalSize = cnt + 1;
		m_ptr = new char[totalSize];
		memset(m_ptr, 0, totalSize);
		m_nSize = cnt;

		return *this;
	}

	StrArray& DeferredMake(size_t& cnt)
	{
		isDeferredMake = true;
		pDeferredCnt = &cnt;

		return *this;
	}

	char* GetPtr()
	{
		return m_ptr;
	}

	size_t GetTotalSize() // length in terms of bytes
	{
		return m_nSize * sizeof(char);
	}

	size_t GetElementSize()
	{
		return sizeof(char);
	}

	size_t GetArraySize()
	{
		return m_nSize;
	}

	char& operator[](size_t i)
	{
		if(i<m_nSize&&m_ptr!=nullptr)
			return m_ptr[i];

		if(i>=m_nSize)
			throw std::out_of_range("Index out of bounds!");
		
		if(m_ptr==nullptr)
			throw std::runtime_error("Null pointer!");
	}

	bool IsDeferredMake()
	{
		return isDeferredMake;
	}

	void MakeNow()
	{
		if(isDeferredMake)
		{
			isDeferredMake=false;
			MakeArray(*pDeferredCnt);
		}
	}

private:
	// copy constructor
	StrArray(const StrArray&) {}
	// assignment
	StrArray& operator=(const StrArray&) { return *this; }

	char* m_ptr;
	size_t m_nSize; // number of elements
	bool isDeferredMake;
	size_t* pDeferredCnt;

};

}
