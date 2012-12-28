#pragma once

#include <string>
#include <vector>
#include "../../Common/Common.h"

namespace Elmax
{

class xStringBuilder
{
public:
	xStringBuilder(void);
	xStringBuilder(size_t capcity);
	xStringBuilder(const std::wstring& other);
	xStringBuilder(const xStringBuilder& other);
	~xStringBuilder(void);

	xStringBuilder& operator=(const std::wstring& other);
	xStringBuilder& operator=(const xStringBuilder& other);

	void Init(size_t capcity);
	void Init(const xStringBuilder& other);
	void Destroy();

	void SwapCurrPtr();

	void ReplaceAll(const std::wstring& find, const std::wstring& replace);
	void ReplaceFirst(const std::wstring& find, const std::wstring& replace);
	void ReplaceLast(const std::wstring& find, const std::wstring& replace);
	void Prepend(const std::wstring& other);
	void Append(const std::wstring& other);
	std::vector<size_t> Find(const std::wstring& find);

	std::wstring ToString();
	size_t size();
	size_t length();
	size_t capacity();

	const wchar_t* c_str();

private:
	void CopyCurrToDest(size_t start, size_t len, size_t startDest);
	void CopyStrToDest(const std::wstring copy, size_t startDest);

	wchar_t* a;
	wchar_t* b;

	size_t sizeA;
	size_t sizeB;
	size_t* sizeCurr;
	size_t* sizeDest;

	size_t lenA;
	size_t lenB;
	size_t* lenCurr;
	size_t* lenDest;

	wchar_t** curr;
	wchar_t** dest;


};

}
