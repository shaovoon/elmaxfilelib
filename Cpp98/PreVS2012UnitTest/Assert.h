#pragma once

#include <string>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include "../FileIO/Text/Utils/StrUtil.h"

template<typename A>
struct identity { typedef A type; };

class Assert
{
public:
	Assert(void);
	~Assert(void);

	template<typename T>
	static void AreEqual(T expected, T result, std::wstring error)
	{
		if(expected != result)
		{
			std::wstring funcName = L"Function:" + ConvToWString(FunctionName) + L",\n";
			std::wstring msg = funcName + error;

			msg += Elmax::StrUtil::Format(L" Expected: {0} but value is {1}", expected, result);
			std::wcout<<msg<<std::endl;
			throw std::logic_error(ConvToString(msg).c_str());
		}
	}

	static std::string ConvToString(const std::wstring& text)
	{
		std::string str = "";
		for(size_t i=0; i<text.length(); ++i)
		{
			str += (char)(text[i]);
		}

		return str;
	}

	static std::wstring ConvToWString(const std::string& text)
	{
		std::wstring str = L"";
		for(size_t i=0; i<text.length(); ++i)
		{
			str += (wchar_t)(text[i]);
		}

		return str;
	}

	static std::string FunctionName;
};

