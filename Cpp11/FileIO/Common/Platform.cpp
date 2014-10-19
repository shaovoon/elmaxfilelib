#include "Platform.h"

#ifdef _MICROSOFT
union wchar_union
{
	wchar_t wch;
	char arr[2];
};
#else
union wchar_union
{
	wchar_t wch;
	char arr[4];
};
#endif

union uint_union
{
	unsigned int n;
	char arr[4];
};

union ushort_union
{
	unsigned short n;
	char arr[2];
};

Platform::Platform(void)
{
}

Platform::~Platform(void)
{
}

wchar_t Platform::SwapOrder(wchar_t wch)
{
	wchar_union src;
	wchar_union dest;
	src.wch = wch;
#ifdef _MICROSOFT
	dest.arr[0] = src.arr[1];
	dest.arr[1] = src.arr[0];
#else
	dest.arr[0] = src.arr[3];
	dest.arr[1] = src.arr[2];
	dest.arr[2] = src.arr[1];
	dest.arr[3] = src.arr[0];
#endif
	return dest.wch;
}

void Platform::SwapOrder(wchar_t* arr, size_t size)
{
	for(size_t i=0; i<size; ++i)
	{
		arr[i] = SwapOrder(arr[i]);
	}
}

unsigned int Platform::SwapOrder(unsigned int n)
{
	uint_union src;
	uint_union dest;
	src.n = n;

	dest.arr[0] = src.arr[3];
	dest.arr[1] = src.arr[2];
	dest.arr[2] = src.arr[1];
	dest.arr[3] = src.arr[0];

	return dest.n;
}

void Platform::SwapOrder(unsigned int* arr, size_t size)
{
	for(size_t i=0; i<size; ++i)
	{
		arr[i] = SwapOrder(arr[i]);
	}
}

unsigned short Platform::SwapOrder(unsigned short n)
{
	ushort_union src;
	ushort_union dest;
	src.n = n;

	dest.arr[0] = src.arr[1];
	dest.arr[1] = src.arr[0];

	return dest.n;
}

void Platform::SwapOrder(unsigned short* arr, size_t size)
{
	for(size_t i=0; i<size; ++i)
	{
		arr[i] = SwapOrder(arr[i]);
	}
}
