CXX = g++
CXXFLAGS = -std=c++23 -O2 -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wduplicated-cond -Wlogical-op
.PHONY: f-% r-%

f-%:
	touch $*.cpp $*.in $*.out

r-%:
	$(CXX) $(CXXFLAGS) $*.cpp -o a.out
	./a.out

%:
	$(CXX) $(CXXFLAGS) $@.cpp -o a.out
	./a.out
	bat $@.out
