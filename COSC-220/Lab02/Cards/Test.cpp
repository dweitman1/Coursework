#include <iostream>
#include <cstring>
#include "Cards.h"
#include "Deck.h"
/*Author: Daniel Weitman
 * Creation Date: 9/14/18
 * Last Update: 9/17/18
 * Description: Main function for calling executable code
 */
using namespace std;

int main(){

    Deck set;
    Deck defDeck;
    set.shuffleDeck();
    
    set.equal(defDeck);
    
   
    return 0;
}
