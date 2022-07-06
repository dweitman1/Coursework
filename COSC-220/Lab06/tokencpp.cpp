#include <iostream>
#include <sstream>
#include <cstdlib>

#include "ListCollection.h"
#include "Stack.h"

using namespace std;

int main()
{
    // string input = "234 32 + 7 *";
    // Must have spaces between tokens.

    string input;
    cout << "Enter a postfix expression: ";
    getline(cin, input);

    ListCollection<string> tokens;
    stringstream inputstream(input);
    string token;

    // Tokenizing w.r.t. space ' '
    while (getline(inputstream, token, ' '))
        tokens.pushBack(token);

    // Printing the token vector
   // for (int i = 0; i < tokens.size(); i++)
        //cout << tokens.getElement(i) << endl;
    //***
    Stack<string> stack;
    string one;
    string two;
    double val1;
    double val2;
    string fin;
    
    for(int i = 0; i < tokens.size(); i++){
        if(tokens.getElement(i) == "+"){
            one = stack.pop();
            two = stack.pop();
            val1 = atof(one.c_str()); 
            val2 = atof(two.c_str());
            fin = to_string(val1 + val2);
            stack.push(fin); 
            
        } else if(tokens.getElement(i) == "-"){
            one = stack.pop();
            two = stack.pop();
            val1 = atof(one.c_str()); 
            val2 = atof(two.c_str());
            fin = to_string(val2 - val1);
            stack.push(fin); 
            
        } else if(tokens.getElement(i) == "*"){
            one = stack.pop();
            two = stack.pop();
            val1 = atof(one.c_str()); 
            val2 = atof(two.c_str());
            fin = to_string(val1 * val2);
            stack.push(fin); 
            
        } else if(tokens.getElement(i) == "/"){
            one = stack.pop();
            two = stack.pop();
            val1 = atof(one.c_str()); 
            val2 = atof(two.c_str());
            fin = to_string(val2 / val1);
            stack.push(fin); 
            
        } else {
            stack.push(tokens.getElement(i));
        }
    }
    
    cout << "Answer: ";
    stack.displayStack();
    cout << endl;
}
