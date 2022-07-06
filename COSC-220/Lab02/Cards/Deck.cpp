#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Deck.h"
#include "Cards.h"
/*Author: Daniel Weitman
 * Creation Date: 9/14/18
 * Last Update: 9/17/18
 * Description: Implementation file for Deck class
 */
using namespace std;

Deck :: Deck() {
    for(int i = 0; i < 52; i++){
        string ssuit;
        string svalue;
        
        if (i < 13){
            ssuit = "D";
        } else if (13 <= i && i < 26){
            ssuit = "C";
        } else if (26 <= i && i < 39){
            ssuit = "H";
        } else if (39 <= i && i < 52){
            ssuit = "S";
        } 
        
        if(i % 13 == 0){
            svalue = "A";
        } else if (i % 13 == 1){
            svalue = "2";
        } else if (i % 13 == 2){
            svalue = "3";
        } else if (i % 13 == 3){
            svalue = "4";
        } else if (i % 13 == 4){
            svalue = "5";
        } else if (i % 13 == 5){
            svalue = "6";
        } else if (i % 13 == 6){
            svalue = "7";
        } else if (i % 13 == 7){
            svalue = "8";
        } else if (i % 13 == 8){
            svalue = "9";
        } else if (i % 13 == 9){
            svalue = "10";
        } else if (i % 13 == 10){
            svalue = "J";
        } else if (i % 13 == 11){
            svalue = "Q";
        } else if (i % 13 == 12){
            svalue = "K";
        } 
        
        Cards(svalue, ssuit);
    }   
}
void Deck :: displayDeck(){
    for(int i = 0; i < 52; i++){
        deck[i].displayCard();
    }
    
}
void Deck :: shuffleDeck(){
    for(int i = 0; i < 500 i++){
        Cards rand1;
        Cards rand2;
        Cards swap
        rand1 = deck[rand()%52 + 1];
        rand2 = deck[rand()%52 + 1];
        temp = rand1;
        rand1 = rand2;
        rand2 = swap;
    }

    
}
Cards Deck :: getCard(int x){
    return deck[x];
}
