#include <iostream>
#include <cstring>
#include "Cards.h"
/*Author: Daniel Weitman
 * Creation Date: 9/14/18
 * Last Update: 9/17/18
 * Description: Implementation file for Cards class
 */
using namespace std;

Cards :: Cards(){
    value = "A";
    suit = "S";
}
Cards :: Cards(string x, string y){
    value = x;
    suit = y;
}
void Cards :: displayCard(){
    cout << value << suit << endl;
}
bool Cards :: equal(Cards a){
    if (value == a.value && suit == a.suit){
        return true;
    } else {
        return false;
    }
}
