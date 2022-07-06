#include <iostream>
#include <stdlib.h>
#include "matrix.h"

using namespace std;

int main(){
    
    int n = 10;
    matrix A(n, n);
    matrix B(n, n);
    
    A.populateMR(1, 100);
    B.populateMR(1, 100);
    
    
    while(true){
        
        A*B;
        
        if(n < 1000){
            n *= 10;
            A.setDim(n, n);
            B.setDim(n, n);
            A.populateMR(1, 100);
            B.populateMR(1, 100);
        } else {
            n += 1000;
            A.setDim(n, n);
            B.setDim(n, n);
            A.populateMR(1, 100);
            B.populateMR(1, 100);
        }
        
    }

    return 0;
}
