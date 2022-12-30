# the OS the user is running
OS=$(shell uname)

PROC	:= blockline
FILE	:= Main.cpp
FLAGS := -Wno-return-type -std=c++17 -O2

# default compiler, run 'make CXX=NAME_OF_COMPILER' to change
CXX 	:= g++

ifeq ($(OS), Windows)

$(PROC).exe: $(FILE)
	$(CXX) $(FLAGS) $< -o $@

else

$(PROC): $(FILE)
	$(CXX) $(FLAGS) $< -o $@

endif

clean:
	$(RM) $(PROC)
