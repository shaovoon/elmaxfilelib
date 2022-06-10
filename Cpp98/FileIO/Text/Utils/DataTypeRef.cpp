#define _VS2005_
#if _MSC_VER < 1400
#undef _VS2005_
#endif
#include "DataTypeRef.h"
#include "../../Common/Common.h"
#include "../../Common/BaseConverter.h"

using namespace Elmax;

DataTypeRef::~DataTypeRef(void)
{
}

bool DataTypeRef::ConvStrToType( const std::wstring& str )
{
	switch( m_type )
	{
	case DTR_INT:
		try
		{
			*(m_ptr.pi) = std::stoi(BaseConverter::ConvToString(str));
		}
		catch (std::exception &)
		{
			*(m_ptr.pi) = -1;
		}
		break;
	case DTR_UINT:
		try
		{
			*(m_ptr.pui) = std::stoul(BaseConverter::ConvToString(str));
		}
		catch (std::exception &)
		{
			*(m_ptr.pui) = 0;
		}

		break;
#ifdef __APPLE__
	case DTR_SIZE_T:
		try
		{
			*(m_ptr.psizet) = std::stoul(BaseConverter::ConvToString(str));
		}
		catch (std::exception &)
		{
			*(m_ptr.psizet) = 0;
		}
		break;
#endif
	case DTR_SHORT:
		try
		{
			*(m_ptr.psi) = static_cast<short>(std::stoi(BaseConverter::ConvToString(str)));
		}
		catch (std::exception &)
		{
			*(m_ptr.psi) = -1;
		}
		break;
	case DTR_USHORT:
		try
		{
			*(m_ptr.pusi) = static_cast<unsigned short>(std::stoul(BaseConverter::ConvToString(str)));
		}
		catch (std::exception &)
		{
			*(m_ptr.pusi) = 0;
		}
		break;
	case DTR_FLOAT:
		try
		{
			*(m_ptr.pf) = std::stof(BaseConverter::ConvToString(str));
		}
		catch (std::exception &)
		{
			*(m_ptr.pf) = 0.0f;
		}
		break;
	case DTR_DOUBLE:
		try
		{
			*(m_ptr.pd) = std::stod(BaseConverter::ConvToString(str));
		}
		catch (std::exception &)
		{
			*(m_ptr.pd) = 0.0;
		}
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
		try
		{
			*(m_ptr.pi64) = std::stoll(BaseConverter::ConvToString(str));
		}
		catch (std::exception &)
		{
			*(m_ptr.pi64) = -1;
		}
		break;
	case DTR_UINT64:
		try
		{
			*(m_ptr.pui64) = std::stoull(BaseConverter::ConvToString(str));
		}
		catch (std::exception &)
		{
			*(m_ptr.pui64) = 0;
		}
		break;
	case DTR_CHAR:
		try
		{
			*(m_ptr.pc) = static_cast<char>(std::stoi(BaseConverter::ConvToString(str)));
		}
		catch (std::exception &)
		{
			*(m_ptr.pc) = '-';
		}
		break;
	case DTR_UCHAR:
		try
		{
			*(m_ptr.puc) = static_cast<unsigned char>(std::stoul(BaseConverter::ConvToString(str)));
		}
		catch (std::exception &)
		{
			*(m_ptr.puc) = '-';
		}
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


