//File: StackT.cpp

//Name:Islam Osama Nwishy
//ID#: 900170200
//Assignment 1 - Part (1)

#include <iostream>
#include"StackT.h"
using namespace std;



//Constructor (1): sets the MaxSize to the given one or 128 if no value was given
//Instantiates the stack
//Sets the top value to -1 since the stack is empty
template <class Type>
StackT <Type>::StackT(int x) {
	MaxSize = x;
	Stack = new Type[MaxSize];
	top = -1;
}

//Constructor (2): Does everything like Constructor (1) but also sets a name to the stack
template <class Type>
StackT <Type>::StackT(int x, char L) {
	MaxSize = x;
	Stack = new Type[MaxSize];
	top = -1;
	Name = L;
}

//Deconstructor: Calls a function that distroys the stack and sets the pointer to NULL
template<class Type>
StackT<Type>::~StackT() {
	Destroy();
}

//Destroys the stack if needed and sets the pointer to NULL
template<class Type>
void StackT<Type>::Destroy() {
	delete[]Stack;
	Stack = NULL;
}

//Adds a new element to the top of the stack if possible and moves the top by 1
template<class Type>
void StackT<Type>::Push(Type x) {
	if (!StackIsFull())
		Stack[++top] = x;
	else
		cout << "Trying To push into a Full Stack! Stack Overflow!" << endl;
}

//Removes an element from the stack if possible and decreases the top by 1
template<class Type>
void StackT<Type>::Pop(Type &x) {
	if (!StackIsEmpty())
		x = Stack[top--];
	else
		cout << "Trying To Pop from an Empty Stack! Stack Underflow!" << endl;
}

//returns the top element in the stack without removing it
template<class Type>
void StackT<Type>::StackTop(Type &x) {
	if (!StackIsEmpty())
		x = Stack[top];
	else
		cout << "Trying To Pop from an Empty Stack! Stack Underflow!" << endl;
}

//returns true if stack is full
template<class Type>
bool StackT<Type>::StackIsFull() {

	return (top > MaxSize);
}

//returns false if stack is empty
template<class Type>
bool StackT<Type>::StackIsEmpty() {
	return(top < 0);
}

//outputs all the values in the stack (if any)
template<class Type>
void StackT<Type>::Display() {
	if (top >= 0) {

		for (int i = 0; i <= top; i++)
		{
			cout << Stack[i] << " \t";
		}

	}
}

