#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>
/*
 Author: Maliak Green, Daniel Weitman
 Creation Date: 9/24/18
 Last Update: 9/24/18
 Description: ListCollection class that will act as an array storing integers in an integer list. the class comes with public and private
 member functions to check certain properties of the list objects and manipulate them.
 Notes: All functions not apart of our lab 4 turn in assignment have been commented out.
*/
class ListCollection
{
  private:
    int *list;// Pointer to the array.
    int numElements;// Number of elements.
    int numCapacity;// Maximum number of elements.
    bool isValid(int) const;// Validates subscripts.
    void resize(int);// Resizes list, moved to private.
    
  public:
    ListCollection(int sz = 10);   // Constructor
    ~ListCollection();             // Destructor
    void setElement(int, int);     // Sets an element to a value
    int getElement(int) const;     // Returns an element
    void displayList(bool nl = false) const;      // Display list

    ListCollection(const ListCollection &obj);
    const ListCollection& operator=(const ListCollection &right);

    const ListCollection operator+(const ListCollection &right);
    const ListCollection sublist(int, int);
    const ListCollection sublist(int);
    const ListCollection sort();
    
    // New functions
    void clear();
    int size();
    int capacity();
    void pushFront(int);
    void pushBack(int);
    int popFront();
    int popBack();
    void insertOrdred(int);
    void removeElement(int);
    void insert(int, int);
	void remove(int);
	
};

#endif
