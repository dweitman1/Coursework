#include <iostream>
#include <string>
#include <cstring>
#include <stack>

/*
 Author: Daniel Weitman
 Description: Determines if delimiters of user entered expression are balanced
 Date Created: 10/23/18
 Date last updated: 10/29/18
 */

using namespace std;

int main(){
    
    //Gets entire user entered expression
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);
    
    //Converts expression from a string to character array
    int sz = expression.size() + 1;
    char line[sz];
    strcpy(line, expression.c_str());
    
    stack<char> delimiter;
    char temp;
    
    //To push and pop delimiter chars onto stack to check balance
    for (int i = 0; i < sz; i++){
        
        //Pushes opening delimiters
        if(line[i] == '('){
            delimiter.push('(');
        }
        if(line[i] == '{'){
            delimiter.push('{');
        }
        if(line[i] == '['){
            delimiter.push('[');
        }
        
        //Conditions for checking ending delimiters are balanced
        if(line[i] == ')'){
            if(delimiter.empty()){
                delimiter.push(')');
            }
            temp = delimiter.top();
            if(temp != '('){
                break;
            } else {
                delimiter.pop();
            }
        }
        if(line[i] == '}'){
             if(delimiter.empty()){
                delimiter.push('}');
            }
            temp = delimiter.top();
            if(temp != '{'){
                break;
            } else {
                delimiter.pop();
           }
        }
        if(line[i] == ']'){
           if(delimiter.empty()){
                delimiter.push(']');
            }
            temp = delimiter.top();
            if(temp != '['){
                break;
           } else {
                delimiter.pop();
           }
        }
    }
    
    //Print whether or not delimiters of expression are balanced.
    if(delimiter.empty()){
        cout << "Delimiters are balanced." << endl;   
    } else {
        cout << "Delimiters are not balanced." << endl; 
    }
        
    return 0;
}
