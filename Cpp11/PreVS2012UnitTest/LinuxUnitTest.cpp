// LinuxUnitTest.cpp : Defines the entry point for the console application.
//


#include <string>
#include "Assert.h"
#include "CustomStruct.h"

#include "../FileIO/Common/Common.h"

#include "../FileIO/Text/Writer/AsciiWriter.h"
#include "../FileIO/Text/Reader/AsciiReader.h"

#include "../FileIO/Text/Writer/UnicodeWriter.h"
#include "../FileIO/Text/Reader/UnicodeReader.h"

#include "../FileIO/Text/Writer/BEUnicodeWriter.h"
#include "../FileIO/Text/Reader/BEUnicodeReader.h"

#include "../FileIO/Text/Writer/UTF8Writer.h"
#include "../FileIO/Text/Reader/UTF8Reader.h"

#include "../FileIO/Text/Writer/UTF32Writer.h"
#include "../FileIO/Text/Reader/UTF32Reader.h"

#include "../FileIO/Text/Writer/UTF32BEWriter.h"
#include "../FileIO/Text/Reader/UTF32BEReader.h"

#include "../FileIO/Text/Utils/StrtokStrategy.h"

#include "../FileIO/Binary/Writer/xBinaryWriter.h"
#include "../FileIO/Binary/Reader/xBinaryReader.h"

#include "../FileIO/Text/Writer/xTextWriter.h"
#include "../FileIO/Text/Reader/xTextReader.h"

#include "../FileIO/Text/Utils/StrUtil.h"

#include "../FileIO/UTF16Utils/utf16.h"
#include "../FileIO/Common/RAII_Array.h"

#include <cstdio>

bool FolderExists(const std::wstring& Path)
{
	return true;
}

std::wstring GetTempPath(const std::wstring& file)
{
	std::wstring folder = L"temp/";
	std::wstring fullpath = folder + file;
	return fullpath;
}

std::string GetTempPathA(const std::string& file)
{
	std::string folder = "temp/";
	std::string fullpath = folder + file;
	return fullpath;
}

void Ascii()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	AsciiWriter writer;
	std::wstring file = GetTempPath(L"ascii.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	AsciiReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}
void UTF8()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF8Writer writer;
	std::wstring file = GetTempPath(L"utf8.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UTF8Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}
void UTF32()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF32Writer writer;
	std::wstring file = GetTempPath(L"utf32.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UTF32Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}
void UTF32BE()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF32BEWriter writer;
	std::wstring file = GetTempPath(L"utf32be.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UTF32BEReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}
void Unicode()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UnicodeWriter writer;
	std::wstring file = GetTempPath(L"unicode.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UnicodeReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}
void BEUnicode()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	BEUnicodeWriter writer;
	std::wstring file = GetTempPath(L"beunicode.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	BEUnicodeReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}

void AsciiReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	AsciiWriter writer;
	std::wstring file = GetTempPath(L"asciiReadAll.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	AsciiReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);
		std::wstring readText = line1;
		readText += L"\n";
		readText += line2;
		readText += L"\n";

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(readText, text, L"Text is not the same");
	}
	reader.Close();
}
void UTF8ReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF8Writer writer;
	std::wstring file = GetTempPath(L"utf8ReadAll.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UTF8Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);
		std::wstring readText = line1;
		readText += L"\n";
		readText += line2;
		readText += L"\n";

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(readText, text, L"Text is not the same");
	}
	reader.Close();
}
void UTF32ReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF32Writer writer;
	std::wstring file = GetTempPath(L"utf32ReadAll.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UTF32Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);
		std::wstring readText = line1;
		readText += L"\n";
		readText += line2;
		readText += L"\n";

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(readText, text, L"Text is not the same");
	}
	reader.Close();
}
void UTF32BEReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF32BEWriter writer;
	std::wstring file = GetTempPath(L"utf32BEReadAll.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UTF32BEReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);
		std::wstring readText = line1;
		readText += L"\n";
		readText += line2;
		readText += L"\n";

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(readText, text, L"Text is not the same");
	}
	reader.Close();
}
void UnicodeReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UnicodeWriter writer;
	std::wstring file = GetTempPath(L"UnicodeReadAll.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UnicodeReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);
		std::wstring readText = line1;
		readText += L"\n";
		readText += line2;
		readText += L"\n";

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(readText, text, L"Text is not the same");
	}
	reader.Close();
}

void BEUnicodeReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	BEUnicodeWriter writer;
	std::wstring file = GetTempPath(L"BeUnicodeReadAll.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	BEUnicodeReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);
		std::wstring readText = line1;
		readText += L"\n";
		readText += line2;
		readText += L"\n";

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(readText, text, L"Text is not the same");
	}
	reader.Close();
}

void UTF8ReadAll2()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF8Writer writer;
	std::wstring file = GetTempPath(L"utf8ReadAll2.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring str = L"Hello My Friend!";
	std::wstring line2 = L"How are you?";
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0x1d10b;
	str += ch3;
	str += line2;
	writer.Write(str);
	writer.Flush();
	writer.Close();

	UTF8Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(str, text, L"Text is not the same");
	}
	reader.Close();
}
void UTF32ReadAll2()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF32Writer writer;
	std::wstring file = GetTempPath(L"utf32ReadAll2.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring str = L"Hello My Friend!";
	std::wstring line2 = L"How are you?";
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0xd834;
	str += ch3;
	wchar_t ch4 = 0xdd0b;
	str += ch4;
	str += line2;
	writer.Write(str);
	writer.Flush();
	writer.Close();

	UTF32Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(str, text, L"Text is not the same");
	}
	reader.Close();
}
void UTF32BEReadAll2()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF32BEWriter writer;
	std::wstring file = GetTempPath(L"utf32BEReadAll2.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring str = L"Hello My Friend!";
	std::wstring line2 = L"How are you?";
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0xd834;
	str += ch3;
	wchar_t ch4 = 0xdd0b;
	str += ch4;
	str += line2;
	writer.Write(str);
	writer.Flush();
	writer.Close();

	UTF32BEReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(str, text, L"Text is not the same");
	}
	reader.Close();
}
void UnicodeReadAll2()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UnicodeWriter writer;
	std::wstring file = GetTempPath(L"UnicodeReadAll2.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring str = L"Hello My Friend!";
	std::wstring line2 = L"How are you?";
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0x1d10b;
	str += ch3;
	str += line2;
	writer.Write(str);
	writer.Flush();
	writer.Close();

	UnicodeReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(str, text, L"Text is not the same");
	}
	reader.Close();
}

