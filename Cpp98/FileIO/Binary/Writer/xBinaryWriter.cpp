#include "xBinaryWriter.h"
#include "../../Text/Utils/StrUtil.h"

using namespace Elmax;

xBinaryWriter::xBinaryWriter(void)
	: fp(NULL)
	, err(L"")
	, errNum(0)
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

	if(fp == NULL)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
	}

	return fp != NULL;
}

bool xBinaryWriter::Open(const std::string& file)
{
	Close();

	fp = FileOpen(file, "wb");

	if(fp == NULL)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
	}

	return fp != NULL;
}


void xBinaryWriter::Close()
{
	if(fp!=NULL)
	{
		fflush(fp);
		fclose(fp);
		fp = NULL;
	}
}

int xBinaryWriter::Seek(long offset, int origin)
{
	if(fp!=NULL)
		return fseek(fp, offset, origin);

	return -1;
}

long xBinaryWriter::GetCurrPos()
{
	if(fp!=NULL)
		return ftell(fp);

	return -1;
}

size_t xBinaryWriter::Write( BinaryTypeRef D1 )
{
	size_t totalWritten = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeRef::DTR_STR && D1.m_type != BinaryTypeRef::DTR_WSTR && D1.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D1.GetAddress(), D1.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(len==D1.arraySize)
				++totalWritten;
		}

	}

	if(totalWritten != 1)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = StrUtil::Format(L"{0}: Less than 1 elements are written! ({1} elements written)", GetErrorMsg(errNum), totalWritten);
		throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalWritten;
}

size_t xBinaryWriter::Write( BinaryTypeRef D1, BinaryTypeRef D2 )
{
	size_t totalWritten = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeRef::DTR_STR && D1.m_type != BinaryTypeRef::DTR_WSTR && D1.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D1.GetAddress(), D1.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(len==D1.arraySize)
				++totalWritten;
		}

		if(D2.m_type != BinaryTypeRef::DTR_STR && D2.m_type != BinaryTypeRef::DTR_WSTR && D2.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D2.GetAddress(), D2.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(len==D2.arraySize)
				++totalWritten;
		}

	}

	if(totalWritten != 2)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = StrUtil::Format(L"{0}: Less than 2 elements are written! ({1} elements written)", GetErrorMsg(errNum), totalWritten);
		throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalWritten;
}


size_t xBinaryWriter::Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3 )
{
	size_t totalWritten = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeRef::DTR_STR && D1.m_type != BinaryTypeRef::DTR_WSTR && D1.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D1.GetAddress(), D1.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(len==D1.arraySize)
				++totalWritten;
		}

		if(D2.m_type != BinaryTypeRef::DTR_STR && D2.m_type != BinaryTypeRef::DTR_WSTR && D2.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D2.GetAddress(), D2.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(len==D2.arraySize)
				++totalWritten;
		}

		if(D3.m_type != BinaryTypeRef::DTR_STR && D3.m_type != BinaryTypeRef::DTR_WSTR && D3.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D3.GetAddress(), D3.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(len==D3.arraySize)
				++totalWritten;
		}

	}

	if(totalWritten != 3)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = StrUtil::Format(L"{0}: Less than 3 elements are written! ({1} elements written)", GetErrorMsg(errNum), totalWritten);
		throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalWritten;
}

size_t xBinaryWriter::Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4 )
{
	size_t totalWritten = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeRef::DTR_STR && D1.m_type != BinaryTypeRef::DTR_WSTR && D1.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D1.GetAddress(), D1.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(len==D1.arraySize)
				++totalWritten;
		}

		if(D2.m_type != BinaryTypeRef::DTR_STR && D2.m_type != BinaryTypeRef::DTR_WSTR && D2.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D2.GetAddress(), D2.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(len==D2.arraySize)
				++totalWritten;
		}

		if(D3.m_type != BinaryTypeRef::DTR_STR && D3.m_type != BinaryTypeRef::DTR_WSTR && D3.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D3.GetAddress(), D3.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(len==D3.arraySize)
				++totalWritten;
		}

		if(D4.m_type != BinaryTypeRef::DTR_STR && D4.m_type != BinaryTypeRef::DTR_WSTR && D4.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D4.GetAddress(), D4.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(len==D4.arraySize)
				++totalWritten;
		}

	}

	if(totalWritten != 4)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = StrUtil::Format(L"{0}: Less than 4 elements are written! ({1} elements written)", GetErrorMsg(errNum), totalWritten);
		throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalWritten;
}

