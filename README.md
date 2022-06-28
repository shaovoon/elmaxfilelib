##elmaxfilelib

Elmax C++ File Library for writing and reading (Unicode) text or binary files

**Text File Usage**

Writing to a test file

```Cpp
using namespace Elmax;

xTextWriter writer;
std::wstring file = L"Unicode.txt";
if(writer.Open(file, FT_UNICODE, NEW))
{
    int i = 25698;
    double d = 1254.69;
    writer.Write(L"{0},{1}", i, d);
    writer.Close();
}
```

Reading from a test file. For C++98 code, user need to set the split strategy. For C++11, delimiter need to be set.

```Cpp
using namespace Elmax;

xTextReader reader;
std::wstring file = L"Unicode.txt";
if(reader.Open(file))
{
    if(reader.IsEOF()==false)
    {
        int i2 = 0;
        double d2 = 0.0;

        StrtokStrategy strat(L",");
        reader.SetSplitStrategy(&strat);
        size_t totalRead = reader.ReadLine(i2, d2); // i2 = 25698 and d2 = 1254.69
}
reader.Close();
```

**Binary File Usage**

Writing to a binary file

```Cpp
using namespace Elmax;

xBinaryWriter writer;
std::wstring file = L"Binary.bin";
if(writer.Open(file))
{
    int i = 25698;
    double d = 1254.69;
    writer.Write(i, d);
    writer.Close();
}
```
    
Reading from a binary file

```Cpp
using namespace Elmax;

xBinaryReader reader;
std::wstring file = L"Binary.bin";
if(reader.Open(file))
{
    if(reader.IsEOF())
    {
        int i2 = 0;
        double d2 = 0.0;
        size_t totalRead = reader.Read(i2, d2); // i2 = 25698 and d2 = 1254.69
    }
    reader.Close();
}
```

More details on the library can be found on [CodeProject article](http://www.codeproject.com/Articles/465434/Unification-of-Text-and-Binary-File-APIs)