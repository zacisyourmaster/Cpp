#include <iostream>
using namespace std;
#include "swap.h"

int main()
{
  int num1 = 5, num2 = 10;
  mySwap(num1, num2);
  cout << num1 << " " << num2 << endl; //10 5

  char c1 = 'A', c2 = 'B';
  mySwap(c1, c2);
  cout << c1 << " " << c2 << endl; //B A

  return 0;
}
