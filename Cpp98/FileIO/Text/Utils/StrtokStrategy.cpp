/*
String Split Library for Native C++ 1.1

Copyright (c) 2007 - 2008 Wong Shao Voon

The Code Project Open License (CPOL)
http://www.codeproject.com/info/cpol10.aspx
*/
#include "StrtokStrategy.h"
#include "../../Common/Common.h"
///////////////////////
///////////////////////
// StrtokStrategyW member functions

using namespace Elmax;

size_t StrtokStrategy::Extract( 
	const std::wstring& StrToExtract, 
	std::vector<Elmax::DataTypeRef*> vecDTR )
{
	std::vector<std::wstring> vecSplit;
	const size_t size = StrToExtract.size()+1;
	wchar_t* pszToExtract = new wchar_t[size];
	wmemset( pszToExtract, 0, size );
	Wcscpy( pszToExtract, StrToExtract.c_str(), size );

	wchar_t *pszContext = 0;
	wchar_t *pszSplit = 0;
#ifdef _MICROSOFT
	pszSplit = wcstok_s( pszToExtract, m_sDelimit.c_str(), &pszContext );
#else
	#ifdef _WIN32
		pszSplit = wcstok( pszToExtract, m_sDelimit.c_str() );
	#else
		pszSplit = wcstok( pszToExtract, m_sDelimit.c_str(), &pszContext );
	#endif
#endif

	while( NULL != pszSplit )
	{
		size_t len = wcslen(pszSplit);
		if(pszSplit[len-1]==65535&&vecSplit.size()==vecDTR.size()-1) // bug workaround: wcstok_s/wcstok will put 65535 at the back of last string.
			pszSplit[len-1] = L'\0';
		
		vecSplit.push_back(std::wstring( pszSplit ) );
		
#ifdef _MICROSOFT
		pszSplit = wcstok_s( NULL, m_sDelimit.c_str(), &pszContext );
#else
	#ifdef _WIN32
		pszSplit = wcstok( NULL, m_sDelimit.c_str() );
	#else
		pszSplit = wcstok( NULL, m_sDelimit.c_str(), &pszContext );
	#endif
#endif
	}

	delete [] pszToExtract;

	size_t fail = 0;
	for( size_t i=0; i<vecDTR.size(); ++i )
	{
		if( i < vecSplit.size() )
		{
			if( false == vecDTR[i]->ConvStrToType( vecSplit[i] ) )
				++fail;
		}
		else
			break;
	}

	return vecSplit.size()-fail;
}
