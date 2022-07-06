#ifndef HEAPQ_H
#define HEAPQ_H

/* Author: Daniel Weitman
 * Course: COSC-320
 * Instructor: Anderson
 * Date: 3/14/19
 * 
 */

template <class T> 
class heapq{
  
  private:
    
    struct HeapObj{
      T data;
      int key;
      
      //Assignment operator for Heapobj
      HeapObj operator =(const HeapObj& obj){
          data = obj.data;
          key = obj.key;
          return *this;
      }
    };
    
    HeapObj* arr;
    int heap_size;
    int capacity;
  
    void MaxHeapify(int i);
    void increaseKey(int i, int k);
    void resize();
    
  public: 
    
    heapq();
    heapq(int);
    ~heapq();
    
    void enqueue(T obj, int priority);
    void timeEn(T, int);
    T dequeue();
    T timeDe();
    T peek();
    void print();

};

#endif

#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;

/* Description: Default constructor
 * Parameters: none
 * Return: none
 */
template <class T>
heapq<T>::heapq(){
    heap_size = 0;
    capacity = 10;
    arr = new HeapObj[capacity];
    
}

/* Description: Non-default constructor
 * Parameters: none
 * Return: none
 */
template <class T>
heapq<T>::heapq(int sz){
    heap_size = 0;
    capacity = sz;
    arr = new HeapObj[capacity];
    
}

/* Description: Destructor
 * Parameters: none
 * Return: none
 */
template <class T>
heapq<T>::~heapq(){
    
 delete [] arr;   
}

/* Description: Places a obj on a heap queue
 * Parameters: T obj, int priority
 * Return: void
 */
template <class T>
void heapq<T>::enqueue(T obj, int priority){
    
    
        //DONE: check of heapsize + 1 > size, if yes double size of arr
    if(heap_size + 1 > capacity){
      resize();
    }
    heap_size++;
    arr[heap_size - 1].data = obj;
    arr[heap_size - 1].key = -1;
    increaseKey(heap_size, priority);
}

/* Description: Removes obj off of queue
 * Parameters: none
 * Return: T obj
 */
template <class T>
T heapq<T>::dequeue(){
    
    if(heap_size < 1){
        T def;
        cout << "Cannot dequeue... returning default" << endl;
        return def;
    }
    T temp;
    temp = arr[0].data;
    
    HeapObj temp1;
    temp1 = arr[0];
    arr[0] = arr[heap_size - 1];
    arr[heap_size - 1] = temp1;
    
    heap_size--;
    
    MaxHeapify(1);
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
  
  for(int i = 0; i < heap_size; i++){
    cout << "(" << arr[i].data << ", " << arr[i].key << ") ";
    
  }
  cout << endl;
  
}

/* Description: Doubles heap capacity for overflow
 * Parameters: none
 * Return: void
 */
template <class T>
void heapq<T>::resize(){
    
    cout << "Doubling capacity" << endl;
        HeapObj store[heap_size];
        for(int i = 0; i < heap_size; i++){
            store[i].data = arr[i].data;
            store[i].key = arr[i].key;
        }
        
        delete [] arr;
        capacity*=2;
        arr = new HeapObj[capacity];
        
        for(int i = 0; i < heap_size; i++){
            arr[i].data = store[i].data;
            arr[i].key = store[i].key;
        }
        for(int i = heap_size; i < capacity; i++){
            
            arr[i].key = 1;
        }
}


/* Description: Changes the priority of a heap element
 * Parameters: int i, int priority
 * Return: void
 */
template <class T>
void heapq<T>::increaseKey(int i, int k){
  if(k <= arr[i - 1].key){
      cout << "Key is larger..." << endl;
      return;
  }
  
  arr[i - 1].key = k;
  int parent = (i/2);
  
  HeapObj temp;
  while(i > 1 && arr[i - 1].key > arr[parent - 1].key){
      
      temp = arr[i - 1];
      arr[i - 1] = arr[parent - 1];
      arr[parent - 1] = temp;
      
      parent = (i/2);
      i = parent;
      
  }
  
  if(arr[0].key < arr[1].key){
      temp = arr[0];
      arr[0] = arr[1];
      arr[1] = temp;
  }
  
  if(arr[0].key < arr[2].key){
      temp = arr[0];
      arr[0] = arr[2];
      arr[2] = temp;
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
  
  if(l <= heap_size && arr[l - 1].key > arr[i - 1].key){
    largest = l;
  } else {
    largest = i;
  }
  
  if (r <= heap_size && arr[r - 1].key > arr[largest - 1].key){
    largest = r;
  }
  
  if(largest != i){
      
    HeapObj temp;
    
    temp = arr[i - 1];
    
    arr[i - 1] = arr[largest - 1];
    
    arr[largest - 1] = temp;
    
    MaxHeapify(largest);
  }
}
//Times enqueue
template <class T>
void heapq<T>::timeEn(T obj, int priority){
    cout << "|ENQUEUE|" << endl;
    auto start = std::chrono::system_clock::now();
    enqueue(obj, priority); 
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished at " << std::ctime(&end_time)
    << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    cout << endl;
    
}
//Times dequeue
template <class T>
T heapq<T>::timeDe(){
    T temp;
    cout << "|DEQUEUE|" << endl;
    auto start = std::chrono::system_clock::now();
    temp = dequeue(); 
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished at " << std::ctime(&end_time)
    << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    cout << endl;
    
    return temp;
}

