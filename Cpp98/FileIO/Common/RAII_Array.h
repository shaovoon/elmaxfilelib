#pragma once

#include <cstring>

template<typename T>
class RAII_Array
{
public:
	RAII_Array(size_t elemSize)
	{
		ptr = new T[elemSize];
		memset(ptr, 0, sizeof(T)*elemSize);
	}
	RAII_Array(T* pArr)
	{
		ptr = pArr;
	}
	~RAII_Array()
	{
		if(ptr!=NULL)
			delete [] ptr;
			
		ptr = NULL;
	}
	
	T* Detach()
	{
		T* tmp = ptr;
		ptr = NULL;
		return tmp;
	}

	T* GetPtr()
	{
		return ptr;
	}

private:
	T* ptr;
};