#include "../FileIO/Text/Stream/istream.h"
#include "../FileIO/Text/Stream/ostream.h"

struct MyStruct
{
	int a;
	int b;
};

struct DiffDelimiterStruct
{
	int a;
	float b;
};

Elmax::ostream operator <<(Elmax::ostream& os, const MyStruct& val);
Elmax::istream operator >>(Elmax::istream& is, MyStruct& val);
Elmax::ostream operator <<(Elmax::ostream& os, const DiffDelimiterStruct& val);
Elmax::istream operator >>(Elmax::istream& is, DiffDelimiterStruct& val);

