/*
String Split Library for Native C++ 1.1

Copyright (c) 2007 - 2008 Wong Shao Voon

The Code Project Open License (CPOL)
http://www.codeproject.com/info/cpol10.aspx
*/

#ifndef __STRTOKSTRATEGY_H__
#define __STRTOKSTRATEGY_H__

#include <vector>
#include <string>
#include "SplitStrategy.h"
#include "DataTypeRef.h"
#include "../../Common/Common.h"

namespace Elmax
{

class StrtokStrategy : public ISplitStrategy
{
public:
	// Constructor
	StrtokStrategy( const std::wstring& sDelimit ) : m_sDelimit(sDelimit) { }

	virtual ~StrtokStrategy() {}

	void Init( const std::wstring& sDelimit)
	{
		m_sDelimit = sDelimit;
	}

	virtual size_t Extract( 
		const std::wstring& StrToExtract, 
		std::vector<Elmax::DataTypeRef*> vecDTR );

	std::wstring m_sDelimit;
};

}
#endif // __STRTOKSTRATEGY_H__
