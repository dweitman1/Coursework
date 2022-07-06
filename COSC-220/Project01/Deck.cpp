#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Deck.h"
#include "Cards.h"
/*Author: Daniel Weitman
 * Creation Date: 10/06/18
 * Last Update: 10/12/18
 * Description: Implementation of Deck object
 */
using namespace std;
/* Description: constructs Deck object in order by card
 * Parameters: none
 * Return: void
 */
Deck :: Deck() {
    for(int i = 0; i < 52; i++){
        
        if (i < 13){
            deck[i] = Cards(i, 0);
        } else if (13 <= i && i < 26){
            deck[i] = Cards(i, 1);
        } else if (26 <= i && i < 39){
            deck[i] = Cards(i, 2);
        } else if (39 <= i && i < 52){
            deck[i] = Cards(i, 3);
        } 
    }   
}
/* Description: displays Deck object
 * Parameters: none
 * Return: void
 */
void Deck :: displayDeck(){
    for(int i = 0; i < 52; i++){
        
        deck[i].displayCard();
        cout << " ";
        if((i+1) % 13 == 0){
         cout << endl;
        }
    }
}
/* Description: shuffles deck to be in random order
 * Parameters: none
 * Return: void
 */
void Deck :: shuffleDeck(){
        int rand1;
        int rand2;
        Cards swap;
        
    for(int i = 0; i < 500; i++){
        
        rand1 = rand()%52;
        rand2 = rand()%52;
        
        swap = deck[rand1];
        deck[rand1] = deck[rand2];
        deck[rand2] = swap;
    }
}
/* Description: gets the Cards object in deck position
 * Parameters: int for position
 * Return: Cards object
 */
Cards Deck :: getCard(int x){
    return deck[x];
}/* Description: gets the Cards object in deck position
 * Parameters: int for position
 * Return: Cards object
 */
Cards& Deck :: operator[](const int &x){
    return deck[x];
}
