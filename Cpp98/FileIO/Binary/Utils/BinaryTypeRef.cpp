#define _VS2005_
#if _MSC_VER < 1400
#undef _VS2005_
#endif
#include "BinaryTypeRef.h"
using namespace Elmax;

BinaryTypeRef::~BinaryTypeRef(void)
{
}

char* BinaryTypeRef::GetAddress()
{
	switch( m_type )
	{
	case DTR_INT:
		return (char*)(void*)(m_ptr.pi);
	case DTR_UINT:
		return (char*)(void*)(m_ptr.pui);
#ifdef __APPLE__
	case DTR_SIZE_T:
		return (char*)(void*)(m_ptr.psizet);
#endif
	case DTR_SHORT:
		return (char*)(void*)(m_ptr.psi);
	case DTR_USHORT:
		return (char*)(void*)(m_ptr.pusi);
	case DTR_FLOAT:
		return (char*)(void*)(m_ptr.pf);
	case DTR_DOUBLE:
		return (char*)(void*)(m_ptr.pd);
	case DTR_STR:
		return (char*)(void*)(m_ptr.ps->c_str());
	case DTR_WSTR:
		return (char*)(void*)(m_ptr.pws->c_str());
	case DTR_BASEARRAY:
		return (char*)(void*)(m_ptr.arr);
	case DTR_INT64:
		return (char*)(void*)(m_ptr.pi64);
	case DTR_UINT64:
		return (char*)(void*)(m_ptr.pui64);
	case DTR_CHAR:
		return (char*)(void*)(m_ptr.pc);
	case DTR_UCHAR:
		return (char*)(void*)(m_ptr.puc);
	case DTR_WCHAR:
		return (char*)(void*)(m_ptr.pwc);
	default:
		return NULL;
	}

	return NULL;
}


