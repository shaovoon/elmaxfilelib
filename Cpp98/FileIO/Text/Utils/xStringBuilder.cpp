#include "xStringBuilder.h"

#define CAPACITY 100

using namespace Elmax;

xStringBuilder::xStringBuilder(void)
{
	Init(CAPACITY);
}

void xStringBuilder::Init(size_t capacity)
{
	a = new wchar_t[capacity+1];
	b = new wchar_t[capacity+1];

	memset(a, 0, (capacity+1)*sizeof(wchar_t));
	memset(b, 0, (capacity+1)*sizeof(wchar_t));

	curr = &a;
	dest = &b;

	sizeA = capacity;
	sizeB = capacity;
	sizeCurr = &sizeA;
	sizeDest = &sizeB;

	lenA = 0;
	lenB = 0;
	lenCurr = &lenA;
	lenDest = &lenB;
}

void xStringBuilder::Init(const xStringBuilder& other)
{
	a = new wchar_t[other.sizeA+1];
	b = new wchar_t[other.sizeB+1];

	memset(a, 0, other.sizeA+1);
	memset(b, 0, other.sizeB+1);

	Wcscpy(a, other.a, other.sizeA+1);
	Wcscpy(b, other.b, other.sizeB+1);

	if(other.a==(*other.curr))
	{
		curr = &a;
		dest = &b;

		sizeA = other.sizeA;
		sizeB = other.sizeB;
		sizeCurr = &sizeA;
		sizeDest = &sizeB;

		lenA = other.lenA;
		lenB = other.lenB;
		lenCurr = &lenA;
		lenDest = &lenB;
	}
	else
	{
		curr = &b;
		dest = &a;

		sizeA = other.sizeA;
		sizeB = other.sizeB;
		sizeCurr = &sizeB;
		sizeDest = &sizeA;

		lenA = other.lenA;
		lenB = other.lenB;
		lenCurr = &lenB;
		lenDest = &lenA;
	}

}

void xStringBuilder::Destroy()
{
	if(a!=NULL)
	{
		memset(a, 0, sizeA+1);
		delete [] a;
		a = NULL;
	}

	if(b!=NULL)
	{
		memset(b, 0, sizeB+1);
		delete [] b;
		b = NULL;
	}

	sizeA = 0;
	sizeB = 0;

	lenA = 0;
	lenB = 0;
}

xStringBuilder::xStringBuilder(size_t capacity)
{
	Init(capacity);
}

xStringBuilder::xStringBuilder(const std::wstring& other)
{
	size_t len = other.length();
	Init(len*2);
	wchar_t* curr1 = *curr;

	Wcscpy(curr1, other.c_str(), (*sizeCurr)+1);
	(*lenCurr) = other.length();
}

xStringBuilder::xStringBuilder(const xStringBuilder& other)
{
	Init(other);
}

xStringBuilder::~xStringBuilder(void)
{
	Destroy();
}

xStringBuilder& xStringBuilder::operator=(const std::wstring& other)
{
	size_t len = other.length()*2;
	Init(len*2);
	wchar_t* curr1 = *curr;

	Wcscpy(curr1, other.c_str(), (*sizeCurr)+1);
	(*lenCurr) = other.length();

	return *this;
}

xStringBuilder& xStringBuilder::operator=(const xStringBuilder& other)
{
	Init(other);
	return *this;
}

void xStringBuilder::SwapCurrPtr()
{
	if(*curr==a)
	{
		curr = &b;
		dest = &a;

		sizeCurr = &sizeB;
		sizeDest = &sizeA;

		lenCurr = &lenB;
		lenDest = &lenA;
	}
	else
	{
		curr = &a;
		dest = &b;

		sizeCurr = &sizeA;
		sizeDest = &sizeB;

		lenCurr = &lenA;
		lenDest = &lenB;
	}
}

void xStringBuilder::ReplaceAll(const std::wstring& find, const std::wstring& replace)
{
	std::vector<size_t> vec = Find(find);

	if(vec.size()<=0)
		return;

	size_t needed = (replace.length()*vec.size()) + (*lenCurr) - (find.length()*vec.size());

	if(needed>=(*sizeDest))
	{
		if(*dest!=NULL)
			delete [] *dest;

		size_t newSize = needed*2;
		*dest = new wchar_t[newSize+1];
		memset(*dest, 0, (newSize+1)*sizeof(wchar_t));

		*lenDest = 0;
		*sizeDest = newSize;
	}

	size_t start = 0;
	size_t startDest = 0;
	for(size_t i=0; i<vec.size(); ++i)
	{
		CopyCurrToDest(start, vec[i]-start, startDest);
		startDest += vec[i] - start;
		CopyStrToDest(replace, startDest);
		startDest += replace.length();
		start += vec[i] - start;
		start += find.length();
	}
	
	size_t lastLen = (*lenCurr)-(start-1);
	CopyCurrToDest(start, lastLen, startDest);
	startDest += lastLen;

	*lenDest = startDest;
	SwapCurrPtr();
}

