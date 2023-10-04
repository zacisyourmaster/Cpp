/***********************************
Template created by Kazumi Slott
CS311
Stack implemented with a LL

Your name here:Zach Smith
Your programmer number here: 30
Hours spent:Over 8
Any problems you had? Explain here: I had problems with copy and operator= function
###### Don't forget to specify the complexity above each function. ######
******************************************************************************************************************/
#ifndef STACK_L_T_H
#define STACK_L_T_H

#include <iostream> 
using namespace std;

template < class T > //forward declaration needed so we can make stack class a friend of node
class Stack;

template < class T > //forward declaration needed so we can make operator<< a friend of node and Stack
ostream& operator<<(ostream& o, const Stack<T>& s);


template < class T >
class Node
{
    friend class Stack<T>; //Stack class accesses the private members of Node
    friend ostream& operator<< <T>(ostream& o, const Stack<T>& s); //operator<< accesses the private members of Node

private:
    //???? elem;
    //???? next;  //check how right and left pointers are declared in BST class --> /cs/slott/cs211/BST_T.h
    T elem;
    Node<T>* next;
public:
    Node() {/*????=NULL;*/next = NULL; } //default constructor
    Node(const T& e) {/*???????*/elem = e; next = NULL; } //You should set next to NULL too.
};

template <class T>
class Stack
{
    friend ostream& operator<< <T>(ostream& o, const Stack& s); //operator<< accesses the private members of Stack

private:
    //???? top;
    Node<T>* top;
    //helper functions - private because they won't be called from client
    void destroy();
    void copy(const Stack& source);

public:
    Stack() {/* ?????? */ top = NULL; } //Implement a small function inside the class definition 
    Stack(const Stack& other);
    ~Stack();
    Stack& operator=(const Stack& rhs); //rhs = right hand side of the operator   LHS_obj = RHS_obj
    bool empty() const {/*return ????????? */return top == NULL; } //implement a small function inside the class definition
    void push(const T& val);
    void pop();
    T& getTop(); //Return type is T& so client can change the top value
    const T& getTop() const; //A const object needs to call a const member function

    //Make an empty exception class here. Underflow or/and Overflow? - You need to figure out where to throw an exception - I am throwing in 3 functions.
    class Underflow {};
};

/******************************************
Member function used to push an element on top of the stack
const T& val represents the value we are pushing onto the stack. The const shows that the value will not be modified
this function is void therefore it does not return anything
*******************************************/
//Complexity of this operation: O(1)
template <class T>
void Stack<T>::push(const T& val)//works
{
    Node<T>* t = new Node<T>(val);//creates new node t and intializes it with the value 'val'
    t->next = top;//sets next pointer to the of new node to point to top
    top = t;//sets top to t
}

/******************************************
This function removes aka pops the top value off of the stack;
this function takes 0 parameters
returns nothing
*******************************************/
//Complexity of this operation: O(1)
template <class T>
void Stack<T>::pop()
{
    //throw an exception if the stack is empty. (You shouldn't call pop if the stack is empty.)
    if (top == NULL)
        throw Underflow();
    Node<T>* temp = top;//creates node called temp which points to location of top
    top = top->next;//sets top node to the next node after top so now top->next is the top
    delete temp;//delete old top
}


/******************************************
this function retrieves the top element
No parameters
returns the top element of the stack
*******************************************/
//Complexity of this operation: O(1)
template <class T>
T& Stack<T>::getTop()
{
    if (top == NULL)//thrown an exception if the stack is empty. You shouldn't call getTop if empty.
        throw Underflow();

    return top->elem; //return the top element
}

/******************************************
same as the getTop() above. We need to provide this so a const object can call getTop()
No parameters
returns the top element of the stack
*******************************************/
//Complexity of this operation: O(1)
template <class T>
const T& Stack<T>::getTop() const
{
    if (top == NULL)//thrown an exception if the stack is empty. You shouldn't call getTop if empty.
        throw Underflow();
   // const T item = top.data;
    return top->elem;//returns the top element
}



