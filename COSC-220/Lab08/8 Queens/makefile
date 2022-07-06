CC = g++
INCLUDE = .
CFLAGS = -g -Wall -std=c++11
PROG = EightQueens

$(PROG): $(PROG).o
	$(CC) -o prog $(PROG).o 

$(PROG).o: $(PROG).cpp
	$(CC) -c -I$(INCLUDE) $(CFLAGS) $(PROG).cpp

clean:
	rm *.o prog
