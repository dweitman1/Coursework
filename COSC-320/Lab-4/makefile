prog: main.o matrix.o
	g++ -o prog main.o matrix.o

main.o: main.cpp matrix.h
	g++ -g -Wall -std=c++11 -c main.cpp

matrix.o: matrix.h matrix.cpp
	g++ -g -Wall -std=c++11 -c matrix.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make

