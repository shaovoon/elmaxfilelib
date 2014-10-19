#include "DataType.h"
#include "../../Common/BaseConverter.h"
#include <boost/lexical_cast.hpp>

using namespace Elmax;

DataType::~DataType(void)
{
}

DataType::DataType( short i )
{
	std::string temp = boost::lexical_cast<std::string>(i);
	m_str = BaseConverter::ConvToString(temp);
}

DataType::DataType( unsigned short ui )
{
	std::string temp = boost::lexical_cast<std::string>(ui);
	m_str = BaseConverter::ConvToString(temp);
}

DataType::DataType( int i )
{
	std::string temp = boost::lexical_cast<std::string>(i);
	m_str = BaseConverter::ConvToString(temp);
}

DataType::DataType( unsigned int ui )
{
	std::string temp = boost::lexical_cast<std::string>(ui);
	m_str = BaseConverter::ConvToString(temp);
}

#ifdef __APPLE__
DataType::DataType( size_t ui )
{
	std::string temp = boost::lexical_cast<std::string>(ui);
	m_str = BaseConverter::ConvToString(temp);
}
#endif

DataType::DataType( const ELMAX_INT64& i64 )
{
	std::string temp = boost::lexical_cast<std::string>(i64);
	m_str = BaseConverter::ConvToString(temp);
}

DataType::DataType( const unsigned ELMAX_INT64& ui64 )
{
	std::string temp = boost::lexical_cast<std::string>(ui64);
	m_str = BaseConverter::ConvToString(temp);
}

DataType::DataType( float f )
{
	std::string temp = boost::lexical_cast<std::string>(f);
	m_str = BaseConverter::ConvToString(temp);
}

DataType::DataType( const double& d )
{
	std::string temp = boost::lexical_cast<std::string>(d);
	m_str = BaseConverter::ConvToString(temp);
}

DataType::DataType( const std::string& s )
{
	BaseConverter::SetString(m_str, s);
}

DataType::DataType( const std::wstring& ws )
{
	m_str = ws;
}

DataType::DataType( const char* pc )
{
	BaseConverter::SetString(m_str, pc);
}

DataType::DataType( const wchar_t* pwc )
{
	m_str = pwc;
}

DataType::DataType( char c )
{
	std::string temp = boost::lexical_cast<std::string>(c);
	m_str = BaseConverter::ConvToString(temp);
}

DataType::DataType( unsigned char c )
{
	std::string temp = boost::lexical_cast<std::string>(c);
	m_str = BaseConverter::ConvToString(temp);
}

DataType::DataType( wchar_t wc )
{
	m_str = wc;
}
