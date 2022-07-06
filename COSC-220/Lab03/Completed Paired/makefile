prog: IntListTest.o IntegerList.o
	g++ -o prog IntListTest.o IntegerList.o

IntListTest.o: IntListTest.cpp IntegerList.h
	g++ -g -Wall -std=c++11 -c IntListTest.cpp

IntegerList.o: IntegerList.h IntegerList.cpp
	g++ -g -Wall -std=c++11 -c IntegerList.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make
