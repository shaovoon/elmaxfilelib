#pragma once

#include "../Utils/SplitStrategy.h"
#include "../Utils/DataTypeRef.h"
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

	void SetSplitStrategy( ISplitStrategy* pSplitStrategy )
	{
		m_pSplitStrategy = pSplitStrategy;
	}

	bool IsEOF();

	void ReadArg(std::vector<DataTypeRef*>& vec)
	{
	}

	template<typename T, typename... Args>
	void ReadArg(std::vector<DataTypeRef*>& vec, T& t, Args&... args)
	{
		vec.push_back(new DataTypeRef(t));
		ReadArg(vec, args...);
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
				std::vector<DataTypeRef*> vec;
				ReadArg(vec, args...);

				size_t ret = m_pSplitStrategy->Extract(text, vec);

				for(size_t i=0; i<vec.size(); ++i)
				{
					delete vec[i];
				}

				vec.clear();

				return ret;
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
				std::vector<DataTypeRef*> vec;
				ReadArg(vec, args...);
				
				size_t ret = m_pSplitStrategy->Extract(text, vec);

				for(size_t i=0; i<vec.size(); ++i)
				{
					delete vec[i];
				}

				vec.clear();

				return ret;
			}
		}

		return 0;
	}

	int GetLastError(std::wstring& str);
	void ClearLastError();

	bool EnableException(bool enable);

private:
	xTextReader(const xTextReader&) {}
	xTextReader& operator=(const xTextReader& other) { return* this; }

	BaseTextReader* pReader;
	ISplitStrategy* m_pSplitStrategy;

	bool enableException;
};

}
