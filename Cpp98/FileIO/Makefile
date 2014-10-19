# Project: FileLib

CPP      = clang++ -stdlib=libstdc++ -lstdc++ -std=c++11
#CPP      = g++
CC       = gcc
OBJ      = Binary/Reader/xBinaryReader.o Binary/Utils/BaseArray.o Binary/Utils/BinaryTypeReadRef.o Binary/Utils/BinaryTypeRef.o Binary/Utils/StrArray.o Binary/Utils/WStrArray.o Binary/Writer/xBinaryWriter.o Text/Reader/AsciiReader.o Text/Reader/BaseTextReader.o Text/Reader/BEUnicodeReader.o Text/Reader/UnicodeReader.o Text/Reader/UTF8Reader.o Text/Reader/UTF32Reader.o Text/Reader/UTF32BEReader.o Text/Reader/xTextReader.o Text/Utils/DataType.o Text/Utils/DataTypeRef.o Text/Utils/SplitStrategy.o Text/Utils/StrtokStrategy.o Text/Utils/StrUtil.o Text/Utils/StrUtilRef.o Text/Writer/AsciiWriter.o Text/Writer/BaseTextWriter.o Text/Writer/BEUnicodeWriter.o Text/Writer/UnicodeWriter.o Text/Writer/UTF8Writer.o Text/Writer/UTF32Writer.o Text/Writer/UTF32BEWriter.o Text/Writer/xTextWriter.o Common/BaseConverter.o Common/Common.o Common/Enumeration.o Common/RAII_Array.o Common/Platform.o Linux/LinuxOperation.o UTF16Utils/utf16.o $(RES)
LINKOBJ  = Binary/Reader/xBinaryReader.o Binary/Utils/BaseArray.o Binary/Utils/BinaryTypeReadRef.o Binary/Utils/BinaryTypeRef.o Binary/Utils/StrArray.o Binary/Utils/WStrArray.o Binary/Writer/xBinaryWriter.o Text/Reader/AsciiReader.o Text/Reader/BaseTextReader.o Text/Reader/BEUnicodeReader.o Text/Reader/UnicodeReader.o Text/Reader/UTF8Reader.o Text/Reader/UTF32Reader.o Text/Reader/UTF32BEReader.o Text/Reader/xTextReader.o Text/Utils/DataType.o Text/Utils/DataTypeRef.o Text/Utils/SplitStrategy.o Text/Utils/StrtokStrategy.o Text/Utils/StrUtil.o Text/Utils/StrUtilRef.o Text/Writer/AsciiWriter.o Text/Writer/BaseTextWriter.o Text/Writer/BEUnicodeWriter.o Text/Writer/UnicodeWriter.o Text/Writer/UTF8Writer.o Text/Writer/UTF32Writer.o Text/Writer/UTF32BEWriter.o Text/Writer/xTextWriter.o Common/BaseConverter.o Common/Common.o Common/Enumeration.o Common/RAII_Array.o Common/Platform.o Linux/LinuxOperation.o UTF16Utils/utf16.o $(RES)
CXXINCS  = -I ~/Downloads/boost_1_55_0
BIN      = FileLib.a
CXXFLAGS = -Wall -g -O1 $(CXXINCS) 
CFLAGS   = -Wall -g -O1  
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before FileLib.a all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(LINKOBJ)
	ar r $(BIN) $(LINKOBJ)
	ranlib $(BIN)

Binary/Reader/xBinaryReader.o: Binary/Reader/xBinaryReader.cpp
	$(CPP) -c Binary/Reader/xBinaryReader.cpp -o Binary/Reader/xBinaryReader.o $(CXXFLAGS)

Binary/Utils/BaseArray.o: Binary/Utils/BaseArray.cpp
	$(CPP) -c Binary/Utils/BaseArray.cpp -o Binary/Utils/BaseArray.o $(CXXFLAGS)

Binary/Utils/BinaryTypeReadRef.o: Binary/Utils/BinaryTypeReadRef.cpp
	$(CPP) -c Binary/Utils/BinaryTypeReadRef.cpp -o Binary/Utils/BinaryTypeReadRef.o $(CXXFLAGS)

Binary/Utils/BinaryTypeRef.o: Binary/Utils/BinaryTypeRef.cpp
	$(CPP) -c Binary/Utils/BinaryTypeRef.cpp -o Binary/Utils/BinaryTypeRef.o $(CXXFLAGS)

Binary/Utils/StrArray.o: Binary/Utils/StrArray.cpp
	$(CPP) -c Binary/Utils/StrArray.cpp -o Binary/Utils/StrArray.o $(CXXFLAGS)

Binary/Utils/WStrArray.o: Binary/Utils/WStrArray.cpp
	$(CPP) -c Binary/Utils/WStrArray.cpp -o Binary/Utils/WStrArray.o $(CXXFLAGS)

Binary/Writer/xBinaryWriter.o: Binary/Writer/xBinaryWriter.cpp
	$(CPP) -c Binary/Writer/xBinaryWriter.cpp -o Binary/Writer/xBinaryWriter.o $(CXXFLAGS)

Text/Reader/AsciiReader.o: Text/Reader/AsciiReader.cpp
	$(CPP) -c Text/Reader/AsciiReader.cpp -o Text/Reader/AsciiReader.o $(CXXFLAGS)

Text/Reader/BaseTextReader.o: Text/Reader/BaseTextReader.cpp
	$(CPP) -c Text/Reader/BaseTextReader.cpp -o Text/Reader/BaseTextReader.o $(CXXFLAGS)

Text/Reader/BEUnicodeReader.o: Text/Reader/BEUnicodeReader.cpp
	$(CPP) -c Text/Reader/BEUnicodeReader.cpp -o Text/Reader/BEUnicodeReader.o $(CXXFLAGS)

