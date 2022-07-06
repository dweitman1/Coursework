#include <iostream>
#include "heapq.h" 

/* Author: Daniel Weitman
 * Course: COSC-320
 * Instructor: Anderson
 * Date: 3/14/19
 * 
 */

using namespace std;

template <class T>
heapq<T>::heapq(){
    heap_size = 0;
    length = 0;
    arr = NULL;
    
}

template <class T>
heapq<T>::heapq(int sz){
    heap_size = sz;
    length = sz;
    arr = new T[heap_size];
    
}

/* Description: Places a obj on a heap queue
 * Parameters: T obj, int priority
 * Return: void
 */
template <class T>
void heapq<T>::enqueue(T obj, int priority){
  
    length++;
    arr[length] = obj;
    arr[length].key = -1;
    increaseKey(length, arr[length].key);
}

/* Description: Removes obj off od queue
 * Parameters: none
 * Return: T obj
 */
template <class T>
T heapq<T>::dequeue(){
  
    T temp;
    temp = arr[0].data;
    
    HeapObj temp1;
    temp1 = arr[0];
    arr[0] = arr[length - 1];
    arr[length - 1] = temp1;
    
    length--;
    
    MaxHeapify(0);
    return temp;
  
}

/* Description: Shows item in front of queue
 * Parameters: none
 * Return: T obj
 */
template <class T>
T heapq<T>::peek(){
  
  return arr[0].data;
}

/* Description: Prints heap
 * Parameters: none
 * Return: void
 */
template <class T>
void heapq<T>::print(){
  
  for(int i = 0; i < length; i++){
    cout << "(" << arr[i].data << ", " << arr[i].key << ") ";
    
  }
  cout << endl;
  
}

/* Description: Changes the priority of a heap element
 * Parameters: int i, int priority
 * Return: void
 */
template <class T>
void heapq<T>::increaseKey(int i, int k){
  if(k <= arr[i].key){
      cout << "Invalid" << endl;
      return;
  }
  
  arr[i].key = k;
  int parent = (i/2);
  
  while(i > 0 && arr[i].key > arr[parent].key){
      HeapObj temp;
      temp = arr[i];
      arr[i] = arr[parent];
      arr[parent] = temp;
      
      i = parent;
  }
  
  
}

/* Description: Corrects heap of index and children and recurses
 * Parameters: int i
 * Return: void
 */
template <class T>
void heapq<T>::MaxHeapify(int i){
  
  int l = 2 * i;
  int r = (2 * i) + 1;
  int largest;
  
  if(l <= heap_size && *this[l] > *this[i]){
    largest = l;
  } else {
    largest = i;
  }
  
  if (r <= heap_size && *this[r] > *this[largest]){
    largest = r;
  }
  
  if(largest != i){
    int temp = *this[i];
    *this[i] = *this[largest];
    *this[largest] = temp;
    MaxHeapify(largest);
  }
}


