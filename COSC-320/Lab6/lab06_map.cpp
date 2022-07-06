#include <iostream>
#include <map>

using namespace std;

int main(){

    map<string, string> A;
    map<string, string>::iterator p;
    string st;
    
    A.emplace(pair<string, string> ("New York", "New York"));
    A.emplace(pair<string, string> ("Tampa", "Florida"));
    A.emplace(pair<string, string> ("Maryland", "Salisbury"));
    A.emplace(pair<string, string> ("Colorado", "Denver"));
    A.emplace(pair<string, string> ("Texas", "Houston"));
    
    cout << "Enter a state: ";
    getline(cin, st);
    
    p = A.begin();
    p = A.find(st);
    
    if(p != A.end()){
        cout << p->first << ", " << p->second << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    
   
    
    return 0;


}
