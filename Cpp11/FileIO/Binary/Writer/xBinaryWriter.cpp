#include "xBinaryWriter.h"
#include "../../Text/Utils/StrUtil.h"

using namespace Elmax;

xBinaryWriter::xBinaryWriter(void)
	: fp(nullptr)
	, err(L"")
	, errNum(0)
	, enableException(true)
{
}

xBinaryWriter::xBinaryWriter(const std::wstring& file)
{
	Open(file);
}

xBinaryWriter::xBinaryWriter(const std::string& file)
{
	Open(file);
}

xBinaryWriter::~xBinaryWriter(void)
{
	Close();
}

bool xBinaryWriter::Open(const std::wstring& file)
{
	Close();

	fp = FileOpen(file, L"wb");

	if(fp == nullptr)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(file)+ ": file cannot be opened!");
	}

	return fp != nullptr;
}

bool xBinaryWriter::Open(const std::string& file)
{
	Close();

	fp = FileOpen(file, "wb");

	if(fp == nullptr)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
		if(enableException)
			throw std::runtime_error(file + ": file cannot be opened!");
	}

	return fp != nullptr;
}


void xBinaryWriter::Close()
{
	if(fp!=nullptr)
	{
		fflush(fp);
		fclose(fp);
		fp = nullptr;
	}
}

int xBinaryWriter::Seek(long offset, int origin)
{
	if(fp!=nullptr)
		return fseek(fp, offset, origin);

	return -1;
}

long xBinaryWriter::GetCurrPos()
{
	if(fp!=nullptr)
		return ftell(fp);

	return -1;
}

bool xBinaryWriter::IsEOF()
{
	if(fp!=nullptr)
	{
		return feof(fp) != 0; // not eof yet
	}

	return true;
}

int xBinaryWriter::GetLastError(std::wstring& msg)
{
	msg = err;
	return errNum;
}


void xBinaryWriter::ClearLastError()
{
	err = L"";
	errNum = 0;
}

bool xBinaryWriter::EnableException(bool enable)
{
	bool prev = enableException;

	enableException = enable;

	return prev;
}
