# Project: UnitTest

#CPP      = clang++ -stdlib=libstdc++ -lstdc++ -std=c++11
CPP      = g++ -lstdc++ -std=c++11 
CC       = gcc
OBJ      = Assert.o LinuxUnitTest.o CustomStruct.o $(RES)
LINKOBJ  = Assert.o LinuxUnitTest.o CustomStruct.o $(RES)
LIBS     = -static-libgcc ../FileIO/FileLib.a  -g 
CXXINCS  = -I ~/Downloads/boost_1_55_0
BIN      = UnitTest.exe
CXXFLAGS = -Wall -g -O1 $(CXXINCS) 
CFLAGS   = -Wall -g -O1  
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before UnitTest.exe all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "UnitTest.exe" $(LIBS)

CustomStruct.o: CustomStruct.cpp
	$(CPP) -c CustomStruct.cpp -o CustomStruct.o $(CXXFLAGS)

Assert.o: Assert.cpp
	$(CPP) -c Assert.cpp -o Assert.o $(CXXFLAGS)

LinuxUnitTest.o: LinuxUnitTest.cpp
	$(CPP) -c LinuxUnitTest.cpp -o LinuxUnitTest.o $(CXXFLAGS)
