prog: Test.o Cards.o Deck.o
	g++ -o prog Test.o Cards.o Deck.o

Test.o: Test.cpp Cards.h Deck.h
	g++ -g -Wall -std=c++11 -c Test.cpp

Cards.o: Cards.h Cards.cpp
	g++ -g -Wall -std=c++11 -c Cards.cpp
	
Deck.o: Deck.h Deck.cpp
	g++ -g -Wall -std=c++11 -c Deck.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make
