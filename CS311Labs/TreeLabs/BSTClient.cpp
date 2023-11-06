/****************************
Kazumi Slott
CS311

Test client for BST.h
***************************/
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "BST.h"

int main()
{
  //  srand(time(0));
  BST<int> b1;
  int n;
  //ofstream fout;
  //fout.open("BST.in");
  ifstream fin;
  fin.open("BST.in");

  for(int i = 1; i <= 30; i++)
  {
      //n = rand()%100 + 1;
      //fout << n << " ";
      fin >> n;
      b1.insertNodeI(n);
  }

  cout << "inOrderPrint()" << endl;
  b1.inOrderPrint();        
  cout << "\n\npreOrderPrint()" << endl;
  b1.preOrderPrint();
  cout << "\n\npostOrderPrint()" << endl;
  b1.postOrderPrint();
   
  cout << endl << endl << "The max length is " << b1.getMaxLength() << endl;
  cout << "The min length is " << b1.getMinLength() << endl;
  cout << "The total number of nodes is " << b1.getNumNodes() << endl;
  cout << "The total number of even nodes is " << b1.getEvenNodes() << endl;

  cout << "Searching n using Recursion " << b1.searchR(n)->getEl() <<  endl;
  cout << "Searching n using Iteration " << b1.searchI(n)->getEl() << endl;
  cout << "Searching 1000 using Recursion " << b1.searchR(1000) << endl;
  cout << "Searching 1000 using Iteration " << b1.searchI(1000) << endl;

  cout << "testing BFTprint()" << endl;
  b1.BFTprint();
  cout << "\n\ntesting DFTprint()" << endl;
  b1.DFTprint();

  cout << "\n\nDestructor is being called" << endl;

  return 0;
}
