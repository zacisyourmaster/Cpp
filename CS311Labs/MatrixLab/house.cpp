/******************************************
Template prepared by Kazumi Slott
CS311
Description of this program: Program to calculate the cost of each house in each area by multiplying 2 matrices.
Your name: Zach Smith
Your programmer number:30
Number of hours you spent: 1
Any difficulties?:
*******************************************/
#include "matrix.h"
#include <iostream>
using namespace std;
int main()
{
  Matrix<double> m1(4, 4);
  Matrix<double> m2(4, 3);
  ifstream fin;
  fin.open("house_info.in");
  fin >> m1;
  fin.close();
  fin.open("house_func.in");
  fin >> m2;
  fin.close();
    try
      {
        Matrix<double> r = m1 * m2;
        
	cout<< r <<endl;
      }
    catch (Matrix<double>::size_error)
      {
        cout << "SIZE ERROR" << endl;
      }
    return 0;
}
