#pragma once

#include "../Utils/SplitStrategy.h"
//#include "../Utils/DataTypeRef.h"
#include "../Stream/istream.h"
#include "BaseTextReader.h"

namespace Elmax
{

class xTextReader
{
public:
	xTextReader(void);
	~xTextReader(void);

	bool Open(const std::wstring& file);
	bool Open(const std::wstring& file, FILE_TYPE ftype);
	void Close();

	bool IsEOF();

	void ReadArg(Elmax::istream &, size_t &)
	{
	}

	template<typename T, typename... Args>
	void ReadArg(Elmax::istream& is, size_t& extracted, T& t, Args&... args)
	{
		is >> t;
		++extracted;
		ReadArg(is, extracted, args...);
	}

	template<typename... Args>
	size_t Read( size_t len, Args&... args )
	{
		if(pReader!=nullptr)
		{
			std::wstring text;
			bool b = pReader->Read(text, len);

			if(b)
			{
				istream is(text, m_delimiter);
				size_t extracted=0;
				ReadArg(is, extracted, args...);
				return extracted;
			}
		}

		return 0;
	}

	template<typename... Args>
	size_t ReadLine( Args&... args )
	{
		if(pReader!=nullptr)
		{
			std::wstring text;
			bool b = pReader->ReadLine(text);

			if(b)
			{
				istream is(text, m_delimiter);
				size_t extracted=0;
				ReadArg(is, extracted, args...);

				return extracted;
			}
		}

		return 0;
	}

	// return old delimiter
	std::wstring SetDelimiter(const std::wstring& delimiter)
	{
		std::wstring temp  = m_delimiter;
		m_delimiter = delimiter;
		return temp;
	}

	bool ReadAll( std::wstring& text );

	int GetLastError(std::wstring& str);
	void ClearLastError();

private:
	xTextReader(const xTextReader&) {}
	xTextReader& operator=(const xTextReader&) { return* this; }

	BaseTextReader* pReader;
	std::wstring m_delimiter;
};

}
