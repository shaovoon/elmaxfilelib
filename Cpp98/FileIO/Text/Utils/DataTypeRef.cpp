#define _VS2005_
#if _MSC_VER < 1400
#undef _VS2005_
#endif
#include "DataTypeRef.h"
#include "../../Common/BaseConverter.h"
#include "../../Common/Common.h"
using namespace Elmax;

DataTypeRef::~DataTypeRef(void)
{
}

bool DataTypeRef::ConvStrToType( const std::wstring& str )
{
	BaseConverter conv;

	switch( m_type )
	{
	case DTR_INT:
		conv.GetInt32(str, *(m_ptr.pi));
		break;
	case DTR_UINT:
		conv.GetUInt32(str, *(m_ptr.pui));
		break;
#ifdef __APPLE__
	case DTR_SIZE_T:
		conv.GetSizeT(str, *(m_ptr.psizet));
		break;
#endif
	case DTR_SHORT:
		conv.GetInt16(str, *(m_ptr.psi));
		break;
	case DTR_USHORT:
		conv.GetUInt16(str, *(m_ptr.pusi));
		break;
	case DTR_FLOAT:
		conv.GetFloat(str, *(m_ptr.pf));
		break;
	case DTR_DOUBLE:
		conv.GetDouble(str, *(m_ptr.pd));
		break;
	case DTR_STR:
		{
#ifdef _VS2005_
				RAII_Array<char> pBuf(str.size()+1);
				if( NULL == pBuf.GetPtr() )
					return false;
				size_t RetSize=0;
				errno_t err = wcstombs_s( &RetSize, pBuf.GetPtr(), str.size()+1, str.c_str(), str.size()+1 );

				if( 0 != err )
					return false;

				*(m_ptr.ps)=pBuf.GetPtr();
#else // _VS2005_
				RAII_Array<char> pBuf(str.size()+1);
				if( NULL == pBuf.GetPtr() )
					return false;
				wcstombs( pBuf.GetPtr(), str.c_str(), str.size()+1 );

				*(m_ptr.ps)=pBuf.GetPtr();
#endif // _VS2005_
		}

		break;
	case DTR_WSTR:
		*(m_ptr.pws) = str;
		break;
	case DTR_INT64:
		conv.GetInt64(str, *(m_ptr.pi64));
		break;
	case DTR_UINT64:
		conv.GetUInt64(str, *(m_ptr.pui64));
		break;
	case DTR_CHAR:
		conv.GetInt8(str, *(m_ptr.pc));
		break;
	case DTR_UCHAR:
		conv.GetUInt8(str, *(m_ptr.puc));
		break;
	case DTR_WCHAR:
		if( str.size() > 0 )
			*(m_ptr.pwc) = str.at(0);
		break;
	default:
		return false;
	}

	return true;
}


