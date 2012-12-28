#include "LinuxOperation.h"
#include <cstdio>
#include "../Text/Utils/StrUtil.h"

FILE* FileOpen(const std::wstring& file, const wchar_t* options)
{
	return fopen(Elmax::StrUtil::ConvToString(file).c_str(), Elmax::StrUtil::ConvToString(options).c_str());
}

FILE* FileOpen(const std::string& file, const char* options)
{
	return fopen(file.c_str(), options);
}

wchar_t* Wcscpy(wchar_t* dest, const wchar_t* src, size_t len)
{
	return wcscpy(dest, src);
}

