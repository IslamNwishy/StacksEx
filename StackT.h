//File: StackT.h

//Name:Islam Osama Nwishy
//ID#: 900170200
//Assignment 1 - Part (1)

#ifndef StackT_H
#define StackT_H

template <class Type>
class StackT {
	//MaxSize for the size of the Array
	//top refrences the top element in the stack
	//Stack a pointer to the array set to be whatever type declared by the user
private:
	int MaxSize, top;
	Type *Stack;

public:
	StackT(int nelements = 128);
	StackT(int nelements,char L);
	~StackT();
	void Push(Type x);
	void Pop(Type &x);
	void StackTop(Type &x);
	bool StackIsEmpty();
	bool StackIsFull();
	void Destroy();
	void Display();
	//A public Char to hold the name of the stack (Optional)
	char Name;
};

#endif // !StackT_H







