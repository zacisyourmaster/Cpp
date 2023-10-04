/**************************************************************************
~/cs311/stack_L_T_client.cpp
Implemented by Kazumi Slott
9-2-2021

Testing stack implemented with a linked list with an exception class
**************************************************************************/
#include <iostream>
using namespace std;
#include "stack_L_T.h"

void func(const Stack<int>& s);

int main()
{
  cout << "-----calling the constructor-----" << endl;
  Stack<int> s;

  cout << "-----calling empty-----" << endl;
  if(s.empty())
    cout << "Empty" << endl; //Empty

  //cout << "-----calling getSize-----" << endl;
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

  cout << "-----calling getTop(non-const)-----" << endl;
  cout << s.getTop() << endl; //2

  cout << "-----calling operator<<-----" << endl;
  cout << s << endl; /*--- Top ---
		       2
		       1
		       --- Bottom ---*/

  //Testing const getTop()
  func(s);


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

   cout << "-----testing exception of getTop(non-const), calling getTop-----" << endl;

  try
    {
      s.getTop();
    }
  catch(Stack<int>::Underflow)
    {
      cout << "Illegal operation of getTop. - Stack is empty" << endl;
    }

   cout << "-----testing exception of getTop(const), calling getTop-----" << endl;
   try
    {
      func(s);
    }
   catch(Stack<int>::Underflow)
    {
      cout << "Illegal operation of getTop. - Stack is empty" << endl;
    }


  //recovered from the error - If we didn't use try-catch, the program would abort here.  

  cout << "-----testing destructor and destroy-----" << endl;





  /*  s.getTop()++; //T& return type lets you change top element. Top is now 3 from 2.

  int& r = s.getTop(); //r points to the top element
  cout << "address of top->elem" << &r << endl; //You could compare the address of r to the address of top element inside stack class. They are the same.

  r += 200; //adds 200 to top element
  cout << r << endl; //203

  int top = s.getTop(); //top gets 203
  cout << top << endl; //203
  top++; //top becomes 204
  cout << s.getTop() << endl; //But the top element is still 203

  cout << s << endl;*/ /*--- top ---
		       203
		       1
		       --- Bottom ---*/
  /*
  Stack<int> s2;
  s2 = s; //operator= is called here. 
  cout << s.getSize() << endl; //2
 
  cout << s2 << endl;*/ /*--- top ---
			203
			1
			--- Bottom ---*/
  
  //func(s); //testing const T& getTop() const

  /*Stack<int> s3(s); //testing the copy constructor
    cout << s3 << endl; *//*--- top ---
			203
			1
			--- Bottom ---*/

  return 0;
}


//s is a const object, so it needs to call the const version of getTop(). 
void func(const Stack<int>& s)
{
  cout << "------Testing getTop(const)------" << endl;
  cout << s.getTop() << endl;
} 
