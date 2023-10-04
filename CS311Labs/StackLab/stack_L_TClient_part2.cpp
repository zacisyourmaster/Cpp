/**************************************************************************
~/cs311/stack_L_T_grade2.cpp
Implemented by Kazumi Slott
9-8-2021

Testing stack implemented with a linked list with an exception class
**************************************************************************/
#include <iostream>
using namespace std;
#include "stack_L_T.h"

void func(const Stack<int>& s);
void func2(const Stack<int>& s);

int main()
{
  cout << "-----calling the constructor-----" << endl;
  Stack<int> s;

  cout << "-----calling empty-----" << endl;
  if(s.empty())
    cout << "Empty" << endl; //Empty

  //  cout << "-----calling getSize-----" << endl;
  //cout << s.getSize() << endl; //0

  cout << "-----calling push 1--------" << endl;
  s.push(1);
  cout << "-----calling push 2--------" << endl;
  s.push(2);

  //cout << "-----calling getSize-----" << endl;
  //cout << s.getSize() << endl; //2

  cout << "-----calling empty-----" << endl;
  if(!s.empty())
    cout << "Not empty" << endl; //Not Empty

  cout << "-----calling operator<<-----" << endl;
  cout << s << endl; /*--- Top ---
		       2
		       1
		       --- Bottom ---*/

  cout << "-----calling pop-----" << endl;
  s.pop();
  cout << "-----calling pop-----" << endl;
  s.pop();
  //cout << "-----calling getSize-----" << endl;
  //cout << s.getSize() << endl;

  cout << "-----calling empty-----" << endl;
  if(s.empty())
    cout << "Empty" << endl; //Empty

  cout << "-----calling operator<<-----" << endl;
  cout << s << endl;

  cout << "-----testing exception of pop, calling pop-----" << endl;

  try
    {
      s.pop();
    }
  catch(Stack<int>::Underflow)
    {
      cout << "Illegal operation of pop. - Stack is empty" << endl;
    }

   cout << "-----testing exception of getTop, calling getTop-----" << endl;

  try
    {
      s.getTop();
    }
  catch(Stack<int>::Underflow)
    {
      cout << "Illegal operation of getTop. - Stack is empty" << endl;
    }

  //recovered from the error - If we didn't use try-catch, the program would abort here.  

  cout << "-----testing destructor and destroy-----" << endl;


  cout << "======================= PART 2 ========================" << endl;

  cout << "------calling push 3-----" << endl;
  s.push(3);
  cout << "------calling push 4-----" << endl;
  s.push(4);
  cout << "------calling push 5-----" << endl;
  s.push(5);

  cout << "------calling T& getTop(). Incrementing top's element by 1------" << endl;
  s.getTop()++; //T& return type lets you change top element. Top is now 6 from 5.

  cout << s.getTop() << endl; //6

  cout << "-----calling operator<<-----" << endl;
  cout << s << endl; /*--- top ---
		       6
		       4
		       3
		       --- Bottom ---*/

  func(s);

  Stack<int> s9;
  func2(s9);
  
  Stack<int> s2;
  cout << "-----calling operator=. Testing to see it copies all elements.  -----" << endl;
  s2 = s; //operator= is called here. 

  cout << s2 << endl; /*--- top ---
			6
			4
			3
			--- Bottom ---*/

  cout << "-----calling operator=. Testing LHS which has some elements = empty RHS-----" << endl;
  Stack<int> s3;
  s2 = s3;

  cout << s2 << endl; /*--- top ---
			--- Bottom ---*/

  cout << "-----calling operator=. Testing operator= when the left and right hand sides are the same object. -----" << endl;
  s = s;
  cout << s << endl; /*--- top ---
			6
			4
			3
			--- Bottom ---*/

  cout << "-----calling copy constructor to see if it copies all elements-----" << endl;
  Stack<int> s5(s); //testing the copy constructor
  cout << s5 << endl; /*--- top ---
			6
			4
			3
			--- Bottom ---*/
  
  cout << "-----calling copy constructor when source is an empty stack. -----" << endl;
  Stack<int> s6(s3);
  cout << s6 << endl; /*--- top ---
			--- Bottom ---*/

  return 0;
}


//s is a const object, so it needs to call the const version of getTop(). 
void func(const Stack<int>& s)
{
  cout << "----Calling the const version of getTop()----" << endl;
  cout << s.getTop() << endl;//6
} 

void func2(const Stack<int>& s)
{
  cout << "----Calling the const version of getTop() to see if it throws an exception----" << endl;
  try{
    s.getTop();
  }
  catch(Stack<int>::Underflow)
    {
      cout << "Illegal operation of getTop. The stack is empty" << endl;
    }

}
