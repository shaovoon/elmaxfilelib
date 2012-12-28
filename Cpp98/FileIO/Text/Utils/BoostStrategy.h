/*
String Split Library for Native C++ 1.1

Copyright (c) 2007 - 2008 Wong Shao Voon

The Code Project Open License (CPOL)
http://www.codeproject.com/info/cpol10.aspx
*/

#ifndef __BOOSTSTRATEGY_H__
#define __BOOSTSTRATEGY_H__

#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/constants.hpp>
#include "SplitStrategy.h"
#include "DataTypeRef.h"

class BoostStrategy : public ISplitStrategy
{
public:
	// Constructor
	BoostStrategy( 
		const std::wstring& sDelimit,
		boost::algorithm::token_compress_mode_type CompressMode = boost::token_compress_off ) { Init( sDelimit, CompressMode ); }

	virtual ~BoostStrategy() {}

	void Init( 	
		const std::wstring& sDelimit,
		boost::algorithm::token_compress_mode_type CompressMode )
	{
		m_sDelimit = sDelimit;
		m_CompressMode = CompressMode;
	}

	virtual size_t Extract( 
		const std::wstring& StrToExtract, 
		std::vector<Elmax::DataTypeRef*> vecDTR );

	std::wstring m_sDelimit;
	boost::algorithm::token_compress_mode_type m_CompressMode;
};

#endif // __BOOSTSTRATEGY_H__