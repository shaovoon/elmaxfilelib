#include "Common.h"

std::map<int, std::wstring> errDict;
bool init = false;

void InitErrMap()
{
	errDict[ELMAX_UNKNOWN_ERROR] = L"Unknown Error!";
	errDict[ELMAX_NULL_POINTER] = L"Null Pointer!";
	errDict[ELMAX_FILE_NOT_OPENED] = L"File Not Opened!";
	errDict[ELMAX_WRITE_ERROR] = L"Write Failure!";
	errDict[ELMAX_READ_ERROR] = L"Read Failure!";
}

std::wstring GetErrorMsg(int errNum)
{
	if(init==false)
	{
		InitErrMap();
		init = true;
	}
	return errDict[errNum];
}