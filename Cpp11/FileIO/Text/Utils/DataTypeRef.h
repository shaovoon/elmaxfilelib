#pragma once
#include <string>
#include "../../Common/Common.h"

namespace Elmax
{

class DataTypeRef
{
public:
	~DataTypeRef(void);

	union UNIONPTR
	{
		int* pi;
		unsigned int* pui;
#ifdef __APPLE__
		size_t* psizet;
#endif
		short* psi;
		unsigned short* pusi;
		ELMAX_INT64* pi64;
		unsigned ELMAX_INT64* pui64;
		float* pf;
		double* pd;
		std::string* ps;
		std::wstring* pws;
		char* pc;
		unsigned char* puc;
		wchar_t* pwc;
	};

	enum DTR_TYPE
	{
		DTR_INT,
		DTR_UINT,
#ifdef __APPLE__
		DTR_SIZE_T,
#endif
		DTR_SHORT,
		DTR_USHORT,
		DTR_INT64,
		DTR_UINT64,
		DTR_FLOAT,
		DTR_DOUBLE,
		DTR_STR,
		DTR_WSTR,
		DTR_CHAR,
		DTR_UCHAR,
		DTR_WCHAR
	} ;

	DataTypeRef( int& i )					 { m_ptr.pi = &i; m_type = DTR_INT; }

	DataTypeRef( unsigned int& ui )			 { m_ptr.pui = &ui; m_type = DTR_UINT; }

#ifdef __APPLE__
	DataTypeRef( size_t& ui )				 { m_ptr.psizet = &ui; m_type = DTR_SIZE_T; }
#endif

	DataTypeRef( short& si )				 { m_ptr.psi = &si; m_type = DTR_SHORT; }

	DataTypeRef( unsigned short& usi )		 { m_ptr.pusi = &usi; m_type = DTR_USHORT; }

	DataTypeRef( ELMAX_INT64& i64 )				 { m_ptr.pi64 = &i64; m_type = DTR_INT64; }

	DataTypeRef( unsigned ELMAX_INT64& ui64 )	 { m_ptr.pui64 = &ui64; m_type = DTR_UINT64; }

	DataTypeRef( float& f )					 { m_ptr.pf = &f; m_type = DTR_FLOAT; }

	DataTypeRef( double& d )				 { m_ptr.pd = &d; m_type = DTR_DOUBLE; }

	DataTypeRef( std::string& s )			 { m_ptr.ps = &s; m_type = DTR_STR; }

	DataTypeRef( std::wstring& ws )			 { m_ptr.pws = &ws; m_type = DTR_WSTR; }

	DataTypeRef( char& c )					 { m_ptr.pc = &c; m_type = DTR_CHAR; }

	DataTypeRef( unsigned char& uc )		 { m_ptr.puc = &uc; m_type = DTR_UCHAR; }

	DataTypeRef( wchar_t& wc )				 { m_ptr.pwc = &wc; m_type = DTR_WCHAR; }

	bool ConvStrToType( const std::string& Str );

	bool ConvStrToType( const std::wstring& Str );

	DTR_TYPE m_type;

	UNIONPTR m_ptr;

};

}
