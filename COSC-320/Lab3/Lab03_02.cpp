/* Author: Daniel Weitman
 * Instructor: Lu
 * Date: 9/18/19
 * 
 */

#include <iostream>
#include "max.h"

int main(){
    
    tnode<int> *a, *b, *c, *d, *e, *f;
    int max = 0;
    
    d = new tnode<int> (5);
    e = new tnode<int> (48);
    f = new tnode<int> (12);
    b = new tnode<int> (40, d, NULL);
    c = new tnode<int> (15, e, f);
    a = new tnode<int> (35, b, c);
    
    maxVal(a, max);
    cout << "Maximum value: " << max << endl;
    
    
    return 0;
}
