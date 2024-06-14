# Makefile

CXX = g++
CXXFLAGS = -Wall -std=c++11

all: sort

sort: main.o insertion_sort.o
	$(CXX) $(CXXFLAGS) -o sort main.o insertion_sort.o

main.o: main.cpp insertion_sort.h
	$(CXX) $(CXXFLAGS) -c main.cpp

insertion_sort.o: insertion_sort.cpp insertion_sort.h
	$(CXX) $(CXXFLAGS) -c insertion_sort.cpp

clean:
	rm -f *.o sort
