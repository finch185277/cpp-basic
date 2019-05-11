CXX = g++ # -std=c++11 # g++ -O2 -std=c++17

all: playground.cpp
		$(CXX) -g -o main $^

.PHONY: clean
clean:
		rm -rf main
