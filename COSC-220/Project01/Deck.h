#ifndef DECK_H
#define DECK_H
#include <cstring>
#include "Cards.h"
/*Author: Daniel Weitman
 * Creation Date: 10/06/18
 * Last Update: 10/12/18
 * Description: Header file for Cards object
 */
using namespace std;

class Deck {
    
    private:
        Cards deck[52];
        
    public:
        Deck();//Default constructor
        void displayDeck();//Displays a Deck object
        void shuffleDeck();//Randomizes order of Deck object
        Cards getCard(int);//Returns the Cards object in index of Deck
        Cards& operator[](const int& x);//[] Overload 
        
};
#endif 
