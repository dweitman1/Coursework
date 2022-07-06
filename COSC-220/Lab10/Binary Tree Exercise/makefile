prog: main.o
	g++ -o prog main.o

main.o: main.cpp BinaryTree.h
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make