/******************************************
This function will show all the elements in the stack in the following format.
--- Top ---
2
1
--- Bottom ---
paramater ostream& o is an ostream object
parameter const Stack<T>& s is the object to be streamed
returns a reference to the original ostream object, which means you can combine insertions
*******************************************/
//Complexity of this operation: O(n)
template <class T>
ostream& operator<<(ostream& o, const Stack<T>& s)//works
{
    if (s.empty()){//if stack is empty print top and bottom and return o;
        o << "--- Top ---" << endl;
        o << "--- Bottom ---" << endl;
        return o;//returns o
    }
    Node<T>* temp =s.top;// create new node that points to top of input stack
    //print from top to bottom.
    cout << "--- Top ---" << endl;
    while (temp != NULL) {//while top is not null aka while stack still has elements print element at top
        o << temp->elem << endl;
        temp = temp->next;//
    }
    cout << "--- Bottom ---" << endl;
  
    return o;//By returning o we can use multiple operators
}



template <class T>
Stack<T>::~Stack()
{
    destroy();//calls destructor function
}
/******************************************
destructor for destroy class. unallocates memory
no params
no return value; void function
*******************************************/
//helper function - called from destructor and operator=
//Complexity of this operation: O(n)
template<class T>
void Stack<T>::destroy() //This function will be called by destructor and operator=
{
    Node<T>* ptr = top;//creates pointer to top of stack
    Node<T>* temp;//temperary node 
    //print from top to bottom.
    while (ptr != NULL)//while top of stack is not null
    {
        temp = ptr->next;//sets temp to next value after ptr
        delete ptr;//delete where pointer points
        ptr = temp;// sets ptr to temp. since location ptr points to is empty we set ptr to temp so we can still use next
    }
    //destroy all nodes
    //?????????????? 

}

/******************************************
This is assignment operator function. Its purpose is to set lhs stack equal to rhs stack. it called the copy function to make lhs a copy of rhs
parameter is refrence to a constant stack
returns this object. 
*******************************************/
//Complexity of this operation: O(n)
template <class T>
Stack<T>& Stack<T>::operator=(const Stack& rhs) //rhs = right hand side of the operator
{
    //Check the addresses of the left and right objects. If they are the same, you are trying to assign the same object   s = s;
    if (this == &rhs)//You copy only if the left object is not the same as the right object.
        return *this;//return the "this" object
    destroy();//destroy any memory space "this" is using.
    top = rhs.top;//make this top equal to input
    copy(rhs);//call copy function
    return *this;//return the "this" object. By returning the this object, we can use multiple assignment operators.
}


/******************************************
This function creates a copy of a stack
parameter is a const Stack& other, which is stack object to be copied from
does not return anything
*******************************************/
//Complexity of this operation: O(n)
template <class T>
void Stack<T>::copy(const Stack& source) //source is the stack object copied from.
{
    Node<T>* last = NULL;// Initialize a pointer to keep track of the last node in this stack.
    Node<T>* ptr = source.top;// Initialize a pointer to traverse the source stack.
    while (ptr != NULL) //iterate through stack until we reach the end
    {
        Node<T>* newNode = new Node<T>(ptr->elem);// Create a new node in this stack with the same element as in the source stack.
        if (last == NULL)//if last is null
            top = newNode;//set top pointer of this stack to newNode
        else
            last->next = newNode;// Link the last node in this stack to the new node.
        last = newNode;// Update the last pointer to point to the newly added node.
        ptr=ptr->next;// Move to the next node in the source stack.
    }
}

/******************************************
//This is a copy constructor. It is used to make a copy of a stack object
Parameter is const Stack& other. It is a reference to 'other' Stack
this constructor does not return anything
*******************************************/
//copy constructor
template <class T>
Stack<T>::Stack(const Stack& other)
{
    //Node<T>* t = other.top;
    top = NULL;//initializing top of current stack to null
    copy(other);//Then you can call the copy function
}



#endif // end the definition here