#ifndef CARDS_H
#define CARDS_H
#include <cstring>
/*Author: Daniel Weitman
 * Creation Date: 10/06/18
 * Last Update: 10/12/18
 * Description: Header file for Cards object
 */
using namespace std;

class Cards{
    
    private:
        int value;
        int suit;
        
    public:
        Cards();//Default constructor
        Cards(int, int);//non-default constructor
        int getValue();//gets value of a Cards object
        int getSuit();//get suit of a Cards object
        void displayCard();//displays a Cards object
        bool equal(Cards);//determines if two Cards objects are equal
        Cards operator =(const Cards&);//overloaded assignment operator
        bool operator <(Cards);//overloaded < operator for Cards object
        bool operator >(Cards);//overloaded > operator for Cards object
        bool operator ==(Cards);//overloaded == operator for Cards object
        bool operator !=(Cards);//overloaded != operator for Cards object
        
};
#endif 