void BEUnicodeReadAll2()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	BEUnicodeWriter writer;
	std::wstring file = GetTempPath(L"BeUnicodeReadAll2.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring str = L"Hello My Friend!";
	std::wstring line2 = L"How are you?";
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0x1d10b;
	str += ch3;
	str += line2;
	writer.Write(str);
	writer.Flush();
	writer.Close();

	BEUnicodeReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadAll(text);

		Assert::AreEqual(true, b, L"Cannot read all");
		Assert::AreEqual(str, text, L"Text is not the same");
	}
	reader.Close();
}

void AsciiNewline()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	AsciiWriter writer;
	std::wstring file = GetTempPath(L"asciiNewline.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello\nMy Friend!";
	std::wstring split1 = L"Hello";
	std::wstring split2 = L"My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	AsciiReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split2, text, L"2nd line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"3rd line is not the same");
	}
	reader.Close();
}
void UTF8Newline()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF8Writer writer;
	std::wstring file = GetTempPath(L"utf8Newline.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello\nMy Friend!";
	std::wstring split1 = L"Hello";
	std::wstring split2 = L"My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UTF8Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split2, text, L"2nd line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"3rd line is not the same");
	}
	reader.Close();
}
void UTF32Newline()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF32Writer writer;
	std::wstring file = GetTempPath(L"utf32Newline.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello\nMy Friend!";
	std::wstring split1 = L"Hello";
	std::wstring split2 = L"My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UTF32Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split2, text, L"2nd line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"3rd line is not the same");
	}
	reader.Close();
}
void UTF32BENewline()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UTF32BEWriter writer;
	std::wstring file = GetTempPath(L"utf32BENewline.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello\nMy Friend!";
	std::wstring split1 = L"Hello";
	std::wstring split2 = L"My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UTF32BEReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split2, text, L"2nd line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"3rd line is not the same");
	}
	reader.Close();
}
void UnicodeNewline()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	UnicodeWriter writer;
	std::wstring file = GetTempPath(L"unicodeNewline.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello\nMy Friend!";
	std::wstring split1 = L"Hello";
	std::wstring split2 = L"My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	UnicodeReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split2, text, L"2nd line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"3rd line is not the same");
	}
	reader.Close();
}
void BEUnicodeNewline()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	BEUnicodeWriter writer;
	std::wstring file = GetTempPath(L"beunicodeNewline.txt");
	Assert::AreEqual(true, writer.Open(file, NEW), L"File cannot be opened for writing!");
	std::wstring line1 = L"Hello\nMy Friend!";
	std::wstring split1 = L"Hello";
	std::wstring split2 = L"My Friend!";
	writer.WriteLine(line1);
	std::wstring line2 = L"How are you?";
	writer.WriteLine(line2);
	writer.Flush();
	writer.Close();

	BEUnicodeReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(split2, text, L"2nd line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"3rd line is not the same");
	}
	reader.Close();
}
void BinaryPOD()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xBinaryWriter writer;
	std::wstring file = GetTempPath(L"binaryPOD.bin");
	Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.69;
	writer.Write(i, d);
	writer.Close();

	xBinaryReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;
		size_t totalRead = reader.Read(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void BinaryWString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xBinaryWriter writer;
	std::wstring file = GetTempPath(L"binaryWString.bin");
	Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
	std::wstring str = L"Coding Monkey";
	double d = 1254.69;
	writer.Write(str.size(), str, d);
	writer.Close();

	xBinaryReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		size_t i2 = 0;
		double d2 = 0.0;
		WStrArray arr;
		size_t totalRead = reader.Read(i2);
		Assert::AreEqual((size_t)(1), totalRead, L"1 value is not read!");
		Assert::AreEqual(str.size(), i2, L"Integer values are not the same");
		totalRead = reader.Read(arr.MakeArray(i2), d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");
		std::wstring str2 = arr.GetPtr();
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void BinaryDeferredMakeWString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xBinaryWriter writer;
	std::wstring file = GetTempPath(L"binaryDeferredMakeWString.bin");
	Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
	std::wstring str = L"Coding Monkey";
	double d = 1254.69;
	writer.Write(str.size(), str, d);
	writer.Close();

	xBinaryReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		size_t i2 = 0;
		double d2 = 0.0;
		WStrArray arr;
		size_t totalRead = reader.Read(i2, arr.DeferredMake(i2), d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(str.size(), i2, L"Integer values are not the same");
		std::wstring str2 = arr.GetPtr();
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void BinaryString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xBinaryWriter writer;
	std::wstring file = GetTempPath(L"binaryString.bin");
	Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
	std::string str = "Coding Monkey";
	double d = 1254.69;
	writer.Write(str.size(), str, d);
	writer.Close();

	xBinaryReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		size_t i2 = 0;
		double d2 = 0.0;
		StrArray arr;
		size_t totalRead = reader.Read(i2);
		Assert::AreEqual((size_t)(1), totalRead, L"1 value is not read!");
		Assert::AreEqual(str.size(), i2, L"Integer values are not the same");
		totalRead = reader.Read(arr.MakeArray(i2), d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");
		std::string str2 = arr.GetPtr();
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void BinaryDeferredMakeString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xBinaryWriter writer;
	std::wstring file = GetTempPath(L"binaryDeferredMakeString.bin");
	Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
	std::string str = "Coding Monkey";
	double d = 1254.69;
	writer.Write(str.size(), str, d);
	writer.Close();

	xBinaryReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		size_t i2 = 0;
		double d2 = 0.0;
		StrArray arr;
		size_t totalRead = reader.Read(i2, arr.DeferredMake(i2), d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(str.size(), i2, L"Integer values are not the same");
		std::string str2 = arr.GetPtr();
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void BinaryBaseArray()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"binaryBaseArray.bin");
	double d = 1254.69;
	int arr[5];
	arr[0] = 123;
	arr[1] = 124;
	arr[2] = 125;
	arr[3] = 126;
	arr[4] = 127;
	{
		xBinaryWriter writer;
		Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
		BaseArray barr;
		barr.SetPtr((char*)arr, sizeof(int), sizeof(arr)/sizeof(int));
		writer.Write(sizeof(arr), &barr, d);
		writer.Close();
	}
	xBinaryReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		size_t i2 = 0;
		double d2 = 0.0;
		size_t totalRead = reader.Read(i2);
		Assert::AreEqual((size_t)(1), totalRead, L"1 value is not read!");
		BaseArray arr2;
		totalRead = reader.Read(arr2.MakeArray(i2), d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		char* ptr1 = (char*)arr;
		char* ptr2 = arr2.GetPtr();
		for(size_t i=0; i<i2; ++i)
			Assert::AreEqual(ptr1[i], ptr2[i], L"Integer values are not the same");

		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void BinaryDeferredMakeBaseArray()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"binaryDeferredMakeBaseArray.bin");
	double d = 1254.69;
	int arr[5];
	arr[0] = 123;
	arr[1] = 124;
	arr[2] = 125;
	arr[3] = 126;
	arr[4] = 127;
	{
		xBinaryWriter writer;
		Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
		BaseArray barr;
		barr.SetPtr((char*)arr, sizeof(int), sizeof(arr)/sizeof(int));
		writer.Write(sizeof(arr), &barr, d);
		writer.Close();
	}
	xBinaryReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		size_t i2 = 0;
		double d2 = 0.0;
		BaseArray arr2;
		size_t totalRead = reader.Read(i2, arr2.DeferredMake(i2), d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");

		char* ptr1 = (char*)arr;
		char* ptr2 = arr2.GetPtr();
		for(size_t i=0; i<i2; ++i)
			Assert::AreEqual(ptr1[i], ptr2[i], L"Integer values are not the same");

		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextAsciiPOD()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textAsciiPOD.txt");
	Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.Write(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF8POD()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8POD.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.Write(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32POD()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32POD.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.Write(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32BEPOD()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32BEPOD.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.Write(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUnicodePOD()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUnicodePOD.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.Write(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextBEUnicodePOD()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textBEUnicodePOD.txt");
	Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.Write(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextAsciiPODWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textAsciiPODWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.WriteLine(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF8PODWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8PODWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.WriteLine(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32PODWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32PODWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.WriteLine(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32BEPODWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32BEPODWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.WriteLine(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUnicodePODWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUnicodePODWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.WriteLine(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextBEUnicodePODWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textBEUnicodePODWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.WriteLine(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextAsciiWString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textAsciiWString.txt");
	Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF8WString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8WString.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32WString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32WString.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32BEWString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32BEWString.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUnicodeWString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUnicodeWString.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextBEUnicodeWString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textBEUnicodeWString.txt");
	Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextAsciiWStringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textAsciiWStringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");

		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF8WStringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8WStringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32WStringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32WStringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32BEWStringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32BEWStringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUnicodeWStringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUnicodeWStringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextBEUnicodeWStringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textBEUnicodeWStringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextAsciiString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textAsciiString.txt");
	Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF8String()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8String.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32String()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32String.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32BEString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32BEString.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUnicodeString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUnicodeString.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextBEUnicodeString()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textBEUnicodeString.txt");
	Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextAsciiStringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textAsciiStringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF8StringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8StringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32StringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32StringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF32BEStringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF32BEStringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUnicodeStringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUnicodeStringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextBEUnicodeStringWriteLine()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textBEUnicodeStringWriteLine.txt");
	Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::string str = "Coding Monkey";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::string str2 = "";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}

void TextAllOtherTypes()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"TextAllOtherTypes.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	char c = 118;
	unsigned char uc = 176;
	short s = 15670;
	unsigned short us = 40597;
	unsigned int ui = 3569858236;
	ELMAX_INT64 i64 = 35698582368L;
	unsigned ELMAX_INT64 ui64 = 36693588379L;
	float f = 1254.5f;
	writer.WriteLine(L"{0},{1},{2},{3},{4},{5},{6},{7}", c, uc, s, us, ui, i64, ui64, f);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		char c2 = 0;
		unsigned char uc2 = 0;
		short s2 = 0;
		unsigned short us2 = 0;
		unsigned int ui2 = 0;
		ELMAX_INT64 i642 = 0L;
		unsigned ELMAX_INT64 ui642 = 0L;
		float f2 = 0.0f;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(c2, uc2, s2, us2, ui2, i642, ui642, f2);
		Assert::AreEqual((size_t)(8), totalRead, L"8 values are not read!");
		Assert::AreEqual(c, c2, L"Char values are not the same");
		Assert::AreEqual(uc, uc2, L"Unsigned char values are not the same");
		Assert::AreEqual(s, s2, L"short values are not the same");
		Assert::AreEqual(us, us2, L"Unsigned short values are not the same");
		Assert::AreEqual(ui, ui2, L"Unsigned Integer values are not the same");
		Assert::AreEqual(i64, i642, L"64 bit Integer values are not the same");
		Assert::AreEqual(ui64, ui642, L"Unsigned 64 bit Integer values are not the same");
		Assert::AreEqual(f, f2, L"Float values are not the same");
	}
	reader.Close();
}

void BinaryAllOtherTypes()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xBinaryWriter writer;
	std::wstring file = GetTempPath(L"BinaryAllOtherTypes.bin");
	Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
	char c = 118;
	unsigned char uc = 176;
	short s = 15670;
	unsigned short us = 40597;
	unsigned int ui = 3569858236;
	ELMAX_INT64 i64 = 35698582368L;
	unsigned ELMAX_INT64 ui64 = 36693588379L;
	float f = 1254.5f;
	writer.Write(c, uc, s, us, ui, i64, ui64, f);
	writer.Close();

	xBinaryReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		char c2 = 0;
		unsigned char uc2 = 0;
		short s2 = 0;
		unsigned short us2 = 0;
		unsigned int ui2 = 0;
		ELMAX_INT64 i642 = 0L;
		unsigned ELMAX_INT64 ui642 = 0L;
		float f2 = 0.0f;

		size_t totalRead = reader.Read(c2, uc2, s2, us2, ui2, i642, ui642, f2);
		Assert::AreEqual((size_t)(8), totalRead, L"8 values are not read!");
		Assert::AreEqual(c, c2, L"Char values are not the same");
		Assert::AreEqual(uc, uc2, L"Unsigned char values are not the same");
		Assert::AreEqual(s, s2, L"Short values are not the same");
		Assert::AreEqual(us, us2, L"Unsigned short values are not the same");
		Assert::AreEqual(ui, ui2, L"Unsigned Integer values are not the same");
		Assert::AreEqual(i64, i642, L"64 bit Integer values are not the same");
		Assert::AreEqual(ui64, ui642, L"Unsigned 64 bit Integer values are not the same");
		Assert::AreEqual(f, f2, L"Float values are not the same");
	}
	reader.Close();
}

void Trim()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;

	std::wstring orig = L"\tGood morning  \n\r";
	std::wstring trimmedCorrect = L"Good morning";

	std::wstring trimmed = StrUtil::Trim(orig);

	Assert::AreEqual(trimmedCorrect, trimmed, L"String values are not the same");
}

void ReplaceAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;

	std::wstring orig = L",.Good,.morning,.friend,.";
	std::wstring replacedCorrect = L"LKGoodLKmorningLKfriendLK";

	std::wstring replaced = StrUtil::ReplaceAll(orig, L",.", L"LK");

	Assert::AreEqual(replacedCorrect, replaced, L"String values are not the same");
}

void BinaryPODSeek()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xBinaryWriter writer;
	std::wstring file = GetTempPath(L"binaryPODSeek.bin");
	Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	short sh = 1516;
	writer.Write(i, d, sh);
	writer.Close();

	xBinaryReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		short sh2 = 0;
		size_t totalRead = reader.Read(i2);
		Assert::AreEqual((size_t)(1), totalRead, L"1 values are not read!");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		reader.Seek(8, SEEK_CUR);
		totalRead = reader.Read(sh2);
		Assert::AreEqual((size_t)(1), totalRead, L"1 value is not read!");
		Assert::AreEqual(sh, sh2, L"Short values are not the same");
	}
	reader.Close();
}

void TextFileMismatched()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textFileMismatched.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	writer.Write(L"{0},{1}", i, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file, FT_BEUNICODE), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, d2);
		Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}

void TextUnicodeUTF16()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUnicodeUTF16.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Hello";
	wchar_t ch1 = 0x007a;
	str += ch1;
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0x1d10b;
	str += ch3;
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}

void TextBEUnicodeUTF16()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textBEUnicodeUTF16.txt");
	Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Hello";
	wchar_t ch1 = 0x007a;
	str += ch1;
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0x1d10b;
	str += ch3;
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}

void TextUnicodeUTF16Line()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUnicodeUTF16Line.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Hello";
	wchar_t ch1 = 0x007a;
	str += ch1;
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0x1d10b;
	str += ch3;
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}

void TextBEUnicodeUTF16Line()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textBEUnicodeUTF16Line.txt");
	Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Hello";
	wchar_t ch1 = 0x007a;
	str += ch1;
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0x1d10b;
	str += ch3;
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}

void TextUTF8UTF16()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8UTF16.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Hello";
	wchar_t ch1 = 0x007a;
	str += ch1;
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0x1d10b;
	str += ch3;
	writer.Write(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}

void TextUTF8UTF16Line()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8UTF16Line.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Hello";
	wchar_t ch1 = 0x007a;
	str += ch1;
	wchar_t ch2 = 0x6c34;
	str += ch2;
	wchar_t ch3 = 0x1d10b;
	str += ch3;
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}

void TextUTF8NoBOM()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8NoBOM.txt");
	Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	std::wstring str = L"Hello";
	writer.WriteLine(L"{0},{1},{2}", i, str, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file, FT_UTF8), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		std::wstring str2 = L"";
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		size_t totalRead = reader.ReadLine(i2, str2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(str, str2, L"String values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}

void AsciiCarriageReturn()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"asciiCarriageReturn.txt");
	std::wstring line1 = L"Hello My Friend!";
	std::wstring line2 = L"How are you?";

	std::string fileA = GetTempPathA("asciiCarriageReturn.txt");
	FILE* fp = std::fopen(fileA.c_str(), "wb");
	std::string line1A = "Hello My Friend!\r\n";
	fwrite((void*)(line1A.c_str()), 1, line1A.size(), fp);
	std::string line2A = "How are you?\r\n";
	fwrite((void*)(line2A.c_str()), 1, line2A.size(), fp);
	fflush(fp);
	fclose(fp);
	fp = NULL;

	AsciiReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}

void UTF8CarriageReturn()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"utf8CarriageReturn.txt");
	std::wstring line1 = L"Hello My Friend!";
	std::wstring line2 = L"How are you?";

	std::string fileA = GetTempPathA("utf8CarriageReturn.txt");
	FILE* fp = std::fopen(fileA.c_str(), "wb");
	// write BOM 1st.
	unsigned char bom[3] = { 0xEF, 0xBB, 0xBF };
	fwrite( bom, 1, 3, fp );
	std::string line1A = "Hello My Friend!\r\n";
	fwrite((void*)(line1A.c_str()), 1, line1A.size(), fp);
	std::string line2A = "How are you?\r\n";
	fwrite((void*)(line2A.c_str()), 1, line2A.size(), fp);
	fflush(fp);
	fclose(fp);
	fp = NULL;


	UTF8Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}

