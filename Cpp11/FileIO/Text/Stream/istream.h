#pragma once
#define _VS2005_
#if _MSC_VER < 1400
#undef _VS2005_
#endif

#include <string>
#include <boost/lexical_cast.hpp>
#include "../../Common/BaseConverter.h"

namespace Elmax
{

class istream
{
public:
	//istream(void);
	istream(const std::wstring& str, const std::wstring& delimiter) : m_str(str), m_delimiter(delimiter) {}
	~istream(void) {}

	istream& operator >> (bool& val);
	istream& operator >> (char& val);
	istream& operator >> (short& val);
	istream& operator >> (int& val);
	istream& operator >> (ELMAX_INT64& val);
	istream& operator >> (unsigned char& val);
	istream& operator >> (unsigned short& val);
	istream& operator >> (unsigned int& val);
	istream& operator >> (unsigned ELMAX_INT64& val);
	istream& operator >> (float& val);
	istream& operator >> (double& val);
	istream& operator >>(std::string& val);
	istream& operator >>(std::wstring& val);
	std::wstring str();
	void set_str(const std::wstring& str);
	// return old delimiter
	std::wstring set_delimiter(const std::wstring& delimiter);

private:
	template<typename T>
	void process(T& val)
	{
		if(m_delimiter!=L"")
		{
			std::wstring result;
			if(split_at_a_time(result))
			{
				std::string temp = BaseConverter::ConvToString(result);
				val = boost::lexical_cast<T>(temp);
			}
		}
		else
		{
			std::string temp = BaseConverter::ConvToString(m_str);
			val = boost::lexical_cast<T>(temp);
			m_str = L"";
		}
	}
	bool is_delimiter(wchar_t ch)
	{
		for(size_t i=0; i<m_delimiter.size(); ++i)
		{
			if(ch==m_delimiter[i])
				return true;
		}
		return false;
	}
	bool split_at_a_time(std::wstring& result)
	{
		result = L"";
		for(size_t i=0; i<m_str.size(); ++i)
		{
			if(is_delimiter(m_str[i]))
			{
				if(result==L"")
					continue;
				else
				{
					m_str = m_str.substr(++i);
					return true;
				}
			}
			else
			{
				result += m_str[i];
			}
		}
		if(result==L"")
			return false;

		return true;
	}

	std::wstring m_str;
	std::wstring m_delimiter;

};

}