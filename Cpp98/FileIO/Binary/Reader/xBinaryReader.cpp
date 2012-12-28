#include "xBinaryReader.h"
#include "../../Text/Utils/StrUtil.h"

using namespace Elmax;

xBinaryReader::xBinaryReader(void)
	: fp(NULL)
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

	if(fp == NULL)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(file)+ ": file cannot be opened!");
	}

	return fp != NULL;
}

bool xBinaryReader::Open(const std::string& file)
{
	Close();

	fp = FileOpen(file, "rb");

	if(fp == NULL)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
		if(enableException)
			throw std::runtime_error(file+ ": file cannot be opened!");
	}

	return fp != NULL;
}


void xBinaryReader::Close()
{
	if(fp!=NULL)
	{
		fflush(fp);
		fclose(fp);
		fp = NULL;
	}
}

int xBinaryReader::Seek(long offset, int origin)
{
	if(fp!=NULL)
		return fseek(fp, offset, origin);

	return -1;
}

long xBinaryReader::GetCurrPos()
{
	if(fp!=NULL)
	 return ftell(fp);

	return -1;
}

size_t xBinaryReader::Read( BinaryTypeReadRef D1 )
{
	size_t totalRead = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeReadRef::DTR_STRARRAY && D1.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D1.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D1.GetAddress(), D1.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D1.DeferredMake();
			size_t cnt = fread(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(cnt == D1.arraySize)
				++totalRead;
		}

	}

	if(totalRead != 1)
	{
		errNum = ELMAX_READ_ERROR;
		err = StrUtil::Format(L"{0}: Less than 1 elements are read! ({1} elements read)", GetErrorMsg(errNum), totalRead);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalRead;
}

