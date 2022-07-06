#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>

using namespace std;
/*
 Author:  Daniel Weitman
 Creation Date: 9/24/18
 Last Update: 10/1/18
 Description: ListCollection class that will act as an array storing integers in an integer list. the class comes with public and private
 member functions to check certain properties of the list objects and manipulate them.
 Notes: All functions not apart of our lab 4 turn in assignment have been commented out.
*/
template <class T>
class ListCollection
{
  private:
    T *list;// Pointer to the array.
    int numElements;// Number of elements.
    int numCapacity;// Maximum number of elements.
    bool isValid(int) const;// Validates subscripts.
    void resize(int);// Resizes list, moved to private.
    
  public:
    ListCollection(int sz = 10);   // Constructor
    ~ListCollection();             // Destructor
    void setElement(int, T);     // Sets an element to a value
    T getElement(int) const;     // Returns an element
    void displayList(bool nl = false) const;      // Display list

    ListCollection(const ListCollection &obj);
    const ListCollection<T>& operator=(const ListCollection &right);

    const ListCollection<T> operator+(const T &right);
    const ListCollection<T> sublist(int, int);
    const ListCollection<T> sublist(int);
    const ListCollection<T> sort();
    
    // New functions
    void clear();
    int size();
    int capacity();
    void pushFront(T);
    void pushBack(T);
    T popFront();
    T popBack();
    void insertOrdred(T);
    void removeElement(T);
    void insert(int, T);
	void remove(int);
	
};
template <class T>
ListCollection<T>::ListCollection(int sz)
{
  numElements = 0;
  numCapacity = sz;
  list = new T[sz];
}

/*
 Description: This function validates if an element position is in the list object.
 Parameters: integer element.
 Return: true if element is in list, false if not.
 Notes: None.
 */
template <class T>
bool ListCollection<T>::isValid(int elem)const
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
template <class T>
ListCollection<T>::ListCollection(const ListCollection &obj)
{
  numElements = obj.numElements;
  numCapacity = obj.numCapacity;
  delete []list;
  list = new T[numCapacity];
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
template <class T>
void ListCollection<T>::resize(int newSize)
{
 T array[newSize]; // Temporary array for copying.
 int number = numCapacity; // Old array capacity.
  
  if(newSize > numCapacity) // If new size is greater, add 0s for extra indexes.
  {
    for(int i = 0; i < numCapacity; i++)
    {  
      array[i] = list[i];
    }
    delete [] list; // Delete old for memory.
    list = new T[newSize]; // New array.
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
   list = new T[newSize];
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
template <class T>
void ListCollection<T>::setElement(int pos, T data)
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
template <class T>
T ListCollection<T>::getElement(int pos)const
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
template <class T>
void ListCollection<T>::displayList(bool nl)const
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
template <class T>
const ListCollection<T> &ListCollection<T>::operator=(const ListCollection &right)
{
  
  numCapacity = right.numCapacity;
  numElements = right.numElements;

  delete [] list;
  list = new T[right.numElements];
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
template <class T>
ListCollection<T>::~ListCollection()
{
 delete [] list; 
}
/*
 Description: This function adds to arrays together
 Parameters: Array to be added
 Return: Summed Array
 Notes: None.
 */
template <class T>
const ListCollection<T> ListCollection<T>::operator +(const T &right){
    
    int newElements = numElements + right.numElements;
    T l(newElements);
    
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
/*
 Description: This function returns a sublist of an array
 Parameters: Two integer elements, indexStart and indexEnd.
 Return: Sub-Array
 Notes: None.
 */
template <class T>
const ListCollection<T> ListCollection<T>::sublist(int a, int b){
    
    int size = b - a + 1;
    ListCollection<T> l(size);
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
/*
 Description: This function returns a sublist of an array
 Parameters: Integer element
 Return: Sub-Array
 Notes: None.
 */
template <class T>
const ListCollection<T> ListCollection<T>::sublist(int a){
    
    int size = numElements - a;
    ListCollection<T> l(size);
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
/*
 Description: This function sorts an array from least to greatest
 Parameters: None
 Return: Sorted array
 Notes: None.
 */
template <class T>
const ListCollection<T> ListCollection<T>::sort(){
    
    ListCollection<T> l(numCapacity);
    l = *this;
    T swap;
    
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
/*
 Description: This function empties an array
 Parameters: None
 Return: None
 Notes: None.
 */
template <class T>
void ListCollection<T>::clear(){
    for(int i = 0; i < numCapacity; i++){
        list[i] = 0;
    }
    numElements = 0;
}
/*
 Description: This function returns number of elements stored
 Parameters: None
 Return: Integer
 Notes: None.
 */
template <class T>
int ListCollection<T>::size(){
    return numElements;
}
/*
 Description: This function returns capacity of array
 Parameters: None
 Return: Integer capacity
 Notes: None.
 */
template <class T>
int ListCollection<T>::capacity(){
    return numCapacity;
}
/*
 Description: This function adds an element to front of an array
 Parameters: Templated data
 Return: None
 Notes: None.
 */
template <class T>
void ListCollection<T>::pushFront(T a){
    
    numElements++;
    if(numElements > numCapacity){
        this->resize(numCapacity * 2);
    }
    for(int i = numElements; i > 0; i--){
        list[i] = list[i-1];
    }
    
    list[0] = a;
}
/*
 Description: This function adds an element to end of an array
 Parameters: Templated data
 Return: None
 Notes: None.
 */
template <class T>
void ListCollection<T>::pushBack(T a){
   numElements++;
   
    if(numElements > numCapacity){
        this->resize(numCapacity * 2);
    }
    
    list[numElements-1] = a;
}
/*
 Description: This function deletes and returns first element
 Parameters: None
 Return: First array element
 Notes: None.
 */
template <class T>
T ListCollection<T>::popFront(){
    
    T item;
    item = list[0];
    
    for(int i = 0; i < numCapacity + 1; i++){
        list[i] = list[i+1];
    }
    numElements = numElements -1;
    
    return item;
}
/*
 Description: This function deletes and returns last element
 Parameters: None
 Return: First array element
 Notes: None.
 */
template <class T>
T ListCollection<T>::popBack(){
    
    T item;
    item = list[numElements - 1];
    numElements = numElements -1;
    
    return item;
}
/*
 Description: This function inserts element front of all lesser values
 Parameters: Templated data
 Return: None
 Notes: None.
 */
template <class T>
void ListCollection<T>::insertOrdred(T a){
   
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
/*
 Description: This function removes element if found in array
 Parameters: Element to be deleted
 Return: None
 Notes: None.
 */
template <class T>
void ListCollection<T>::removeElement(T a){
    
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
/*
 Description: This function inserts element inside the list
 Parameters: Integer position, Templated data
 Return: None
 Notes: None.
 */
template <class T>
void ListCollection<T>::insert(int a, T b){
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
/*
 Description: Removes element given position
 Parameters: Integer position
 Return: None
 Notes: None.
 */
template <class T>
void ListCollection<T>::remove(int a){
    
    if(a > 0 && a < numElements - 1){
        
    list[a] = 0;
    numElements--;
        for(int j = a; j < numElements; j++){
                list[j] = list[j+1];
        }
    }
}

#endif
