/**********************************
Templated created by Kazumi Slott
CS311

Your name: Zach Smith
Your programmer number: 30
Hours spent: 2 and 41 mins
Any difficulties?:??????????
***********************************/
#include <iostream>
using namespace std;

void printAr(const int ar[], int s)
{
 for(int i = 0; i < s; i++)
    cout << ar[i] << " ";
  cout << endl;
}

void merge(int ar[], int first, int last)
{
    int size = last - first;
    int* temp = new int[size + 1];
    int left = first;
    int mid = (first + last) / 2;
    int right = mid + 1;
    int i = 0;
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
    while (left <= mid)
        temp[i++] = ar[left++];
    while (right <= last)
        temp[i++] = ar[right++];
    i--;
    while (i >= 0) {
        ar[i + first] = temp[i];
        i--;
    }
    delete[] temp;
}

void mergeSort(int ar[], int first, int last)
{
    if (first < last) {
        int mid = (first + last) / 2;//integer division drop decimal
        mergeSort(ar, first, mid);
        mergeSort(ar, mid+1, last);
        merge(ar, first, last);
    }
  
  //For implementation of this function, refer to my lecture notes "merge sort"
}

int main()
{
  int ar[] = {1, 8, 6, 4, 10, 5, 3, 2, 22}; //the array used in my lecture notes
  mergeSort(ar, 0, 8);
  printAr(ar, 9); //1 2 3 4 5 6 8 10 22

  int ar1[] = {1, 7, 5, 3, 9, 4};
  mergeSort(ar1, 0, 5);
  printAr(ar1, 6); //1 3 4 5 7 9 

  int ar2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  mergeSort(ar2, 0, 9);
  printAr(ar2, 10); //1 2 3 4 5 6 7 8 9 10

  return 0;
}
