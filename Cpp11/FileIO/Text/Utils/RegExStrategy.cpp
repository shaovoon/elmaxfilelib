/*
String Split Library for Native C++ 1.1

Copyright (c) 2007 - 2008 Wong Shao Voon

The Code Project Open License (CPOL)
http://www.codeproject.com/info/cpol10.aspx
*/

#include "RegExStrategy.h"


/////////////////////////////
/////////////////////////////
// RegExStrategy member functions

size_t RegExStrategy::Extract( 
		const std::wstring& StrToExtract, 
		std::vector<Elmax::DataTypeRef*> vecDTR )
{
	using namespace boost;

	wregex expression( m_sExpression );
	
	match_results<std::wstring::const_iterator> what;

	bool bSearch = regex_search( StrToExtract, what, expression, m_flags );

	size_t fail = 0;
	if( bSearch )
	{
		for( size_t i=0; i<vecDTR.size(); ++i )
		{
			if( i+1 < what.size() )
			{
				if( false == vecDTR[i]->ConvStrToType( what.str(i+1) ) )
					++fail;
			}
			else
				break;
		}
	}
	else
		return 0;

	return (what.size()-1)-fail;
}
