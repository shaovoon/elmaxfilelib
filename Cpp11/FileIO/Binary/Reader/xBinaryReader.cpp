#include "xBinaryReader.h"
#include "../../Text/Utils/StrUtil.h"

using namespace Elmax;

xBinaryReader::xBinaryReader(void)
	: fp(nullptr)
	, err(L"")
	, errNum(0)
	, enableException(true)
{
}


xBinaryReader::xBinaryReader(const std::wstring& file)
{
	Open(file);
}

xBinaryReader::xBinaryReader(const std::string& file)
{
	Open(file);
}

xBinaryReader::~xBinaryReader(void)
{
	Close();
}

bool xBinaryReader::Open(const std::wstring& file)
{
	Close();

	fp = FileOpen(file, L"rb");

	if(fp == nullptr)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(file)+ ": file cannot be opened!");
	}

	return fp != nullptr;
}

bool xBinaryReader::Open(const std::string& file)
{
	Close();

	fp = FileOpen(file, "rb");

	if(fp == nullptr)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
		if(enableException)
			throw std::runtime_error(file+ ": file cannot be opened!");
	}

	return fp != nullptr;
}


void xBinaryReader::Close()
{
	if(fp!=nullptr)
	{
		fflush(fp);
		fclose(fp);
		fp = nullptr;
	}
}

int xBinaryReader::Seek(long offset, int origin)
{
	if(fp!=nullptr)
		return fseek(fp, offset, origin);

	return -1;
}

long xBinaryReader::GetCurrPos()
{
	if(fp!=nullptr)
	 return ftell(fp);

	return -1;
}

bool xBinaryReader::IsEOF()
{
	if(fp!=nullptr)
	{
		return feof(fp) != 0; // not eof yet
	}

	return true;
}

int xBinaryReader::GetLastError(std::wstring& msg)
{
	msg = err;
	return errNum;
}


void xBinaryReader::ClearLastError()
{
	err = L"";
	errNum = 0;
}

bool xBinaryReader::EnableException(bool enable)
{
	bool prev = enableException;

	enableException = enable;

	return prev;
}