void UTF32CarriageReturn()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"utf32CarriageReturn.txt");
	std::wstring line1 = L"Hello My Friend!";
	std::wstring line2 = L"How are you?";

	std::string fileA = GetTempPathA("utf32CarriageReturn.txt");
	FILE* fp = std::fopen(fileA.c_str(), "wb");
	// write BOM 1st.
	unsigned char bom[4] = { 0xFF, 0xFE, 0x0, 0x0 };
	fwrite( bom, 1, 4, fp );
	std::wstring line1A = L"Hello My Friend!\r\n";
	fwrite((void*)(line1A.c_str()), 4, line1A.size(), fp);
	std::wstring line2A = L"How are you?\r\n";
	fwrite((void*)(line2A.c_str()), 4, line2A.size(), fp);
	fflush(fp);
	fclose(fp);
	fp = NULL;


	UTF32Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}

void UTF32BECarriageReturn()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"utf32beCarriageReturn.txt");
	std::wstring line1 = L"Hello My Friend!";
	std::wstring line2 = L"How are you?";

	std::string fileA = GetTempPathA("utf32beCarriageReturn.txt");
	FILE* fp = std::fopen(fileA.c_str(), "wb");
	// write BOM 1st.
	unsigned char bom[4] = { 0x0, 0x0, 0xFE, 0xFF  };
	fwrite( bom, 1, 4, fp );
	std::wstring line1A = L"Hello My Friend!\r\n";
	std::vector<unsigned int> vec;
	utf16::ConvertToUTF32BE(line1A, vec);
	fwrite((void*)(&vec[0]), 4, vec.size(), fp);

	std::wstring line2A = L"How are you?\r\n";
	vec.clear();
	utf16::ConvertToUTF32BE(line2A, vec);
	fwrite((void*)(&vec[0]), 4, vec.size(), fp);
	fflush(fp);
	fclose(fp);
	fp = NULL;


	UTF32BEReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}

