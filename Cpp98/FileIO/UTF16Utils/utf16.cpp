#include "utf16.h"
#include "../Common/RAII_Array.h"

using namespace Elmax;

bool utf16::ContainsSurrogate(unsigned short* src, size_t arrLen, size_t& charLen)
{
	bool found = false;
	charLen = arrLen;
	for(size_t i=0; i<arrLen; ++i)
	{
		if(src[i] >= 0xd800 && src[i] < 0xdc00)
		{
			if(i+1 < arrLen)
			{
				if (src[i+1] >= 0xdc00 && src[i+1] < 0xe000)
				{
					found = true;
					++i;
					--charLen;
				}
			}
		}
	}

	return found;
}

bool utf16::ContainsSurrogate(unsigned short src1, unsigned short src2)
{
	bool found = false;
	if((src1 >= 0xd800 && src1 < 0xdc00) && (src2 >= 0xdc00 && src2 < 0xe000))
	{
		found = true;
	}

	return found;
}

bool utf16::Is1stSurrogate(unsigned short src1)
{
	bool found = false;
	if(src1 >= 0xd800 && src1 < 0xdc00)
	{
		found = true;
	}

	return found;
}

bool utf16::Is2ndSurrogate(unsigned short src2)
{
	bool found = false;
	if(src2 >= 0xdc00 && src2 < 0xe000)
	{
		found = true;
	}

	return found;
}

bool utf16::ContainsUpperPlane(const std::wstring& src, size_t& arrLen)
{
	bool found = false;
	arrLen = 0;
	for(size_t i=0; i< src.size(); ++i)
	{
		if(src[i] > 0xFFFF)
		{
			found = true;
			arrLen += 2;
		}
		else
			++arrLen;
	}

	return found;
}

unsigned short* utf16::ConvertToUTF16(const std::wstring& src, size_t destArrLen)
{
	if(destArrLen<src.size())
		return NULL;

	RAII_Array<unsigned short> arr(destArrLen);
	for(size_t i=0, destCnt=0; i< src.size(); ++i, ++destCnt)
	{
		if(src[i] > 0xFFFF)
		{
			int ch = src[i] - 0x10000;
			arr.GetPtr()[destCnt] = 0xD800 + ((ch >> 10) & 0x3FF);
			if((destCnt+1)<destArrLen)
			{
				arr.GetPtr()[destCnt+1] = 0xDC00 + (ch & 0x3FF);
				++destCnt;
			}
		}
		else
		{
			arr.GetPtr()[destCnt] = (unsigned short)(src[i]);
		}
	}

	return arr.Detach();
}

std::wstring utf16::ConvertToUTF16W(const std::wstring& src)
{
	std::wstring str = L"";
	for(size_t i=0; i< src.size(); ++i)
	{
		if(src[i] > 0xFFFF)
		{
			int ch = src[i] - 0x10000;
			str += (wchar_t)(0xD800 + ((ch >> 10) & 0x3FF));
			str +=  (wchar_t)(0xDC00 + (ch & 0x3FF));
		}
		else
		{
			str += (wchar_t)(src[i]);
		}
	}

	return str;
}

// This method is for Linux.
std::wstring utf16::ConvertToWString(unsigned short* src, size_t srcArrLen)
{
	std::wstring dest = L"";
	for(size_t i=0; i<srcArrLen; ++i)
	{
		if(src[i] >= 0xd800 && src[i] < 0xdc00)
		{
			if(i+1 < srcArrLen)
			{
				if (src[i+1] >= 0xdc00 && src[i+1] < 0xe000)
				{
					dest += (wchar_t)( ((src[i] & 0x3ff) << 10) + (src[i+1] & 0x3ff) + 0x10000 );

					++i;
				}
				else
					dest += src[i];
			}
			else
				dest += src[i];
		}
		else
			dest += src[i];

	}

	return dest;
}

wchar_t utf16::ConvertToWChar(unsigned short src1, unsigned short src2)
{
	wchar_t dest = L' ';
	if((src1 >= 0xd800 && src1 < 0xdc00) && (src2 >= 0xdc00 && src2 < 0xe000))
	{
		dest = (wchar_t)( ((src1 & 0x3ff) << 10) + (src2 & 0x3ff) + 0x10000 );
	}
	else
		dest = src1;

	return dest;
}
