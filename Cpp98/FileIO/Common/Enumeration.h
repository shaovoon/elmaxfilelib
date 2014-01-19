#pragma once

#include <map>
#include <string>

enum FILE_TYPE
{
	FT_ASCII,
	FT_UTF8,
	FT_UNICODE,
	FT_BEUNICODE,
	FT_UTF32,
	FT_UTF32BE,
};

enum FILE_OP
{
	NEW,
	APPEND
};

union UnionText
{
	wchar_t ch;
	char arr[2];
};

#define ELMAX_UNKNOWN_ERROR -1
#define ELMAX_NULL_POINTER 1
#define ELMAX_FILE_NOT_OPENED 2
#define ELMAX_WRITE_ERROR 3
#define ELMAX_READ_ERROR 4


