#pragma once
#include <cstdio>

class Platform
{
public:
	Platform(void);
	~Platform(void);

	static bool IsLittleEndian()
	{
		int a = 0x12345678;
		unsigned char *c = (unsigned char*)(&a);
		if (*c == 0x78)
			return true;

		return false;
	}
	static bool IsBigEndian()
	{
		int a = 0x12345678;
		unsigned char *c = (unsigned char*)(&a);
		if (*c == 0x12)
			return true;

		return false;
	}

	static bool Is32bit()
	{
		return sizeof(size_t) == 4;
	}
	static bool Is64bit()
	{
		return sizeof(size_t) == 8;
	}

	inline static wchar_t SwapOrder(wchar_t wch);
	static void SwapOrder(wchar_t* arr, size_t size);

	inline static unsigned int SwapOrder(unsigned int wch);
	static void SwapOrder(unsigned int* arr, size_t size);

	inline static unsigned short SwapOrder(unsigned short wch);
	static void SwapOrder(unsigned short* arr, size_t size);
};
