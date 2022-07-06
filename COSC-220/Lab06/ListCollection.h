#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

/*
    Author: Don Spickler
    Creation Date: 9/21/2018
    Last Update: 9/21/2018
    Description: ListCollection class for restricted collection access and auto resizing.
        This class can be used as a base class to specialized structures later in the course.
        This version is templated.
*/

template <class T>
class ListCollection
{
  private:
    T *list;                   // Pointer to the array.
    int numElements;           // Number of elements.
    int numCapacity;           // Maximum number of elements.
    bool isValid(int) const;   // Validates subscripts.
    void resize(int);          // Resizes list, moved to private.

  public:
    ListCollection(int sz = 10); // Constructor
    ~ListCollection();           // Destructor
    void setElement(int, T);     // Sets an element to a value
    T getElement(int) const;     // Returns an element
    void displayList(bool nl = false) const;    // Display list

    ListCollection(const ListCollection &obj);
    const ListCollection<T> operator=(const ListCollection &right);

    // Updated functions
    const ListCollection<T> operator+(const ListCollection &right);
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

/*
    Description: Constructor
    Parameters: size - size of the array
*/

template <class T>
ListCollection<T>::ListCollection(int size)
{
    if (size <= 0)
        size = 1;
    list = new T[size];
    numElements = 0;
    numCapacity = size;
}

/*
    Description: Destructor, removes the memory allocated for the array.
*/

template <class T>
ListCollection<T>::~ListCollection()
{
    delete [] list;
}

/*
    Description: Copy Constructor
    Parameters: obj - IntergerList being copied.
*/

template <class T>
ListCollection<T>::ListCollection(const ListCollection &obj)
{
    numCapacity = obj.numCapacity;
    numElements = obj.numElements;
    list = new T[numCapacity];
    for (int i = 0; i < numCapacity; i++)
        list[i] = obj.list[i];
}

/*
    Description: Overloaded assignment operator.
    Parameters: right - RHS of expression to be copied to calling object.
    Return: Copy of the RHS.
    Notes: Calling object is updated.
*/

template <class T>
const ListCollection<T> ListCollection<T>::operator=(const ListCollection &right)
{
    delete [] list;
    numCapacity = right.numCapacity;
    numElements = right.numElements;
    list = new T[numCapacity];
    for (int i = 0; i < numCapacity; i++)
        list[i] = right.list[i];

    return *this;
}

/*
    Description: Function to determine if array index is in the correct range or not.
    Parameters: element - integer position to be tested
    Return: True if element is in the current array range, false if not.
*/

template <class T>
bool ListCollection<T>::isValid(int element) const
{
    bool status;

    if (element < 0 || element >= numElements)
        status = false;
    else
        status = true;

    return status;
}

/*
    Description: Sets the array element if the podiion is in the correct range, does nothing otherwise.
    Parameters:
    element - position to update
    value - value to store
*/

template <class T>
void ListCollection<T>::setElement(int element, T value)
{
    if (isValid(element))
        list[element] = value;
}

/*
    Description: Returns the element in the specified position.  If the position
    is negative the return value is the first element of the array and if the
    position is beyond the upper bound of the array the return value is the
    last position of the array.
    Parameters: pos - array position to be returned.
    Return: The value in the pos position of the array.
    Notes: If the position is negative the return value is the first element of
    the array and if the position is beyond the upper bound of the array the
    return value is the last position of the array.
*/

template <class T>
T ListCollection<T>::getElement(int pos) const
{
    T defaultret;

    if (numElements == 0)
        return defaultret;

    if (pos < 0)
        return list[0];

    if (pos >= numElements)
        return list[numElements - 1];

    return list[pos];
}

/*
    Description: Prints the list to the console.
*/

template <class T>
void ListCollection<T>::displayList(bool nl) const
{
    for (int i = 0; i < numElements; i++)
    {
        cout << list[i] << " ";
        if (nl)
            cout << endl;
    }
    if (!nl)
        cout << endl;
}

/*
    Description: Resizes the array.
    Parameters: sz - new size
    Notes: If the new size is smaller then the old size the data
    will be truncated.  If the new size is larger the array will
    be padded with 0.
*/

template <class T>
void ListCollection<T>::resize(int sz)
{
    T *newArray = new T[sz];

    int min = sz;
    if (min > numCapacity)
        min = numCapacity;

    for (int i = 0; i < min; i++)
        newArray[i] = list[i];

    if (numElements > sz)
        numElements = sz;

    numCapacity = sz;

    delete [] list;
    list = newArray;
}

/*
    Description: Overloaded + operator.
    Parameters: right - RHS integer list.
    Return: new ListCollection that is the concatenation of the two lists in
    the expression.
*/

template <class T>
const ListCollection<T> ListCollection<T>::operator+(const ListCollection &right)
{
    ListCollection<T> newList(numElements + right.numElements);

    for (int i = 0; i < numElements; i++)
        newList.list[i] = list[i];

    for (int i = 0; i < right.numElements; i++)
        newList.list[i + numElements] = right.list[i];

    newList.numElements = numElements + right.numElements;

    return newList;
}

/*
    Description: Creates a sublist from the calling list.
    Parameters:
    b - beginning index of sublist.
    e - ending index of sublist.
    Return: new ListCollection that is the sublist between b and e inclusively.
    Notes: If b < 0 the sublist starts at the beginning.  If e is beyond the
    end of the list the end is taken as the last element.  Also, if b and e
    are out of order, they are interchanged.
*/

template <class T>
const ListCollection<T> ListCollection<T>::sublist(int b, int e)
{
    if (b > e)
    {
        int temp = b;
        b = e;
        e = temp;
    }

    if (b < 0)
        b = 0;

    if (e < 0)
        e = 0;

    if (b >= numElements)
        b = numElements - 1;

    if (e >= numElements)
        e = numElements - 1;

    ListCollection<T> newList(e - b + 1);
    for (int i = 0; i < e - b + 1; i++)
        newList.list[i] = list[b + i];

    newList.numElements = e - b + 1;

    return newList;
}

/*
    Description: Creates a sublist from the calling list.
    Parameters: b - beginning index of sublist, end is taken as the last element.
    Return: new ListCollection that is the sublist from index b to the end of the list.
    Notes: If b < 0 the sublist starts at the beginning.  If b is beyond the
    end of the list the result is a single element array of the last element.
*/

template <class T>
const ListCollection<T> ListCollection<T>::sublist(int b)
{
    return sublist(b, numElements - 1);
}

/*
    Description: Sorts the list and returns a new list.
    Return: A sorted list with the same elements as in the calling list.
    Notes: The original list is unaltered.
*/

template <class T>
const ListCollection<T> ListCollection<T>::sort()
{
    ListCollection<T> newList(numElements);
    newList.numElements = numElements;
    for (int i = 0; i < numElements; i++)
        newList.list[i] = list[i];

    for (int i = numElements - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
        {
            if (newList.list[j] > newList.list[j + 1])
            {
                T temp = newList.list[j];
                newList.list[j] = newList.list[j + 1];
                newList.list[j + 1] = temp;
            }
        }

    return newList;
}

/*
    Description: Returns the size of the list
    Return: Size of the list.
*/

template <class T>
int ListCollection<T>::size()
{
    return numElements;
}

/*
    Description: Returns the capacity of the list
    Return: Capacity of the list.
*/

template <class T>
int ListCollection<T>::capacity()
{
    return numCapacity;
}

/*
    Description: Adds the parameter element to the front of the list.
    Parameters: elt - integer to add to the front of the list.
*/

template <class T>
void ListCollection<T>::pushFront(T elt)
{
    if (numElements == numCapacity)
        resize(2 * numCapacity);

    for (int i = numElements - 1; i >= 0; i--)
        list[i + 1] = list[i];

    list[0] = elt;
    numElements++;
}

/*
    Description: Adds the parameter element to the back of the list.
    Parameters: elt - integer to add to the back of the list.
*/

template <class T>
void ListCollection<T>::pushBack(T elt)
{
    if (numElements == numCapacity)
        resize(2 * numCapacity);

    list[numElements] = elt;
    numElements++;
}

/*
    Description: Removes and returns the element in the front of the list.
    Return: Front element of the list.
*/

template <class T>
T ListCollection<T>::popFront()
{
    T defaultret;

    if (numElements == 0)
        return defaultret;

    T retval = list[0];

    for (int i = 1; i < numElements; i++)
        list[i - 1] = list[i];

    numElements--;

    return retval;
}

/*
    Description: Removes and returns the element in the back of the list.
    Return: Back element of the list.
*/

template <class T>
T ListCollection<T>::popBack()
{
    T defaultret;

    if (numElements == 0)
        return defaultret;

    T retval = list[numElements - 1];

    numElements--;

    return retval;
}

/*
    Description: Adds the parameter element to the list. The new element is placed in the position
         so that all smaller elements are before the insert.
    Parameters: elt - integer to add to the list.
*/

template <class T>
void ListCollection<T>::insertOrdred(T elt)
{
    if (numElements == numCapacity)
        resize(2 * numCapacity);

    int pos = 0;
    while (pos < numElements && list[pos] < elt)
        pos++;

    if (pos == 0)
        pushFront(elt);
    else if (pos == numElements)
        pushBack(elt);
    else
    {
        for (int i = numElements; i >= pos; i--)
            list[i + 1] = list[i];

        list[pos] = elt;
        numElements++;
    }
}

/*
    Description: Removes the parameter element to the list. If the element is not in the list then
         the list is unaltered.
    Parameters: elt - integer to remove from the list.
*/

template <class T>
void ListCollection<T>::removeElement(T elt)
{
    int pos = 0;
    while (pos < numElements && list[pos] != elt)
        pos++;

    if (pos == numElements)
        return;

    for (int i = pos + 1; i < numElements; i++)
        list[i - 1] = list[i];

    numElements--;
}

/*
    Description: Inserts the element at the given position.  If the position is < 0 the
		new element will be added to the front of the list and if the position is larger than than
		the length of the list the new element is placed at the end of the list.
    Parameters:
		elt - integer to inserted into the list.
		pos - the position of insertion.
*/

template <class T>
void ListCollection<T>::insert(int pos, T elt)
{
    if (numElements == numCapacity)
        resize(2 * numCapacity);

    if (pos >= numElements)
        pushBack(elt);
    else if (pos <= 0)
        pushFront(elt);
    else
    {
        for (int i = numElements; i >= pos; i--)
            list[i + 1] = list[i];

        list[pos] = elt;
        numElements++;
    }
}

/*
    Description: Removes the element at position pos. If the position is not not valid
         the list is unaltered.
    Parameters: pos - position of integer to remove from the list.
*/

template <class T>
void ListCollection<T>::remove(int pos)
{
    if (!isValid(pos))
        return;

    for (int i = pos + 1; i < numElements; i++)
        list[i - 1] = list[i];

    numElements--;
}

/*
    Description: Removes all elements from the list.
*/

template <class T>
void ListCollection<T>::clear()
{
    numElements = 0;
}

#endif
