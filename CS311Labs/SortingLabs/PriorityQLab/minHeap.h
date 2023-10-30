/*****************************************************
Template prepared by Kazumi Slott
CS311
min heap class

Your name: Zach Smith 
Your programmer number: 30
Hours spent making and testing your min heap class: 2
An y difficulties?: ????
*******************************************************/
#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream> //for operator<<()
using namespace std;
#include "swap.h" //for mySwap().  If you didn't create it, you can use the library's swap()

template <class T>
class minHeap;

template <class T>
ostream& operator<<(ostream& o, const minHeap<T>& h);

template <class T>
class minHeap
{
  friend ostream& operator<< <T>(ostream& o, const minHeap<T>& h);
private:
  T* ar; //dynamic array
  int capacity; //the size of ar
  int num; //the number of elements I have in ar
public:
  minHeap(){ar = NULL; capacity = 0; num = 0;}
  minHeap(int c);
  ~minHeap(){if(ar!=NULL)delete [] ar;}
  void min_heapify(int i);
  //void build_min_heap(); //no need to implement this. We won't use it for our application.
  void bubbleUp(int i);
  void insert(const T& el);
  int find(const T& key) const;
  void remove(int i);
  T getMin();

  class Overflow{};
  class BadIndex{};
  class NotFound{};
};
//You need to implement all the memeber functions above.
template <class T>
minHeap<T>::minHeap(int c) {
    capacity = c;
    ar = new T[c];
    num = 0;
}

template <class T>
void minHeap<T>::min_heapify(int i) {
    int l = (2 * i) + 1; //the index of the left child of i
    int r = (2 * i) + 2;//the index of the right child of 
    int smallest = i; //the index of the largest value amoung the values at i, l and r
    if (l < num && ar[l] < ar[smallest])
        smallest = l;
    if (r < num && ar[r] < ar[smallest])
        smallest = r;
        //The largest is either the right or left child. We need to exchange the parent with it.
    if (smallest != i) {
        mySwap(ar[i], ar[smallest]);
        min_heapify(smallest);
    }
}

template <class T>
void minHeap<T>::bubbleUp(int i) {
    int parent = (i - 1) / 2;
    while(ar[i] < ar[parent]) {
        mySwap(ar[i], ar[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

template <class T>
void minHeap<T>::insert(const T& el){
    if(num==capacity)
        throw Overflow(); //"The array is full"; 
    ar[num] = el;
    bubbleUp(num);
    num++;
}

template <class T>
int minHeap<T>::find(const T& key) const
{
  for(int i = 0; i < num; i++) 
    if(ar[i] == key)
      return i;

  //The element doesn't exist 
  throw NotFound();// "The element doesn't exist";                                                                                             
}

template <class T>
void minHeap<T>::remove(int i)
{
  if(i > num - 1 || i < 0)
    throw BadIndex(); //"The element doesn't exist";
  else
  {
      mySwap(ar[num - 1], ar[i]);
      num--;
      if (ar[i] < ar[(i - 1) / 2] && i > 0)//fix violation
          bubbleUp(i);
      else
          min_heapify(i);
  }
}

template <class T>
T minHeap<T>::getMin()
{
  //This function removes the top element and returns it.
  //You should be calling remove()
    T min = ar[0];
    remove(0);
    return min;
}

template<class T>
ostream& operator<< (ostream& o, const minHeap<T>& h) {
    if (h.num == 0)
    {
        o << "none";//if heap is empty
    }
    for (int i = 0; i < h.num; i++) //iterate through heap
    {
        o << h.ar[i] << " "; //print elements
    }
    o << endl;
    return o;
}
#endif