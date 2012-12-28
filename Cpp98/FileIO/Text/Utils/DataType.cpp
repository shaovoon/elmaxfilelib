#include "DataType.h"
#include "../../Common/BaseConverter.h"

using namespace Elmax;

DataType::~DataType(void)
{
}

DataType::DataType( short i )
{
	BaseConverter conv;
	conv.SetInt16(m_str, i);
}

DataType::DataType( unsigned short ui )
{
	BaseConverter conv;
	conv.SetUInt16(m_str, ui);
}

DataType::DataType( int i )
{
	BaseConverter conv;
	conv.SetInt32(m_str, i);
}

DataType::DataType( unsigned int ui )
{
	BaseConverter conv;
	conv.SetUInt32(m_str, ui);
}

#ifdef __APPLE__
DataType::DataType( size_t ui )
{
	BaseConverter conv;
	conv.SetSizeT(m_str, ui);
}
#endif

DataType::DataType( const ELMAX_INT64& i64 )
{
	BaseConverter conv;
	conv.SetInt64(m_str, i64);
}

DataType::DataType( const unsigned ELMAX_INT64& ui64 )
{
	BaseConverter conv;
	conv.SetUInt64(m_str, ui64);
}

DataType::DataType( float f )
{
	BaseConverter conv;
	conv.SetFloat(m_str, f);
}

DataType::DataType( const double& d )
{
	BaseConverter conv;
	conv.SetDouble(m_str, d);
}

DataType::DataType( const std::string& s )
{
	BaseConverter conv;
	conv.SetString(m_str, s);
}

DataType::DataType( const std::wstring& ws )
{
	m_str = ws;
}

DataType::DataType( const char* pc )
{
	BaseConverter conv;
	conv.SetString(m_str, pc);
}

DataType::DataType( const wchar_t* pwc )
{
	m_str = pwc;
}

DataType::DataType( char c )
{
	BaseConverter conv;
	conv.SetInt8(m_str, c);
}

DataType::DataType( unsigned char c )
{
	BaseConverter conv;
	conv.SetUInt8(m_str, c);
}

DataType::DataType( wchar_t wc )
{
	m_str = wc;
}
