/*
String Split Library for Native C++ 1.1

Copyright (c) 2007 - 2008 Wong Shao Voon

The Code Project Open License (CPOL)
http://www.codeproject.com/info/cpol10.aspx
*/

#ifndef __REGEXSPLIT_H__
#define __REGEXSPLIT_H__

#include <vector>
#include <string>

//#define BOOST_REGEX_DYN_LINK
//#define BOOST_REGEX_NO_LIB

#include <boost/cstdint.hpp>
#include <boost/regex/v4/regex.hpp>
#include "SplitStrategy.h"
#include "DataTypeRef.h"

class RegExStrategy : public ISplitStrategy
{
public:
	// Constructor
	RegExStrategy( 
		const std::wstring& sExpression,
		boost::match_flag_type flags ) { Init( sExpression, flags ); }

	virtual ~RegExStrategy() {}

	void Init( 	
		const std::wstring& sExpression,
		boost::match_flag_type flags )
	{
		m_sExpression = sExpression;
		m_flags = flags;
	}

	virtual size_t Extract( 
		const std::wstring& StrToExtract, 
		std::vector<Elmax::DataTypeRef*> vecDTR );

	std::wstring m_sExpression;
	boost::match_flag_type m_flags; 
};

#endif // __REGEXSPLIT_H__