prog: main.o Complex.o
	g++ -o prog main.o Complex.o

main.o: main.cpp Complex.h
	g++ -g -Wall -std=c++11 -c main.cpp

Complex.o: Complex.h Complex.cpp
	g++ -g -Wall -std=c++11 -c Complex.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make
