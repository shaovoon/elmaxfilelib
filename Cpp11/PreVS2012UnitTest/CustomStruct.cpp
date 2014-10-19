#include "CustomStruct.h"

Elmax::ostream operator <<(Elmax::ostream& os, const MyStruct& val)
{
	os << val.a;
	os << L",";
	os << val.b;
	os << L",";

	return os;
}

Elmax::istream operator >>(Elmax::istream& is, MyStruct& val)
{
	is >> val.a;
	is >> val.b;

	return is;
}

Elmax::ostream operator <<(Elmax::ostream& os, const DiffDelimiterStruct& val)
{
	os << val.a;
	os << L"|";
	os << val.b;
	os << L"|";

	return os;
}

Elmax::istream operator >>(Elmax::istream& is, DiffDelimiterStruct& val)
{
	std::wstring old_delimiter = is.set_delimiter(L"|");

	is >> val.a;
	is >> val.b;

	is.set_delimiter(old_delimiter);

	return is;
}

