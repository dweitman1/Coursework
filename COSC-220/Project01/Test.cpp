#include <iostream>
#include <cstring>
#include "Cards.h"
#include "Deck.h"
#include "Hand.h"
/*Author: Daniel Weitman
 * Creation Date: 10/06/18
 * Last Update: 10/12/18
 * Description: Main function for playing poker
 */
using namespace std;

int main(){

    int numPlayers = 0;
    
    do{
    cout << "Enter number of players (2-6): ";
    cin >> numPlayers;
    } while (numPlayers < 2 || numPlayers > 7);
    
    //Creates and shuffles a deck of cards to be played
    Deck set;
    set.shuffleDeck();
    //set.displayDeck();
    cout << endl;
    
    //Creates hand object for each player
    Hand players[numPlayers];
    
    //Deals hands to players
    for(int i = 0; i < numPlayers; i++){
        players[i].dealHand(i, numPlayers, set);
    }
    
    //Stores position of Deck
    int pos = numPlayers * 5;
    
    //Draws cards for replacement
    int numDraw;
    for(int i = 0; i < numPlayers; i++){
        cout << "Player " << i + 1 << " ---  ";
        players[i].sortHand();
        players[i].findType();
        
        do{
            cout << "Amount to draw (0-3): ";
            cin >> numDraw;
        } while (numDraw < 0 || numDraw > 3);
      
        int *array = new int[numDraw];
        
        //Replaces cards for drawing
        for(int j = 0; j < numDraw; j++){
            cout << "Which position to draw ";
            do{
                cout << "Draw #" << j + 1 << " (1-5): ";
                cin >> array[j];
            } while (array[j] < 1 || array[j] > 5);
            players[i].setDraws(array[j], pos, set);
        }
        cout << endl;
        delete [] array;
    }
    
    for(int i = 0; i < numPlayers; i++){
        cout << "Player " << i + 1 << " ---  ";
        players[i].sortHand();
        players[i].findType();
    }
    
    int winner = 0;
    for(int i = 0; i < numPlayers - 1; i++){
        if(players[winner] < players[i + 1]){
            winner = i + 1;
        } else if(players[winner] == players[i + 1]){
            winner = players[winner].tieWinner(players[i + 1], winner, i + 1);
        } 

    }
    if(winner == 100){
        cout << "TIE!" << endl;
    } else {
         cout << "\nPLAYER " << winner + 1 << " WINS!" << endl;
    }
    return 0;
}
