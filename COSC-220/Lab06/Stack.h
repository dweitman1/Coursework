#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
#include "ListCollection.h"

using namespace std;

/*
    Author: Don Spickler
    Creation Date: 10/8/2018
    Last Update: 10/8/2018
    Description: Stack
*/

template <class T>
class Stack
{
  private:
    ListCollection<T> stack;

  public:
    Stack();   // Constructor
    ~Stack();  // Destructor
    void displayStack(bool nl = false) const; // Display list

    Stack(const Stack &obj);
    const Stack operator=(const Stack &right);

    void clear();
    int size();
    void push(T);
    T pop();
    bool isEmpty();
};

/*
    Description: Constructor
*/

template <class T>
Stack<T>::Stack()
{
}

/*
    Description: Destructor
*/

template <class T>
Stack<T>::~Stack()
{
}

/*
    Description: Copy Constructor
    Parameters: obj - IntergerList being copied.
*/

template <class T>
Stack<T>::Stack(const Stack &obj)
{
    stack = obj.stack;
}

/*
    Description: Overloaded assignment operator.
    Parameters: right - RHS of expression to be copied to calling object.
    Return: Copy of the RHS.
    Notes: Calling object is updated.
*/

template <class T>
const Stack<T> Stack<T>::operator=(const Stack &right)
{
    stack = right.stack;
    return *this;
}

/*
    Description: Prints the list to the console.
*/

template <class T>
void Stack<T>::displayStack(bool nl) const
{
    stack.displayList(nl);
}

/*
    Description: Returns the size of the list
    Return: Size of the list.
*/

template <class T>
int Stack<T>::size()
{
    return stack.size();
}

/*
    Description: Adds the parameter element to the front of the list.
    Parameters: elt - integer to add to the front of the list.
*/

template <class T>
void Stack<T>::push(T elt)
{
    stack.pushFront(elt);
}

/*
    Description: Removes and returns the element in the front of the list.
    Return: Front element of the list.
*/

template <class T>
T Stack<T>::pop()
{
    return stack.popFront();
}

/*
    Description: Removes all elements from the list.
*/

template <class T>
void Stack<T>::clear()
{
    stack.clear();
}

/*
    Description: Tests if the stack is empty.
	Return: True if the stack os empty and falce otherwise.
*/

template <class T>
bool Stack<T>::isEmpty()
{
    return stack.size() == 0;
}

#endif
