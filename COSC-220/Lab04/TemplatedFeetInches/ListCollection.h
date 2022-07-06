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

#endif
