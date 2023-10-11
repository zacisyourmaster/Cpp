/**************************************
Template created by Kazumi Slott
CS311

Your name: Yonko, Zach D. Smith
Your programmer number:30
Hours spent:2
Any difficulties?:had trouble with Bubble
**************************************/

#include <iostream>
using namespace std;

void swap(int& data1, int& data2)
{
  int temp = data1;
  data1 = data2;
  data2 = temp;
}

void print(const int ar[], int n)
{
  for(int i = 0; i < n; i++)
    cout << ar[i] << " ";
}


//https://www.youtube.com/watch?v=ROalU379l3U
//Implement the insertion sort by watching the above youTube video. Your algorithm has to match their dance.
void insertionSort(int ar[], int n)
{
    for (int i = 1; i < n; i++) {//iterating through the dancers
        int current = i;
        while (current >= 0 && ar[current - 1] > ar[current]) {//while we are within bounds of array and last index greater than current
            swap(ar[current], ar[current - 1]);//swap last and current
            current--;//decrement value
        }
    }
}


void selectionSort(int array[], int N)
{
    int smallest; //the index of the largest value

    //last is the last index in unsorted part
    for (int first = 0; first < N - 1; first++)
    {
        smallest = first;//assume first item is smallest
        //find the largest in unsorted part ([0..last])
        for (int i = first + 1; i < N; i++)
        {
            if (array[i] < array[smallest]) //The current item is larger
                smallest = i;
        }

        //swap the largest with the last item in the unsorted part
        swap(array[smallest], array[first]);
    }
}


//Replace the ????s.
//For more info on bubble sort, read my CS211 lec notes "Lec notes 2-2: bubble sort"
//You could also watch my CS211 lecture recording "Lecture 2/5(Fri) - bubble sort and enum" 
void bubbleSort(int ar[], int s)
{
    bool swapped=true; //true if there was swapping in the current iteration, false otherwise
    int last = s-2; //last is the index of the left element of the last pair to be checked in the current iteration.

    while(swapped) //swapping required in the previous iteration or the first iteration starts
      {
        swapped = false; //no swapping has happened yet when a new iteration starts.

        for(int i=0; i <= last;i++) //check each adjacent pair of items in the unsorted part
          {
        if(ar[i]>ar[i+1]) //the pair is out of order
          {
            swap(ar[i],ar[i+1]);
            swapped = true; //swapping required - meaning we need to proceed to the next iteration.
          }
          }
        last--; //the area to be checked shrinks down after each iteration
      }//end of while
}
int partition(int ar[], int start, int end) {
    swap(ar[(start + end) / 2], ar[end]);
    int pivot = ar[end];
    int swap_index = start;
    for (int i = start; i < end; i++) {
        if (ar[i] <= pivot) {
            swap(ar[i], ar[swap_index]);
            swap_index++;
        }
    }
    swap(ar[end], ar[swap_index]);
    return swap_index;
}
void quickSort(int ar[], int start, int end) {//set the bounds of the array/subarray
    if (start < end) {//if the size of sub array is at least 2
        int pivot = partition(ar, start, end);//pivot become value returned from partition
        quickSort(ar, start, pivot - 1);//sort the left side
        quickSort(ar, pivot + 1, end);//sort the right side

    }

}

void merge(int ar[], int first, int last)//in the end of this function, array[first..last] will be sorted
{
    int size = last - first;
    int* temp = new int[size + 1];//declaring dynamic array with size of
    int left = first;// left finger points to the first slot of left half = first
    int mid = (first + last) / 2;
    int right = mid + 1;// right finger points to the first slot of right half = (first + last) /2 + 1
    int i = 0;//counter
    // Merge the two subarrays into the temporary array while comparing elements
    while (left <= mid && right <= last) {
        if (ar[left] > ar[right]) {
            temp[i] = ar[right];
            i++;
            right++;
        }
        if (ar[left] <= ar[right]) {
            temp[i] = ar[left];
            i++;
            left++;
        }
    }
    // Copy any remaining elements from the left subarray to the temporary array
    while (left <= mid) {
        temp[i] = ar[left];
        i++;
        left++;
    }
    // Copy any remaining elements from the right subarray to the temporary array
    while (right <= last) {
        temp[i] = ar[right];
        i++;
        right++;
    }
    i--;// Decrement the counter to point to the last element in the temporary array

    // Copy the merged elements from the temporary array back to the original array
    while (i >= 0) {
        ar[i + first] = temp[i];
        i--;
    }
    delete[] temp;// Deallocate the memory used for the temp array
}

void mergeSort(int ar[], int first, int last)
{
    if (first < last) { //if there is only one element, return to the caller immediately
        int mid = (first + last) / 2;//the left half goes from first and mid inclusive. [first .. mid]
        mergeSort(ar, first, mid);//mergeSort() on left half
        mergeSort(ar, mid + 1, last);//mergeSort() on right half
        merge(ar, first, last);//merge the left and right halves into one sorted array
    }

    //For implementation of this function, refer to my lecture notes "merge sort"
}
