#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
/*
 * Author: Maliak Green, Dan Weitman
 * Desciption: Push Nodes onto a queue and use them along with other class implementations i.e. Complex.
 * Notes: None.
 */

using namespace std;

template <class T>
class PQNode{
  public:
    T data;
    int priority;
    
    PQNode(T Data){
	data = Data;
	priority = 1;
    }
    
    PQNode(T Data, int Priority){
      data = Data; 
      if(priority < 1){
	  priority = 1;
      }
      
      priority = Priority;
    }
  
};

template <class T>
class PriorityQueue{
  private:
    vector<PQNode<T>> queue;
    
  public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue & obj);
    ~PriorityQueue();
    
    void enqueue(T Data);
    void enqueue(T Data, int priority);
    T dequeue();
    
    void print();
    bool isEmpty();
    void clear();
    int size();
    PQNode<T> &operator[](unsigned const int &);

};

/*
 * Desciption: Default constructor,
 * Parameters: None.
 * Return: None.
 */
template <class T>
PriorityQueue<T>::PriorityQueue(){
  
}


/*
 * Desciption: Enqueue class function.
 * Parameters: None.
 * Return: None.
 */

template <class T>
void PriorityQueue<T>::enqueue(T Data)
{
  PQNode<T> node(Data);  
  queue.push_back(node);
}

/*
 * Desciption: Enqueue overload.
 * Parameters: None.
 * Return: None.
 */

template <class T>
void PriorityQueue<T>::enqueue(T Data, int Priority)
{
  PQNode<T> node(Data, Priority); 
  queue.push_back(node);
}

/*
 * Desciption: Dequeue class function to remove elements from queue. 
 * Parameters: None.
 * Return: T data.
 */


template <class T>
T PriorityQueue<T>::dequeue()
{
    T def;
    if(queue.empty()){
        return def;
    }
    int it = 0, max = 0;
    for(int i = queue.size(); i > 0; i--)
    {
        if(max < queue[i].priority)
        { 
            it = i;
            max = queue[i].priority;
        }
    
}
T ret = queue[it].data;
queue.erase(queue.begin()+it);
 return ret;

}


/*
 * Desciption: Print function prints elements.
 * Parameters: None.
 * Return: None.
 */



template <class T>
void PriorityQueue<T>::print()
{
 for(int i = 0; i < queue.size(); i++)
  cout << queue[i].data << " ";

}

/*
 * Desciption: Default constructor,
 * Parameters: None.
 * Return: None.
 */


template <class T>
bool PriorityQueue<T>::isEmpty()
{
return queue.empty(); 
}

/*
 * Desciption: Clear function to clear queue.
 * Parameters: None.
 * Return: None.
 */


template <class T>
void PriorityQueue<T>::clear()
{
  queue.clear();

  
}

/*
 * Desciption: Size function of queue.
 * Parameters: None.
 * Return: Integer.
 */

template <class T>
int PriorityQueue<T>::size()
{
  return queue.size();
}

/*
 * Desciption: Bracket overload.
 * Parameters: None.
 * Return: Integer.
 */

template <class T>
PQNode<T> &PriorityQueue<T>::operator[](unsigned const int &pos)
{
  if(pos < 0)
    return queue[0];
  
  else if(pos > queue.size())
    return queue[queue.size() - 1];
  
  else
    return queue[pos];
}

/*
 * Desciption: Copy constructor.
 * Parameters: None.
 * Return: None.
 */


template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &obj)
{
  queue = obj.queue; 
}

/*
 * Desciption: Deconstructor.
 * Parameters: None.
 * Return: Integer.
 */

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
  
  
}

#endif
