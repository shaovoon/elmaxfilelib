#pragma once

#include "../../Common/Common.h"

namespace Elmax
{

class WStrArray
{
public:
	WStrArray()
	{
		Init();
	}

	WStrArray(const size_t& cnt)
	{
		Init();
		MakeArray(cnt);
	}

	virtual ~WStrArray(void)
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

	WStrArray& MakeArray(const size_t& cnt)
	{
		Destroy();
		size_t totalSize = cnt + 1;
		m_ptr = new wchar_t[totalSize];
		memset(m_ptr, 0, totalSize*sizeof(wchar_t));
		m_nSize = cnt;

		return *this;
	}

	WStrArray& DeferredMake(size_t& cnt)
	{
		isDeferredMake = true;
		pDeferredCnt = &cnt;

		return *this;
	}

	wchar_t* GetPtr()
	{
		return m_ptr;
	}

	size_t GetTotalSize() // length in terms of bytes
	{
		return m_nSize * sizeof(wchar_t);
	}

	size_t GetElementSize()
	{
		return sizeof(wchar_t);
	}

	size_t GetArraySize()
	{
		return m_nSize;
	}

	wchar_t& operator[](size_t i)
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
	WStrArray(const WStrArray&) {}
	// assignment
	WStrArray& operator=(const WStrArray&) { return *this; }

	wchar_t* m_ptr;
	size_t m_nSize;
	bool isDeferredMake;
	size_t* pDeferredCnt;
};

}
