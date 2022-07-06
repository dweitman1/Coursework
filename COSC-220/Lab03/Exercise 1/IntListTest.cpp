#include <iostream>
#include "IntegerList.h"

using namespace std;
/*
    Author: Don Spickler
    Creation Date: 9/10/2018
    Last Update: 9/10/2018
    Description: Testing program for the updated Interger List program.
    This is class is also called a safe array.
*/
void PopulateList(IntegerList &L, int size)
{
    cout << "In PopulateList" << endl;
    for (int i = 0; i < size; i++)
        L[i] = i; 
    cout << "Out PopulateList" << endl;
}

void PopulateList2(IntegerList L, int size)
{
    cout << "In PopulateList2" << endl;
    for (int i = 0; i < size; i++)
        L[i] = i; 
    cout << "Out PopulateList2" << endl;
}

int main()
{
    IntegerList l1(7);
    IntegerList l2(17);

    for (int i = 0; i < 7; i++)
        l1[i] = i * i;
   
    
  
    PopulateList2(l1, 7); 
    PopulateList(l2, 17);

    l1.displayList();
    l2.displayList();

    IntegerList l3;
    
    l3 = l1 + l2;
    l3.displayList();


    l3[4] = 100;
    l3.displayList();

    IntegerList l4 = l3.sublist(3, 8);
    l4.displayList();

    IntegerList l5 = l3.sublist(8);
    l5.displayList();

    IntegerList l6 = l3.sublist(3, 23);
    l6.displayList();

    l6.resize(5);
    l4.resize(30);
    l6.displayList();
    l4.displayList();

    IntegerList l7 = l3.sort();
    l3.displayList();
    l7.displayList();

    IntegerList l8 = l7;
    l8.displayList();
    
    return 0;
}