size_t xBinaryWriter::Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5 )
{
	size_t totalWritten = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeRef::DTR_STR && D1.m_type != BinaryTypeRef::DTR_WSTR && D1.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D1.GetAddress(), D1.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(len==D1.arraySize)
				++totalWritten;
		}

		if(D2.m_type != BinaryTypeRef::DTR_STR && D2.m_type != BinaryTypeRef::DTR_WSTR && D2.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D2.GetAddress(), D2.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(len==D2.arraySize)
				++totalWritten;
		}

		if(D3.m_type != BinaryTypeRef::DTR_STR && D3.m_type != BinaryTypeRef::DTR_WSTR && D3.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D3.GetAddress(), D3.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(len==D3.arraySize)
				++totalWritten;
		}

		if(D4.m_type != BinaryTypeRef::DTR_STR && D4.m_type != BinaryTypeRef::DTR_WSTR && D4.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D4.GetAddress(), D4.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(len==D4.arraySize)
				++totalWritten;
		}

		if(D5.m_type != BinaryTypeRef::DTR_STR && D5.m_type != BinaryTypeRef::DTR_WSTR && D5.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D5.GetAddress(), D5.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(len==D5.arraySize)
				++totalWritten;
		}

	}

	if(totalWritten != 5)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = StrUtil::Format(L"{0}: Less than 5 elements are written! ({1} elements written)", GetErrorMsg(errNum), totalWritten);
		throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalWritten;
}


size_t xBinaryWriter::Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5, 
	BinaryTypeRef D6 )
{
	size_t totalWritten = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeRef::DTR_STR && D1.m_type != BinaryTypeRef::DTR_WSTR && D1.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D1.GetAddress(), D1.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(len==D1.arraySize)
				++totalWritten;
		}

		if(D2.m_type != BinaryTypeRef::DTR_STR && D2.m_type != BinaryTypeRef::DTR_WSTR && D2.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D2.GetAddress(), D2.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(len==D2.arraySize)
				++totalWritten;
		}

		if(D3.m_type != BinaryTypeRef::DTR_STR && D3.m_type != BinaryTypeRef::DTR_WSTR && D3.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D3.GetAddress(), D3.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(len==D3.arraySize)
				++totalWritten;
		}

		if(D4.m_type != BinaryTypeRef::DTR_STR && D4.m_type != BinaryTypeRef::DTR_WSTR && D4.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D4.GetAddress(), D4.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(len==D4.arraySize)
				++totalWritten;
		}

		if(D5.m_type != BinaryTypeRef::DTR_STR && D5.m_type != BinaryTypeRef::DTR_WSTR && D5.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D5.GetAddress(), D5.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(len==D5.arraySize)
				++totalWritten;
		}

		if(D6.m_type != BinaryTypeRef::DTR_STR && D6.m_type != BinaryTypeRef::DTR_WSTR && D6.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D6.GetAddress(), D6.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D6.GetAddress(), D6.elementSize, D6.arraySize, fp);
			if(len==D6.arraySize)
				++totalWritten;
		}

	}

	if(totalWritten != 6)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = StrUtil::Format(L"{0}: Less than 6 elements are written! ({1} elements written)", GetErrorMsg(errNum), totalWritten);
		throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalWritten;
}

size_t xBinaryWriter::Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5, 
	BinaryTypeRef D6, BinaryTypeRef D7 )
{
	size_t totalWritten = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeRef::DTR_STR && D1.m_type != BinaryTypeRef::DTR_WSTR && D1.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D1.GetAddress(), D1.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(len==D1.arraySize)
				++totalWritten;
		}

		if(D2.m_type != BinaryTypeRef::DTR_STR && D2.m_type != BinaryTypeRef::DTR_WSTR && D2.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D2.GetAddress(), D2.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(len==D2.arraySize)
				++totalWritten;
		}

		if(D3.m_type != BinaryTypeRef::DTR_STR && D3.m_type != BinaryTypeRef::DTR_WSTR && D3.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D3.GetAddress(), D3.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(len==D3.arraySize)
				++totalWritten;
		}

		if(D4.m_type != BinaryTypeRef::DTR_STR && D4.m_type != BinaryTypeRef::DTR_WSTR && D4.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D4.GetAddress(), D4.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(len==D4.arraySize)
				++totalWritten;
		}

		if(D5.m_type != BinaryTypeRef::DTR_STR && D5.m_type != BinaryTypeRef::DTR_WSTR && D5.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D5.GetAddress(), D5.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(len==D5.arraySize)
				++totalWritten;
		}

		if(D6.m_type != BinaryTypeRef::DTR_STR && D6.m_type != BinaryTypeRef::DTR_WSTR && D6.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D6.GetAddress(), D6.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D6.GetAddress(), D6.elementSize, D6.arraySize, fp);
			if(len==D6.arraySize)
				++totalWritten;
		}

		if(D7.m_type != BinaryTypeRef::DTR_STR && D7.m_type != BinaryTypeRef::DTR_WSTR && D7.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D7.GetAddress(), D7.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D7.GetAddress(), D7.elementSize, D7.arraySize, fp);
			if(len==D7.arraySize)
				++totalWritten;
		}

	}

	if(totalWritten != 7)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = StrUtil::Format(L"{0}: Less than 7 elements are written! ({1} elements written)", GetErrorMsg(errNum), totalWritten);
		throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalWritten;
}


size_t xBinaryWriter::Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5, 
	BinaryTypeRef D6, BinaryTypeRef D7, BinaryTypeRef D8 )
{
	size_t totalWritten = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeRef::DTR_STR && D1.m_type != BinaryTypeRef::DTR_WSTR && D1.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D1.GetAddress(), D1.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(len==D1.arraySize)
				++totalWritten;
		}

		if(D2.m_type != BinaryTypeRef::DTR_STR && D2.m_type != BinaryTypeRef::DTR_WSTR && D2.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D2.GetAddress(), D2.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(len==D2.arraySize)
				++totalWritten;
		}

		if(D3.m_type != BinaryTypeRef::DTR_STR && D3.m_type != BinaryTypeRef::DTR_WSTR && D3.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D3.GetAddress(), D3.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(len==D3.arraySize)
				++totalWritten;
		}

		if(D4.m_type != BinaryTypeRef::DTR_STR && D4.m_type != BinaryTypeRef::DTR_WSTR && D4.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D4.GetAddress(), D4.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(len==D4.arraySize)
				++totalWritten;
		}

		if(D5.m_type != BinaryTypeRef::DTR_STR && D5.m_type != BinaryTypeRef::DTR_WSTR && D5.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D5.GetAddress(), D5.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(len==D5.arraySize)
				++totalWritten;
		}

		if(D6.m_type != BinaryTypeRef::DTR_STR && D6.m_type != BinaryTypeRef::DTR_WSTR && D6.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D6.GetAddress(), D6.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D6.GetAddress(), D6.elementSize, D6.arraySize, fp);
			if(len==D6.arraySize)
				++totalWritten;
		}

		if(D7.m_type != BinaryTypeRef::DTR_STR && D7.m_type != BinaryTypeRef::DTR_WSTR && D7.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D7.GetAddress(), D7.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D7.GetAddress(), D7.elementSize, D7.arraySize, fp);
			if(len==D7.arraySize)
				++totalWritten;
		}

		if(D8.m_type != BinaryTypeRef::DTR_STR && D8.m_type != BinaryTypeRef::DTR_WSTR && D8.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D8.GetAddress(), D8.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D8.GetAddress(), D8.elementSize, D8.arraySize, fp);
			if(len==D8.arraySize)
				++totalWritten;
		}

	}

	if(totalWritten != 8)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = StrUtil::Format(L"{0}: Less than 8 elements are written! ({1} elements written)", GetErrorMsg(errNum), totalWritten);
		throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalWritten;
}


size_t xBinaryWriter::Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5, 
	BinaryTypeRef D6, BinaryTypeRef D7, BinaryTypeRef D8, BinaryTypeRef D9 )
{
	size_t totalWritten = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeRef::DTR_STR && D1.m_type != BinaryTypeRef::DTR_WSTR && D1.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D1.GetAddress(), D1.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(len==D1.arraySize)
				++totalWritten;
		}

		if(D2.m_type != BinaryTypeRef::DTR_STR && D2.m_type != BinaryTypeRef::DTR_WSTR && D2.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D2.GetAddress(), D2.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(len==D2.arraySize)
				++totalWritten;
		}

		if(D3.m_type != BinaryTypeRef::DTR_STR && D3.m_type != BinaryTypeRef::DTR_WSTR && D3.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D3.GetAddress(), D3.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(len==D3.arraySize)
				++totalWritten;
		}

		if(D4.m_type != BinaryTypeRef::DTR_STR && D4.m_type != BinaryTypeRef::DTR_WSTR && D4.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D4.GetAddress(), D4.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(len==D4.arraySize)
				++totalWritten;
		}

		if(D5.m_type != BinaryTypeRef::DTR_STR && D5.m_type != BinaryTypeRef::DTR_WSTR && D5.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D5.GetAddress(), D5.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(len==D5.arraySize)
				++totalWritten;
		}

		if(D6.m_type != BinaryTypeRef::DTR_STR && D6.m_type != BinaryTypeRef::DTR_WSTR && D6.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D6.GetAddress(), D6.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D6.GetAddress(), D6.elementSize, D6.arraySize, fp);
			if(len==D6.arraySize)
				++totalWritten;
		}

		if(D7.m_type != BinaryTypeRef::DTR_STR && D7.m_type != BinaryTypeRef::DTR_WSTR && D7.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D7.GetAddress(), D7.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D7.GetAddress(), D7.elementSize, D7.arraySize, fp);
			if(len==D7.arraySize)
				++totalWritten;
		}

		if(D8.m_type != BinaryTypeRef::DTR_STR && D8.m_type != BinaryTypeRef::DTR_WSTR && D8.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D8.GetAddress(), D8.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D8.GetAddress(), D8.elementSize, D8.arraySize, fp);
			if(len==D8.arraySize)
				++totalWritten;
		}

		if(D9.m_type != BinaryTypeRef::DTR_STR && D9.m_type != BinaryTypeRef::DTR_WSTR && D9.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D9.GetAddress(), D9.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D9.GetAddress(), D9.elementSize, D9.arraySize, fp);
			if(len==D9.arraySize)
				++totalWritten;
		}

	}

	if(totalWritten != 9)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = StrUtil::Format(L"{0}: Less than 9 elements are written! ({1} elements written)", GetErrorMsg(errNum), totalWritten);
		throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalWritten;
}


