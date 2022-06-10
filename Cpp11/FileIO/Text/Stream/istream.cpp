#include "istream.h"

using namespace Elmax;

istream& istream::operator >> (bool& val)
{
	if(m_delimiter!=L"")
	{
		std::wstring result;
		if(split_at_a_time(result))
		{
			BaseConverter::GetBool(result, false, val);				
		}
	}
	else
	{
		std::string temp = BaseConverter::ConvToString(m_str);
		BaseConverter::GetBool(m_str, false, val);
		m_str = L"";
	}
	return *this;
}
istream& istream::operator >> (char& val)
{
	process(val);
	return *this;
}
istream& istream::operator >> (short& val)
{
	process(val);
	return *this;
}
istream& istream::operator >> (int& val)
{
	process(val);
	return *this;
}
istream& istream::operator >> (ELMAX_INT64& val)
{
	process(val);
	return *this;
}
istream& istream::operator >> (unsigned char& val)
{
	process(val);
	return *this;
}
istream& istream::operator >> (unsigned short& val)
{
	process(val);
	return *this;
}
istream& istream::operator >> (unsigned int& val)
{
	process(val);
	return *this;
}
istream& istream::operator >> (unsigned ELMAX_INT64& val)
{
	process(val);
	return *this;
}
istream& istream::operator >> (float& val)
{
	process(val);
	return *this;
}
istream& istream::operator >> (double& val)
{
	process(val);
	return *this;
}
istream& istream::operator >>(std::string& val)
{
#ifdef _VS2005_
	if(m_delimiter!=L"")
	{
		std::wstring result;
		if(split_at_a_time(result))
		{
			RAII_Array<char> pBuf(result.size()+1);
			if( nullptr == pBuf.GetPtr() )
				throw std::runtime_error("nullptr == pBuf.GetPtr()");
			size_t RetSize=0;
			errno_t err = wcstombs_s( &RetSize, pBuf.GetPtr(), result.size()+1, result.c_str(), result.size()+1 );

			if( 0 != err )
				throw std::runtime_error("0 != err");

			val=pBuf.GetPtr();
		}
	}
	else
	{
		RAII_Array<char> pBuf(m_str.size()+1);
		if( nullptr == pBuf.GetPtr() )
			throw std::runtime_error("nullptr == pBuf.GetPtr()");
		size_t RetSize=0;
		errno_t err = wcstombs_s( &RetSize, pBuf.GetPtr(), m_str.size()+1, m_str.c_str(), m_str.size()+1 );

		if( 0 != err )
			throw std::runtime_error("0 != err");

		val=pBuf.GetPtr();
		m_str = L"";
	}

#else // _VS2005_
	if(m_delimiter!=L"")
	{
		std::wstring result;
		if(split_at_a_time(result))
		{
			RAII_Array<char> pBuf(result.size()+1);
			if( nullptr == pBuf.GetPtr() )
				throw std::runtime_error("nullptr == pBuf.GetPtr()");
			wcstombs( pBuf.GetPtr(), result.c_str(), result.size()+1 );

			val=pBuf.GetPtr();
		}
	}
	else
	{
		RAII_Array<char> pBuf(m_str.size()+1);
		if( nullptr == pBuf.GetPtr() )
			throw std::runtime_error("nullptr == pBuf.GetPtr()");
		wcstombs( pBuf.GetPtr(), m_str.c_str(), m_str.size()+1 );

		val=pBuf.GetPtr();
	}
#endif // _VS2005_
	return *this;
}
istream& istream::operator >>(std::wstring& val)
{
	if(m_delimiter!=L"")
	{
		std::wstring result;
		if(split_at_a_time(result))
		{
			val = result;
		}
	}
	else
	{
		val = m_str;
	}
	return *this;
}

std::wstring istream::str()
{
	return m_str;
}

void istream::set_str(const std::wstring& str)
{
	m_str = str;
}

// return old delimiter
std::wstring istream::set_delimiter(const std::wstring& delimiter)
{
	std::wstring temp = m_delimiter;
	m_delimiter = delimiter;
	return temp;
}
