#include <iostream>
#include <cstring>
#include "Cards.h"
/*Author: Daniel Weitman
 * Creation Date: 10/06/18
 * Last Update: 10/12/18
 * Description: Implementation of Cards object
 */
using namespace std;
/* Description: constructs card as Ace of Spades
 * Parameters: none
 * Return: void
 */
Cards :: Cards(){
    value = 12;
    suit = 3;
}
/* Description: constructs pre-defined card
 * Parameters: int value, int suit
 * Return: void
 */
Cards :: Cards(int x, int y){
    value = x;
    suit = y;
}
/* Description: gets value of Cards object 0-12
 * Parameters: none
 * Return: int value
 */
int Cards :: getValue(){
    return (value % 13);
}
/* Description: gets suit of Cards object
 * Parameters: none
 * Return: int suit
 */
int Cards :: getSuit(){
    return suit;
}
/* Description: displays a Cards object
 * Parameters: none
 * Return: void
 */
void Cards :: displayCard(){
    
        if(value % 13 == 0){
            cout << "2";
        } else if (value % 13 == 1){
            cout << "3";
        } else if (value % 13 == 2){
            cout << "4";
        } else if (value % 13 == 3){
            cout << "5";
        } else if (value % 13 == 4){
            cout << "6";
        } else if (value % 13 == 5){
            cout << "7";
        } else if (value % 13 == 6){
            cout << "8";
        } else if (value % 13 == 7){
            cout << "9";
        } else if (value % 13 == 8){
            cout << "10";
        } else if (value % 13 == 9){
            cout << "J";
        } else if (value % 13 == 10){
            cout << "Q";
        } else if (value % 13 == 11){
            cout << "K";
        } else if (value % 13 == 12){
            cout << "A";
        } 
        
        if (suit == 0){
            cout << "D";
        } else if (suit == 1){
            cout << "C";
        } else if (suit == 2){
            cout << "H";
        } else if (suit == 3){
            cout << "S";
        } 
}
/* Description: checks if two Cards objects are equal
 * Parameters: Cards right
 * Return: bool
 */
bool Cards :: equal(Cards a){
    if (value == a.value && suit == a.suit){
        return true;
    } else {
        return false;
    }
}
/* Description: assigns Cards object into another
 * Parameters: Cards right
 * Return: Cards
 */
Cards Cards :: operator =(const Cards &right){
    value = right.value;
    suit = right.suit;
    return *this;
}
/* Description: checks < for Cards object
 * Parameters: Cards right
 * Return: bool
 */
bool Cards :: operator <(Cards right){
    return (value % 13 < right.value % 13);
}
/* Description: checks > for Cards object
 * Parameters: Cards right
 * Return: bool
 */
bool Cards :: operator >(Cards right){
    return (value % 13 > right.value % 13);
}
/* Description: checks == for Cards object
 * Parameters: Cards right
 * Return: bool
 */
bool Cards :: operator ==(Cards right){
    return (value % 13 == right.value % 13);
}
/* Description: checks != for Cards object
 * Parameters: Cards right
 * Return: bool
 */
bool Cards :: operator !=(Cards right){
    return (value % 13 != right.value % 13);
}
