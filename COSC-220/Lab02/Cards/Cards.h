#ifndef CARDS_H
#define CARDS_H
#include <cstring>
#include "Deck.h"
/*Author: Daniel Weitman
 * Creation Date: 9/14/18
 * Last Update: 9/17/18
 * Description: Header file for class Cards with private data members and member 
 * functions
 */
using namespace std;

class Cards{
    
    private:
        string value;
        string suit;
    public:
        Cards();
        Cards(string, string);
        void displayCard();
        bool equal(Cards);
};
#endif 
