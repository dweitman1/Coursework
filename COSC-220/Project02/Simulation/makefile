prog: main.o  Complex.o
	g++ -o prog main.o Complex.o


Complex.o: Complex.h Complex.cpp
	g++ -g -Wall -std=c++11 -c Complex.cpp

main.o: Complex.h PriorityQueue.h Process.h
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make
