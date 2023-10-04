/*************************
Written By Kazumi Slott
CS211
 ************************/
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <class T> //forward declaration
class BST;

template <class T>
class Node
{
  friend class BST<T>; //make BST a friend of Node so it can access the private members

 private:
   T elem;
   Node<T>* right;
   Node<T>* left;

 public:
   Node(){right = NULL; left = NULL;}
   Node(const T& e){elem = e; right = NULL; left = NULL;}
};


template <class T>
class BST
{
private:
  Node<T>* root;
  void insertNode(Node<T>*&, const T&);
public:
  BST();
  void insertNode(const T&);
  bool search(const T&);
};


template <class T>
BST<T>::BST()
{
  root = NULL;
}

template <class T>
void BST<T>::insertNode(const T& e)
{
  insertNode(root, e);
}


template <class T>
void BST<T>::insertNode(Node<T>*& p, const T& e)
{
  if(p == NULL)
    p = new Node<T>(e);
  else if(e < p->elem)
    return insertNode(p->left, e);
  else // e > p->elem
    return insertNode(p->right, e);
}

template <class T>
bool BST<T>::search(const T& e)
{

}


#endif