void UnicodeCarriageReturn()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"unicodeCarriageReturn.txt");
	std::wstring line1 = L"Hello My Friend!";
	std::wstring line2 = L"How are you?";
	std::wstring line1n = L"Hello My Friend!\r\n";
	std::wstring line2n = L"How are you?\r\n";

	std::string fileA = GetTempPathA("unicodeCarriageReturn.txt");
	FILE* fp = std::fopen(fileA.c_str(), "wb");
	// write BOM 1st.
	unsigned char bom[2] = { 0xFF, 0xFE };
	fwrite( bom, 1, 2, fp );

	size_t arrLen = 0;
	utf16::ContainsUpperPlane(line1n, arrLen);
	RAII_Array<unsigned short> sh1 = utf16::ConvertToUTF16(line1n, arrLen);
	fwrite((void*)(sh1.GetPtr()), 2, arrLen, fp);
	utf16::ContainsUpperPlane(line2n, arrLen);
	RAII_Array<unsigned short> sh2 = utf16::ConvertToUTF16(line2n, arrLen);
	fwrite((void*)(sh2.GetPtr()), 2, arrLen, fp);
	fflush(fp);
	fclose(fp);
	fp = NULL;


	UnicodeReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 1st line");
		Assert::AreEqual(line1, text, L"1st line is not the same");
	}
	eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		std::wstring text = L"";
		bool b = reader.ReadLine(text);
		Assert::AreEqual(true, b, L"Cannot read 2nd line");
		Assert::AreEqual(line2, text, L"2nd line is not the same");
	}
	reader.Close();
}

void AsciiCarriageReturnReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"asciiCarriageReturnReadAll.txt");
	std::wstring line1 = L"Hello My Friend!";

	std::string fileA = GetTempPathA("asciiCarriageReturnReadAll.txt");
	FILE* fp = std::fopen(fileA.c_str(), "wb");
	std::string line1A = "Hello My Friend!\r";
	fwrite((void*)(line1A.c_str()), 1, line1A.size(), fp);
	fflush(fp);
	fclose(fp);
	fp = NULL;

	AsciiReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	std::wstring text = L"";
	bool b = reader.ReadAll(text);
	Assert::AreEqual(true, b, L"Cannot read all");
	Assert::AreEqual(line1, text, L"1st line is not the same");
	reader.Close();
}

void UTF8CarriageReturnReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"utf8CarriageReturnReadAll.txt");
	std::wstring line1 = L"Hello My Friend!";

	std::string fileA = GetTempPathA("utf8CarriageReturnReadAll.txt");
	FILE* fp = std::fopen(fileA.c_str(), "wb");
	// write BOM 1st.
	unsigned char bom[3] = { 0xEF, 0xBB, 0xBF };
	fwrite( bom, 1, 3, fp );
	std::string line1A = "Hello My Friend!\r";
	fwrite((void*)(line1A.c_str()), 1, line1A.size(), fp);
	fflush(fp);
	fclose(fp);
	fp = NULL;


	UTF8Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	std::wstring text = L"";
	bool b = reader.ReadAll(text);
	Assert::AreEqual(true, b, L"Cannot read all");
	Assert::AreEqual(line1, text, L"1st line is not the same");
	reader.Close();
}

