/******************************
Kazumi Slott
CS311
Test Client for matrix.h
******************************/
#include <iostream>
using namespace std;
#include "matrix.h"

int main()
{
  Matrix<double> m1(4, 5);//4 rows x 5 columns
  Matrix<double> m2(4, 3);//4 rows x 3 columns
  ifstream fin;
  fin.open("/cs/slott/cs311/matrix_mult_bad.in");

  cout << "filling m1 ----" << endl;
  fin >> m1;
  cout << "filling m2 ----" << endl;
  fin >> m2;

  fin.close();

  cout << "printing m1 ----" << endl;
  cout << m1 << endl;
  cout << "printing m2 ----" << endl;
  cout << m2 << endl;
  
  try
  {  
    Matrix<double> r = m1 * m2;
    cout << "result of m1 * m2 is ------" << endl;
    cout << r << endl;
  }
  catch(Matrix<double>::size_error)
   {
     cout << "imcomparable sizes" << endl;
     cout << "---------------------------------" << endl;
   }

  Matrix<int> m3(4, 5);//4 rows x 5 columns                                                                                                 
  Matrix<int> m4(5, 3);//5 rows x 3 columns                                                                                                 
   
  fin.open("/cs/slott/cs311/matrix_mult.in");

  cout << "filling m3 ----" << endl;
  fin >> m3;
  cout << "filling m4 ----" << endl;
  fin >> m4;


  cout << "printing m3 ----" << endl;
  cout << m3 << endl;
  cout << "printing m4 ----" << endl;
  cout << m4 << endl;

  try
    {
      Matrix<int> r = m3 * m4;
      cout << "result of m3 * m4 is ------" << endl;
      cout << r << endl;
    }
  catch(Matrix<int>::size_error)
    {
      cout << "imcomparable sizes" << endl;
    }
  
  return 0;
}
