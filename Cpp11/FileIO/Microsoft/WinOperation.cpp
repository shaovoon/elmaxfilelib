#include "WinOperation.h"
#include <cstdio>

#ifdef _MICROSOFT
FILE* FileOpen(const std::wstring& file, const wchar_t* options)
{
	FILE* fp = nullptr;
	errno_t err = _wfopen_s(&fp, file.c_str(), options);

	if(err==0&&fp!=nullptr) // success
		return fp;

	return nullptr;
}

FILE* FileOpen(const std::string& file, const char* options)
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, file.c_str(), options);

	if(err==0&&fp!=nullptr) // success
		return fp;

	return nullptr;
}

wchar_t* Wcscpy(wchar_t* dest, const wchar_t* src, size_t len)
{
	wcscpy_s(dest, len, src);
	return dest;
}
#else
FILE* FileOpen(const std::wstring& file, const wchar_t* options)
{
	return _wfopen(file.c_str(), options);
}

FILE* FileOpen(const std::string& file, const char* options)
{
	return fopen(file.c_str(), options);
}

wchar_t* Wcscpy(wchar_t* dest, const wchar_t* src, size_t len)
{
	return wcscpy(dest, src);
}

#endif
