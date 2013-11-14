#include "stdafx.h"
#include "CustomStruct.h"

Elmax::ostream operator <<(Elmax::ostream& os, const MyStruct& val)
{
	std::string temp = boost::lexical_cast<std::string>(val.a);
	std::wstring str = Elmax::BaseConverter::ConvToString(temp);
	str += L",";
	temp = boost::lexical_cast<std::string>(val.b);
	str += Elmax::BaseConverter::ConvToString(temp);
	str += L",";

	os.set_str(os.str() + str);
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
	std::string temp = boost::lexical_cast<std::string>(val.a);
	std::wstring str = Elmax::BaseConverter::ConvToString(temp);
	str += L"|";
	temp = boost::lexical_cast<std::string>(val.b);
	str += Elmax::BaseConverter::ConvToString(temp);
	str += L"|";

	os.set_str(os.str() + str);
	return os;
}

Elmax::istream operator >>(Elmax::istream& is, DiffDelimiterStruct& val)
{
	Elmax::istream new_is(is.str(), L"|");

	new_is >> val.a;
	new_is >> val.b;

	is.set_str(new_is.str());

	return is;
}