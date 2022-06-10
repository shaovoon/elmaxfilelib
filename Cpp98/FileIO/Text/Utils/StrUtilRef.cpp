#include "../Utils/StrUtilRef.h"
#include "../../Common/BaseConverter.h"
#include <cassert>

using namespace Elmax;

StrUtilRef::StrUtilRef(void)
{
}


StrUtilRef::~StrUtilRef(void)
{
}

std::wstring StrUtilRef::Format( const wchar_t* fmt, DataType& D1 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(1);
	vs.push_back( D1.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtilRef::Format( const wchar_t* fmt, DataType& D1, DataType& D2 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(2);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtilRef::Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(3);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );
	vs.push_back( D3.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtilRef::Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(4);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );
	vs.push_back( D3.ToString() );
	vs.push_back( D4.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtilRef::Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
	DataType& D5 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(5);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );
	vs.push_back( D3.ToString() );
	vs.push_back( D4.ToString() );
	vs.push_back( D5.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtilRef::Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
	DataType& D5, DataType& D6 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(6);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );
	vs.push_back( D3.ToString() );
	vs.push_back( D4.ToString() );
	vs.push_back( D5.ToString() );
	vs.push_back( D6.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtilRef::Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
	DataType& D5, DataType& D6, DataType& D7 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(7);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );
	vs.push_back( D3.ToString() );
	vs.push_back( D4.ToString() );
	vs.push_back( D5.ToString() );
	vs.push_back( D6.ToString() );
	vs.push_back( D7.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtilRef::Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
	DataType& D5, DataType& D6, DataType& D7, DataType& D8 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(8);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );
	vs.push_back( D3.ToString() );
	vs.push_back( D4.ToString() );
	vs.push_back( D5.ToString() );
	vs.push_back( D6.ToString() );
	vs.push_back( D7.ToString() );
	vs.push_back( D8.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtilRef::Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
	DataType& D5, DataType& D6, DataType& D7, DataType& D8, DataType& D9 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(9);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );
	vs.push_back( D3.ToString() );
	vs.push_back( D4.ToString() );
	vs.push_back( D5.ToString() );
	vs.push_back( D6.ToString() );
	vs.push_back( D7.ToString() );
	vs.push_back( D8.ToString() );
	vs.push_back( D9.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtilRef::Format( const wchar_t* fmt, DataType& D1, DataType& D2, DataType& D3, DataType& D4, 
	DataType& D5, DataType& D6, DataType& D7, DataType& D8, DataType& D9, DataType& D10 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(10);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );
	vs.push_back( D3.ToString() );
	vs.push_back( D4.ToString() );
	vs.push_back( D5.ToString() );
	vs.push_back( D6.ToString() );
	vs.push_back( D7.ToString() );
	vs.push_back( D8.ToString() );
	vs.push_back( D9.ToString() );
	vs.push_back( D10.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtilRef::Replace( std::wstring& fmtstr, std::vector<std::wstring>& vs )
{
	size_t pos = 0;
	for( size_t i=0; i<vs.size(); ++i )
	{
		pos = 0;
		std::wstring anchor = Anchor( i );

		while( std::wstring::npos != pos )
		{
			pos = fmtstr.find( anchor, pos );

			if( std::wstring::npos != pos )
			{
				//fmtstr.replace( pos, 1, vs.at(i) );
				fmtstr.erase( pos, anchor.size() );
				fmtstr.insert( pos, vs.at(i) );
				pos += vs.at(i).size();
			}
		}
	}

	return fmtstr;
}

std::wstring StrUtilRef::Anchor( int i )
{
	std::string temp = std::to_string(i);
	std::wstring str2 = BaseConverter::ConvToString(temp);

	std::wstring str = L"{";
	str += str2 + L"}";

	return str;
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1,
	DataTypeRef& D2 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1,
	DataTypeRef& D2,
	DataTypeRef& D3 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);
	vecDTR.push_back(&D21);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);
	vecDTR.push_back(&D21);
	vecDTR.push_back(&D22);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);
	vecDTR.push_back(&D21);
	vecDTR.push_back(&D22);
	vecDTR.push_back(&D23);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);
	vecDTR.push_back(&D21);
	vecDTR.push_back(&D22);
	vecDTR.push_back(&D23);
	vecDTR.push_back(&D24);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);
	vecDTR.push_back(&D21);
	vecDTR.push_back(&D22);
	vecDTR.push_back(&D23);
	vecDTR.push_back(&D24);
	vecDTR.push_back(&D25);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25, 
		DataTypeRef& D26)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);
	vecDTR.push_back(&D21);
	vecDTR.push_back(&D22);
	vecDTR.push_back(&D23);
	vecDTR.push_back(&D24);
	vecDTR.push_back(&D25);
	vecDTR.push_back(&D26);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25, 
		DataTypeRef& D26, DataTypeRef& D27)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);
	vecDTR.push_back(&D21);
	vecDTR.push_back(&D22);
	vecDTR.push_back(&D23);
	vecDTR.push_back(&D24);
	vecDTR.push_back(&D25);
	vecDTR.push_back(&D26);
	vecDTR.push_back(&D27);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25, 
		DataTypeRef& D26, DataTypeRef& D27, DataTypeRef& D28)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);
	vecDTR.push_back(&D21);
	vecDTR.push_back(&D22);
	vecDTR.push_back(&D23);
	vecDTR.push_back(&D24);
	vecDTR.push_back(&D25);
	vecDTR.push_back(&D26);
	vecDTR.push_back(&D27);
	vecDTR.push_back(&D28);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25, 
		DataTypeRef& D26, DataTypeRef& D27, DataTypeRef& D28, DataTypeRef& D29)
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);
	vecDTR.push_back(&D21);
	vecDTR.push_back(&D22);
	vecDTR.push_back(&D23);
	vecDTR.push_back(&D24);
	vecDTR.push_back(&D25);
	vecDTR.push_back(&D26);
	vecDTR.push_back(&D27);
	vecDTR.push_back(&D28);
	vecDTR.push_back(&D29);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtilRef::Split( const std::wstring& StrToExtract, DataTypeRef& D1, DataTypeRef& D2, DataTypeRef& D3, DataTypeRef& D4,
	DataTypeRef& D5, DataTypeRef& D6, DataTypeRef& D7, DataTypeRef& D8, DataTypeRef& D9, DataTypeRef& D10,
		DataTypeRef& D11, DataTypeRef& D12, DataTypeRef& D13, DataTypeRef& D14, DataTypeRef& D15, 
		DataTypeRef& D16, DataTypeRef& D17, DataTypeRef& D18, DataTypeRef& D19, DataTypeRef& D20,
		DataTypeRef& D21, DataTypeRef& D22, DataTypeRef& D23, DataTypeRef& D24, DataTypeRef& D25, 
		DataTypeRef& D26, DataTypeRef& D27, DataTypeRef& D28, DataTypeRef& D29, DataTypeRef& D30 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);
	vecDTR.push_back(&D5);
	vecDTR.push_back(&D6);
	vecDTR.push_back(&D7);
	vecDTR.push_back(&D8);
	vecDTR.push_back(&D9);
	vecDTR.push_back(&D10);
	vecDTR.push_back(&D11);
	vecDTR.push_back(&D12);
	vecDTR.push_back(&D13);
	vecDTR.push_back(&D14);
	vecDTR.push_back(&D15);
	vecDTR.push_back(&D16);
	vecDTR.push_back(&D17);
	vecDTR.push_back(&D18);
	vecDTR.push_back(&D19);
	vecDTR.push_back(&D20);
	vecDTR.push_back(&D21);
	vecDTR.push_back(&D22);
	vecDTR.push_back(&D23);
	vecDTR.push_back(&D24);
	vecDTR.push_back(&D25);
	vecDTR.push_back(&D26);
	vecDTR.push_back(&D27);
	vecDTR.push_back(&D28);
	vecDTR.push_back(&D29);
	vecDTR.push_back(&D30);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}
