#ifndef HAND_H
#define HAND_H

#include <cstring>
#include "Cards.h"
#include "Deck.h"
/*Author: Daniel Weitman
 * Creation Date: 10/06/18
 * Last Update: 10/12/18
 * Description: Header file for Hand object
 */
using namespace std;

class Hand{

    private:
        Cards hand[5];
        int type;
        int arr[13];

    public:
        Hand();//default constuctor
        void dealHand(int, int, Deck);//function for dealing
        void sortHand();//sorts hand in order by face value
        void displayHand();//displays hand object
        void setDraws(int, int &, Deck);//alters hand with next deck position
        void findType();//finds the hand type 
        void displayType();//converts type from int to string literal
        int getType();//returns the type of hand
        int tieWinner(Hand &, int, int);//determines winner between two same types
        
        Cards& operator [](const int &x);//[] operator for easy access
        bool operator >(const Hand);//> operator for comparing hands by type
        bool operator <(const Hand);//< operator for comparing hands by type
        bool operator ==(const Hand);//== operator for comparing hands by type
};
#endif
