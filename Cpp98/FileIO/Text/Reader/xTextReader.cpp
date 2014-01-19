#include "xTextReader.h"
#include "../Utils/StrUtilRef.h"

#include "UTF8Reader.h"
#include "UTF32Reader.h"
#include "UTF32BEReader.h"
#include "UnicodeReader.h"
#include "BEUnicodeReader.h"
#include "AsciiReader.h"
#include "../../Common/Enumeration.h"

using namespace Elmax;

xTextReader::xTextReader(void)
	:	pReader(NULL),
		m_pSplitStrategy(NULL)
{
}

xTextReader::~xTextReader(void)
{
	Close();
}

bool xTextReader::Open(const std::wstring& file)
{
	Close();
	if(UTF8Reader::IsValid(file))
	{
		pReader = new UTF8Reader();
		return pReader->Open(file);
	}
	if(UTF32Reader::IsValid(file))
	{
		pReader = new UTF32Reader();
		return pReader->Open(file);
	}
	if(UTF32BEReader::IsValid(file))
	{
		pReader = new UTF32BEReader();
		return pReader->Open(file);
	}
	if(UnicodeReader::IsValid(file))
	{
		pReader = new UnicodeReader();
		return pReader->Open(file);
	}
	if(BEUnicodeReader::IsValid(file))
	{
		pReader = new BEUnicodeReader();
		return pReader->Open(file);
	}
	if(AsciiReader::IsValid(file))
	{
		pReader = new AsciiReader();
		return pReader->Open(file);
	}

	return false;
}

bool xTextReader::Open(const std::wstring& file, FILE_TYPE ftype)
{
	Close();
	if(UTF8Reader::IsValid(file))
	{
		pReader = new UTF8Reader();
		return pReader->Open(file);
	}
	if(UnicodeReader::IsValid(file))
	{
		pReader = new UnicodeReader();
		return pReader->Open(file);
	}
	if(BEUnicodeReader::IsValid(file))
	{
		pReader = new BEUnicodeReader();
		return pReader->Open(file);
	}
	if(UTF32Reader::IsValid(file))
	{
		pReader = new UTF32Reader();
		return pReader->Open(file);
	}
	if(UTF32BEReader::IsValid(file))
	{
		pReader = new UTF32BEReader();
		return pReader->Open(file);
	}
	else
	{
		switch(ftype)
		{
		case FT_UTF8:
			pReader = new UTF8Reader();
			return pReader->Open(file);
			break;
		case FT_UNICODE:
			pReader = new UnicodeReader();
			return pReader->Open(file);
			break;
		case FT_BEUNICODE:
			pReader = new BEUnicodeReader();
			return pReader->Open(file);
			break;
		case FT_ASCII:
			pReader = new AsciiReader();
			return pReader->Open(file);
			break;
		case FT_UTF32:
			pReader = new UTF32Reader();
			return pReader->Open(file);
			break;
		case FT_UTF32BE:
			pReader = new UTF32BEReader();
			return pReader->Open(file);
			break;
		default:
			pReader = new AsciiReader();
			return pReader->Open(file);
			break;
		}
	}

	return false;
}

void xTextReader::Close()
{
	if(pReader != NULL)
	{
		pReader->Close();
		delete pReader;
		pReader = NULL;
	}

	return;
}

bool xTextReader::IsEOF()
{
	if(pReader!=NULL)
	{
		return pReader->IsEOF();
	}

	return true;
}

size_t xTextReader::Read( size_t len, DataTypeRef D1 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->Read(text, len);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1);
		}
	}

	return 0;
}


size_t xTextReader::Read( size_t len, DataTypeRef D1, DataTypeRef D2 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->Read(text, len);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2);
		}
	}

	return 0;
}

size_t xTextReader::Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->Read(text, len);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3);
		}
	}

	return 0;
}


size_t xTextReader::Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->Read(text, len);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4);
		}
	}

	return 0;
}


size_t xTextReader::Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->Read(text, len);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5);
		}
	}

	return 0;
}

size_t xTextReader::Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->Read(text, len);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6);
		}
	}

	return 0;
}

size_t xTextReader::Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->Read(text, len);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7);
		}
	}

	return 0;
}

size_t xTextReader::Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->Read(text, len);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8);
		}
	}

	return 0;
}

size_t xTextReader::Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->Read(text, len);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9);
		}
	}

	return false;
}

size_t xTextReader::Read( size_t len, DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->Read(text, len);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10);
		}
	}
	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2);
		}
	}

	return 0;
}


size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4,
	DataTypeRef D5, DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
	DataTypeRef D21)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20,
				D21);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
	DataTypeRef D21, DataTypeRef D22)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20,
				D21, D22);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
	DataTypeRef D21, DataTypeRef D22, DataTypeRef D23)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20,
				D21, D22, D23);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
	DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20,
				D21, D22, D23, D24);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
	DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20,
				D21, D22, D23, D24, D25);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
	DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25, 
	DataTypeRef D26)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20,
				D21, D22, D23, D24, D25, D26);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
	DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25, 
	DataTypeRef D26, DataTypeRef D27)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20,
				D21, D22, D23, D24, D25, D26, D27);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
	DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25, 
	DataTypeRef D26, DataTypeRef D27, DataTypeRef D28)
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20,
				D21, D22, D23, D24, D25, D26, D27, D28);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
	DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25, 
	DataTypeRef D26, DataTypeRef D27, DataTypeRef D28, DataTypeRef D29 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20,
				D21, D22, D23, D24, D25, D26, D27, D28, D29);
		}
	}

	return 0;
}

size_t xTextReader::ReadLine( DataTypeRef D1, DataTypeRef D2, DataTypeRef D3, DataTypeRef D4, DataTypeRef D5, 
	DataTypeRef D6, DataTypeRef D7, DataTypeRef D8, DataTypeRef D9, DataTypeRef D10,
	DataTypeRef D11, DataTypeRef D12, DataTypeRef D13, DataTypeRef D14, DataTypeRef D15, 
	DataTypeRef D16, DataTypeRef D17, DataTypeRef D18, DataTypeRef D19, DataTypeRef D20,
	DataTypeRef D21, DataTypeRef D22, DataTypeRef D23, DataTypeRef D24, DataTypeRef D25, 
	DataTypeRef D26, DataTypeRef D27, DataTypeRef D28, DataTypeRef D29, DataTypeRef D30 )
{
	if(pReader!=NULL)
	{
		std::wstring text;
		bool b = pReader->ReadLine(text);

		if(b)
		{
			StrUtilRef strUtil;
			strUtil.SetSplitStrategy(m_pSplitStrategy);

			return strUtil.Split(text.c_str(), D1, D2, D3, D4, D5, D6, D7, D8, D9, D10,
				D11, D12, D13, D14, D15, D16, D17, D18, D19, D20,
				D21, D22, D23, D24, D25, D26, D27, D28, D29, D30);
		}
	}

	return 0;
}

bool xTextReader::ReadAll( std::wstring& text )
{
	if(pReader!=NULL)
	{
		return pReader->ReadAll(text);
	}

	return false;
}

int xTextReader::GetLastError(std::wstring& msg)
{
	if(pReader!=NULL)
	{
		return pReader->GetLastError(msg);
	}

	msg = GetErrorMsg(ELMAX_NULL_POINTER);
	return ELMAX_NULL_POINTER;
}


void xTextReader::ClearLastError()
{
	if(pReader!=NULL)
	{
		pReader->ClearLastError();
	}
}

