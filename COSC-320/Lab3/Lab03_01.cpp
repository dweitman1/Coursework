/* Author: Daniel Weitman
 * Instructor: Lu
 * Date: 9/18/19
 * 
 */

#include <iostream>
#include "countOneChild.h"

using namespace std;

int main(){
    
    tnode<char> *a, *b, *c, *d, *e, *f, *g;
    int interiorCount = 0;
    
    d = new tnode<char> ('D');
    g = new tnode<char> ('G');
    f = new tnode<char> ('F');
    b = new tnode<char> ('B', d, NULL);
    e = new tnode<char> ('E', NULL, g);
    c = new tnode<char> ('C', e, f);
    a = new tnode<char> ('A', b, c);
    
    countInterior(a, interiorCount);
    cout << "Interior nodes: " << interiorCount << endl;
   
    return 0;
}
