#include <iostream>
#include <fstream>
#include <vector>
/* Author: Daniel Weitman
 * Date created: 11/21/18
 * Last update: 11/27/18
 * Description: Allows user to enter words and then check if they in dictionary
 * text and if they are not found gives some suggestions close to entered char array
 * 
 */
using namespace std;

int main(){
    
    ifstream infile("en_US.txt");
    string store;
    vector<string> terms;
    bool erase = true;
    
    //Takes in the dictionary list
    while(infile >> store){
        terms.push_back(store);
    }
    
    //Removes all '/' tags, contractions, and converts all uppercases to lowercase
    for(unsigned int i = 0; i < terms.size(); i++){
        for(unsigned int j = 0; j < terms[i].size(); j++){
            if(terms[i][j] > 64 && terms[i][j] < 91){
             terms[i][j] += 32;   
            }
                
            if(terms[i][j] == '\''){
               erase = false;
            }
            
            if(terms[i][j] == '/'){
                terms[i].resize(j);
                //continue;
            }
            
        }
        if(!erase){
            terms.erase(terms.begin() + i);
            erase = true;
            i--;
        }
    }
    
    /*for(int i = 0; i < terms.size(); i++){
        cout << terms[i] << endl;
    }*/
    
    string word;//Word to be checked against dictionary
    unsigned int count = 0;//Checks if word has one letter difference
    char temp;//Swap for transposes of two connected letters
    bool flag;//Flag for printing correct output
    vector<string> suggestions;//Vector to store all words close enough to entered
    
    //Loops entire program to allow multiple searches
    while(true){
    flag = true;
    cout << "Enter word to search for (none to quit): ";
    
    getline(cin, word);
    if(word.empty()){
        break;
    }
    
    //Converts the entered word's uppercases to lowercase
    for(unsigned int i = 0; i < word.size(); i++){
        if(word[i] > 64 && word[i] < 91){
             word[i] += 32;   
        }
    }
    
    //Searches dictionary for entered word and/or finds suggestions
    for(unsigned int i = 0; i < terms.size(); i++){
        count = 0;
        
        //If word is in dictionary display and trigger while exit condition
        if(word == terms[i] && flag){
            cout << word << " is in the dictionary." << endl;
            suggestions.push_back(word);
            flag = false;
            
        //Finds suggestions 
        } else {
            
            //Only necessary to work on words of same length
            if(terms[i].size() == word.size()){
                
                //Increments count if letter of entered word equals letter of term pos
                for(unsigned int j = 0; j < terms[i].size(); j++){
                    if(terms[i][j] == word[j]){
                            count++;
                    }
                }
                
                //Pushes suggestions onto a vector 
                if(word.size() == count + 1){
                    suggestions.push_back(terms[i]);
                }
                
                //Finds transpose suggestions
                for(unsigned int j = 0; j < word.size() - 1; j++){
                    //Swaps two connected letters in word
                    temp = word[j];
                    word[j] = word[j + 1];
                    word[j + 1] = temp;
                      
                    //Pushes suggestions onto a vector
                    if(terms[i] == word){
                        suggestions.push_back(terms[i]);
                    }
       
                    //Resets word to original
                    word[j + 1] = word[j];
                    word[j] = temp;
                }
            }
        }
    }
    
    //Conditional printing
    if(flag && !suggestions.empty()){
        cout << word << " is not in the dictionary." << endl;
        cout << "Here are some suggestions..." << endl;
        for(unsigned int i = 0; i < suggestions.size(); i++){
           cout << suggestions[i] << endl;
        }
    } 
    if(suggestions.empty()){
        cout << word << " is not in the dictionary." << endl;
    }
    suggestions.clear();
    cout << endl;
    }
    
    return 0;
}
