#include"ListCollection.h"
#include<iostream>
/*
 Author: Daniel Weitman
 Creation Date: 10/8/18
 Last Update: 10/15/18
 Description: Implementation for altering linked list ListCollection
*/
using namespace std;


bool ListCollection::isValid(int elem) const{
    ListNode *nodePtr;
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
ListCollection::ListCollection(){
    head = nullptr;
}
ListCollection::~ListCollection(){
    ListNode *nodePtr;
    ListNode *nextNode;
    
    nodePtr = head;
    
    while(nodePtr != nullptr){
        nextNode = nodePtr;
        delete nodePtr;
        nodePtr = nextNode;
        
    }
}
void ListCollection::setElement(int pos, int data){
  ListNode *newNode = new ListNode;
  newNode->next = nullptr;
  newNode->value = data;
  
  ListNode *nodePtr; 
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
int ListCollection::getElement(int pos){
  ListNode *cursor;
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
void ListCollection::displayList(bool nl) const{
    ListNode *nodePtr;
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
ListCollection::ListCollection(const ListCollection &obj){
    ListNode *nodePtr;
    ListNode *newNode;
    
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
const ListCollection &ListCollection::operator=(const ListCollection &right){
  
 // head = right.head;
  ListNode *cursor, *cursor2;
  
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
const ListCollection ListCollection::operator +(const ListCollection &right)
{
if(!head) // If list is empty.
return *this;

ListNode *cursor, *cursor2;
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
const ListCollection ListCollection::sublist(int a, int b){
    ListCollection l;
    ListNode *nodePtr;
    int swap;
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
const ListCollection ListCollection::sublist(int a){
    return sublist(a, size());
}
void ListCollection::clear(){
    ListNode *nodePtr;
    
    nodePtr = head;
    while(nodePtr->next){
        nodePtr->value = 0;
        nodePtr = nodePtr->next;
    }

}
int ListCollection::size(){
    ListNode *nodePtr;
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
int ListCollection::capacity(){
    return size();
}
void ListCollection::pushFront(int data){
    ListNode *newNode;
    
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
void ListCollection::pushBack(int data){
    ListNode *newNode;
    ListNode *nodePtr;
    
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
int ListCollection::popFront(){
    ListNode *nodePtr;
    ListNode *newNode;
    int ret;
    
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

int ListCollection::popBack(){
    ListNode *nodePtr;
    ListNode *end;
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
void ListCollection::insertOrdred(int data){
    ListNode *newNode;
    ListNode *nodePtr;
    ListNode *previousNode = nullptr;
    
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

void ListCollection::removeElement(int data){
    ListNode *nodePtr;
    ListNode *previousNode;
    
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
void ListCollection::insert(int pos, int data){
    ListNode *nodePtr;
    int count = 0;
    if(!isValid(pos)){
        
    }
    nodePtr = head;
    
    while(nodePtr->next && count < pos){
        nodePtr = nodePtr->next;
        count++;
    }
    

}
void ListCollection::remove(int pos){
   if(!isValid(pos)){
       return;
   }
   ListNode *nodePtr;
   nodePtr = head;
   
   while(nodePtr->next && nodePtr->value != pos){
    nodePtr = nodePtr->next;
   }
   removeElement(nodePtr->value);
}
