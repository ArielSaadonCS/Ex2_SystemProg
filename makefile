
CC = clang++
CFLAGS = -Wall -std=c++11 -g

.PHONY: all main test valgrind clean

all: main test

main: main.cpp SquareMat.cpp SquareMat.hpp
	$(CC) $(CFLAGS) main.cpp SquareMat.cpp -o main

test: test.cpp SquareMat.cpp SquareMat.hpp
	$(CC) $(CFLAGS) test.cpp SquareMat.cpp -o test
	./test

valgrind: main test
	valgrind --leak-check=full ./main
	valgrind --leak-check=full ./test

clean: 
	rm -f main test *.o