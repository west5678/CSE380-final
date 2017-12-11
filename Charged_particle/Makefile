# Files
EXEC := test
SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))
# Options
CC := icc
CXXFLAGS := -std=c++11 -I$$BOOST_INC -I$$GRVY_INC
LDFLAGS := -L$$BOOST_LIB -L$$GRVY_LIB
LDLIBS := -lgrvy
# Rules
$(EXEC) : $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $<
%.o : solveODE.h
