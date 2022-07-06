#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>
/*
 Author: Daniel Weitman
 Creation Date: 10/08/18
 Last Update: 10/15/18
 Description: ListCollection class that will act as a linked list storing integers in an integer list. the class comes with public and private
 member functions to check certain properties of the list objects and manipulate them.
 Notes: All functions not apart of our lab 4 turn in assignment have been commented out.
*/
template <class T>
class ListCollection
{
  private:
    template <class T>
    class ListNode
    {
        public:
            T value;
            ListNode *next;
            
            ListNode(T nodeValue = 0){
                value = nodeValue;
                next = nullptr;
            }
    };
    
    ListNode *head;
    bool isValid(int) const;// Validates subscripts.
    
    
  public:
    ListCollection();   // Constructor
    ~ListCollection();             // Destructor
    void setElement(int, T);     // Sets an element to a value
    T getElement(int);     // Returns an element
    void displayList(bool nl = false) const;      // Display list

    ListCollection(const ListCollection &obj);
    const ListCollection& operator =(const ListCollection &right);

    const ListCollection<T> operator +(const ListCollection &right);
    const ListCollection<T> sublist(int, int);
    const ListCollection<T> sublist(int);
    //const ListCollection<T> sort();
    
    // New functions
    
    void clear();
    int size();
    int capacity();
    void pushFront(int);
    void pushBack(int);
    T popFront();
    T popBack();
    void insertOrdred(T);
    void removeElement(int);
    void insert(int, T);
    void remove(int);
    
};

#endif
