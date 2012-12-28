#include "../Utils/StrUtil.h"
#include "../../Common/BaseConverter.h"
#include <cassert>

using namespace Elmax;

StrUtil::StrUtil(void)
{
}


StrUtil::~StrUtil(void)
{
}

std::wstring StrUtil::Format( const wchar_t* fmt, DataType D1 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(1);
	vs.push_back( D1.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtil::Format( const wchar_t* fmt, DataType D1, DataType D2 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(2);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtil::Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3 )
{
	std::wstring wsfmtstr = fmt;

	std::vector<std::wstring> vs;
	vs.reserve(3);
	vs.push_back( D1.ToString() );
	vs.push_back( D2.ToString() );
	vs.push_back( D3.ToString() );

	return Replace( wsfmtstr, vs );
}

std::wstring StrUtil::Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4 )
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

std::wstring StrUtil::Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
	DataType D5 )
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

std::wstring StrUtil::Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
	DataType D5, DataType D6 )
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

std::wstring StrUtil::Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
	DataType D5, DataType D6, DataType D7 )
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

std::wstring StrUtil::Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
	DataType D5, DataType D6, DataType D7, DataType D8 )
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

std::wstring StrUtil::Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
	DataType D5, DataType D6, DataType D7, DataType D8, DataType D9 )
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

std::wstring StrUtil::Format( const wchar_t* fmt, DataType D1, DataType D2, DataType D3, DataType D4, 
	DataType D5, DataType D6, DataType D7, DataType D8, DataType D9, DataType D10 )
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

std::wstring StrUtil::Replace( std::wstring& fmtstr, std::vector<std::wstring>& vs )
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

std::wstring StrUtil::Anchor( int i )
{
	std::wstring str2 = L"";
	BaseConverter conv;

	conv.SetInt32(str2, i);
	std::wstring str = L"{";
	str += str2 + L"}";

	return str;
}

size_t StrUtil::Split( const std::wstring& StrToExtract, DataTypeRef D1 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtil::Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtil::Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2,
	DataTypeRef D3 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtil::Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4 )
{
	std::vector<DataTypeRef*> vecDTR;
	vecDTR.push_back(&D1);
	vecDTR.push_back(&D2);
	vecDTR.push_back(&D3);
	vecDTR.push_back(&D4);

	assert( m_pSplitStrategy );
	return m_pSplitStrategy->Extract( StrToExtract, vecDTR );
}

size_t StrUtil::Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5 )
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

size_t StrUtil::Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6 )
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

size_t StrUtil::Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7 )
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

size_t StrUtil::Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8 )
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

size_t StrUtil::Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9 )
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

size_t StrUtil::Split( const std::wstring& StrToExtract, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10 )
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

std::wstring StrUtil::ReplaceAll(const std::wstring& text, const std::wstring& find, const std::wstring& replace)
{
	std::wstring dest = text;

	size_t pos = 0;
	while (pos != std::wstring::npos)
	{
		pos = dest.find_first_of(find, pos);
		if(pos != std::wstring::npos)
		{
			dest.erase( pos, find.size() );
			dest.insert( pos, replace );
			pos += replace.size();
		}
	} 

	return dest;
}

std::string StrUtil::ConvToString(const std::wstring& text)
{
	std::string str = "";
	for(size_t i=0; i<text.length(); ++i)
	{
		str += (char)(text[i]);
	}

	return str;
}

std::wstring StrUtil::ConvToWString(const std::string& text)
{
	std::wstring str = L"";
	for(size_t i=0; i<text.length(); ++i)
	{
		str += (wchar_t)(text[i]);
	}

	return str;
}

std::wstring StrUtil::TrimRight(const std::wstring& str, const std::wstring& trimChars)
{
	std::wstring result = L"";
	// trim trailing spaces
	size_t endpos = str.find_last_not_of(trimChars);
	if( std::wstring::npos != endpos )
	{
		result = str.substr( 0, endpos+1 );
	}
	else
		result = str;

	return result;
}

std::wstring StrUtil::TrimLeft(const std::wstring& str, const std::wstring& trimChars)
{
	std::wstring result = L"";

	// trim leading spaces
	size_t startpos = str.find_first_not_of(trimChars);
	if( std::wstring::npos != startpos )
	{
		result = str.substr( startpos );
	}
	else
		result = str;

	return result;
}

std::wstring StrUtil::Trim(const std::wstring& str, const std::wstring& trimChars)
{
	return TrimLeft(TrimRight(str, trimChars), trimChars);
}
