#ifndef DECK_H
#define DECK_H
#include <cstring>
#include "Cards.h"
/*Author: Daniel Weitman
 * Creation Date: 9/14/18
 * Last Update: 9/17/18
 * Description: Header file for class Deck with private data variables and member 
 * functions
 */
using namespace std;

class Deck {
    
    private:
        Cards deck[52];
    public:
        Deck();
        void displayDeck();
        void shuffleDeck();
        Cards getCard(int);
        
};
#endif 
