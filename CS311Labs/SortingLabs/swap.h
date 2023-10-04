/********************************
The following mySwap works like the swap function in the library.

Your name: Zachary Smith
Your programmer number:30
Hours spent: less than 1
Any difficulties?: nope
********************************/

template <class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
