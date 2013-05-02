#include "UTF8Reader.h"
#include "../../UTF8Utils/utf8.h"
#include "../Utils/StrUtil.h"
#include <vector>

using namespace Elmax;

#define VECTOR_RESERVE 50000

UTF8Reader::UTF8Reader(void)
	: pos(0)
{
}

UTF8Reader::UTF8Reader(const std::wstring& file)
	: pos(0)
{
	Open(file);
}

UTF8Reader::~UTF8Reader(void)
{
}

bool UTF8Reader::IsValid(const std::wstring& file)
{
	FILE* f = FileOpen(file, L"rb");

	if(f==nullptr)
		return false;

	unsigned char tt[3] = {0,0,0};

	fseek( f, 0, SEEK_SET );

	fread( tt, 1, 3, f );

	if( tt[0] != 0xEF || tt[1] != 0xBB || tt[2] != 0xBF )
	{
		fclose( f );

		return false; // not a unicode file
	}

	fclose( f );

	return true;
}

void UTF8Reader::ReadBOM()
{
	if(fp==nullptr)
		return;

	unsigned char tt[3] = {0,0,0};

	fseek( fp, 0, SEEK_SET );

	fread( tt, 1, 3, fp );

	if( tt[0] != 0xEF || tt[1] != 0xBB || tt[2] != 0xBF ) // not the correct BOM, so reset the pos to beginning (file might not have BOM)
	{
		fseek( fp, 0, SEEK_SET );
		hasBOM = false;
	}
	else
		hasBOM = true;
}

bool UTF8Reader::Open(const std::wstring& file)
{
	filename = file;

	fp = FileOpen(file, L"rb");

	if(fp == nullptr)
	{
		errNum = ELMAX_FILE_NOT_OPENED;
		err = GetErrorMsg(errNum);
	}

	if(fp!=nullptr)
	{
		ReadBOM();
		bool b = ReadAll(allText);
		Close();
		return b;
	}

	return fp != nullptr;
}

bool UTF8Reader::Read( std::wstring& text, size_t len )
{
	text = L"";
	if((pos+len) < (allText.size()-1))
	{
		text = allText.substr(pos, len);
		pos = pos+len;
	}
	else if(pos < (allText.size()-1))
	{
		text = allText.substr(pos, allText.size()-pos);
		pos = pos+len;
	}
	else
		return false;

	return true;
}

bool UTF8Reader::ReadAll( std::wstring& text )
{
	size_t size = GetFileSize(filename);

	if(allText.size()>0)
	{
		if(pos < (allText.size()-1))
		{
			text = allText.substr(pos, allText.size()-pos);
			pos = size-1;
			return true;
		}
		else
			return false;
	}

	if(size==0)
		return false;

	if(fp == nullptr)
		return false;

	if(pos==0)
	{
		if(hasBOM)
			size -= 3;

		RAII_Array<char> buf(size+1);

		size_t lenRead = fread(buf.GetPtr(), 1, size, fp);
		if(lenRead!=size)
		{
			errNum = ELMAX_READ_ERROR;
			std::wstring str = StrUtil::Format(L": Read {0} bytes out of {1} required!", lenRead, size);
			err = GetErrorMsg(errNum) + str;

			throw std::runtime_error(StrUtil::ConvToString(err));

			return false;
		}


#ifdef _MICROSOFT
		std::vector<unsigned short> utf16line;
		utf16line.reserve(size+1);
		utf8::utf8to16(buf.GetPtr(), buf.GetPtr()+(size+1), back_inserter(utf16line));

		text = L"";
		for(size_t i=0; i<utf16line.size(); ++i)
		{
			if(utf16line[i]!=L'\r'&&utf16line[i]!=L'\0')
				text += utf16line[i];
		}
#else
		if(sizeof(wchar_t)==4)
		{
			std::vector<unsigned int> utf32line;
			utf32line.reserve(size+1);
			utf8::utf8to32(buf.GetPtr(), buf.GetPtr()+(size+1), back_inserter(utf32line));
			text = L"";
			for(size_t i=0; i<utf32line.size(); ++i)
			{
				if(utf32line[i]!=L'\r'&&utf32line[i]!=L'\0')
					text += utf32line[i];
			}
		}
		else
		{
			std::vector<unsigned short> utf16line;
			utf16line.reserve(size+1);
			utf8::utf8to16(buf.GetPtr(), buf.GetPtr()+(size+1), back_inserter(utf16line));
			text = L"";
			for(size_t i=0; i<utf16line.size(); ++i)
			{
				if(utf16line[i]!=L'\r'&&utf16line[i]!=L'\0')
					text += utf16line[i];
			}
		}
#endif
	}
	else if(pos < (allText.size()-1))
	{
		text = allText.substr(pos, allText.size()-pos);
		pos = size-1;
	}
	else
		return false;

	return true;
}

bool UTF8Reader::ReadLine( std::wstring& text )
{
	text = L"";
	if(pos < (allText.size()-1))
	{
		size_t i=0;
		for( i=pos; i<allText.size(); ++i)
		{
			wchar_t ch = allText[i];
			if(ch!=L'\r'&&ch!=L'\n')
				text += ch;

			if(ch==L'\n')
			{
				pos = i+1;
				break;
			}
		}

		if(i>=allText.size())
			pos = allText.size() - 1;

		return true;
	}

	return false;
}

bool UTF8Reader::IsEOF()
{
	return pos >= allText.size();
}
