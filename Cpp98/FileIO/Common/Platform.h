#pragma once

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
};
