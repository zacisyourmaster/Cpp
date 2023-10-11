/**************************************
Written by Kazumi Slott
CS311
10-12-2021

This client tests the sorting functions in sort.h
**************************************/

#include <iostream>
using namespace std;
#include "sort.h"

int main()
{
	cout << "-------- testing insertion sort --------" << endl;
	int ar[10] = { 5, 3, 7, 10, 4, 9, 2, 8, 1, 6 };
	insertionSort(ar, 10);
	print(ar, 10); //1 2 3 4 5 6 7 8 9 10
	cout << endl;

	cout << "------- testing selection sort --------" << endl;
	int ar2[10] = { 5, 3, 7, 10, 4, 9, 2, 8, 1, 6 };
	selectionSort(ar2, 10);
	print(ar2, 10);//1 2 3 4 5 6 7 8 9 10
	cout << endl;


	cout << "------- testing bubble sort --------" << endl;
	int ar3[10] = { 5, 3, 7, 10, 4, 9, 2, 8, 1, 6 };
	bubbleSort(ar3, 10);
	print(ar3, 10);
	cout << endl;


	cout << "------- testing quick sort --------" << endl;
	int ar4[] = { 15, 10, 5, 7, 1, 4, 12, 8, 6 };
	quickSort(ar4, 0, 8);
	print(ar4, 9);//1 4 5 6 7 8 10 12 15
	cout << endl;

	cout << "------- testing merge sort --------" << endl;
	int ar5[] = { 1, 8, 6, 4, 10, 5, 3, 2, 22 }; //the array used in my lecture notes
	mergeSort(ar5, 0, 8);
	print(ar5, 9); //1 2 3 4 5 6 8 10 22
	cout << endl;

	return 0;
}
