# Files
EXEC := test
# Options
CC := icc
CXXFLAGS := -std=c++11 -I$$BOOST_INC
LDFLAGS := -L$$BOOST_LIB
# Rules
$(EXEC) : main.o 
	$(CC) $(LDFLAGS) -o $(EXEC) main.o
main.o: main.cpp solveODE.h
	$(CC) $(CXXFLAGS) -c main.cpp
