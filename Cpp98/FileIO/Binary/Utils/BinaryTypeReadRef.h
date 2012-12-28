#pragma once

#include "../../Common/Common.h"
#include "BaseArray.h"
#include "StrArray.h"
#include "WStrArray.h"

namespace Elmax
{

class BinaryTypeReadRef
{
public:
	~BinaryTypeReadRef(void);

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
		char* psarr;
		wchar_t* pwsarr;
		char* pc;
		unsigned char* puc;
		wchar_t* pwc;
		char* arr;
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
		DTR_STRARRAY,
		DTR_WSTRARRAY,
		DTR_CHAR,
		DTR_UCHAR,
		DTR_WCHAR,
		DTR_BASEARRAY
	} ;

	BinaryTypeReadRef( int& i )						 { InitDeferred(); m_ptr.pi = &i; m_type = DTR_INT; size=sizeof(i); }

	BinaryTypeReadRef( unsigned int& ui )			 { InitDeferred(); m_ptr.pui = &ui; m_type = DTR_UINT; size=sizeof(ui); }

#ifdef __APPLE__
	BinaryTypeReadRef( size_t& ui )					 { InitDeferred(); m_ptr.psizet = &ui; m_type = DTR_SIZE_T; size=sizeof(size_t); }
#endif

	BinaryTypeReadRef( short& si )					 { InitDeferred(); m_ptr.psi = &si; m_type = DTR_SHORT; size=sizeof(si); }

	BinaryTypeReadRef( unsigned short& usi )		 { InitDeferred(); m_ptr.pusi = &usi; m_type = DTR_USHORT; size=sizeof(usi); }

	BinaryTypeReadRef( ELMAX_INT64& i64 )				 { InitDeferred(); m_ptr.pi64 = &i64; m_type = DTR_INT64; size=sizeof(i64); }

	BinaryTypeReadRef( unsigned ELMAX_INT64& ui64 )		 { InitDeferred(); m_ptr.pui64 = &ui64; m_type = DTR_UINT64; size=sizeof(ui64); }

	BinaryTypeReadRef( float& f )					 { InitDeferred(); m_ptr.pf = &f; m_type = DTR_FLOAT; size=sizeof(f); }

	BinaryTypeReadRef( double& d )					 { InitDeferred(); m_ptr.pd = &d; m_type = DTR_DOUBLE; size=sizeof(d); }

	BinaryTypeReadRef( StrArray& sarr )				 { InitDeferred(); deferredMake = sarr.IsDeferredMake(); psarr = &sarr; m_ptr.psarr = sarr.GetPtr(); m_type = DTR_STRARRAY; 
														size=sarr.GetTotalSize(); elementSize=sarr.GetElementSize(); arraySize=sarr.GetArraySize(); }

	BinaryTypeReadRef( WStrArray& wsarr )			 { InitDeferred(); deferredMake = wsarr.IsDeferredMake(); pwsarr = &wsarr; m_ptr.pwsarr = wsarr.GetPtr(); m_type = DTR_WSTRARRAY; 
														size=wsarr.GetTotalSize(); elementSize=wsarr.GetElementSize(); arraySize=wsarr.GetArraySize(); }

	BinaryTypeReadRef( char& c )					 { InitDeferred(); m_ptr.pc = &c; m_type = DTR_CHAR; size=sizeof(c); }

	BinaryTypeReadRef( unsigned char& uc )			 { InitDeferred(); m_ptr.puc = &uc; m_type = DTR_UCHAR; size=sizeof(uc); }

	BinaryTypeReadRef( wchar_t& wc )				 { InitDeferred(); m_ptr.pwc = &wc; m_type = DTR_WCHAR; size=sizeof(wc); }

	BinaryTypeReadRef( BaseArray& barr )			 { InitDeferred(); deferredMake = barr.IsDeferredMake(); pbarr = &barr; m_ptr.arr = barr.GetPtr(); m_type = DTR_BASEARRAY; 
													   size=barr.GetTotalSize(); elementSize=barr.GetElementSize(); arraySize=barr.GetArraySize(); }

	char* GetAddress();

	void DeferredMake();

	DTR_TYPE m_type;

	UNIONPTR m_ptr;

	size_t size;

	size_t elementSize;

	size_t arraySize;

	void InitDeferred()
	{
		deferredMake = false;

		pwsarr = NULL;
		psarr = NULL;
		pbarr = NULL;
	}

	bool deferredMake;

	WStrArray* pwsarr;

	StrArray* psarr;

	BaseArray* pbarr;

};

}
