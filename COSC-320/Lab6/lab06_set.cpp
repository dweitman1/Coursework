#include <iostream>
#include <set>
#include "d_state.h"

using namespace std;

int main(){

    set<stateCity> A;
    set<stateCity>::iterator p;
    string st;
    
    A.emplace("New York", "New York");
    A.emplace("Tampa", "Florida");
    A.emplace("Maryland", "Salisbury");
    A.emplace("Colorado", "Denver");
    A.emplace("Texas", "Houston");
    
    cout << "Enter a state: ";
    getline(cin, st);
    
    p = A.begin();
    p = A.find(st);
    
    if(p != A.end()){
        cout << *p << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    
   
    
    return 0;


}
