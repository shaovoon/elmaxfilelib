#pragma once

#include "../../Common/Common.h"

namespace Elmax
{

class BaseArray
{
public:
	BaseArray()
	{
		Init();
	}

	BaseArray(const size_t& cnt)
	{
		Init();
		m_ptr = new char[cnt];
		m_nElemSize = 1;
		m_nSize = cnt;
		m_bDelete = true;
	}

	virtual ~BaseArray(void)
	{
		Destroy();
	}

	void Init()
	{
		m_ptr = NULL;
		m_nElemSize = 0;
		m_nSize = 0;
		m_bDelete = false;
		isDeferredMake = false;
		pDeferredCnt = NULL;
	}

	void Destroy()
	{
		if(m_bDelete)
		{
			if(m_ptr!=NULL)
			{
				delete [] m_ptr;
				m_ptr = NULL;
			}
		}
	}

	BaseArray& MakeArray(const size_t& cnt)
	{
		Destroy();
		m_ptr = new char[cnt];
		m_nElemSize = 1;
		m_nSize = cnt;
		m_bDelete = true;

		return *this;
	}

	BaseArray& DeferredMake(size_t& cnt)
	{
		isDeferredMake = true;
		pDeferredCnt = &cnt;

		return *this;
	}

	void SetPtr(char* ptr, size_t nElemSize, size_t nSize)
	{
		m_ptr = ptr;
		m_nElemSize = nElemSize;
		m_nSize = nSize;
		m_bDelete = false;
	}

	char* GetPtr()
	{
		return m_ptr;
	}

	size_t GetTotalSize() // length in terms of bytes
	{
		return m_nElemSize * m_nSize;
	}

	size_t GetElementSize()
	{
		return m_nElemSize;
	}

	size_t GetArraySize()
	{
		return m_nSize;
	}

	char* GetPtr() const
	{
		return m_ptr;
	}

	size_t GetTotalSize() const // length in terms of bytes
	{
		return m_nElemSize * m_nSize;
	}

	size_t GetElementSize() const
	{
		return m_nElemSize;
	}

	size_t GetArraySize() const
	{
		return m_nSize;
	}

	char& operator[](size_t i)
	{
		if(i<m_nSize&&m_ptr!=NULL)
			return m_ptr[i];

		if(i>=m_nSize)
			throw std::out_of_range("Index out of bounds!");

		if(m_ptr==NULL)
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
	BaseArray(const BaseArray&) {}
	// assignment
	BaseArray& operator=(const BaseArray&) { return *this; }

	char* m_ptr;
	size_t m_nElemSize; // element size
	size_t m_nSize; // number of elements
	bool m_bDelete;
	bool isDeferredMake;
	size_t* pDeferredCnt;


};

}
