#include "BaseTextWriter.h"
#include <vector>

using namespace Elmax;

#define VECTOR_RESERVE 50000

BaseTextWriter::BaseTextWriter(void)
	: fp(NULL)
	, err(L"")
	, errNum(0)
{
}

BaseTextWriter::~BaseTextWriter(void)
{
	Close();
}

void BaseTextWriter::Close()
{
	if(fp!=NULL)
	{
		fflush(fp);
		fclose(fp);
		fp = NULL;
	}
}

void BaseTextWriter::Flush()
{
	if(fp!=NULL)
		fflush(fp);
}

bool BaseTextWriter::ContentsToFile( 
	const wchar_t* pszSource, 
	size_t nSource, 
	wchar_t*& pszDest,
	size_t& nDest	)
{
	if( !pszSource )
		return false;

	std::vector<wchar_t> vwc;

	if( 0 == nSource )
	{
		vwc.reserve( VECTOR_RESERVE );
		const wchar_t* pszSource2 = pszSource;

		while( pszSource2 )
		{
			if( L'\n' == *pszSource2 )
			{
				vwc.push_back( L'\r' );
				vwc.push_back( L'\n' );
			}
			else
				vwc.push_back( *pszSource2 );

			pszSource2++;
		}
	}
	else
	{
		vwc.reserve( nSource + 100 );

		for( size_t i=0; i<nSource; ++i )
		{
			if( L'\n' == pszSource[i] )
			{
				vwc.push_back( L'\r' );
				vwc.push_back( L'\n' );
			}
			else
				vwc.push_back( pszSource[i] );
		}
	}

	pszDest = new wchar_t[vwc.size()+1];
	memset(pszDest, 0, sizeof(wchar_t)*(vwc.size()+1));

	if( !pszDest )
		return false;

	nDest = vwc.size();
	for( size_t i=0; i<nDest; ++i )
	{
		pszDest[i] = vwc[i];
	}

	return true;
}

bool BaseTextWriter::ContainsNewline(const wchar_t* text, size_t len)
{
	for(size_t i=0; i<len; ++i)
	{
		if(text[i]==L'\n')
		{
			if(i!=0)
			{
				if(text[i-1]!=L'\r') // not \r\n
					return true; // true is single \n
			}
		}
	}

	return false;
}

int BaseTextWriter::GetLastError(std::wstring& msg)
{
	msg = err;
	return errNum;
}


void BaseTextWriter::ClearLastError()
{
	err = L"";
	errNum = 0;
}

