#include <iostream>
#include <cstdlib>
#include "int.h"
#include "BinaryTree.h"

using namespace std;

int main(){
    
    srand(time(0));
    
    BinaryTree<integer> integerTree;
    integer temp0(0);
    integer temp1(1);
    integer temp2(2);
    integer temp3(3);
    integer temp4(4);
    integer temp5(5);
    integer temp6(6);
    int x;
    
    for(int i = 0; i < 10000; i++){
      x = (rand()%7);
      switch (x){
          
    case 0:
	  if(integerTree.searchNode(temp0)){
	    temp0.incCount();
        /*integerTree.remove(temp0);
	    integerTree.insertNode(temp0);*/
	  } else {
	    integerTree.insertNode(temp0);
	  }
	  break;
	case 1:
	  if(integerTree.searchNode(temp1)){
	    temp1.incCount();
        /*integerTree.remove(temp1);
	    integerTree.insertNode(temp1);*/
	  } else {
	    integerTree.insertNode(temp1);
	  }
	  break;
	  
	case 2:
	  if(integerTree.searchNode(temp2)){
	    temp2.incCount();
        /*integerTree.remove(temp2);
	    integerTree.insertNode(temp2);*/
	  } else {
	    integerTree.insertNode(temp2);
	  }
	  break;
	  
	case 3:
	  if(integerTree.searchNode(temp3)){
	    temp3.incCount();
        /*integerTree.remove(temp3);
	    integerTree.insertNode(temp3);*/
	  } else {
	    integerTree.insertNode(temp3);
	  }
	  break;
	  
	case 4:
	  if(integerTree.searchNode(temp4)){
	    temp4.incCount();
        /*integerTree.remove(temp4);
	    integerTree.insertNode(temp4);*/
	  } else {
	    integerTree.insertNode(temp4);
	  }
	  break;
	  
	case 5:
	  if(integerTree.searchNode(temp5)){
	    temp5.incCount();
        /*integerTree.remove(temp5);
	    integerTree.insertNode(temp5);*/
	  } else {
	    integerTree.insertNode(temp5);
	  }
	  break;
	  
	case 6:
	  if(integerTree.searchNode(temp6)){
	    temp6.incCount();
        /*integerTree.remove(temp6);
	    integerTree.insertNode(temp6);*/
	  } else {
	    integerTree.insertNode(temp6);
	  }
	  break;
	
      }
     
    }
    
    cout << "Values in the tree:\n";
    cout << temp1 << endl;
    cout << temp2 << endl;
    cout << temp3 << endl;
    cout << temp4 << endl;
    cout << temp5 << endl;
    cout << temp6 << endl << endl;
    integerTree.PrintTree();
    
    return 0;
}
