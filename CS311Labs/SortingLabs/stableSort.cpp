/***************************************
Template prepared by Kazumi Slott
CS311
This program sorts an array of persons.

Your name: Zach Smith
Your programmer number: 30
Hours spent: ??????
Any difficulties?: ?????
****************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "swap.h"  //<=== include your swap.h if you made it so you can call your mySwap() in stableSort(). 
//     If you didn't make it, you can make a swap function in this file or call the library's swap(). 
using namespace std;

const int SIZE = 13;

struct person
{
    string fN;
    string lN;
    int grade;
};

bool fillAr(person a[])
{
    ifstream fin;
    fin.open(/*"/cs/slott/cs311/*/"stableSort3.in");

    if (!fin)
    {
        cout << "You don't have the input file" << endl;
        return false;
    }
    string f, l;
    int g;
    int i = 0;

    fin >> f >> l >> g;
    while (fin)
    {
        a[i].fN = f;
        a[i].lN = l;
        a[i++].grade = g;
        fin >> f >> l >> g;
    }
    fin.close();
    return true;
}

void printAr(const person a[])
{
    for (int i = 0; i < SIZE; i++)
        cout << a[i].grade << "  " << left << setw(10) << a[i].lN << setw(10) << a[i].fN << endl;
}

//You need to create some functions here, which will be called from stableSort()
bool compareFirst(person p1, person p2) {
    return p1.fN > p2.fN;
}

bool compareLast(person p1, person p2) {
    return p1.lN > p2.lN;
}

bool compareGrade(person p1, person p2) {
    return p1.grade > p2.grade;
}

void stableSort(person a[], int n, bool(&func)(person, person))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (func(a[j], a[j + 1]))
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}


int main()
{
    person ar[SIZE];
    if (fillAr(ar))
    {
        cout << "--- original ---" << endl;
        printAr(ar);
        //You need to sort the array here
        //HINT: call stableSort multiple times.
        stableSort(ar, SIZE, compareFirst);
        stableSort(ar, SIZE, compareLast);
        stableSort(ar, SIZE, compareGrade);
        cout << "--- result ---" << endl; 
        printAr(ar);
    }
    return 0;
}


