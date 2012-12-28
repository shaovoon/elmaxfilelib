#include "../Utils/StrUtilRef.h"
#include "../../Common/BaseConverter.h"
#include <cassert>

using namespace Elmax;

StrUtilRef::StrUtilRef(void)
{
}


StrUtilRef::~StrUtilRef(void)
{
}


std::wstring StrUtilRef::Replace( std::wstring fmtstr, std::vector<std::wstring>& vs )
{
	size_t pos = 0;
	//std::wstring fmtstr2 = fmtstr;

	for( size_t i=0; i<vs.size(); ++i )
	{
		pos = 0;
		std::wstring anchor = Anchor( i );

		while( std::wstring::npos != pos )
		{
			pos = fmtstr.find( anchor, pos );

			if( std::wstring::npos != pos )
			{
				//fmtstr.replace( pos, 1, vs.at(i) );
				fmtstr.erase( pos, anchor.size() );
				fmtstr.insert( pos, vs.at(i) );
				pos += vs.at(i).size();
			}
		}
	}

	return fmtstr;
}

std::wstring StrUtilRef::Replace( std::wstring fmtstr, size_t index, const std::wstring& s )
{
	size_t pos = 0;
	std::wstring anchor = Anchor( index );
	//std::wstring fmtstr2 = fmtstr;
	
	while( std::wstring::npos != pos )
	{
		pos = fmtstr.find( anchor, pos );

		if( std::wstring::npos != pos )
		{
			//fmtstr.replace( pos, 1, vs.at(i) );
			fmtstr.erase( pos, anchor.size() );
			fmtstr.insert( pos, s );
			pos += s.size();
		}
	}

	return fmtstr;
}

std::wstring StrUtilRef::Anchor( int i )
{
	std::wstring str2 = L"";
	BaseConverter conv;

	conv.SetInt32(str2, i);
	std::wstring str = L"{";
	str += str2 + L"}";

	return str;
}
