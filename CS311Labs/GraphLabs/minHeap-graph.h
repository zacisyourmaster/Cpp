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
//#include "swap.h" //for mySwap().  If you didn't create it, you can use the library's swap()

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
	minHeap() { ar = NULL; capacity = 0; num = 0; }
	minHeap(int c);
	~minHeap() { if (ar != NULL)delete[] ar; }
	void min_heapify(int* curDist, int* locator, int i);
	//void build_min_heap(); //no need to implement this. We won't use it for our application.
	void bubbleUp(int* curDist, int* locator, int i);
	void insert(int* curDist, int* locator, const T& el);
	int find(const T& key) const;
	void remove(int* curDist, int* locator, int i);
	T getMin(int* curDist, int* locator);
	int getNum() const;
	void fixHeap(int* curDist, int* locator, int i);

	class Overflow {};
	class BadIndex {};
	class NotFound {};
};
//You need to implement all the memeber functions above.
template <class T>
minHeap<T>::minHeap(int c) {
	capacity = c;
	ar = new T[c];
	num = 0;
}

template <class T>
void minHeap<T>::min_heapify(int* curDist, int* locator, int i) {
	int l = (2 * i) + 1; //the index of the left child of i
	int r = (2 * i) + 2;//the index of the right child of 
	int smallest = i; //the index of the largest value amoung the values at i, l and r
	if (l < num && curDist[ar[l]] < curDist[ar[smallest]])
		smallest = l;
	if (r < num && curDist[ar[r]] < curDist[ar[smallest]])
		smallest = r;
	//The largest is either the right or left child. We need to exchange the parent with it.
	if (smallest != i) {
		locator[ar[i]] = smallest; //swap locator
		locator[ar[smallest]] = i;
		swap(ar[i], ar[smallest]);
		min_heapify(curDist, locator, smallest);
	}
}

template <class T>
void minHeap<T>::bubbleUp(int* curDist, int* locator, int i) {
	int parent = (i - 1) / 2;
	while (i > 0 && curDist[ar[parent]] > curDist[ar[i]]) //the child is smaller 
	{
		locator[ar[i]] = parent;//swap locator
		locator[ar[parent]] = i;
		swap(ar[parent], ar[i]); //swap
		i = parent; //make i the new parent
		parent = (parent - 1) / 2; //find the parent of i
	}
}

template <class T>
void minHeap<T>::insert(int* curDist, int* locator, const T& el) {
	if (num == capacity)
		throw Overflow(); //"The array is full"; 
	ar[num] = el;
	bubbleUp(curDist, locator, num);
	num++;
}

template <class T>
int minHeap<T>::find(const T& key) const
{
	for (int i = 0; i < num; i++)
		if (ar[i] == key)
			return i;

	//The element doesn't exist 
	throw NotFound();// "The element doesn't exist";                                                                                             
}

template <class T>
void minHeap<T>::remove(int* curDist, int* locator, int i)
{
	if (i > num - 1 || i < 0)
		throw BadIndex(); //"The element doesn't exist";
	else {
		locator[ar[i]] = num - 1;
		locator[ar[num - 1]] = i;
		swap(ar[num - 1], ar[i]);//swap the current element with last element
		num--; //decrement
		fixHeap(curDist, locator, i);
	}
}

template <class T>
T minHeap<T>::getMin(int* curDist, int* locator)
{
	//This function removes the top element and returns it.
  //You should be calling remove()
	T min = ar[0];
	remove(curDist, locator, 0);
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

//return the number of elements in the heap.
template <class T>
int minHeap<T>::getNum() const
{
	return num;
}

//i is the index (within heap) of the vertex whose distance was changed. 
//For example, if vertex 0's distance changed when it is located at 3, i is 3. This is where the heap needs to be fixed by either going up or down.
//curDist is the array that contains the shortest distance from start to every other vertex.                                           
//locator is the array that contains the location of each vertex within the heap. 
// Make sure you understand the homework document posted on Canvas to understand how locator works.                                               
template <class T>
void minHeap<T>::fixHeap(int* curDist, int* locator, int i)
{

	//We need to maintain the min heap based on curDist. When 2 vertices swap within the heap, their locations will change,
	//hence you need to update the locator array. Make sure you understand how each array works by reading the homework document (there are pictures to explain).
	if (i < num && i >= 0)//From i, either bubble up or down. 
		if (curDist[ar[i]] < curDist[ar[(i - 1) / 2]])
			bubbleUp(curDist, locator, i);//For up, call bubbleUp().
		else if (curDist[ar[i]] > curDist[ar[2 * i + 1]] || curDist[ar[i]] > curDist[ar[2 * i + 2]])
			min_heapify(curDist, locator, i);//For down, call min_heapify().
                                                                    

	//Reminder: A lot of the member functions in minHeap class need to have 2 more parameters, int* curDist, int* locator.

	//Since I have the same code inside minHeap::remove(), I am now calling fixHeap() from remove() so I won't have duplicate code.	
}

#endif