CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++11

run: calc costs.in.txt
	@./main

# Compile the main executable
calc: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o calc

# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump

