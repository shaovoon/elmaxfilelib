#include "stdafx.h"
#include "CppUnitTest.h"
#include "CustomStruct.h"

#include <string>
#include <Windows.h>

#include "..\\FileIO\\Text\\Writer\\AsciiWriter.h"
#include "..\\FileIO\\Text\\Reader\\AsciiReader.h"

#include "..\\FileIO\\Text\\Writer\\UnicodeWriter.h"
#include "..\\FileIO\\Text\\Reader\\UnicodeReader.h"

#include "..\\FileIO\\Text\\Writer\\BEUnicodeWriter.h"
#include "..\\FileIO\\Text\\Reader\\BEUnicodeReader.h"

#include "..\\FileIO\\Text\\Writer\\UTF8Writer.h"
#include "..\\FileIO\\Text\\Reader\\UTF8Reader.h"

#include "..\\FileIO\\Text\\Writer\\UTF32Writer.h"
#include "..\\FileIO\\Text\\Reader\\UTF32Reader.h"

#include "..\\FileIO\\Text\\Writer\\UTF32BEWriter.h"
#include "..\\FileIO\\Text\\Reader\\UTF32BEReader.h"

#include "..\\FileIO\\Text\\Utils\\StrtokStrategy.h"

#include "..\\FileIO\\Binary\\Writer\\xBinaryWriter.h"
#include "..\\FileIO\\Binary\\Reader\\xBinaryReader.h"

#include "..\\FileIO\\Text\\Writer\\xTextWriter.h"
#include "..\\FileIO\\Text\\Reader\\xTextReader.h"

#include "..\\FileIO\\Text\\Utils\\StrUtil.h"

#if _MSC_VER == 1800
	#ifdef _DEBUG
		#pragma comment(lib, "..\\Debug\\FileIO_2013.lib")
	#else
		#pragma comment(lib, "..\\Release\\FileIO_2013.lib")
	#endif
#else
	#ifdef _DEBUG
		#pragma comment(lib, "..\\Debug\\FileIO_2012.lib")
	#else
		#pragma comment(lib, "..\\Release\\FileIO_2012.lib")
	#endif
