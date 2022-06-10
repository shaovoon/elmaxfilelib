#include "ostream.h"

using namespace Elmax;

ostream& ostream::operator <<(bool val)
{
	m_str += BaseConverter::SetBool(m_str, val);
	return *this;
}
ostream& ostream::operator <<(char val)
{
	std::string temp = std::to_string(val);
	m_str += BaseConverter::ConvToString(temp);
	return *this;
}
ostream& ostream::operator <<(short val)
{
	std::string temp = std::to_string(val);
	m_str += BaseConverter::ConvToString(temp);
	return *this;
}
ostream& ostream::operator <<(int val)
{
	std::string temp = std::to_string(val);
	m_str += BaseConverter::ConvToString(temp);
	return *this;
}
ostream& ostream::operator <<(ELMAX_INT64 val)
{
	std::string temp = std::to_string(val);
	m_str += BaseConverter::ConvToString(temp);
	return *this;
}
ostream& ostream::operator <<(unsigned char val)
{
	std::string temp = std::to_string(val);
	m_str += BaseConverter::ConvToString(temp);
	return *this;
}
ostream& ostream::operator <<(unsigned short val)
{
	std::string temp = std::to_string(val);
	m_str += BaseConverter::ConvToString(temp);
	return *this;
}
ostream& ostream::operator <<(unsigned int val)
{
	std::string temp = std::to_string(val);
	m_str += BaseConverter::ConvToString(temp);
	return *this;
}
ostream& ostream::operator <<(unsigned ELMAX_INT64 val)
{
	std::string temp = std::to_string(val);
	m_str += BaseConverter::ConvToString(temp);
	return *this;
}
ostream& ostream::operator <<(float val)
{
	std::string temp = std::to_string(val);
	m_str += BaseConverter::ConvToString(temp);
	return *this;
}
ostream& ostream::operator <<(double val)
{
	std::string temp = std::to_string(val);
	m_str += BaseConverter::ConvToString(temp);
	return *this;
}
ostream& ostream::operator <<(const std::string& val)
{
	std::wstring temp=L"";
	BaseConverter::SetString(temp, val);
	m_str += temp;
	return *this;
}
ostream& ostream::operator <<(const char* val)
{
	std::wstring temp=L"";
	BaseConverter::SetString(temp, val);
	m_str += temp;
	return *this;
}
ostream& ostream::operator <<(const std::wstring& val)
{
	m_str += val;
	return *this;
}
ostream& ostream::operator <<(const wchar_t* val)
{
	m_str += val;
	return *this;
}

std::wstring ostream::str()
{
	return m_str;
}
void ostream::set_str(const std::wstring& str)
{
	m_str = str;
}
