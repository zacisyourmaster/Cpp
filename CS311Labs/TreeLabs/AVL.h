/****************
Template created by Kazumi Slott
CS311

Your name: Zach Smith
Your programmer number: 30
Hours spent?:
Any difficulties?:
*****************/

#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <queue>
using namespace std;

//forward declaration of AVL class. We need this because AVL class is used as a friend in Node. 
//Check your stack_L_T.h if you don't know what to put here.
template <class T>
class AVL;

//Make Node and AVL template classes.
//You put the class definition and member function implementations in .h when you use template.  
//If you don't know how to make them template,
//Check page 3 of CS211 "Lec Notes on Exception Handling". I have a template stack class there.
//Also you made stack_L_T.h using template at the beginning of this semester.

template <class T>  //make it a template class
class Node
{
	friend class AVL<T>; //AVL wants to access private members of Node
private:
	T el;
	int BF;
	Node* right;
	Node* left;
	Node* up;

public:
	Node() { right = left = up = NULL; }; //default constructor. set right and left to NULL
	Node(const T& e) { BF = 0; el = e; right = left = up = NULL;/*????? What do you do here?*/ };
	T getEl() const { return el; } //returns el
};

//Make it a template class
template <class T>
class AVL
{
private:
	Node<T>* root;
	void destroy(Node<T>* p);
	void inOrderPrint(Node<T>* p);
	int getMaxLength(Node<T>* p);
	Node<T>* rightRotation(Node<T>* P); //These 4 are new additions
	Node<T>* leftRotation(Node<T>* P);
	void balanceTree(Node<T>* newNode);
	Node<T>* updateBF(Node<T>* Q);
public:
	AVL() { root = NULL; } //implement constructor here
	~AVL(); //need to have a private recursive function. Name it destroy.
	void insertNodeI(const T& e);
	void inOrderPrint();
	void BFTprint();
	int getMaxLength();
};

//implement the member functions in the header if you are making a template class


//destructor.
//If you don't know how to make the destructor, check the following
//CS211 Lec notes on AVL recursive functions - destroy and in order traversal
//CS211 Lecture recording - Lecture 4/28(Wed) - AVL:: inOrderPrint(), destroy()

template <class T>
AVL<T>::~AVL()
{
	destroy(root);
}

template <class T>
void AVL<T>::destroy(Node<T>* p) //private function. WHY?
{
	//destroy all nodes
	if (p == NULL)
		return;
	destroy(p->left);
	destroy(p->right);
	//cout << p->el << "-->";
	delete p;
}

template <class T>
void AVL<T>::insertNodeI(const T& e)
{
	Node<T>* newNode = new Node<T>(e);//make a new node.  Check stack_L_T.h to see how you made a new node.
	Node<T>* p = root;
	Node<T>* parent = NULL; //points to the parent of p. 

	//move p to NULL
	while (p != NULL)
	{
		//parent points to the parent node while p points to the left or right child.
		parent = p;
		if (e < p->el)
			p = p->left;
		else //p->el <= e
			p = p->right;

	}

	if (parent == NULL) //tree is empty
		root = newNode;
	else if (e < parent->el) //insert a child as the parent's left child
		parent->left = newNode;
	else //parent->el <= e //insert a child as the parent's left child
		parent->right = newNode;
	newNode->up = parent;
	balanceTree(newNode);
}
template <class T>
void AVL<T>::inOrderPrint()
{
	inOrderPrint(root);
}

template <class T> //private function. WHY?
void AVL<T>::inOrderPrint(Node<T>* p)
{
	if (p == NULL)
		return;
	inOrderPrint(p->left);
	cout << p->el << "-->";
	inOrderPrint(p->right);
}

template <class T>
void AVL<T>::BFTprint()  //Breadth First Traversal Print
{
	//Use the library's queue. https://cplusplus.com/reference/queue/queue/

	//Make sure to include <queue> at the top
	queue<Node<T>*> q;
	q.push(root);

	while (!q.empty()) {
		Node<T>* front = q.front();
		q.pop();

		// Print element and balance factor
		cout << front->el << " " << front->BF << " ";

		// If it's not the root, print the parent's element
		if (front->up != NULL)
			cout << front->up->el << "-->";
		else
			cout << "-->";

		// Enqueue left and right children if they exist
		if (front->left != NULL)
			q.push(front->left);
		if (front->right != NULL)
			q.push(front->right);
	}
}

template <class T>
int AVL<T>::getMaxLength()
{
	return getMaxLength(root);
}

