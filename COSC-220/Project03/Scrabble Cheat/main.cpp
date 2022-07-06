#include <iostream>
#include <fstream>
#include <vector>
/* Author: Daniel Weitman
 * Date created: 12/1/18
 * Last update: 12/5/18
 * Description: Program used to cheat in scrabble that allows user
 * to enter a string of characters and give them all possible words forms
 * As well as all the possible words formed given one additional letter
 * 
 * 
 */
using namespace std;

struct add{
    string possible;
    char letter;
    int value;
};

int main(){
    
    ifstream infile("en_US.txt");
    string store;
    vector<string> terms;
    bool erase = true;
    
    //Takes in the dictionary list
    while(infile >> store){
        terms.push_back(store);
    }
    
    //Removes all '/' tags, contractions, and removes 
    //all terms with an uppercase and single characters
    for(unsigned int i = 0; i < terms.size(); i++){
        for(unsigned int j = 0; j < terms[i].size(); j++){
            if(terms[i][j] > 64 && terms[i][j] < 91){
                erase = false;
            }
                
            if(terms[i][j] == '\''){
                erase = false;
            }
            
            if(terms[i][j] == '/'){
                terms[i].resize(j);
                
                if(terms[i].size() == 1){
                erase = false;
                }
            }
            if(terms[i].size() == 1){
                erase = false;
            }
            
        }
        if(!erase){
            terms.erase(terms.begin() + i);
            erase = true;
            i--;
        }
    }
    /*
    for(unsigned int i = 0; i < terms.size(); i++){
        cout << terms[i] << endl;
    }
    */
    //*************************
    
    vector<string> scram; //Vector
    string set; //Input string entered by the user
    string temp; //Stores value of original string
    string temp2;//Original copy with no added chars
    unsigned int count;
    
    cout << "Enter the characters you have (none to quit): ";
    getline(cin, set);
    if(set.empty()){
        exit(0);
    }
    cout << "\nInput letters: " << set << endl << endl << 
    "Complete words from the input: " << endl; 
    
    temp = set;
    temp2 = set;
    //Determines possible words by checking each letter of every 
    //word and comparing to a count
    for(unsigned int i = 0; i < terms.size(); i++){
        count = 0;
        
        for(unsigned int j = 0; j < terms[i].size(); j++){
            for(unsigned int k = 0; k < set.size(); k++){
                //Removes the char from input string if the 
                //letter of term[i] is present
                if(terms[i][j] == set[k]){
                    set.erase(set.begin() + k);
                    count++;
                }
            }
        }
        //Compares count to size of term to determine if it 
        //is to be pushed onto the vector
        if(count >= terms[i].size()){
            scram.push_back(terms[i]);
        }
        set = temp;
    }
    
    if(scram.empty()){
        cout << "No possible words from input." << endl;
    }
    //Prints possible words from scrambled letters
    for(unsigned int i = 0; i < scram.size(); i++){
        cout << scram[i] << "\n";
    }
    
    cout << "\nScrabble words formed from the input and the needed extra letter: " 
    << endl;
    
    add pusher; //Temp variable to push data type add onto a vector of add
    pusher.value = 0;
    pusher.letter = 'a';
    vector<add> added; //Vector of possible words given one additional letter
    set.push_back('a');//add first addition of a letter to input string
    bool flag = false; // bool for ensuring an additional letter was needed
    bool flag2 = false;
    temp = set; 
    
    //Loop to incorporate adding all 26 letters
    for(int g = 0; g < 26; g++){
        //Loop to incorporate all terms in dictionary post preprocessing
        for(unsigned int i = 0; i < terms.size(); i++){
            count = 0;
            
            //Loop to increment count of matching letters
            for(unsigned int j = 0; j < terms[i].size(); j++){
                for(unsigned int k = 0; k < set.size(); k++){
                    if(terms[i][j] == set[k]){
                        set.erase(set.begin() + k);
                        count++;
                    }
                }
            }
            
             //If term is in list without added letter don't push
            for(unsigned int j = 0; j < scram.size(); j++){
                if(terms[i] == scram[j]){
                    flag = true;
                }
            }
            
            if(count >= terms[i].size() && !flag){
                pusher.possible = terms[i];
                added.push_back(pusher);
            }
            set = temp;
            flag = false;
        }
        temp[temp.size() - 1]++;//Alter set extra to next in alphabet
        set = temp; //Put original set plus new char into set
    }
    
    //Removes all duplicates for letters added to set unhandled condition
    unsigned int sz = added.size();
    for(unsigned int i = 0; i < sz; i++){
        for(unsigned int j = 0; j < sz; j++){
            if(added[i].possible == added[j].possible){
                added.erase(added.begin() + j);
                sz--;
            }
        }
    }
    
    //Corrects some mismatched letters of output
    for(unsigned int i = 0; i < added.size(); i++){
        for(unsigned int j = 0; j < added[i].possible.size(); j++){
            flag2 = false;
            
            for(unsigned int k = 0; k < temp2.size(); k++){
                if(temp2[k] == added[i].possible[j]){
                    flag2 = true;
                }
            }
            if(!flag2){
                added[i].letter = added[i].possible[j];
            }
        }
    }
    
    //For every letter of each word add its scrabble point 
    //worth to its value data member
    for(unsigned int i = 0; i < added.size(); i++){
        for(unsigned int j = 0; j < added[i].possible.size(); j++){
            if(added[i].possible[j] == 'a'){
                added[i].value += 1;
            } else if (added[i].possible[j] == 'b'){
                added[i].value += 3;
            } else if (added[i].possible[j] == 'c'){
                added[i].value += 3;
            } else if (added[i].possible[j] == 'd'){
                added[i].value += 2;
            } else if (added[i].possible[j] == 'e'){
                added[i].value += 1;
            } else if (added[i].possible[j] == 'f'){
                added[i].value += 4;
            } else if (added[i].possible[j] == 'g'){
                added[i].value += 2;
            } else if (added[i].possible[j] == 'h'){
                added[i].value += 4;
            } else if (added[i].possible[j] == 'i'){
                added[i].value += 1;
            } else if (added[i].possible[j] == 'j'){
                added[i].value += 8;
            } else if (added[i].possible[j] == 'k'){
                added[i].value += 5;
            } else if (added[i].possible[j] == 'l'){
                added[i].value += 1;
            } else if (added[i].possible[j] == 'm'){
                added[i].value += 3;
            } else if (added[i].possible[j] == 'n'){
                added[i].value += 1;
            } else if (added[i].possible[j] == 'o'){
                added[i].value += 1;
            } else if (added[i].possible[j] == 'p'){
                added[i].value += 3;
            } else if (added[i].possible[j] == 'q'){
                added[i].value += 10;
            } else if (added[i].possible[j] == 'r'){
                added[i].value += 1;
            } else if (added[i].possible[j] == 's'){
                added[i].value += 1;
            } else if (added[i].possible[j] == 't'){
                added[i].value += 1;
            } else if (added[i].possible[j] == 'u'){
                added[i].value += 1;
            } else if (added[i].possible[j] == 'v'){
                added[i].value += 4;
            } else if (added[i].possible[j] == 'w'){
                added[i].value += 4;
            } else if (added[i].possible[j] == 'x'){
                added[i].value += 8;
            } else if (added[i].possible[j] == 'y'){
                added[i].value += 4;
            } else if (added[i].possible[j] == 'z'){
                added[i].value += 10;
            }
        }
    }
    
    //Sorts added vector by point value using bubble sort
    for(unsigned int i = 0; i < added.size() - 1; i++){
        for(unsigned int j = 0; j < added.size() - i - 1; j++){
            if(added[j].value < added[j + 1].value){
                add bubble = added[j];
                added[j] = added[j + 1];
                added[j + 1] = bubble;
            }
        }
    }
    
    //Loop to print out the vector of words formed with one added letter to set
    for(unsigned int i = 0; i < added.size(); i++){
        cout << added[i].value << ": " << added[i].possible << " --- " << added[i].letter << endl;
    }
    
    return 0;
}
