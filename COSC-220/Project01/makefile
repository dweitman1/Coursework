prog: Test.o Cards.o Deck.o Hand.o
	g++ -o prog Test.o Cards.o Deck.o Hand.o

Test.o: Test.cpp Cards.h Deck.h Hand.h
	g++ -g -Wall -std=c++11 -c Test.cpp

Cards.o: Cards.h Cards.cpp
	g++ -g -Wall -std=c++11 -c Cards.cpp

Deck.o: Deck.h Deck.cpp
	g++ -g -Wall -std=c++11 -c Deck.cpp

Hand.o: Hand.h Hand.cpp
	g++ -g -Wall -std=c++11 -c Hand.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make
