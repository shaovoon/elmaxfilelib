#include "BaseTextReader.h"
#include <vector>
#include <sys/stat.h>
#include "../Utils/StrUtil.h"
#include "../../Common/RAII_Array.h"

using namespace Elmax;

#define VECTOR_RESERVE 50000

BaseTextReader::BaseTextReader(void)
	: fp(nullptr)
	, err(L"")
	, errNum(0)
	, hasBOM(false)
{
}

BaseTextReader::~BaseTextReader(void)
{
	Close();
}

void BaseTextReader::Close()
{
	if(fp!=nullptr)
	{
		fclose(fp);
		fp = nullptr;
	}
}

bool BaseTextReader::FileToContents( 
	const wchar_t* pszSource, 
	size_t nSource, 
	wchar_t*& pszDest,
	size_t& nDest	)
{
	if( !pszSource )
		return false;

	std::vector<wchar_t> vwc;
	vwc.reserve( VECTOR_RESERVE );

	if( 0 == nSource )
	{
		const wchar_t* pszSource2 = pszSource;

		while( pszSource2 )
		{
			if( L'\r' == *pszSource2 && L'\n' == *(pszSource2+1) )
			{
				vwc.push_back( L'\n' );
				pszSource2++;
			}
			else
				vwc.push_back( *pszSource2 );

			pszSource2++;
		}
	}
	else
	{
		for( size_t i=0; i<nSource; ++i )
		{
			if( i+1 < nSource && L'\r' == pszSource[i] && L'\n' == pszSource[i+1] )
			{
				vwc.push_back( L'\n' );
				++i;
			}
			else
				vwc.push_back( pszSource[i] );
		}
	}

	if( !vwc.empty() )
		vwc.push_back( L'\0' );
	else
		return false;

	pszDest = new wchar_t[vwc.size()];
	RAII_Array<wchar_t> raii = pszDest;
	
	if( !pszDest )
		return false;

	nDest = vwc.size();
	for( size_t i=0; i<nDest; ++i )
	{
		pszDest[i] = vwc[i];
	}

	raii.Detach();

	return true;
}

#ifdef _MICROSOFT
size_t BaseTextReader::GetFileSize(const std::wstring& file)
{
	struct _stat64i32 st;
	_wstat(file.c_str(), &st);
	return st.st_size;
}
#else
size_t BaseTextReader::GetFileSize(const std::wstring& file)
{
	struct stat st;
	stat(StrUtil::ConvToString(file).c_str(), &st);
	return st.st_size;
}
#endif

bool BaseTextReader::ContainsNewline(const wchar_t* text, size_t len)
{
	for(size_t i=0; i<len; ++i)
	{
#ifdef _MICROSOFT
		if(text[i]==L'\n')
		{
			if(i!=0)
			{
				if(text[i-1]==L'\r') // is \r\n
					return true; // true if \r\n
			}
		}
#else
		if(text[i]==L'\n')
		{
			return true; // true if \r\n
		}
#endif
	}

	return false;
}

// For Linux use
bool BaseTextReader::ContainsReturnCarriage(const wchar_t* text, size_t len)
{
	for(size_t i=0; i<len; ++i)
	{
		if(text[i]==L'\r')
			return true; // true if \r
	}

	return false;
}

bool BaseTextReader::ContainsReturnCarriage(const std::wstring& text)
{
	for(size_t i=0; i<text.size(); ++i)
	{
		if(text[i] == L'\r')
			return true; // true if \r
	}

	return false;
}

std::wstring BaseTextReader::RemoveReturnCarriage(const std::wstring& text)
{
	std::wstring dest = L"";
	for(size_t i=0; i<text.size(); ++i)
	{
		if(text[i] != L'\r')
			dest += text[i];
	}

	return dest;
}

int BaseTextReader::GetLastError(std::wstring& msg)
{
	msg = err;
	return errNum;
}


void BaseTextReader::ClearLastError()
{
	err = L"";
	errNum = 0;
}

