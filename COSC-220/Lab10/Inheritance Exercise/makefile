prog: main.o GradedActivity.o 
	g++ -o prog main.o GradedActivity.o 

main.o: main.cpp 
	g++ -g -Wall -std=c++11 -c main.cpp

GradedActivity.o: GradedActivity.h GradedActivity.cpp 
	g++ -g -Wall -std=c++11 -c GradedActivity.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make