void UTF32CarriageReturnReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"utf32CarriageReturnReadAll.txt");
	std::wstring line1 = L"Hello My Friend!";

	std::string fileA = GetTempPathA("utf32CarriageReturnReadAll.txt");
	FILE* fp = std::fopen(fileA.c_str(), "wb");
	// write BOM 1st.
	unsigned char bom[4] = { 0xFF, 0xFE, 0x0, 0x0 };
	fwrite( bom, 1, 4, fp );
	std::wstring line1A = L"Hello My Friend!";
	line1A += L'\r';
	fwrite((void*)(line1A.c_str()), 4, line1A.size(), fp);
	fflush(fp);
	fclose(fp);
	fp = NULL;


	UTF32Reader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	std::wstring text = L"";
	bool b = reader.ReadAll(text);
	Assert::AreEqual(true, b, L"Cannot read all");
	Assert::AreEqual(line1, text, L"1st line is not the same");
	reader.Close();
}

void UTF32BECarriageReturnReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"utf32beCarriageReturnReadAll.txt");
	std::wstring line1 = L"Hello My Friend!";

	std::string fileA = GetTempPathA("utf32beCarriageReturnReadAll.txt");
	FILE* fp = std::fopen(fileA.c_str(), "wb");
	// write BOM 1st.
	unsigned char bom[4] = {  0x0, 0x0, 0xFE, 0xFF };
	fwrite( bom, 1, 4, fp );
	std::wstring line1A = L"Hello My Friend!";
	line1A += L'\r';
	std::vector<unsigned int> vec;
	utf16::ConvertToUTF32BE(line1A, vec);
	fwrite((void*)(&vec[0]), 4, vec.size(), fp);
	fflush(fp);
	fclose(fp);
	fp = NULL;

	UTF32BEReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	std::wstring text = L"";
	bool b = reader.ReadAll(text);
	Assert::AreEqual(true, b, L"Cannot read all");
	Assert::AreEqual(line1, text, L"1st line is not the same");
	reader.Close();
}

