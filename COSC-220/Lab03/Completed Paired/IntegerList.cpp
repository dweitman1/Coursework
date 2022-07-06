#include <iostream>
#include <cstdlib>
#include "IntegerList.h"
/*
Author: Maliak Green, Daniel Weitman

Created: 09/17/18
Last Updated: 09/22/18
Description: Lab worked onto to manipulate list objects with c++ operands.
*/


using namespace std;
IntegerList :: IntegerList()
{
  list = nullptr;
  
}

IntegerList::IntegerList(int size)
{
    list = new int[size];
    numElements = size;
    for (int ndx = 0; ndx < size; ndx++)
        list[ndx] = 0;
}

IntegerList::~IntegerList()
{
    delete [] list;
}

IntegerList::IntegerList(const IntegerList &obj)
{
    numElements = obj.numElements;
    list = new int[numElements];
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
}



bool IntegerList::isValid(int element) const
{
    bool status;
 IntegerList l1,l2,l3;
  l3 = l1 + l2;
  l3.displayList();
    if (element < 0 || element >= numElements)
        status = false;
    else
        status = true;
    return status;
}

void IntegerList::setElement(int element, int value)
{
    if (isValid(element))
        list[element] = value;
    else
    {
        cout << "Error: Invalid subscript\n";
        exit(EXIT_FAILURE);
    }
}

int IntegerList::getElement(int element) const
{
    if (isValid(element))
        return list[element];
    else
    {
        cout << "Error: Invalid subscript\n";
        exit(EXIT_FAILURE);
    }
}

void IntegerList::displayList() const
{
    for (int i = 0; i < numElements; i++)
        cout << list[i] << " ";
    cout << endl;
}
//+ operator to allow IntegerList object addition.
const IntegerList IntegerList::operator+(const IntegerList &right)
{
  int newElem = numElements + right.numElements;// combine the sizes into a new one.
  IntegerList l(newElem);//create new list with combined size.
  //populate first half.
  for(int i = 0; i<numElements; i++)
  {
      l.list[i] = list[i];
  }
  
  int j = 0;//populate second half.
  for(int i = numElements;  i<newElem; i++)
  {
    l.list[i] = right.list[j];
    j++;
  }
  return l;
}

const IntegerList IntegerList::operator=(const IntegerList &right)
{
    delete [] list;
    numElements = right.numElements;
    list = new int[numElements];
    for (int i = 0; i < numElements; i++)
        list[i] = right.list[i];

    return *this;
}
//Return element at current list position.
int& IntegerList::operator[] (const int &x)
{
  if(x < 0)//return first.
    return list[0];
  
  else if(x > numElements - 1)//return last.
    return list[numElements - 1];
  
  else//return specific element.
 return list[x]; 
}
//resize list to new user selected size.
void IntegerList :: resize(int size)
{
    int array[size];
    int number = numElements;
    
        if(size > numElements){
            for(int i = 0; i < numElements; i++){
                array[i] = list[i];
            }
            
            delete [] list;
            list = new int[size];
            numElements = size;
            
            for(int i = 0; i < number; i++){
                list[i] = array[i];
            }
            for(int i = number; i < size; i++){
                list[i] = 0;
            }
        } else if (size < numElements){
            for(int i = 0; i < size; i++){
                array[i] = list[i];
            }
            
            delete [] list;
            list = new int[size];
            numElements = size;
            
            for(int i = 0; i < size; i++){
                list[i] = array[i];
            }
        }
}
//Returns a subset of an IntegerList between two integers
const IntegerList IntegerList :: sublist(int a, int b){

    int size = b - a + 1;
    IntegerList l(size);
    int j = 0;
    
    for(int i = 0; i <= b; i++){
        if(i >= a){
            l.list[j] = list[i];
            j++;
        }
    }
    return l;
}    
//Returns a subset of an IntegerList after a certain element
const IntegerList IntegerList :: sublist(int a){
    
    int size = numElements - a;
    IntegerList l(size);
    int j = 0;
    
    for(int i = 0; i < numElements; i++){
        if(i >= a){
            l.list[j] = list[i];
            j++;
        }
    }
    return l;
}
//Sorts an IntegerList in ascending order
const IntegerList IntegerList :: sort(){
    IntegerList l(numElements);
    int temp;
    
    l = *this; 
    
    for(int i = 0; i < numElements; i++){
        for(int j = 0; j < numElements; j++){
            if(l.list[j] > l.list[j+1]){ 
            temp = l.list[j];
            l.list[j] = l.list[j+1];
            l.list[j+1] = temp;
            
            }
        }    
    }
    
    return l;
}

