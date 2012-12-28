#include "BinaryTypeReadRef.h"


using namespace Elmax;

BinaryTypeReadRef::~BinaryTypeReadRef(void)
{
}

char* BinaryTypeReadRef::GetAddress()
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
	case DTR_STRARRAY:
		return (char*)(void*)(m_ptr.psarr);
	case DTR_WSTRARRAY:
		return (char*)(void*)(m_ptr.pwsarr);
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
		return nullptr;
	}

	return nullptr;
}

void BinaryTypeReadRef::DeferredMake()
{
	switch( m_type )
	{
	case DTR_STRARRAY:
		if(deferredMake)
		{
			psarr->MakeNow();
			m_ptr.psarr = psarr->GetPtr(); m_type = DTR_WSTRARRAY; 
			size=psarr->GetTotalSize(); elementSize=psarr->GetElementSize(); arraySize=psarr->GetArraySize();
		}
		break;
	case DTR_WSTRARRAY:
		if(deferredMake)
		{
			pwsarr->MakeNow();
			m_ptr.pwsarr = pwsarr->GetPtr(); m_type = DTR_WSTRARRAY; 
			size=pwsarr->GetTotalSize(); elementSize=pwsarr->GetElementSize(); arraySize=pwsarr->GetArraySize();
		}
		break;
	case DTR_BASEARRAY:
		if(deferredMake)
		{
			pbarr->MakeNow();
			m_ptr.arr = pbarr->GetPtr(); m_type = DTR_WSTRARRAY; 
			size=pbarr->GetTotalSize(); elementSize=pbarr->GetElementSize(); arraySize=pbarr->GetArraySize();
		}
		break;
	default:
		return;
	}

}