void UnicodeCarriageReturnReadAll()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	std::wstring file = GetTempPath(L"unicodeCarriageReturnReadAll.txt");
	std::wstring line1 = L"Hello My Friend!";
	std::wstring line1r = L"Hello My Friend!\r";

	std::string fileA = GetTempPathA("unicodeCarriageReturnReadAll.txt");
	FILE* fp = std::fopen(fileA.c_str(), "wb");
	// write BOM 1st.
	unsigned char bom[2] = { 0xFF, 0xFE };
	fwrite( bom, 1, 2, fp );

	size_t arrLen = 0;
	utf16::ContainsUpperPlane(line1r, arrLen);
	RAII_Array<unsigned short> sh1 = utf16::ConvertToUTF16(line1r, arrLen);
	fwrite((void*)(sh1.GetPtr()), 2, arrLen, fp);
	fflush(fp);
	fclose(fp);
	fp = NULL;


	UnicodeReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	std::wstring text = L"";
	bool b = reader.ReadAll(text);
	Assert::AreEqual(true, b, L"Cannot read all");
	Assert::AreEqual(line1, text, L"1st line is not the same");

	reader.Close();
}
void TextAsciiStruct()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textAsciiStruct.txt");
	Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	MyStruct my = { 22, 33 };
	writer.Write(L"{0},{1},{2}", i, my, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		MyStruct my2 = { 0, 0 };
		size_t totalRead = reader.ReadLine(i2, my2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(my2.a, my.a, L"MyStruct.a values are not the same");
		Assert::AreEqual(my2.b, my.b, L"MyStruct.b values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextAsciiDiffDelimiterStruct()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textAsciiDiffDelimiterStruct.txt");
	Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	DiffDelimiterStruct my = { 22, 33 };
	writer.Write(L"{0},{1},{2}", i, my, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		DiffDelimiterStruct my2 = { 0, 0 };
		size_t totalRead = reader.ReadLine(i2, my2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(my2.a, my.a, L"DiffDelimiterStruct.a values are not the same");
		Assert::AreEqual(my2.b, my.b, L"DiffDelimiterStruct.b values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUnicodeStruct()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUnicodeStruct.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	MyStruct my = { 22, 33 };
	writer.Write(L"{0},{1},{2}", i, my, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		MyStruct my2 = { 0, 0 };
		size_t totalRead = reader.ReadLine(i2, my2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(my2.a, my.a, L"MyStruct.a values are not the same");
		Assert::AreEqual(my2.b, my.b, L"MyStruct.b values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUnicodeDiffDelimiterStruct()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUnicodeDiffDelimiterStruct.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	DiffDelimiterStruct my = { 22, 33 };
	writer.Write(L"{0},{1},{2}", i, my, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		DiffDelimiterStruct my2 = { 0, 0 };
		size_t totalRead = reader.ReadLine(i2, my2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(my2.a, my.a, L"DiffDelimiterStruct.a values are not the same");
		Assert::AreEqual(my2.b, my.b, L"DiffDelimiterStruct.b values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextBEUnicodeStruct()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textBEUnicodeStruct.txt");
	Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	MyStruct my = { 22, 33 };
	writer.Write(L"{0},{1},{2}", i, my, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		MyStruct my2 = { 0, 0 };
		size_t totalRead = reader.ReadLine(i2, my2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(my2.a, my.a, L"MyStruct.a values are not the same");
		Assert::AreEqual(my2.b, my.b, L"MyStruct.b values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextBEUnicodeDiffDelimiterStruct()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textBEUnicodeDiffDelimiterStruct.txt");
	Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	DiffDelimiterStruct my = { 22, 33 };
	writer.Write(L"{0},{1},{2}", i, my, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		DiffDelimiterStruct my2 = { 0, 0 };
		size_t totalRead = reader.ReadLine(i2, my2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(my2.a, my.a, L"DiffDelimiterStruct.a values are not the same");
		Assert::AreEqual(my2.b, my.b, L"DiffDelimiterStruct.b values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF8Struct()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8Struct.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	MyStruct my = { 22, 33 };
	writer.Write(L"{0},{1},{2}", i, my, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		MyStruct my2 = { 0, 0 };
		size_t totalRead = reader.ReadLine(i2, my2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(my2.a, my.a, L"MyStruct.a values are not the same");
		Assert::AreEqual(my2.b, my.b, L"MyStruct.b values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}
void TextUTF8DiffDelimiterStruct()
{
	Assert::FunctionName = __FUNCTION__;

	using namespace Elmax;
	xTextWriter writer;
	std::wstring file = GetTempPath(L"textUTF8DiffDelimiterStruct.txt");
	Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
	int i = 25698;
	double d = 1254.5;
	DiffDelimiterStruct my = { 22, 33 };
	writer.Write(L"{0},{1},{2}", i, my, d);
	writer.Close();

	xTextReader reader;
	Assert::AreEqual(true, reader.Open(file), L"File cannot be opened for reading!");
	bool eof = reader.IsEOF();
	Assert::AreEqual(false, eof, L"EOF is reached prematurely!");
	if(eof==false)
	{
		int i2 = 0;
		double d2 = 0.0;

		reader.SetDelimiter(L",");
		DiffDelimiterStruct my2 = { 0, 0 };
		size_t totalRead = reader.ReadLine(i2, my2, d2);
		Assert::AreEqual((size_t)(3), totalRead, L"3 values are not read");
		Assert::AreEqual(i, i2, L"Integer values are not the same");
		Assert::AreEqual(my2.a, my.a, L"DiffDelimiterStruct.a values are not the same");
		Assert::AreEqual(my2.b, my.b, L"DiffDelimiterStruct.b values are not the same");
		Assert::AreEqual(d, d2, L"Double values are not the same");
	}
	reader.Close();
}

int main(int argc, char* argv[])
{
	using namespace std;
	try
	{
		Ascii();
		cout<<"Ascii"<<endl;
		UTF8();
		cout<<"UTF8"<<endl;
		UTF32();
		cout<<"UTF32"<<endl;
		UTF32BE();
		cout<<"UTF32BE"<<endl;
		Unicode();
		cout<<"Unicode"<<endl;
		BEUnicode();
		cout<<"BEUnicode"<<endl;
		AsciiNewline();
		cout<<"AsciiNewline"<<endl;
		UTF8Newline();
		cout<<"UTF8Newline"<<endl;
		UTF32Newline();
		cout<<"UTF32Newline"<<endl;
		UTF32BENewline();
		cout<<"UTF32BENewline"<<endl;
		UnicodeNewline();
		cout<<"UnicodeNewline"<<endl;
		BEUnicodeNewline();
		cout<<"BEUnicodeNewline"<<endl;
		BinaryPOD();
		cout<<"BinaryPOD"<<endl;
		BinaryWString();
		cout<<"BinaryWString"<<endl;
		BinaryDeferredMakeWString();
		cout<<"BinaryDeferredMakeWString"<<endl;
		BinaryString();
		cout<<"BinaryString"<<endl;
		BinaryDeferredMakeString();
		cout<<"BinaryDeferredMakeString"<<endl;
		BinaryBaseArray();
		cout<<"BinaryBaseArray"<<endl;
		BinaryDeferredMakeBaseArray();
		cout<<"BinaryDeferredMakeBaseArray"<<endl;
		TextAsciiPOD();
		cout<<"TextAsciiPOD"<<endl;
		TextUTF8POD();
		cout<<"TextUTF8POD"<<endl;
		TextUTF32POD();
		cout<<"TextUTF32POD"<<endl;
		TextUTF32BEPOD();
		cout<<"TextUTF32BEPOD"<<endl;
		TextUnicodePOD();
		cout<<"TextUnicodePOD"<<endl;
		TextBEUnicodePOD();
		cout<<"TextBEUnicodePOD"<<endl;
		TextAsciiPODWriteLine();
		cout<<"TextAsciiPODWriteLine"<<endl;
		TextUTF8PODWriteLine();
		cout<<"TextUTF8PODWriteLine"<<endl;
		TextUTF32PODWriteLine();
		cout<<"TextUTF32PODWriteLine"<<endl;
		TextUTF32BEPODWriteLine();
		cout<<"TextUTF32BEPODWriteLine"<<endl;
		TextUnicodePODWriteLine();
		cout<<"TextUnicodePODWriteLine"<<endl;
		TextBEUnicodePODWriteLine();
		cout<<"TextBEUnicodePODWriteLine"<<endl;
		TextAsciiWString();
		cout<<"TextAsciiWString"<<endl;
		TextUTF8WString();
		cout<<"TextUTF8WString"<<endl;
		TextUTF32WString();
		cout<<"TextUTF32WString"<<endl;
		TextUTF32BEWString();
		cout<<"TextUTF32BEWString"<<endl;
		TextUnicodeWString();
		cout<<"TextUnicodeWString"<<endl;
		TextBEUnicodeWString();
		cout<<"TextBEUnicodeWString"<<endl;
		TextAsciiWStringWriteLine();
		cout<<"TextAsciiWStringWriteLine"<<endl;
		TextUTF8WStringWriteLine();
		cout<<"TextUTF8WStringWriteLine"<<endl;
		TextUTF32WStringWriteLine();
		cout<<"TextUTF32WStringWriteLine"<<endl;
		TextUTF32BEWStringWriteLine();
		cout<<"TextUTF32BEWStringWriteLine"<<endl;
		TextUnicodeWStringWriteLine();
		cout<<"TextUnicodeWStringWriteLine"<<endl;
		TextBEUnicodeWStringWriteLine();
		cout<<"TextBEUnicodeWStringWriteLine"<<endl;
		TextAsciiString();
		cout<<"TextAsciiString"<<endl;
		TextUTF8String();
		cout<<"TextUTF8String"<<endl;
		TextUTF32String();
		cout<<"TextUTF32String"<<endl;
		TextUTF32BEString();
		cout<<"TextUTF32BEString"<<endl;
		TextUnicodeString();
		cout<<"TextUnicodeString"<<endl;
		TextBEUnicodeString();
		cout<<"TextBEUnicodeString"<<endl;
		TextAsciiStringWriteLine();
		cout<<"TextAsciiStringWriteLine"<<endl;
		TextUTF8StringWriteLine();
		cout<<"TextUTF8StringWriteLine"<<endl;
		TextUTF32StringWriteLine();
		cout<<"TextUTF32StringWriteLine"<<endl;
		TextUTF32BEStringWriteLine();
		cout<<"TextUTF32BEStringWriteLine"<<endl;
		TextUnicodeStringWriteLine();
		cout<<"TextUnicodeStringWriteLine"<<endl;
		TextBEUnicodeStringWriteLine();
		cout<<"TextBEUnicodeStringWriteLine"<<endl;
		TextAllOtherTypes();
		cout<<"TextAllOtherTypes"<<endl;
		BinaryAllOtherTypes();
		cout<<"BinaryAllOtherTypes"<<endl;
		Trim();
		cout<<"Trim"<<endl;
		ReplaceAll();
		cout<<"ReplaceAll"<<endl;
		BinaryPODSeek();
		cout<<"BinaryPODSeek"<<endl;
		TextFileMismatched();
		cout<<"TextFileMismatched"<<endl;
		TextUnicodeUTF16();
		cout<<"TextUnicodeUTF16"<<endl;
		TextBEUnicodeUTF16();
		cout<<"TextBEUnicodeUTF16"<<endl;
		TextUnicodeUTF16Line();
		cout<<"TextUnicodeUTF16Line"<<endl;
		TextBEUnicodeUTF16Line();
		cout<<"TextBEUnicodeUTF16Line"<<endl;
		TextUTF8UTF16();
		cout<<"TextUTF8UTF16"<<endl;
		TextUTF8UTF16Line();
		cout<<"TextUTF8UTF16Line"<<endl;
		TextUTF8NoBOM();
		cout<<"TextUTF8NoBOM"<<endl;
		AsciiReadAll();
		cout<<"AsciiReadAll"<<endl;
		UTF8ReadAll();
		cout<<"UTF8ReadAll"<<endl;
		UTF32ReadAll();
		cout<<"UTF32ReadAll"<<endl;
		UTF32BEReadAll();
		cout<<"UTF32BEReadAll"<<endl;
		UnicodeReadAll();
		cout<<"UnicodeReadAll"<<endl;
		BEUnicodeReadAll();
		cout<<"BEUnicodeReadAll"<<endl;
		UTF8ReadAll2();
		cout<<"UTF8ReadAll2"<<endl;
		UTF32ReadAll2();
		cout<<"UTF32ReadAll2"<<endl;
		UTF32BEReadAll2();
		cout<<"UTF32BEReadAll2"<<endl;
		UnicodeReadAll2();
		cout<<"UnicodeReadAll2"<<endl;
		BEUnicodeReadAll2();
		cout<<"BEUnicodeReadAll2"<<endl;
		AsciiCarriageReturn();
		cout<<"AsciiCarriageReturn"<<endl;
		UTF8CarriageReturn();
		cout<<"UTF8CarriageReturn"<<endl;
		UTF32CarriageReturn();
		cout<<"UTF32CarriageReturn"<<endl;
		UTF32BECarriageReturn();
		cout<<"UTF32BECarriageReturn"<<endl;
		UnicodeCarriageReturn();
		cout<<"UnicodeCarriageReturn"<<endl;
		AsciiCarriageReturnReadAll();
		cout<<"AsciiCarriageReturnReadAll"<<endl;
		UTF8CarriageReturnReadAll();
		cout<<"UTF8CarriageReturnReadAll"<<endl;
		UTF32CarriageReturnReadAll();
		cout<<"UTF32CarriageReturnReadAll"<<endl;
		UTF32BECarriageReturnReadAll();
		cout<<"UTF32BECarriageReturnReadAll"<<endl;
		UnicodeCarriageReturnReadAll();
		cout<<"UnicodeCarriageReturnReadAll"<<endl;

		TextAsciiStruct();
		cout<<"TextAsciiStruct"<<endl;
		TextAsciiDiffDelimiterStruct();
		cout<<"TextAsciiDiffDelimiterStruct"<<endl;
		TextUnicodeStruct();
		cout<<"TextUnicodeStruct"<<endl;
		TextUnicodeDiffDelimiterStruct();
		cout<<"TextUnicodeDiffDelimiterStruct"<<endl;

		TextBEUnicodeStruct();
		cout<<"TextBEUnicodeStruct"<<endl;
		TextBEUnicodeDiffDelimiterStruct();
		cout<<"TextBEUnicodeDiffDelimiterStruct"<<endl;
		TextUTF8Struct();
		cout<<"TextUTF8Struct"<<endl;
		TextUTF8DiffDelimiterStruct();
		cout<<"TextUTF8DiffDelimiterStruct"<<endl;
		
		cout<<"All unit tests passed!"<<endl;
	}
	catch (std::runtime_error& e)
	{
		std::cout<<"Runtime error: "<<e.what()<< std::endl;
	}
	catch (std::logic_error& e)
	{
		std::cout<<"Logic error: "<<e.what()<< std::endl;
	}
	catch (std::exception& e)
	{
		std::cout<<"Exception error: "<<e.what()<< std::endl;
	}

	std::cout<<"Ended"<<std::endl;

	return 0;
}



