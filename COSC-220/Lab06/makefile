prog: tokencpp.o
	g++ -o prog tokencpp.o 

tokencpp.o: tokencpp.cpp ListCollection.h
	g++ -g -Wall -std=c++11 -c tokencpp.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make

