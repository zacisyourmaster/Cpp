/**********************************
Templated created by Kazumi Slott
CS311
Your name: Zach Smith
Your programmer number: 30
Hours spent: 2
Any difficulties?: when you said you used pivot, i and swap_index I thought that i was a seperate variable not the variable inside for loop.
***********************************/
#include <iostream>
#include "swap.h"
using namespace std;

void printAr1(const int ar[], int s)
{
    for (int i = 0; i < s; i++)
        cout << ar[i] << " ";
    cout << endl;
}
//I have 3 variables: pivot, i and swap_index. You may have any local variables.

    //swap the middle element with the last element first (recall this would be a good idea in case the list is sorted already).

    //For implementation of this function, refer to my lecture notes "quick sort".
    //If you used a different algorithm, I would assume you cheated and give you zero points.
    //This function returns the index where the pivot value went in.
int partition(int ar[],int start,int end) {
    mySwap(ar[(start + end) / 2], ar[end]);
    int pivot = ar[end];
    int swap_index = start;
    for (int i = start; i < end; i++) {
        if (ar[i] <= pivot) {
            mySwap(ar[i], ar[swap_index]);
            swap_index++;
        }
    }
    mySwap(ar[end], ar[swap_index]);
    return swap_index;
}
void quickSort(int ar[],int start, int end) {//set the bounds of the array/subarray
    if (start < end) {//if the size of sub array is at least 2
        int pivot = partition(ar, start, end);//pivot become value returned from partition
        quickSort(ar, start, pivot-1);//sort the left side
        quickSort(ar, pivot+1, end);//sort the right side

    }

}
int main1()
{
    int ar[] = { 15, 10, 5, 7, 1, 4, 12, 8, 6 };
    quickSort(ar, 0, 8);
    printAr1(ar, 9); //1 4 5 6 7 8 10 12 15

    int ar1[] = { 1, 7, 5, 3, 9, 4 };
    quickSort(ar1, 0, 5);
    printAr1(ar1, 6); //1 3 4 5 7 9 

    int ar2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    quickSort(ar2, 0, 9);
    printAr1(ar2, 10); //1 2 3 4 5 6 7 8 9 10

    return 0;
}