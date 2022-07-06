#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Cards.h"
#include "Deck.h"
#include "Hand.h"
/*Author: Daniel Weitman
 * Creation Date: 10/06/18
 * Last Update: 10/12/18
 * Description: Implementation of Hand object
 */
using namespace std;
/* Description: default constructor of Hand object
 * Parameters: none
 * Return: void
 */
Hand :: Hand(){
    for(int i = 0; i < 5; i++){
        hand[i] = Cards(12, 3);
    }
    type = 0;
}
/* Description: deals a hand to each player from the Deck object
 * Parameters: int start deal, int numPlayers, Deck set
 * Return: void
 */
void Hand :: dealHand(int start,int num, Deck a){
    int j = 0;
    for(int i = start; i < num * 5; i+=num){
        hand[j] = a[i];
        j++;
    }/*
    hand[0] = Cards(8, 2);
    hand[1] = Cards(9, 2);
    hand[2] = Cards(10, 2);
    hand[3] = Cards(11, 2);
    hand[4] = Cards(12, 2);
    */
}
/* Description: sorts a hand in order of face value
 * Parameters: none
 * Return: void
 */
void Hand :: sortHand(){
    Hand h; 
    Cards temp;
    
    for(int i = 0; i < 5; i++){
        h[i] = hand[i]; 
    }
    
    for(int i = 0; i < 5; i++){  
        for(int j = 0; j < 5 - 1; j++){
            if(h.hand[j] > h.hand[j + 1]){
                temp = h.hand[j];
                h.hand[j] = h.hand[j + 1];
                h.hand[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < 5; i++){
        hand[i] = h[i]; 
    }
    h.displayHand();
}
/* Description: displays the hand of a player
 * Parameters: none
 * Return: void
 */
void Hand :: displayHand(){
    for(int i = 0; i < 5; i++){
        cout << "|";
        hand[i].displayCard();
        cout << "|  ";
    }
}
/* Description: alters a players hand based on their desired draws
 * Parameters: int numDraws, int posDeck, Deck set
 * Return: void
 */
void Hand :: setDraws(int draw, int &pos, Deck a){
    hand[draw - 1] = a[pos];
    type = 0;
    pos++;
}
/* Description: finds the type of hand a player has
 * Parameters: none
 * Return: void
 */
void Hand :: findType(){
    int values[5];
    
    for(int i = 0; i < 13; i++){
      arr[i] = 0;
    }
    
    for(int i = 0; i < 5; i++){
        values[i] = hand[i].getValue();
        for(int j = 0; j < 13; j++){
            if(values[i] == j){
                arr[j]++;
            }
        }
    }
   /* for(int i = 0; i < 13; i++){
      cout << i << ": " << arr[i] << endl;
    }*/
    int pair = 0;
    int ToK = 0;
    int str = 0;
    int flu = 0;
    for(int i = 0; i < 13; i++){
        //one pair
        if(arr[i] == 2){
            type = 1;
            pair++;
        }
        //two pair
        if(pair == 2){
            type = 2;
        }
        //three of a kind
        if(arr[i] == 3){
            type = 3;
            ToK++;
        }
        //straight
        if(arr[i]==1 && arr[i+1]==1 && arr[i+2]==1 && arr[i+3]==1 && arr[i+4]==1){
            type = 4;
            str++;
        }
        //flush
        if(hand[0].getSuit() == hand[1].getSuit() && hand[0].getSuit() == hand[2].getSuit() && hand[0].getSuit() == hand[3].getSuit() && hand[0].getSuit() == hand[4].getSuit()){
            type = 5;
            flu++;
        }
        //full house
        if(pair == 1 && ToK == 1){
            type = 6;
        }
        //four of a kind
        if(arr[i] == 4){
            type = 7;
        }
        //straight flush
        if(str == 1 && flu == 1){
            type = 8;
        }
    }
    displayType();
}
/* Description: displays the type of a hand a player has as string literal
 * Parameters: none
 * Return: void
 */
void Hand :: displayType(){
    cout << "--- ";
    if(type == 0){
        cout << "High Card" << endl;
    } else if (type == 1){
        cout << "One Pair " << endl;
    } else if (type == 2){
        cout << "Two Pair " << endl;
    } else if (type == 3){
        cout << "Three of a Kind" << endl;
    } else if (type == 4){
        cout << "Straight " << endl;
    } else if (type == 5){
        cout << "Flush" << endl;
    } else if (type == 6){
        cout << "Full House" << endl;
    } else if (type == 7){
        cout << "Four of a Kind" << endl;
    } else if (type == 8){
        cout << "Straight Flush" << endl;
    } 
}
/* Description: accesses the type of hand a player has
 * Parameters: none
 * Return: int typeValue
 */
int Hand :: getType(){
    return type;
}
/* Description: deteremines winner when tie of type occurs
 * Parameters: Hand compared, int calledPos, comparedPos
 * Return: int playerIndex
 */
int Hand :: tieWinner(Hand &obj, int leftPos, int rightPos){
    Hand left;
    Hand right;
    int leftHigh;
    int rightHigh;
    int flag;
    
    for(int i = 0; i < 5; i++){
        left[i] = hand[i];
        right[i] = obj[i];
    }
    
    if(type == 0 || type == 4 || type == 5 || type == 8){
        do{
            flag = 0;
            for(int i = 0; i < 4; i++){
                if(left[i] < left[i + 1] ){
                    leftHigh = left[i].getValue();
                }
                if(right[i] < right[i + 1]){
                    rightHigh = right[i].getValue();
                }
            }
            if(rightHigh == leftHigh){
                for(int i = 0; i < 5; i++){
                    if(rightHigh == right[i].getValue()){
                        right[i] = Cards(0, 0);
                    }
                    if(leftHigh == left[i].getValue()){
                        left[i] = Cards(0, 0);
                    }
                }
                flag = 1;
            } else if(rightHigh > leftHigh){
                return rightPos;
            } else if(leftHigh > rightHigh){
                return leftPos;
            } 
            
        }while(flag);
        return 100;
        
    } else if (type == 1){
        for(int i = 0; i < 13; i++){
            if(right.arr[i] == 2){
                rightHigh = i;
            }
            if(left.arr[i] == 2){
                leftHigh = i;
            }
        }
        
        if(rightHigh > leftHigh){
            return rightPos;
        } else if(leftHigh > rightHigh){
            return leftPos;
        } else {
            for(int i = 0; i < 13; i++){
                if(left.arr[i] == 2){
                    
                }
            }
        }
    } else if (type == 2){
        
    } else if (type == 3){
        
    } else if (type == 6){
        
    } else if (type == 7){
        
    } 
    return 100;
}
/* Description: [] overload for facilitated access
 * Parameters: int posHand
 * Return: Cards indexed
 */
Cards& Hand :: operator[](const int &x){
    return hand[x];
}
/* Description: determines if calling is > parameter
 * Parameters: Hand right
 * Return: bool greater
 */
bool Hand :: operator >(const Hand right){
    if(type > right.type){
        return true;
    } else {
        return false;
    } 
}
/* Description: determines if calling is < parameter
 * Parameters: Hand right
 * Return: bool lesser
 */
bool Hand :: operator <(const Hand right){
    if(type < right.type){
        return true;
    } else {
        return false;
    } 
}
/* Description: determines if calling is equals parameter
 * Parameters: Hand right
 * Return: bool equivalent
 */
bool Hand :: operator ==(const Hand right){
    if(type == right.type){
        return true;
    } else {
        return false;
    } 
}
