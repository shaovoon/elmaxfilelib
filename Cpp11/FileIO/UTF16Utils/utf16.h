#pragma once

#include <string>

// This class is for Linux use because their wchar_t is 4 bytes

namespace Elmax
{

class utf16
{
public:
	static bool ContainsSurrogate(unsigned short* src, size_t arrLen, size_t& charLen);
	static bool ContainsSurrogate(unsigned short src1, unsigned short src2);
	static bool Is1stSurrogate(unsigned short src1);
	static bool Is2ndSurrogate(unsigned short src2);

	static bool ContainsUpperPlane(const std::wstring& src, size_t& arrLen);
	static unsigned short* ConvertToUTF16(const std::wstring& src, size_t destArrLen);
	static std::wstring ConvertToUTF16W(const std::wstring& src);
	static std::wstring ConvertToWString(unsigned short* src, size_t srcArrLen);
	static wchar_t ConvertToWChar(unsigned short src1, unsigned short src2);
};

}
