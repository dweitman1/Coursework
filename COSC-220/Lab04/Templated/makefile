prog: ListTest.o ListCollection.o
	g++ -o prog ListTest.o ListCollection.o

ListTest.o: ListTest.cpp ListCollection.h
	g++ -g -Wall -std=c++11 -c ListTest.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make