#endif
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		std::wstring GetTempPath(const std::wstring& path)
		{
			/*
			wchar_t buf[MAX_PATH];
			if(::GetTempPathW(MAX_PATH, buf))
			{
				if(FolderExists(buf)==false)
					CreateDirectoryW(buf, NULL);

				std::wstring str = buf;
				if( str.length() > 0 && str.at(str.length()-1) != L'\\' )
					str += L"\\";

				str += path;

				return str;
			}

			return L"";
			*/

			return std::wstring(L"c:\\temp\\") + path;
		}
		
		bool FolderExists(const std::wstring& Path)
		{
			DWORD dwAttrib = GetFileAttributes(Path.c_str());

			return (dwAttrib != INVALID_FILE_ATTRIBUTES && 
				(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
		}

		TEST_METHOD(Ascii)
		{
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
		TEST_METHOD(UTF8)
		{
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
		TEST_METHOD(UTF32)
		{
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
		TEST_METHOD(UTF32BE)
		{
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
		TEST_METHOD(Unicode)
		{
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
		TEST_METHOD(BEUnicode)
		{
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

		TEST_METHOD(AsciiReadAll)
		{
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
		TEST_METHOD(UTF8ReadAll)
		{
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
		TEST_METHOD(UTF32ReadAll)
		{
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
		TEST_METHOD(UTF32BEReadAll)
		{
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
		TEST_METHOD(UnicodeReadAll)
		{
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

		TEST_METHOD(BEUnicodeReadAll)
		{
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

		TEST_METHOD(UTF8ReadAll2)
		{
			using namespace Elmax;
			UTF8Writer writer;
			std::wstring file = GetTempPath(L"utf8ReadAll2.txt");
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
		TEST_METHOD(UTF32ReadAll2)
		{
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
		TEST_METHOD(UTF32BEReadAll2)
		{
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
		TEST_METHOD(UnicodeReadAll2)
		{
			using namespace Elmax;
			UnicodeWriter writer;
			std::wstring file = GetTempPath(L"UnicodeReadAll2.txt");
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

		TEST_METHOD(BEUnicodeReadAll2)
		{
			using namespace Elmax;
			BEUnicodeWriter writer;
			std::wstring file = GetTempPath(L"BeUnicodeReadAll2.txt");
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

		TEST_METHOD(AsciiNewline)
		{
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
		TEST_METHOD(UTF8Newline)
		{
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
		TEST_METHOD(UTF32Newline)
		{
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
		TEST_METHOD(UTF32BENewline)
		{
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
		TEST_METHOD(UnicodeNewline)
		{
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
		TEST_METHOD(BEUnicodeNewline)
		{
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
		TEST_METHOD(BinaryPOD)
		{
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
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");

				Assert::AreEqual(i, i2, L"Integer values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(BinaryWString)
		{
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
				Assert::AreEqual((size_t)(1), totalRead, L"1 value is not read");
				Assert::AreEqual(str.size(), i2, L"Integer values are not the same");
				totalRead = reader.Read(arr.MakeArray(i2), d2);
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");
				std::wstring str2 = arr.GetPtr();
				Assert::AreEqual(str, str2, L"String values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(BinaryDeferredMakeWString)
		{
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
		TEST_METHOD(BinaryString)
		{
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
				Assert::AreEqual((size_t)(1), totalRead, L"1 value is not read");
				Assert::AreEqual(str.size(), i2, L"Integer values are not the same");
				totalRead = reader.Read(arr.MakeArray(i2), d2);
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");
				std::string str2 = arr.GetPtr();
				Assert::AreEqual(str, str2, L"String values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(BinaryDeferredMakeString)
		{
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
		TEST_METHOD(BinaryBaseArray)
		{
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
				Assert::AreEqual((size_t)(1), totalRead, L"1 value is not read");

				BaseArray arr2;
				totalRead = reader.Read(arr2.MakeArray(i2), d2);
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");

				char* ptr1 = (char*)arr;
				char* ptr2 = arr2.GetPtr();
				for(size_t i=0; i<i2; ++i)
					Assert::AreEqual(ptr1[i], ptr2[i], L"Integer values are not the same");

				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(BinaryDeferredMakeBaseArray)
		{
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
		TEST_METHOD(TextAsciiPOD)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textAsciiPOD.txt");
			Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");

				Assert::AreEqual(i, i2, L"Integer values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(TextUTF8POD)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8POD.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");
				Assert::AreEqual(i, i2, L"Integer values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(TextUTF32POD)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32POD.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF32BEPOD)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32BEPOD.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUnicodePOD)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUnicodePOD.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");
				Assert::AreEqual(i, i2, L"Integer values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(TextBEUnicodePOD)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textBEUnicodePOD.txt");
			Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");
				Assert::AreEqual(i, i2, L"Integer values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(TextAsciiPODWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textAsciiPODWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");
				Assert::AreEqual(i, i2, L"Integer values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(TextUTF8PODWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8PODWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");
				Assert::AreEqual(i, i2, L"Integer values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(TextUTF32PODWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32PODWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF32BEPODWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32BEPODWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUnicodePODWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUnicodePODWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");
				Assert::AreEqual(i, i2, L"Integer values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(TextBEUnicodePODWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textBEUnicodePODWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
				Assert::AreEqual((size_t)(2), totalRead, L"2 values are not read");
				Assert::AreEqual(i, i2, L"Integer values are not the same");
				Assert::AreEqual(d, d2, L"Double values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(TextAsciiWString)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textAsciiWString.txt");
			Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF8WString)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8WString.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF32WString)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32WString.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF32BEWString)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32BEWString.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUnicodeWString)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUnicodeWString.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextBEUnicodeWString)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textBEUnicodeWString.txt");
			Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextAsciiWStringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textAsciiWStringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF8WStringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8WStringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF32WStringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32WStringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF32BEWStringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32BEWStringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUnicodeWStringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUnicodeWStringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextBEUnicodeWStringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textBEUnicodeWStringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextAsciiString)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textAsciiString.txt");
			Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF8String)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8String.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF32String)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32String.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF32BEString)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32BEString.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUnicodeString)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUnicodeString.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextBEUnicodeString)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textBEUnicodeString.txt");
			Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextAsciiStringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textAsciiStringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF8StringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8StringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF32StringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32StringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF32BEStringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF32BEStringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF32BE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUnicodeStringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUnicodeStringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextBEUnicodeStringWriteLine)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textBEUnicodeStringWriteLine.txt");
			Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextAllOtherTypes)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"TextAllOtherTypes.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
			char c = 118;
			unsigned char uc = 176;
			short s = 15670;
			unsigned short us = 40597;
			unsigned int ui = 3569858236;
			__int64 i64 = 35698582368L;
			unsigned __int64 ui64 = 36693588379L;
			float f = 1254.69f;
			writer.Write(L"{0},{1},{2},{3},{4},{5},{6},{7}", c, uc, s, us, ui, i64, ui64, f);
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
				__int64 i642 = 0L;
				unsigned __int64 ui642 = 0L;
				float f2 = 0.0f;

				reader.SetDelimiter(L",");
				size_t totalRead = reader.ReadLine(c2, uc2, s2, us2, ui2, i642, ui642, f2);
				Assert::AreEqual((size_t)(8), totalRead, L"8 values are not read!");
				Assert::AreEqual(c, c2, L"Char values are not the same");
				Assert::AreEqual(uc, uc2, L"Unsigned char values are not the same");
				Assert::AreEqual(s, s2, L"Short values are not the same");
				Assert::AreEqual(true, us2==us, L"Unsigned short values are not the same");
				Assert::AreEqual(ui, ui2, L"Unsigned Integer values are not the same");
				Assert::AreEqual(true, i642==i64, L"64 bit Integer values are not the same");
				Assert::AreEqual(ui64, ui642, L"Unsigned 64 bit Integer values are not the same");
				Assert::AreEqual(f, f2, L"Float values are not the same");
			}
			reader.Close();
		}

		TEST_METHOD(BinaryAllOtherTypes)
		{
			using namespace Elmax;
			xBinaryWriter writer;
			std::wstring file = GetTempPath(L"BinaryAllOtherTypes.bin");
			Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
			char c = 118;
			unsigned char uc = 176;
			short s = 15670;
			unsigned short us = 40597;
			unsigned int ui = 3569858236;
			__int64 i64 = 35698582368L;
			unsigned __int64 ui64 = 36693588379L;
			float f = 1254.69f;
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
				__int64 i642 = 0L;
				unsigned __int64 ui642 = 0L;
				float f2 = 0.0f;

				size_t totalRead = reader.Read(c2, uc2, s2, us2, ui2, i642, ui642, f2);
				Assert::AreEqual((size_t)(8), totalRead, L"8 values are not read!");
				Assert::AreEqual(c, c2, L"Char values are not the same");
				Assert::AreEqual(uc, uc2, L"Unsigned char values are not the same");
				Assert::AreEqual(s, s2, L"Short values are not the same");
				Assert::AreEqual(true, us2==us, L"Unsigned short values are not the same");
				Assert::AreEqual(ui, ui2, L"Unsigned Integer values are not the same");
				Assert::AreEqual(true, i642==i64, L"64 bit Integer values are not the same");
				Assert::AreEqual(ui64, ui642, L"Unsigned 64 bit Integer values are not the same");
				Assert::AreEqual(f, f2, L"Float values are not the same");
			}
			reader.Close();
		}
		TEST_METHOD(Trim)
		{
			using namespace Elmax;

			std::wstring orig = L"\tGood morning  \n\r";
			std::wstring trimmedCorrect = L"Good morning";

			std::wstring trimmed = StrUtil::Trim(orig);

			Assert::AreEqual(trimmedCorrect, trimmed, L"String values are not the same");
		}
		TEST_METHOD(ReplaceAll)
		{
			using namespace Elmax;

			std::wstring orig = L",.Good,.morning,.friend,.";
			std::wstring replacedCorrect = L"LKGoodLKmorningLKfriendLK";

			std::wstring replaced = StrUtil::ReplaceAll(orig, L",.", L"LK");

			Assert::AreEqual(replacedCorrect, replaced, L"String values are not the same");
		}
		TEST_METHOD(BinaryPODSeek)
		{
			using namespace Elmax;
			xBinaryWriter writer;
			std::wstring file = GetTempPath(L"binaryPODSeek.bin");
			Assert::AreEqual(true, writer.Open(file), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextFileMismatched)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"TextFileMismatched.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF8UTF16)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8UTF16.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
			std::wstring str = L"Hello";
			wchar_t ch1 = 0x007a;
			str += ch1;
			wchar_t ch2 = 0x6c34;
			str += ch2;
			wchar_t ch3 = 0xd834;
			str += ch3;
			wchar_t ch4 = 0xdd0b;
			str += ch4;
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

		TEST_METHOD(TextUTF8UTF16Line)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8UTF16Line.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
			std::wstring str = L"Hello";
			wchar_t ch1 = 0x007a;
			str += ch1;
			wchar_t ch2 = 0x6c34;
			str += ch2;
			wchar_t ch3 = 0xd834;
			str += ch3;
			wchar_t ch4 = 0xdd0b;
			str += ch4;
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

		TEST_METHOD(TextUTF8NoBOM)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8NoBOM.txt");
			Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextAsciiStruct)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textAsciiStruct.txt");
			Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextAsciiDiffDelimiterStruct)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textAsciiDiffDelimiterStruct.txt");
			Assert::AreEqual(true, writer.Open(file, FT_ASCII, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUnicodeStruct)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUnicodeStruct.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUnicodeDiffDelimiterStruct)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUnicodeDiffDelimiterStruct.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextBEUnicodeStruct)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textBEUnicodeStruct.txt");
			Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextBEUnicodeDiffDelimiterStruct)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textBEUnicodeDiffDelimiterStruct.txt");
			Assert::AreEqual(true, writer.Open(file, FT_BEUNICODE, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF8Struct)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8Struct.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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
		TEST_METHOD(TextUTF8DiffDelimiterStruct)
		{
			using namespace Elmax;
			xTextWriter writer;
			std::wstring file = GetTempPath(L"textUTF8DiffDelimiterStruct.txt");
			Assert::AreEqual(true, writer.Open(file, FT_UTF8, NEW), L"File cannot be opened for writing!");
			int i = 25698;
			double d = 1254.69;
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

	};
}