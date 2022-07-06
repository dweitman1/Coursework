#include"ListCollection.h"
#include<iostream>
/*
 Author: Maliak Green, Daniel Weitman
 Creation Date: 9/24/18
 Last Update: 10/1/18
*/
using namespace std;

ListCollection::ListCollection(int sz)
{
  numElements = 0;
  numCapacity = sz;
  list = new int[sz];
}

/*
 Description: This function validates if an element position is in the list object.
 Parameters: integer element.
 Return: true if element is in list, false if not.
 Notes: None.
 */
bool ListCollection::isValid(int elem)const
{
 if(elem >= 0 && elem < numElements - 1)
    return true;
 else
   return false;
}
/*
 Description: Copy Constructor for object assignment.
 Parameters: "old" const list object.
 Return: None.
 Notes: None.
 */

ListCollection::ListCollection(const ListCollection &obj)
{
  numElements = obj.numElements;
  numCapacity = obj.numCapacity;
  delete []list;
  list = new int[numCapacity];
 for(int i = 0; i < numCapacity; i++)
 {
  list[i] = obj.list[i]; 
 }
}
/*
 Description: This function resizes a list object to speicified size in parameter.
 Parameters: integer new list size.
 Return: None.
 Notes: None.
 */
void ListCollection::resize(int newSize)
{
 int array[newSize]; // Temporary array for copying.
 int number = numCapacity; // Old array capacity.
  
  if(newSize > numCapacity) // If new size is greater, add 0s for extra indexes.
  {
    for(int i = 0; i < numCapacity; i++)
    {  
      array[i] = list[i];
    }
    delete [] list; // Delete old for memory.
    list = new int[newSize]; // New array.
    numCapacity = newSize;
    for(int i = 0; i < number; i++)
    {
      list[i] = array[i]; // Copy elements from temp.
    }
    
    for(int i = number; i < numCapacity; i++)
    {
      list[i] = 0; // For extra indexes.
    }
  }
  else
  {
   for(int i = 0; i < newSize; i++)
   {
    array[i] = list[i]; // Use temp.
   }
   delete [] list;
   list = new int[newSize];
   numCapacity = newSize;
   
   for(int i = 0; i < newSize; i++)
   {
     list[i] = array[i];  
  }
  }
 
}

/*
 Description: This function sets the desired data in the list object given the element.
 Parameters: integer data and integer position.
 Return: None.
 Notes: None.
 */
void ListCollection::setElement(int pos, int data)
{

  if(pos < numElements && pos >= 0)
  list[pos] = data;
  
  else
    cout<<"Invalid position. \n";
}

/*
 Description: This function simply returns an element based on the given postion.
 Parameters: integer element.
 Return: integer value at given position.
 Notes: None.
 */
int ListCollection::getElement(int pos)const
{
 if(pos < 0)
   return *(list);
  else if(pos > numElements)
    return *(list + (numElements - 1));
  else
    return *(list + pos);
}

/*
 Description: This function displays the list objects contents based on the user's preffered style.
 Parameters: bool for list printing (horiziontal or vertical).
 Return: None.
 Notes: None.
 */

void ListCollection::displayList(bool nl)const
{
 if(nl == false)
 {
   for(int i = 0; i < numElements; i++)
   {
    cout<< *(list + i) << " "; 
   }
   cout<<endl;
 }
 else
 {
    for(int i = 0; i < numElements; i++)
   {
    cout<< *(list + i) << " " << endl; 
   } 
 }
}

/*
 Description: This function overloads the assignment operator allowing for the copying of list objects.
 Parameters: const list object.
 Return: list object caller modified.
 Notes: None.
 */

const ListCollection &ListCollection::operator=(const ListCollection &right)
{
  
  numCapacity = right.numCapacity;
  numElements = right.numElements;

  delete [] list;
  list = new int[right.numElements];
   for(int i = 0; i < right.numElements; i++)
  {
    list[i] = right.list[i];
  
  }
  
  return *this;
}

/*
 Description: Destructor deletes what list-collection object is pointing at.
 Parameters: None.
 Return: None.
 Notes: None.
 */
