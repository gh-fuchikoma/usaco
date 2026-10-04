CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wshadow

# Compile, run, and show the .out file
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o a.out
	./a.out
	bat $*.out

# Compile and run only
run-%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o a.out
	./a.out