size_t xBinaryReader::Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2 )
{
	size_t totalRead = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeReadRef::DTR_STRARRAY && D1.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D1.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D1.GetAddress(), D1.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D1.DeferredMake();
			size_t cnt = fread(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(cnt == D1.arraySize)
				++totalRead;
		}

		if(D2.m_type != BinaryTypeReadRef::DTR_STRARRAY && D2.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D2.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D2.GetAddress(), D2.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D2.DeferredMake();
			size_t cnt = fread(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(cnt==D2.arraySize)
				++totalRead;
		}

	}

	if(totalRead != 2)
	{
		errNum = ELMAX_READ_ERROR;
		err = StrUtil::Format(L"{0}: Less than 2 elements are read! ({1} elements read)", GetErrorMsg(errNum), totalRead);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalRead;
}


size_t xBinaryReader::Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3 )
{
	size_t totalRead = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeReadRef::DTR_STRARRAY && D1.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D1.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D1.GetAddress(), D1.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D1.DeferredMake();
			size_t cnt = fread(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(cnt == D1.arraySize)
				++totalRead;
		}

		if(D2.m_type != BinaryTypeReadRef::DTR_STRARRAY && D2.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D2.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D2.GetAddress(), D2.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D2.DeferredMake();
			size_t cnt = fread(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(cnt==D2.arraySize)
				++totalRead;
		}

		if(D3.m_type != BinaryTypeReadRef::DTR_STRARRAY && D3.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D3.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D3.GetAddress(), D3.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D3.DeferredMake();
			size_t cnt = fread(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(cnt==D3.arraySize)
				++totalRead;
		}

	}

	if(totalRead != 3)
	{
		errNum = ELMAX_READ_ERROR;
		err = StrUtil::Format(L"{0}: Less than 3 elements are read! ({1} elements read)", GetErrorMsg(errNum), totalRead);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalRead;
}

size_t xBinaryReader::Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4 )
{
	size_t totalRead = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeReadRef::DTR_STRARRAY && D1.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D1.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D1.GetAddress(), D1.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D1.DeferredMake();
			size_t cnt = fread(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(cnt == D1.arraySize)
				++totalRead;
		}

		if(D2.m_type != BinaryTypeReadRef::DTR_STRARRAY && D2.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D2.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D2.GetAddress(), D2.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D2.DeferredMake();
			size_t cnt = fread(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(cnt==D2.arraySize)
				++totalRead;
		}

		if(D3.m_type != BinaryTypeReadRef::DTR_STRARRAY && D3.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D3.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D3.GetAddress(), D3.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D3.DeferredMake();
			size_t cnt = fread(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(cnt==D3.arraySize)
				++totalRead;
		}

		if(D4.m_type != BinaryTypeReadRef::DTR_STRARRAY && D4.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D4.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D4.GetAddress(), D4.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D4.DeferredMake();
			size_t cnt = fread(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(cnt==D4.arraySize)
				++totalRead;
		}

	}

	if(totalRead != 4)
	{
		errNum = ELMAX_READ_ERROR;
		err = StrUtil::Format(L"{0}: Less than 4 elements are read! ({1} elements read)", GetErrorMsg(errNum), totalRead);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalRead;
}

size_t xBinaryReader::Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5 )
{
	size_t totalRead = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeReadRef::DTR_STRARRAY && D1.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D1.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D1.GetAddress(), D1.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D1.DeferredMake();
			size_t cnt = fread(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(cnt == D1.arraySize)
				++totalRead;
		}

		if(D2.m_type != BinaryTypeReadRef::DTR_STRARRAY && D2.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D2.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D2.GetAddress(), D2.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D2.DeferredMake();
			size_t cnt = fread(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(cnt==D2.arraySize)
				++totalRead;
		}

		if(D3.m_type != BinaryTypeReadRef::DTR_STRARRAY && D3.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D3.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D3.GetAddress(), D3.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D3.DeferredMake();
			size_t cnt = fread(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(cnt==D3.arraySize)
				++totalRead;
		}

		if(D4.m_type != BinaryTypeReadRef::DTR_STRARRAY && D4.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D4.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D4.GetAddress(), D4.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D4.DeferredMake();
			size_t cnt = fread(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(cnt==D4.arraySize)
				++totalRead;
		}

		if(D5.m_type != BinaryTypeReadRef::DTR_STRARRAY && D5.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D5.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D5.GetAddress(), D5.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D5.DeferredMake();
			size_t cnt = fread(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(cnt==D5.arraySize)
				++totalRead;
		}

	}

	if(totalRead != 5)
	{
		errNum = ELMAX_READ_ERROR;
		err = StrUtil::Format(L"{0}: Less than 5 elements are read! ({1} elements read)", GetErrorMsg(errNum), totalRead);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalRead;
}


size_t xBinaryReader::Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5, 
	BinaryTypeReadRef D6 )
{
	size_t totalRead = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeReadRef::DTR_STRARRAY && D1.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D1.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D1.GetAddress(), D1.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D1.DeferredMake();
			size_t cnt = fread(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(cnt == D1.arraySize)
				++totalRead;
		}

		if(D2.m_type != BinaryTypeReadRef::DTR_STRARRAY && D2.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D2.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D2.GetAddress(), D2.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D2.DeferredMake();
			size_t cnt = fread(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(cnt==D2.arraySize)
				++totalRead;
		}

		if(D3.m_type != BinaryTypeReadRef::DTR_STRARRAY && D3.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D3.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D3.GetAddress(), D3.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D3.DeferredMake();
			size_t cnt = fread(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(cnt==D3.arraySize)
				++totalRead;
		}

		if(D4.m_type != BinaryTypeReadRef::DTR_STRARRAY && D4.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D4.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D4.GetAddress(), D4.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D4.DeferredMake();
			size_t cnt = fread(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(cnt==D4.arraySize)
				++totalRead;
		}

		if(D5.m_type != BinaryTypeReadRef::DTR_STRARRAY && D5.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D5.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D5.GetAddress(), D5.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D5.DeferredMake();
			size_t cnt = fread(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(cnt==D5.arraySize)
				++totalRead;
		}

		if(D6.m_type != BinaryTypeReadRef::DTR_STRARRAY && D6.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D6.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D6.GetAddress(), D6.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D6.DeferredMake();
			size_t cnt = fread(D6.GetAddress(), D6.elementSize, D6.arraySize, fp);
			if(cnt==D6.arraySize)
				++totalRead;
		}

	}

	if(totalRead != 6)
	{
		errNum = ELMAX_READ_ERROR;
		err = StrUtil::Format(L"{0}: Less than 6 elements are read! ({1} elements read)", GetErrorMsg(errNum), totalRead);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalRead;
}

size_t xBinaryReader::Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5, 
	BinaryTypeReadRef D6, BinaryTypeReadRef D7 )
{
	size_t totalRead = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeReadRef::DTR_STRARRAY && D1.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D1.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D1.GetAddress(), D1.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D1.DeferredMake();
			size_t cnt = fread(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(cnt == D1.arraySize)
				++totalRead;
		}

		if(D2.m_type != BinaryTypeReadRef::DTR_STRARRAY && D2.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D2.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D2.GetAddress(), D2.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D2.DeferredMake();
			size_t cnt = fread(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(cnt==D2.arraySize)
				++totalRead;
		}

		if(D3.m_type != BinaryTypeReadRef::DTR_STRARRAY && D3.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D3.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D3.GetAddress(), D3.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D3.DeferredMake();
			size_t cnt = fread(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(cnt==D3.arraySize)
				++totalRead;
		}

		if(D4.m_type != BinaryTypeReadRef::DTR_STRARRAY && D4.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D4.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D4.GetAddress(), D4.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D4.DeferredMake();
			size_t cnt = fread(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(cnt==D4.arraySize)
				++totalRead;
		}

		if(D5.m_type != BinaryTypeReadRef::DTR_STRARRAY && D5.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D5.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D5.GetAddress(), D5.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D5.DeferredMake();
			size_t cnt = fread(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(cnt==D5.arraySize)
				++totalRead;
		}

		if(D6.m_type != BinaryTypeReadRef::DTR_STRARRAY && D6.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D6.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D6.GetAddress(), D6.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D6.DeferredMake();
			size_t cnt = fread(D6.GetAddress(), D6.elementSize, D6.arraySize, fp);
			if(cnt==D6.arraySize)
				++totalRead;
		}

		if(D7.m_type != BinaryTypeReadRef::DTR_STRARRAY && D7.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D7.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D7.GetAddress(), D7.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D7.DeferredMake();
			size_t cnt = fread(D7.GetAddress(), D7.elementSize, D7.arraySize, fp);
			if(cnt==D7.arraySize)
				++totalRead;
		}

	}

	if(totalRead != 7)
	{
		errNum = ELMAX_READ_ERROR;
		err = StrUtil::Format(L"{0}: Less than 7 elements are read! ({1} elements read)", GetErrorMsg(errNum), totalRead);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalRead;
}

size_t xBinaryReader::Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5, 
	BinaryTypeReadRef D6, BinaryTypeReadRef D7, BinaryTypeReadRef D8 )
{
	size_t totalRead = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeReadRef::DTR_STRARRAY && D1.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D1.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D1.GetAddress(), D1.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D1.DeferredMake();
			size_t cnt = fread(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(cnt == D1.arraySize)
				++totalRead;
		}

		if(D2.m_type != BinaryTypeReadRef::DTR_STRARRAY && D2.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D2.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D2.GetAddress(), D2.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D2.DeferredMake();
			size_t cnt = fread(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(cnt==D2.arraySize)
				++totalRead;
		}

		if(D3.m_type != BinaryTypeReadRef::DTR_STRARRAY && D3.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D3.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D3.GetAddress(), D3.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D3.DeferredMake();
			size_t cnt = fread(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(cnt==D3.arraySize)
				++totalRead;
		}

		if(D4.m_type != BinaryTypeReadRef::DTR_STRARRAY && D4.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D4.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D4.GetAddress(), D4.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D4.DeferredMake();
			size_t cnt = fread(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(cnt==D4.arraySize)
				++totalRead;
		}

		if(D5.m_type != BinaryTypeReadRef::DTR_STRARRAY && D5.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D5.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D5.GetAddress(), D5.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D5.DeferredMake();
			size_t cnt = fread(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(cnt==D5.arraySize)
				++totalRead;
		}

		if(D6.m_type != BinaryTypeReadRef::DTR_STRARRAY && D6.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D6.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D6.GetAddress(), D6.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D6.DeferredMake();
			size_t cnt = fread(D6.GetAddress(), D6.elementSize, D6.arraySize, fp);
			if(cnt==D6.arraySize)
				++totalRead;
		}

		if(D7.m_type != BinaryTypeReadRef::DTR_STRARRAY && D7.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D7.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D7.GetAddress(), D7.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D7.DeferredMake();
			size_t cnt = fread(D7.GetAddress(), D7.elementSize, D7.arraySize, fp);
			if(cnt==D7.arraySize)
				++totalRead;
		}

		if(D8.m_type != BinaryTypeReadRef::DTR_STRARRAY && D8.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D8.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D8.GetAddress(), D8.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D8.DeferredMake();
			size_t cnt = fread(D8.GetAddress(), D8.elementSize, D8.arraySize, fp);
			if(cnt==D8.arraySize)
				++totalRead;
		}

	}

	if(totalRead != 8)
	{
		errNum = ELMAX_READ_ERROR;
		err = StrUtil::Format(L"{0}: Less than 8 elements are read! ({1} elements read)", GetErrorMsg(errNum), totalRead);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalRead;
}


size_t xBinaryReader::Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5, 
	BinaryTypeReadRef D6, BinaryTypeReadRef D7, BinaryTypeReadRef D8, BinaryTypeReadRef D9 )
{
	size_t totalRead = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeReadRef::DTR_STRARRAY && D1.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D1.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D1.GetAddress(), D1.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D1.DeferredMake();
			size_t cnt = fread(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(cnt == D1.arraySize)
				++totalRead;
		}

		if(D2.m_type != BinaryTypeReadRef::DTR_STRARRAY && D2.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D2.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D2.GetAddress(), D2.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D2.DeferredMake();
			size_t cnt = fread(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(cnt==D2.arraySize)
				++totalRead;
		}

		if(D3.m_type != BinaryTypeReadRef::DTR_STRARRAY && D3.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D3.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D3.GetAddress(), D3.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D3.DeferredMake();
			size_t cnt = fread(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(cnt==D3.arraySize)
				++totalRead;
		}

		if(D4.m_type != BinaryTypeReadRef::DTR_STRARRAY && D4.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D4.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D4.GetAddress(), D4.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D4.DeferredMake();
			size_t cnt = fread(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(cnt==D4.arraySize)
				++totalRead;
		}

		if(D5.m_type != BinaryTypeReadRef::DTR_STRARRAY && D5.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D5.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D5.GetAddress(), D5.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D5.DeferredMake();
			size_t cnt = fread(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(cnt==D5.arraySize)
				++totalRead;
		}

		if(D6.m_type != BinaryTypeReadRef::DTR_STRARRAY && D6.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D6.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D6.GetAddress(), D6.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D6.DeferredMake();
			size_t cnt = fread(D6.GetAddress(), D6.elementSize, D6.arraySize, fp);
			if(cnt==D6.arraySize)
				++totalRead;
		}

		if(D7.m_type != BinaryTypeReadRef::DTR_STRARRAY && D7.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D7.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D7.GetAddress(), D7.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D7.DeferredMake();
			size_t cnt = fread(D7.GetAddress(), D7.elementSize, D7.arraySize, fp);
			if(cnt==D7.arraySize)
				++totalRead;
		}

		if(D8.m_type != BinaryTypeReadRef::DTR_STRARRAY && D8.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D8.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D8.GetAddress(), D8.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D8.DeferredMake();
			size_t cnt = fread(D8.GetAddress(), D8.elementSize, D8.arraySize, fp);
			if(cnt==D8.arraySize)
				++totalRead;
		}

		if(D9.m_type != BinaryTypeReadRef::DTR_STRARRAY && D9.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D9.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D9.GetAddress(), D9.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D9.DeferredMake();
			size_t cnt = fread(D9.GetAddress(), D9.elementSize, D9.arraySize, fp);
			if(cnt==D9.arraySize)
				++totalRead;
		}

	}

	if(totalRead != 9)
	{
		errNum = ELMAX_READ_ERROR;
		err = StrUtil::Format(L"{0}: Less than 9 elements are read! ({1} elements read)", GetErrorMsg(errNum), totalRead);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalRead;
}


size_t xBinaryReader::Read( BinaryTypeReadRef D1, BinaryTypeReadRef D2, BinaryTypeReadRef D3, BinaryTypeReadRef D4, BinaryTypeReadRef D5, 
	BinaryTypeReadRef D6, BinaryTypeReadRef D7, BinaryTypeReadRef D8, BinaryTypeReadRef D9, BinaryTypeReadRef D10 )
{
	size_t totalRead = 0;
	if(fp!=NULL)
	{
		if(D1.m_type != BinaryTypeReadRef::DTR_STRARRAY && D1.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D1.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D1.GetAddress(), D1.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D1.DeferredMake();
			size_t cnt = fread(D1.GetAddress(), D1.elementSize, D1.arraySize, fp);
			if(cnt == D1.arraySize)
				++totalRead;
		}

		if(D2.m_type != BinaryTypeReadRef::DTR_STRARRAY && D2.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D2.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D2.GetAddress(), D2.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D2.DeferredMake();
			size_t cnt = fread(D2.GetAddress(), D2.elementSize, D2.arraySize, fp);
			if(cnt==D2.arraySize)
				++totalRead;
		}

		if(D3.m_type != BinaryTypeReadRef::DTR_STRARRAY && D3.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D3.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D3.GetAddress(), D3.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D3.DeferredMake();
			size_t cnt = fread(D3.GetAddress(), D3.elementSize, D3.arraySize, fp);
			if(cnt==D3.arraySize)
				++totalRead;
		}

		if(D4.m_type != BinaryTypeReadRef::DTR_STRARRAY && D4.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D4.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D4.GetAddress(), D4.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D4.DeferredMake();
			size_t cnt = fread(D4.GetAddress(), D4.elementSize, D4.arraySize, fp);
			if(cnt==D4.arraySize)
				++totalRead;
		}

		if(D5.m_type != BinaryTypeReadRef::DTR_STRARRAY && D5.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D5.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D5.GetAddress(), D5.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D5.DeferredMake();
			size_t cnt = fread(D5.GetAddress(), D5.elementSize, D5.arraySize, fp);
			if(cnt==D5.arraySize)
				++totalRead;
		}

		if(D6.m_type != BinaryTypeReadRef::DTR_STRARRAY && D6.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D6.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D6.GetAddress(), D6.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D6.DeferredMake();
			size_t cnt = fread(D6.GetAddress(), D6.elementSize, D6.arraySize, fp);
			if(cnt==D6.arraySize)
				++totalRead;
		}

		if(D7.m_type != BinaryTypeReadRef::DTR_STRARRAY && D7.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D7.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D7.GetAddress(), D7.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D7.DeferredMake();
			size_t cnt = fread(D7.GetAddress(), D7.elementSize, D7.arraySize, fp);
			if(cnt==D7.arraySize)
				++totalRead;
		}

		if(D8.m_type != BinaryTypeReadRef::DTR_STRARRAY && D8.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D8.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D8.GetAddress(), D8.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D8.DeferredMake();
			size_t cnt = fread(D8.GetAddress(), D8.elementSize, D8.arraySize, fp);
			if(cnt==D8.arraySize)
				++totalRead;
		}

		if(D9.m_type != BinaryTypeReadRef::DTR_STRARRAY && D9.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D9.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D9.GetAddress(), D9.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D9.DeferredMake();
			size_t cnt = fread(D9.GetAddress(), D9.elementSize, D9.arraySize, fp);
			if(cnt==D9.arraySize)
				++totalRead;
		}

		if(D10.m_type != BinaryTypeReadRef::DTR_STRARRAY && D10.m_type != BinaryTypeReadRef::DTR_WSTRARRAY && D10.m_type != BinaryTypeReadRef::DTR_BASEARRAY)
		{
			size_t cnt = fread(D10.GetAddress(), D10.size, 1, fp);
			if(cnt==1)
				++totalRead;
		}
		else
		{
			D10.DeferredMake();
			size_t cnt = fread(D10.GetAddress(), D10.elementSize, D10.arraySize, fp);
			if(cnt==D10.arraySize)
				++totalRead;
		}
	}

	if(totalRead != 10)
	{
		errNum = ELMAX_READ_ERROR;
		err = StrUtil::Format(L"{0}: Less than 10 elements are read! ({1} elements read)", GetErrorMsg(errNum), totalRead);
		if(enableException)
			throw std::runtime_error(StrUtil::ConvToString(err));
	}

	return totalRead;
}

bool xBinaryReader::IsEOF()
{
	if(fp!=NULL)
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
