#include <iostream>
#include <utility>
#include "int.h"
#include "d_stree.h"
#include "d_random.h"
#include "d_except.h"

using namespace std;

int main(){
    
    srand(time(0));
    
    stree<integer> integerTree;
    
    for(int i = 0; i < 100; i++){
        integer temp((rand() % 6) + 1);
        cout << temp.getInt() << " ";
    }
   
    
    
    return 0;
}
