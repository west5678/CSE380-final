# Files
EXEC := test
SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))
# Options
CC := icc
CXXFLAGS := -std=c++11 -I$$TACC_BOOST_INC -I$$TACC_GRVY_INC
LDFLAGS := -L$$TACC_BOOST_LIB -L$$TACC_GRVY_LIB
LDLIBS := -lgrvy
# Rules
$(EXEC) : $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $<
%.o : solveODE.h
