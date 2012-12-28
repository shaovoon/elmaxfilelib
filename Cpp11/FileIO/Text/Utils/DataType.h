#pragma once

#include <string>
#include "../../Common/Common.h"

namespace Elmax
{

class DataType
{
public:
	~DataType(void);

	DataType( short i );

	DataType( unsigned short ui );

	DataType( int i );

	DataType( unsigned int ui );

#ifdef __APPLE__
	DataType( size_t ui );
#endif

	DataType( const ELMAX_INT64& i64 );

	DataType( const unsigned ELMAX_INT64& ui64 );

	DataType( float f );

	DataType( const double& d );

	DataType( const std::string& s );

	DataType( const std::wstring& ws );

	DataType( const char* pc );

	DataType( const wchar_t* pwc );

	DataType( char c );

	DataType( unsigned char c );

	DataType( wchar_t wc );

	std::wstring& ToString() { return m_str; }

protected:
	std::wstring m_str;

};

}