Text/Reader/UnicodeReader.o: Text/Reader/UnicodeReader.cpp
	$(CPP) -c Text/Reader/UnicodeReader.cpp -o Text/Reader/UnicodeReader.o $(CXXFLAGS)

Text/Reader/UTF8Reader.o: Text/Reader/UTF8Reader.cpp
	$(CPP) -c Text/Reader/UTF8Reader.cpp -o Text/Reader/UTF8Reader.o $(CXXFLAGS)

Text/Reader/UTF32Reader.o: Text/Reader/UTF32Reader.cpp
	$(CPP) -c Text/Reader/UTF32Reader.cpp -o Text/Reader/UTF32Reader.o $(CXXFLAGS)

Text/Reader/UTF32BEReader.o: Text/Reader/UTF32BEReader.cpp
	$(CPP) -c Text/Reader/UTF32BEReader.cpp -o Text/Reader/UTF32BEReader.o $(CXXFLAGS)

Text/Reader/xTextReader.o: Text/Reader/xTextReader.cpp
	$(CPP) -c Text/Reader/xTextReader.cpp -o Text/Reader/xTextReader.o $(CXXFLAGS)

Text/Utils/DataType.o: Text/Utils/DataType.cpp
	$(CPP) -c Text/Utils/DataType.cpp -o Text/Utils/DataType.o $(CXXFLAGS)

Text/Utils/DataTypeRef.o: Text/Utils/DataTypeRef.cpp
	$(CPP) -c Text/Utils/DataTypeRef.cpp -o Text/Utils/DataTypeRef.o $(CXXFLAGS)

Text/Utils/SplitStrategy.o: Text/Utils/SplitStrategy.cpp
	$(CPP) -c Text/Utils/SplitStrategy.cpp -o Text/Utils/SplitStrategy.o $(CXXFLAGS)

Text/Utils/StrtokStrategy.o: Text/Utils/StrtokStrategy.cpp
	$(CPP) -c Text/Utils/StrtokStrategy.cpp -o Text/Utils/StrtokStrategy.o $(CXXFLAGS)

Text/Utils/StrUtil.o: Text/Utils/StrUtil.cpp
	$(CPP) -c Text/Utils/StrUtil.cpp -o Text/Utils/StrUtil.o $(CXXFLAGS)

Text/Utils/StrUtilRef.o: Text/Utils/StrUtilRef.cpp
	$(CPP) -c Text/Utils/StrUtilRef.cpp -o Text/Utils/StrUtilRef.o $(CXXFLAGS)

Text/Writer/AsciiWriter.o: Text/Writer/AsciiWriter.cpp
	$(CPP) -c Text/Writer/AsciiWriter.cpp -o Text/Writer/AsciiWriter.o $(CXXFLAGS)

Text/Writer/BaseTextWriter.o: Text/Writer/BaseTextWriter.cpp
	$(CPP) -c Text/Writer/BaseTextWriter.cpp -o Text/Writer/BaseTextWriter.o $(CXXFLAGS)

Text/Writer/BEUnicodeWriter.o: Text/Writer/BEUnicodeWriter.cpp
	$(CPP) -c Text/Writer/BEUnicodeWriter.cpp -o Text/Writer/BEUnicodeWriter.o $(CXXFLAGS)

Text/Writer/UnicodeWriter.o: Text/Writer/UnicodeWriter.cpp
	$(CPP) -c Text/Writer/UnicodeWriter.cpp -o Text/Writer/UnicodeWriter.o $(CXXFLAGS)

Text/Writer/UTF8Writer.o: Text/Writer/UTF8Writer.cpp
	$(CPP) -c Text/Writer/UTF8Writer.cpp -o Text/Writer/UTF8Writer.o $(CXXFLAGS)

Text/Writer/UTF32Writer.o: Text/Writer/UTF32Writer.cpp
	$(CPP) -c Text/Writer/UTF32Writer.cpp -o Text/Writer/UTF32Writer.o $(CXXFLAGS)

Text/Writer/UTF32BEWriter.o: Text/Writer/UTF32BEWriter.cpp
	$(CPP) -c Text/Writer/UTF32BEWriter.cpp -o Text/Writer/UTF32BEWriter.o $(CXXFLAGS)

Text/Writer/xTextWriter.o: Text/Writer/xTextWriter.cpp
	$(CPP) -c Text/Writer/xTextWriter.cpp -o Text/Writer/xTextWriter.o $(CXXFLAGS)

Common/BaseConverter.o: Common/BaseConverter.cpp
	$(CPP) -c Common/BaseConverter.cpp -o Common/BaseConverter.o $(CXXFLAGS)

Common/Common.o: Common/Common.cpp
	$(CPP) -c Common/Common.cpp -o Common/Common.o $(CXXFLAGS)

Common/Enumeration.o: Common/Enumeration.cpp
	$(CPP) -c Common/Enumeration.cpp -o Common/Enumeration.o $(CXXFLAGS)

Common/RAII_Array.o: Common/RAII_Array.cpp
	$(CPP) -c Common/RAII_Array.cpp -o Common/RAII_Array.o $(CXXFLAGS)

Common/Platform.o: Common/Platform.cpp
	$(CPP) -c Common/Platform.cpp -o Common/Platform.o $(CXXFLAGS)

Linux/LinuxOperation.o: Linux/LinuxOperation.cpp
	$(CPP) -c Linux/LinuxOperation.cpp -o Linux/LinuxOperation.o $(CXXFLAGS)

UTF16Utils/utf16.o: UTF16Utils/utf16.cpp
	$(CPP) -c UTF16Utils/utf16.cpp -o UTF16Utils/utf16.o $(CXXFLAGS)
