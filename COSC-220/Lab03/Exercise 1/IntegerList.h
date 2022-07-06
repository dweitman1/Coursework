#ifndef INTEGERLIST_H
#define INTEGERLIST_H
/*
Author: Daniel Weitman
Created: 09/17/18
Last Updated: 09/22/18
Description: Lab worked onto to manipulate list objects with c++ operands.
*/
class IntegerList
{
  private:
    int *list;                 // Pointer to the array.
    int numElements;           // Number of elements.
    bool isValid(int) const;   // Validates subscripts.
  public:
    IntegerList(int); 
    IntegerList();// Constructor
    ~IntegerList();            // Destructor
    void setElement(int, int); // Sets an element to a value
    int getElement(int) const; // Returns an element
    void displayList() const;  // Display list

    IntegerList(const IntegerList &obj);
    const IntegerList operator=(const IntegerList &right);
    const IntegerList operator+(const IntegerList &right);//allow object addition.
    int &operator[] (const int &);//access elements within list object.
    void resize(int);//resize list object.
    const IntegerList sublist(int, int);//Returns the elements between two elements
    const IntegerList sublist(int);//Returns the elements after paraments element #
    const IntegerList sort();//Sorts integer list in ascending order
};

#endif
