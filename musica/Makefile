CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic
BIN=loja

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN)  $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)
