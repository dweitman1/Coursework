/* Author: Daniel Weitman
 * Course: COSC-320
 * Instructor: Anderson
 * Due: 3/17/19
 * 
 */

#include <iostream>
#include "matrix.h"

using namespace std;


int main(int argc, char* args[]){
    
    matrix a(3, 3);
    
    a.populateMR(1, 10);
    a.setElement(5, 0, 1);
    a.setElement(6, 0, 2);
    a.setElement(7, 1, 2);
    a.setElement(a.getElement(0, 1), 1, 0);
    a.setElement(a.getElement(0, 2), 2, 0);
    a.setElement(a.getElement(1, 2), 2, 1);
    
    a.printM();
    a.transpose().printM();
    
    a.invert().printM();
 
    
    return 0;
}