template <class T>
int AVL<T>::getMaxLength(Node<T>* p) //private function. Why?
{
	if (p == NULL)
		return 0;

	int leftLen = getMaxLength(p->left);
	int rightLen = getMaxLength(p->right);

	if (leftLen > rightLen)
		return leftLen + 1;
	else
		return rightLen + 1;
}

template <class T>
void AVL<T>::balanceTree(Node<T>* newNode)
{
	Node<T>* P = updateBF(newNode); //violation node
	if (P == NULL)
	{
		return;
	}
	Node<T>* temp;
	if (P->BF == 2 && P->left != NULL && P->left->BF == 1)//LL violation
	{
		temp = rightRotation(P); //rotate right
	}
	else if (P->BF == -2 && P->right != NULL && P->right->BF == -1)//RR
	{
		temp = leftRotation(P); //rotate left
	}
	else if (P->BF == 2 && P->left != NULL && P->left->BF == -1)//LR violation
	{
		//make left and right rotate
		temp = leftRotation(P->left); //temp point to P left rotation
		P->left = temp;//have that node's up be the violation
		temp = rightRotation(P); //rotate right
	}
	else//RL
	{
		//makes a right then left rotation
		temp = rightRotation(P->right); //temp point to P right rotation
		P->right = temp; //node up is the violation 
		//left rotation once the right rotation is completed
		temp = leftRotation(P); //rotate left
	}

	Node<T>* parent = temp->up; //parent of temp (root)

	if (P == root)//if the original was root
	{
		root = temp;//new root
	}
	else if (P == parent->left) //violating node was parents left child 
	{
		parent->left = temp;
	}
	else //violating node was parents right
	{
		parent->right = temp;
	}
}
//void AVL<T>::balanceTree(Node<T>* newNode) {
//	Node<T>* P = updateBF(newNode);
//	if (P == NULL)
//		return;
//	Node<T>* parent = P->up;
//	// Figure out if P (the root of the subtree that needs to be fixed) comes from left or right of its parent or root.
//	if (P->BF == 2 && P->left != NULL && P->left->BF == 1)//LL
//		rightRotation(P);
//	else if (P->BF == -2 && P->right != NULL && P->right->BF == -1)//RR
//		leftRotation(P);
//	else if (P->BF == 2 && P->left != NULL && P->left->BF == -1) {//LR
//		leftRotation(P->left);  // Left rotation on P's left child
//		rightRotation(P);       // Right rotation on P
//	}
//	else if (P->BF == -2 && P->right != NULL && P->right->BF == 1) {//RL
//		rightRotation(P->right);  // Right rotation on P's right child
//		leftRotation(P);
//	}
//
//	if (parent != NULL) {
//		if (parent->left == P)
//			parent->left = P;
//		else
//			parent->right = P;
//	}
//	else {
//		// If parent is NULL, it means P is the new root of the entire tree
//		// Update the root pointer of the AVL tree
//		root = P;
//	}
//}



template <class T>
Node<T>* AVL<T>::updateBF(Node<T>* Q) {
	Node<T>* P = Q->up; // Parent of Q

	if (P == NULL)
		return NULL;

	if (P->left == Q)
		P->BF++;
	else
		P->BF--;

	while (P != root && (P->BF != -2 && P->BF != 2)) {
		Q = P;
		P = P->up;

		if (Q->BF == 0)
			return NULL;

		if (P->left == Q)
			P->BF++;
		else
			P->BF--;
	}

	if (P->BF == -2 || P->BF == 2)
		return P;

	return NULL;
}


template <class T>
Node<T>* AVL<T>::rightRotation(Node<T>* p) {
	if (p == NULL || p->left == NULL)
		return NULL;

	Node<T>* rroot = p->left;
	Node<T>* temp = rroot->right;

	// Update up pointers
	rroot->up = p->up;
	p->up = rroot;
	if (temp != NULL)
		temp->up = p;

	rroot->right = p;
	p->left = temp;

	// Recalculate balance factors
	p->BF = getMaxLength(p->left) - getMaxLength(p->right);
	rroot->BF = getMaxLength(rroot->left) - getMaxLength(rroot->right);
	return rroot;
}

template <class T>
Node<T>* AVL<T>::leftRotation(Node<T>* p) {
	if (p == NULL || p->right == NULL)
		return NULL;

	Node<T>* lroot = p->right;
	Node<T>* temp = lroot->left;

	// Update up pointers
	lroot->up = p->up;
	p->up = lroot;
	if (temp != NULL)
		temp->up = p;

	lroot->left = p;
	p->right = temp;

	// Recalculate balance factors
	p->BF = getMaxLength(p->left) - getMaxLength(p->right);
	lroot->BF = getMaxLength(lroot->left) - getMaxLength(lroot->right);
	return lroot;
}
#endif