size_t xBinaryWriter::Write( BinaryTypeRef D1, BinaryTypeRef D2, BinaryTypeRef D3, BinaryTypeRef D4, BinaryTypeRef D5, 
	BinaryTypeRef D6, BinaryTypeRef D7, BinaryTypeRef D8, BinaryTypeRef D9, BinaryTypeRef D10 )
{
	size_t totalWritten = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeRef::DTR_STR && D1.m_type != BinaryTypeRef::DTR_WSTR && D1.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D1.GetAddress(), D1.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(len==D1.arraySize)
				++totalWritten;
		}

		if(D2.m_type != BinaryTypeRef::DTR_STR && D2.m_type != BinaryTypeRef::DTR_WSTR && D2.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D2.GetAddress(), D2.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(len==D2.arraySize)
				++totalWritten;
		}

		if(D3.m_type != BinaryTypeRef::DTR_STR && D3.m_type != BinaryTypeRef::DTR_WSTR && D3.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D3.GetAddress(), D3.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(len==D3.arraySize)
				++totalWritten;
		}

		if(D4.m_type != BinaryTypeRef::DTR_STR && D4.m_type != BinaryTypeRef::DTR_WSTR && D4.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D4.GetAddress(), D4.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(len==D4.arraySize)
				++totalWritten;
		}

		if(D5.m_type != BinaryTypeRef::DTR_STR && D5.m_type != BinaryTypeRef::DTR_WSTR && D5.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D5.GetAddress(), D5.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(len==D5.arraySize)
				++totalWritten;
		}

		if(D6.m_type != BinaryTypeRef::DTR_STR && D6.m_type != BinaryTypeRef::DTR_WSTR && D6.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D6.GetAddress(), D6.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D6.GetAddress(), D6.elementSize, D6.arraySize, fp);
			if(len==D6.arraySize)
				++totalWritten;
		}

		if(D7.m_type != BinaryTypeRef::DTR_STR && D7.m_type != BinaryTypeRef::DTR_WSTR && D7.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D7.GetAddress(), D7.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D7.GetAddress(), D7.elementSize, D7.arraySize, fp);
			if(len==D7.arraySize)
				++totalWritten;
		}

		if(D8.m_type != BinaryTypeRef::DTR_STR && D8.m_type != BinaryTypeRef::DTR_WSTR && D8.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D8.GetAddress(), D8.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D8.GetAddress(), D8.elementSize, D8.arraySize, fp);
			if(len==D8.arraySize)
				++totalWritten;
		}

		if(D9.m_type != BinaryTypeRef::DTR_STR && D9.m_type != BinaryTypeRef::DTR_WSTR && D9.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D9.GetAddress(), D9.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D9.GetAddress(), D9.elementSize, D9.arraySize, fp);
			if(len==D9.arraySize)
				++totalWritten;
		}

		if(D10.m_type != BinaryTypeRef::DTR_STR && D10.m_type != BinaryTypeRef::DTR_WSTR && D10.m_type != BinaryTypeRef::DTR_BASEARRAY)
		{
			size_t len = fwrite(D10.GetAddress(), D10.size, 1, fp);
			if(len==1)
				++totalWritten;
		}
		else
		{
			size_t len = fwrite(D10.GetAddress(), D10.elementSize, D10.arraySize, fp);
			if(len==D10.arraySize)
				++totalWritten;
		}
	}

	if(totalWritten != 10)
	{
		errNum = ELMAX_WRITE_ERROR;
		err = StrUtil::Format(L"{0}: Less than 10 elements are written! ({1} elements written)", GetErrorMsg(errNum), totalWritten);
		throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalWritten;
}

bool xBinaryWriter::IsEOF()
{
	if(fp!=NULL)
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

