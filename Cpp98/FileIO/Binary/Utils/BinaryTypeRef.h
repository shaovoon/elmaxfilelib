#pragma once
#include <string>
#include "BaseArray.h"
#include "../../Common/Common.h"

namespace Elmax
{

class BinaryTypeRef
{
public:
	~BinaryTypeRef(void);

	union UNIONPTR
	{
		const int* pi;
		const unsigned int* pui;
#ifdef __APPLE__
		const size_t* psizet;
#endif
		const short* psi;
		const unsigned short* pusi;
		const ELMAX_INT64* pi64;
		const unsigned ELMAX_INT64* pui64;
		const float* pf;
		const double* pd;
		std::string* ps;
		const std::wstring* pws;
		const char* pc;
		const unsigned char* puc;
		const wchar_t* pwc;
		const char* arr;
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
		DTR_WCHAR,
		DTR_BASEARRAY
	} ;

	BinaryTypeRef( const int& i )					 { m_ptr.pi = &i; m_type = DTR_INT; size=sizeof(i); }

	BinaryTypeRef( const unsigned int& ui )			 { m_ptr.pui = &ui; m_type = DTR_UINT; size=sizeof(ui); }

#ifdef __APPLE__
	BinaryTypeRef( const size_t& ui )				 { m_ptr.psizet = &ui; m_type = DTR_SIZE_T; size=sizeof(size_t); }
#endif

	BinaryTypeRef( const short& si )				 { m_ptr.psi = &si; m_type = DTR_SHORT; size=sizeof(si); }

	BinaryTypeRef( const unsigned short& usi )		 { m_ptr.pusi = &usi; m_type = DTR_USHORT; size=sizeof(usi); }

	BinaryTypeRef( const ELMAX_INT64& i64 )				 { m_ptr.pi64 = &i64; m_type = DTR_INT64; size=sizeof(i64); }

	BinaryTypeRef( const unsigned ELMAX_INT64& ui64 )	 { m_ptr.pui64 = &ui64; m_type = DTR_UINT64; size=sizeof(ui64); }

	BinaryTypeRef( const float& f )					 { m_ptr.pf = &f; m_type = DTR_FLOAT; size=sizeof(f); }

	BinaryTypeRef( const double& d )				 { m_ptr.pd = &d; m_type = DTR_DOUBLE; size=sizeof(d); }

	BinaryTypeRef( std::string& s )					 { m_ptr.ps = &s; m_type = DTR_STR; elementSize=sizeof(char);size=s.length(); arraySize=s.length();}

	BinaryTypeRef( const std::wstring& ws )			 { m_ptr.pws = &ws; m_type = DTR_WSTR; elementSize=sizeof(wchar_t);size=ws.length()*sizeof(wchar_t); arraySize=ws.length();}

	BinaryTypeRef( const char& c )					 { m_ptr.pc = &c; m_type = DTR_CHAR; size=sizeof(c); }

	BinaryTypeRef( const unsigned char& uc )		 { m_ptr.puc = &uc; m_type = DTR_UCHAR; size=sizeof(uc); }

	BinaryTypeRef( const wchar_t& wc )				 { m_ptr.pwc = &wc; m_type = DTR_WCHAR; size=sizeof(wc); }

	BinaryTypeRef( const BaseArray& arr )			 { m_ptr.arr = arr.GetPtr(); m_type = DTR_BASEARRAY; 
														size=arr.GetTotalSize(); elementSize=arr.GetElementSize(); 
														arraySize=arr.GetArraySize(); }
	char* GetAddress();

	DTR_TYPE m_type;

	UNIONPTR m_ptr;

	size_t size;

	size_t elementSize;

	size_t arraySize;
};

}
