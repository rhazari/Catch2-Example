INCLUDES=-I includes/
CXXFLAGS=-fsanitize=address --std=c++14 -g -O0 -Wall -Wextra -Werror -pedantic $(INCLUDES)
CXX=g++

tests: bin/tests.out
	- $<

exec: bin/main.out
	$<

clean:
	rm -f bin/*

bin/main.out: src/main.cpp src/BankApp.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

bin/tests.out: tests/tests.cpp src/BankApp.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

src/%.cc: includes/%.hpp
	touch $@

.DEFAULT_GOAL := exec
.PHONY: clean exec