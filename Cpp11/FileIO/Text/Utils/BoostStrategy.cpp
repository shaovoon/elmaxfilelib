/*
String Split Library for Native C++ 1.1

Copyright (c) 2007 - 2008 Wong Shao Voon

The Code Project Open License (CPOL)
http://www.codeproject.com/info/cpol10.aspx
*/

#include "BoostStrategy.h"

///////////////////////
///////////////////////
// BoostStrategy member functions

size_t BoostStrategy::Extract( 
	const std::wstring& StrToExtract, 
	std::vector<Elmax::DataTypeRef*> vecDTR )
{
	std::vector<std::wstring> vecSplit;
	boost::split(vecSplit, StrToExtract, boost::is_any_of(m_sDelimit), m_CompressMode );

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