void xStringBuilder::ReplaceFirst(const std::wstring& find, const std::wstring& replace)
{
	std::vector<size_t> vec = Find(find);

	if(vec.size()<=0)
		return;

	size_t needed = (replace.length()*vec.size()) + (*lenCurr) - (find.length()*vec.size());

	if(needed>=(*sizeDest))
	{
		if(*dest!=NULL)
			delete [] *dest;

		size_t newSize = needed*2;
		*dest = new wchar_t[newSize+1];
		memset(*dest, 0, (newSize+1)*sizeof(wchar_t));

		*lenDest = 0;
		*sizeDest = newSize;
	}

	size_t start = 0;
	size_t startDest = 0;
	CopyCurrToDest(start, vec[0], startDest);
	startDest += vec[0] - start;
	CopyStrToDest(replace, startDest);
	startDest += replace.length();
	start += vec[0] - start;
	start += find.length();

	size_t lastLen = (*lenCurr)-(start-1);
	CopyCurrToDest(start, lastLen, startDest);
	startDest += lastLen;

	*lenDest = startDest;
	SwapCurrPtr();
}

void xStringBuilder::ReplaceLast(const std::wstring& find, const std::wstring& replace)
{
	std::vector<size_t> vec = Find(find);

	if(vec.size()<=0)
		return;

	size_t needed = (replace.length()*vec.size()) + (*lenCurr) - (find.length()*vec.size());

	if(needed>=(*sizeDest))
	{
		if(*dest!=NULL)
			delete [] *dest;

		size_t newSize = needed*2;
		*dest = new wchar_t[newSize+1];
		memset(*dest, 0, (newSize+1)*sizeof(wchar_t));

		*lenDest = 0;
		*sizeDest = newSize;
	}

	size_t start = 0;
	size_t startDest = 0;
	CopyCurrToDest(start, vec[vec.size()-1], startDest);
	startDest += vec[vec.size()-1] - start;
	CopyStrToDest(replace, startDest);
	startDest += replace.length();
	start += vec[vec.size()-1] - start;
	start += find.length();

	size_t lastLen = (*lenCurr)-(start-1);
	CopyCurrToDest(start, lastLen, startDest);
	startDest += lastLen;

	*lenDest = startDest;
	SwapCurrPtr();
}

void xStringBuilder::CopyCurrToDest(size_t start, size_t len, size_t startDest)
{
	for(size_t i=0; i<len; ++i)
	{
		(*dest)[startDest+i] = (*curr)[start+i];
	}
	*lenDest = startDest + len;
}

void xStringBuilder::CopyStrToDest(const std::wstring copy, size_t startDest)
{
	for(size_t i=0; i<copy.length(); ++i)
	{
		(*dest)[startDest+i] = copy[i];
	}
	*lenDest = startDest + copy.length();
}

void xStringBuilder::Prepend(const std::wstring& other)
{
	if(other==L"")
		return;

	if(curr!=NULL&&(*curr)!=NULL)
	{
		size_t needed = (*lenCurr)+other.length();
		if(needed>=(*sizeDest))
		{
			if(*dest!=NULL)
				delete [] *dest;

			size_t newSize = needed*2;
			*dest = new wchar_t[newSize+1];
			memset(*dest, 0, (newSize+1)*sizeof(wchar_t));

			*sizeDest = newSize;
		}

		Wcscpy(*dest, other.c_str(), (*sizeDest)+1);
		*lenDest = other.length();
		wchar_t* dest1 = *dest;
		wchar_t* curr1 = *curr;
		for(size_t i=0; i<(*lenCurr); ++i)
		{
			dest1[(*lenDest)+i] = curr1[i];
		}
		dest1[(*lenDest)+(*lenCurr)] = L'\0';
		*lenDest += (*lenCurr);

		SwapCurrPtr();
	}
}

void xStringBuilder::Append(const std::wstring& other)
{
	if(other==L"")
		return;

	if(curr!=NULL&&(*curr)!=NULL)
	{
		size_t needed = (*lenCurr)+other.length();
		if(needed>=(*sizeDest))
		{
			if(*dest!=NULL)
				delete [] *dest;

			size_t newSize = needed*2;
			*dest = new wchar_t[newSize+1];
			memset(*dest, 0, (newSize+1)*sizeof(wchar_t));

			*sizeDest = newSize;
		}

		Wcscpy(*dest, *curr, (*sizeDest)+1);
		*lenDest = (*lenCurr);
		wchar_t* dest1 = *dest;
		for(size_t i=0; i<other.length(); ++i)
		{
			dest1[(*lenDest)+i] = other[i];
		}
		dest1[(*lenDest)+other.length()] = L'\0';
		*lenDest += other.length();

		SwapCurrPtr();
	}
}

std::vector<size_t> xStringBuilder::Find(const std::wstring& find)
{
	std::vector<size_t> vec;
	if(curr!=NULL&&(*curr)!=NULL)
	{
		bool NotFound = false;
		wchar_t* curr1 = *curr;
		for(size_t i=0; i<*lenCurr; ++i)
		{
			NotFound = false;
			for(size_t j=0; j<find.length(); ++j)
			{
				if(curr1[i+j] != find[j])
				{
					NotFound = true;
					break;
				}
			}
			if(NotFound==false)
				vec.push_back(i);
		}
	}

	return vec;
}

std::wstring xStringBuilder::ToString()
{
	if(*curr == NULL)
		return std::wstring();

	std::wstring str = *curr;
	return str;
}

size_t xStringBuilder::size()
{
	return *lenCurr;
}

size_t xStringBuilder::length()
{
	return *lenCurr;
}

size_t xStringBuilder::capacity()
{
	return *sizeCurr;
}

const wchar_t* xStringBuilder::c_str()
{
	return *curr;
}

