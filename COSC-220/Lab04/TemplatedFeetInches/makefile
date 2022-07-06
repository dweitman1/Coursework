prog: ListTest.o ListCollection.o FeetInches.o
	g++ -o prog ListCollection.o FeetInches.o ListTest.o

ListTest.o: ListTest.cpp ListCollection.h FeetInches.h
	g++ -g -Wall -std=c++11 -c ListTest.cpp

ListCollection.o: ListCollection.cpp ListCollection.h
	g++ -g -Wall -std=c++11 -c ListCollection.cpp

FeetInches.o: FeetInches.cpp FeetInches.h
	g++ -g -Wall -std=c++11 -c FeetInches.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make
