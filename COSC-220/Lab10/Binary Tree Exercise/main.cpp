#include <iostream>
#include "BinaryTree.h"

using namespace std;

/*
    Templated binary search tree.
    Author: Maliak Green Dan Weitman
    Created: 11/26/2018
    Updated: 11/26/2018
*/
int main()
{
    BinaryTree <int> access;
      int selection;
    while(selection != 7)
    {
  cout << "1. Input new node.\n" << "2. Delete node.\n" << "3. Find node.\n" << "4. Print tree.\n" 
  << "5. Print ordered list.\n" <<"6. Display tree information.\n" <<"7. Quit.\n" << endl;
  

  cout << "Input selection: ";
  cin >> selection;
  
 
  if(selection == 1){
    int val;
    cout<<"Input new value: ";
    cin >> val;
    access.insertNode(val);
    cout << endl;
   
  } else if (selection == 2){
    int select;
    cout<< "What value do you want removed? ";
    cin >> select;
    cout << endl;
    access.remove(select);
    cout << endl;
    
  } else if (selection == 3){
    int find;
    cout << "Which node do you want to find: ";
    cin >> find;
    bool res = access.searchNode(find);
    if(res)
      cout<< find << " is in tree. \n\n";
    else
      cout << find <<" is not in tree. \n\n";
    
  } else if (selection == 4){
      
    cout << "Printing... \n";
    access.PrintTree();
    cout << endl;
    
  } else if (selection == 5){
    access.displayInOrder();
    cout << endl;
    
  } else if (selection == 6){
    cout << "Tree information" << endl;
    cout << "# of nodes: " << access.nodeCPub() << endl;
    cout << "# of leaf nodes: " << access.leafPub() << endl;
    cout << "Tree height: " << access.heightPub() << endl;
    cout << endl;
  }
}

    return 0;
}
 
