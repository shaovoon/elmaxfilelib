#pragma once

#include <string>
#include "../../Common/BaseConverter.h"
#include <boost/lexical_cast.hpp>

namespace Elmax
{

class ostream
{
public:
	ostream(void) : m_str(L"") {}
	ostream(const std::wstring& str) : m_str(str) {}
	~ostream(void) {}

	ostream& operator <<(bool val);
	ostream& operator <<(char val);
	ostream& operator <<(short val);
	ostream& operator <<(int val);
	ostream& operator <<(__int64 val);
	ostream& operator <<(unsigned char val);
	ostream& operator <<(unsigned short val);
	ostream& operator <<(unsigned int val);
	ostream& operator <<(unsigned __int64 val);
	ostream& operator <<(float val);
	ostream& operator <<(double val);
	ostream& operator <<(const std::string& val);
	ostream& operator <<(const char* val);
	ostream& operator <<(const std::wstring& val);
	ostream& operator <<(const wchar_t* val);
	std::wstring str();
	void set_str(const std::wstring& str);
	
private:
	std::wstring m_str;
};

}