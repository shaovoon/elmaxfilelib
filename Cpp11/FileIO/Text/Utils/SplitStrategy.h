/*
String Split Library for Native C++ 1.1

Copyright (c) 2007 - 2008 Wong Shao Voon

The Code Project Open License (CPOL)
http://www.codeproject.com/info/cpol10.aspx
*/

#ifndef __SPLITSTRATEGY_H__
#define __SPLITSTRATEGY_H__

#include <vector>
#include <string>
#include "DataTypeRef.h"

namespace Elmax
{

class ISplitStrategy
{
public:
	// Constructor
	ISplitStrategy() {}

	virtual ~ISplitStrategy() {}

	virtual size_t Extract( 
		const std::wstring& StrToExtract, 
		std::vector<Elmax::DataTypeRef*> vecDTR ) = 0;
};

}

#endif // __SPLITSTRATEGY_H__