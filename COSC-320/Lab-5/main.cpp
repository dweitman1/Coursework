#include <iostream>
#include <stdlib.h>
#include "heapq.h"

/* Author: Daniel Weitman
 * Course: COSC-320
 * Instructor: Anderson
 * Date: 3/14/19
 * 
 */

using namespace std;

int main(){
    
    srand(time(0));
    heapq<string> a(6);
    
    
    a.enqueue("Dan", 10);
    a.enqueue("Steve", 8);
    a.enqueue("Victor", 20);
    a.enqueue("Edward", 11);
    a.enqueue("Alex", 12);
    a.enqueue("Eric", 40);
    a.enqueue("Matthew", 9);
    a.print();
    
    cout << a.peek() << endl;
    cout << a.dequeue() << endl;
    a.print();
    
    a.dequeue();
    a.dequeue();
    a.print();
    
    heapq<string> b(1000000);
    for(int i = 0; i < 1000000; i++){
        if(i == 999 || i == 9999 || i == 99999 || i == 999999){
            b.timeEn("John Doe", (rand() % 100) + 1);
            b.timeDe();
        } else {
            b.enqueue("John Doe", (rand() % 100) + 1);
        }
    }
    
    return 0;
}
