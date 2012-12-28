# Project: UnitTest
# Makefile created by Dev-C++ 5.2.0.3

CPP      = g++-4.7
CC       = gcc-4.7
# WINDRES  = windres.exe
OBJ      = Assert.o LinuxUnitTest.o $(RES)
LINKOBJ  = Assert.o LinuxUnitTest.o $(RES)
LIBS     = -static-libgcc ../FileIO/FileLib.a  -g 
# INCS     = -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" 
# CXXINCS  = -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" 
BIN      = UnitTest.exe
CXXFLAGS = -Wall -g -O1 
CFLAGS   = -Wall -g -O1  
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before UnitTest.exe all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "UnitTest.exe" $(LIBS)

Assert.o: Assert.cpp
	$(CPP) -c Assert.cpp -o Assert.o $(CXXFLAGS)

LinuxUnitTest.o: LinuxUnitTest.cpp
	$(CPP) -c LinuxUnitTest.cpp -o LinuxUnitTest.o $(CXXFLAGS)
