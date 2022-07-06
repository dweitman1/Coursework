prog: Main.o Circle.o
	g++ -o prog Main.o Circle.o

Main.o: Main.cpp Circle.h
	g++ -g -Wall -std=c++11 -c Main.cpp

Circle.o: Circle.h Circle.cpp
	g++ -g -Wall -std=c++11 -c Circle.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make
