#include"ListCollection.h"
#include<iostream>
/*
 Author: Daniel Weitman
 Creation Date: 10/8/18
 Last Update: 10/15/18
 Description: Implementation for altering linked list ListCollection
*/
using namespace std;

template <class T>
bool ListCollection<T>::isValid(int elem) const{
    ListNode<T> *nodePtr;
    int counter = 0;
    if(elem < 1){
        return false;
    }
    
    while(nodePtr->next){
        nodePtr = nodePtr->next;
        counter++;
    }
    if(counter > elem){
        return true;
    } else {
        return false;
    }
}
template <class T>
ListCollection<T>::ListCollection(){
    head = nullptr;
}
template <class T>
ListCollection<T>::~ListCollection(){
    ListNode<T> *nodePtr;
    ListNode<T> *nextNode;
    
    nodePtr = head;
    
    while(nodePtr != nullptr){
        nextNode = nodePtr;
        delete nodePtr;
        nodePtr = nextNode;
        
    }
}
template <class T>
void ListCollection<T>::setElement(int pos, int data){
  ListNode<T> *newNode = new ListNode;
  newNode->next = nullptr;
  newNode->value = data;
  
  ListNode<T> *nodePtr; 
  nodePtr = head;
  int cCount = 0; 
  
  while(nodePtr) 
  {
    nodePtr = nodePtr->next;
    cCount++;
  }
  if(pos > cCount) 
    return;
  
  if(pos < 0)
  return;
  
  if(!head)
  {
    head = newNode;
    newNode = newNode->next;
  }
  else
  { 
   head->next = newNode;
   newNode = newNode->next;
  }
}
template <class T>
T ListCollection<T>::getElement(int pos){
  ListNode<T> *cursor;
  cursor = head;
  int cCount = 0; 
  while(cursor)
  {
    cursor = cursor->next;
    cCount++; 
  }
  
  
 if(pos < 0 || pos == 0)
   return head->value;
 
  else if(pos > cCount || pos == cCount){
    int cCount2 = 0;
   cursor = head;
   while(cCount2 < cCount)
   {
   cursor = cursor->next; 
   cCount2++;

   }
   return cursor->value;
  }
  else 
  {
    int cCount2 = 0;
   while(cCount2 <= pos)
   {
    cursor = cursor->next;
    cCount++;
    
    if(cCount == pos)
      return cursor->value;
   }
  }
  return 0;
}
template <class T>
void ListCollection<T>::displayList(bool nl) const{
    ListNode<T> *nodePtr;
    nodePtr = head;
    
    while(nodePtr){
        
        cout << nodePtr->value << " ";
            if(nl == true){
                cout << endl;
            }
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
template <class T>
ListCollection<T>::ListCollection(const ListCollection &obj){
    ListNode<T> *nodePtr;
    ListNode<T> *newNode;
    
    if(!obj.head){
        head = 0;
    } else {
        head = new ListNode;
        head->value = obj.head->value;
        
        nodePtr = head;
        newNode = obj.head->next;
    } 
    while(newNode){
        nodePtr->next = new ListNode;
        nodePtr = nodePtr->next;
        nodePtr->value = newNode->value;
        
        newNode = newNode->next;
    }
    nodePtr->next = 0;
}
template <class T>
const ListCollection<T> &ListCollection<T>::operator=(const ListCollection &right){
  
 // head = right.head;
  ListNode<T> *cursor, *cursor2;
  
  cursor = head;
  cursor2 = head;
  
  while(cursor)
  {
   cursor = head;
   head = cursor->next;
   delete cursor;
   
  }
  while(cursor && cursor2)
  {
   cursor->value = cursor2->value;
   cursor = cursor->next;
   cursor2 = cursor2->next;
  }
  
  return *this;
}
template <class T>
const ListCollection<T> ListCollection<T>::operator +(const ListCollection &right)
{
if(!head) // If list is empty.
return *this;

ListNode<T> *cursor, *cursor2;
cursor = head;
cursor2 = right.head;
int cCount, cCount2 = 0;

while(cursor) // Size of first list.
{
  cursor = cursor->next;
  cCount++;
}

while(cursor2) // Size of second list.
{
  cursor2 = cursor2->next;
  cCount2++;
}


ListCollection l3;

return l3;
}
template <class T>
const ListCollection<T> ListCollection<T>::sublist(int a, int b){
    ListCollection<T> l;
    ListNode<T> *nodePtr;
    T swap;
    int dist;
    if(b < a){
        swap = b;
        b = a;
        a = swap;
    }
    dist = b - a + 1;
    nodePtr = head;
    
    for(int i = 0; i < a - 1; i++){
        nodePtr = nodePtr->next;
    }
    for(int i = 0; i < dist; i++){
        l.pushBack(nodePtr->value);
        nodePtr = nodePtr->next;
    }
    return l;
}
template <class T>
const ListCollection<T> ListCollection<T>::sublist(int a){
    return sublist(a, size());
}
template <class T>
void ListCollection<T>::clear(){
    ListNode<T> *nodePtr;
    
    nodePtr = head;
    while(nodePtr->next){
        nodePtr->value = 0;
        nodePtr = nodePtr->next;
    }

}
template <class T>
int ListCollection<T>::size(){
    ListNode<T> *nodePtr;
    int count = 0;
    
    if(!head){
        return count;
    }
    
    nodePtr = head;
    
    while(nodePtr){
        nodePtr = nodePtr->next;
        count++;
    }
    
    return count;
}
template <class T>
int ListCollection<T>::capacity(){
    return size();
}
template <class T>
void ListCollection<T>::pushFront(int data){
    ListNode<T> *newNode;
    
    newNode = new ListNode;
    newNode->value = data;
    newNode->next = nullptr;
    
    if(!head){
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}
template <class T>
void ListCollection<T>::pushBack(int data){
    ListNode<T> *newNode;
    ListNode<T> *nodePtr;
    
    newNode = new ListNode;
    newNode->value = data;
    newNode->next = nullptr;
    
    if(!head){
        head = newNode;
    } else {
        nodePtr = head;
        
        while(nodePtr->next){
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}
template <class T>
T ListCollection<T>::popFront(){
    ListNode<T> *nodePtr;
    ListNode<T> *newNode;
    T ret;
    
    if(!head){
        return 0;
    } else {
       newNode = head;
       nodePtr = newNode->next;
       head = nodePtr;
       
       ret = newNode->value;
       delete newNode;
       return ret;
    }
}
template <class T>
T ListCollection<T>::popBack(){
    ListNode<T> *nodePtr;
    ListNode<T> *end;
    int ret;
    
    while(nodePtr->next){
        nodePtr = nodePtr->next;
        end = nodePtr;
    }
    end->next = nullptr;
    ret = nodePtr->value;
    delete nodePtr;
    
    return ret;
    
}
template <class T>
void ListCollection<T>::insertOrdred(int data){
    ListNode<T> *newNode;
    ListNode<T> *nodePtr;
    ListNode<T> *previousNode = nullptr;
    
    newNode = new ListNode;
    newNode->value = data;
    
    if(!head){
        head = newNode;
        newNode->next  = nullptr;
    } else {
        nodePtr = head;
        
        while(nodePtr != nullptr && nodePtr->value < data){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if(previousNode == nullptr){
            head = newNode;
            newNode->next = nodePtr;
        } else {
            previousNode->next = newNode;
            newNode->next = nodePtr;
            
        }
    } 
}
template <class T>
void ListCollection<T>::removeElement(int data){
    ListNode<T> *nodePtr;
    ListNode<T> *previousNode;
    
    if(!head){
        return;
    }
    
    if(head->value == data){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {
        nodePtr = head;
        
        while(nodePtr != nullptr && nodePtr->value != data){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if(nodePtr){
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
template <class T>
void ListCollection<T>::insert(int pos, int data){
    ListNode<T> *nodePtr;
    int count = 0;
    if(!isValid(pos)){
        
    }
    nodePtr = head;
    
    while(nodePtr->next && count < pos){
        nodePtr = nodePtr->next;
        count++;
    }

}
template <class T>
void ListCollection<T>::remove(int pos){
   if(!isValid(pos)){
       return;
   }
   ListNode<T> *nodePtr;
   nodePtr = head;
   
   while(nodePtr->next && nodePtr->value != pos){
    nodePtr = nodePtr->next;
   }
   removeElement(nodePtr->value);
}