ListCollection::~ListCollection()
{
 delete [] list; 
}

const ListCollection ListCollection::operator +(const ListCollection &right){
    
    int newElements = numElements + right.numElements;
    ListCollection l(newElements);
    
    for(int i = 0; i < numElements; i++){
        l.list[i] = list[i];
    }
    
    int j = 0;
    
    for(int i = numElements;  i < newElements; i++){
        l.list[i] = right.list[j];
        j++;
    }
    return l;
}
const ListCollection ListCollection::sublist(int a, int b){
    
    int size = b - a + 1;
    ListCollection l(size);
    int j = 0;
    
    for(int i = 0; i <= b; i++){
        if(i >= a){
            l.list[j] = list[i];
            j++;
            l.numElements++;
        }
    }
    return l;
}
const ListCollection ListCollection::sublist(int a){
    
    int size = numElements - a;
    ListCollection l(size);
    int j = 0;
    
    for(int i = 0; i < numElements; i++){
        if(i >= a){
        l.list[j] = list[i];
        j++;
        l.numElements++;
        }
    }
    return l;
}
const ListCollection ListCollection::sort(){
    
    ListCollection l(numCapacity);
    l = *this;
    int swap;
    
    for (int i = 0; i < numElements; i++){
        for(int j = 0; j < numElements-1; j++){
            
            if(l.list[j] > l.list[j+1]){
                swap = l.list[j];
                l.list[j] = l.list[j+1];
                l.list[j+1] = swap;
            }
        }
    }
    
    l.numCapacity = l.numElements;
    
    return l;
}
void ListCollection::clear(){
    for(int i = 0; i < numCapacity; i++){
        list[i] = 0;
    }
    numElements = 0;
}
int ListCollection::size(){
    return numElements;
}
int ListCollection::capacity(){
    return numCapacity;
}
void ListCollection::pushFront(int a){
    
    numElements++;
    if(numElements > numCapacity){
        this->resize(numCapacity * 2);
    }
    for(int i = numElements; i > 0; i--){
        list[i] = list[i-1];
    }
    
    list[0] = a;
}
void ListCollection::pushBack(int a){
   numElements++;
   
    if(numElements > numCapacity){
        this->resize(numCapacity * 2);
    }
    
    list[numElements-1] = a;
}
int ListCollection::popFront(){
    
    int item;
    item = list[0];
    
    for(int i = 0; i < numCapacity + 1; i++){
        list[i] = list[i+1];
    }
    numElements = numElements -1;
    
    return item;
}
int ListCollection::popBack(){
    
    int item;
    item = list[numElements - 1];
    numElements = numElements -1;
    
    return item;
}
void ListCollection::insertOrdred(int a){
   
    if(numElements >= numCapacity){
        this->resize(numCapacity * 2);
    }
    int index = 0;
    
    for(int i = 0; i < numElements; i++){
        if(a > list[i]){
         
                index = i +1;
          
        } 
    }
        for(int i = numElements; i > index; i--){
            list[i] = list[i-1];
        }
    
        list[index] = a;
            numElements++;

}
void ListCollection::removeElement(int a){
    
    for(int i = 0; i < numCapacity; i++){
        if(a == list[i]){
            
            list[i] = 0;
            for(int j = i; j < numElements; j++){
                list[j] = list[j+1];
            }
            numElements--;
        }
            continue;
    }
}
void ListCollection::insert(int a, int b){
    numElements++;
    
    if(numElements > numCapacity){
        this->resize(numCapacity * 2);
    }
    if(a < numElements){
    int temp[numElements];
    
    for(int i = 0; i < a; i++){
        temp[i] = list[i];
    }
    for(int i = a; i < numElements; i++){
        temp[i+1] = list[i];
    }
    temp[a] = b;
    
    for(int i = 0; i < numElements; i++){
        list[i] = temp[i];
    }
    } else {
        list[numElements-1] = b;
    } 
}
void ListCollection::remove(int a){
    
    if(a > 0 && a < numElements - 1){
        
    list[a] = 0;
    numElements--;
        for(int j = a; j < numElements; j++){
                list[j] = list[j+1];
        }
    }
}
