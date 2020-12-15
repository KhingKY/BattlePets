#pragma once
#include <iostream>
using namespace std;
//this class is used to represent the stack concept which is used in the main for how the enemy pokemon team will be ordered by
template <class T>
class PetStack
{
private:
	T* PetElements;
	int PetStackPointer;
	int PetStackSize;
public:
	PetStack(int size);
	~PetStack();

	//this checks if the stack is empty
	bool isEmpty() const;

	//this checks the size of the stack
	int size() const;

	//this pushes objects into the stack
	void push(T aItem);

	//this removes the 1st element on top of the stack which is the last element to enter the stack
	void pop();

	//this reads the top of the stack
	T& top();

};

template <class T>
PetStack<T>::PetStack(int size)
{//initializes the stack
	if (size <= 0)//if the size from the parameter is smaller than 0, then throw a error message
	{
		throw invalid_argument("Error: Invalid stack size. ");
	}
	else
	{
		PetElements = new T[size];
		PetStackPointer = 0;
		PetStackSize = size;
	}
}

//stack destructor
template <class T>
PetStack<T>::~PetStack()
{
	delete[] PetElements;
}

template <class T>
bool PetStack<T>::isEmpty() const
{
	return PetStackPointer == 0;//once the stack pointer hits is 0 which means the size of the stack is 0
}

template <class T>
int PetStack<T>::size() const
{
	return PetStackPointer;//returns the current position the stack pointer is pointing at the top of the stack
}

template <class T>
void PetStack<T>::push(T aItem)
{
	if (PetStackPointer < PetStackSize)//if the current size is smaller than the size set when creating the stack
	{
		PetElements[PetStackPointer++] = aItem;//assigns the parsed in item into available slot
	}
	else
	{
		throw overflow_error("Stack has reached maximum capacity.");
	}
}

template <class T>
void PetStack<T>::pop()
{
	if (!isEmpty())//if the stack is not empty
	{
		PetStackPointer--;//removes the stack pointer starting from the top
	}
	else
	{
		throw underflow_error("Stack is currently empty.");
	}
}

template <class T>
T& PetStack<T>::top() //returns the item in the current slot of the stack which is at the top
{
	if (!isEmpty())
	{
		return PetElements[PetStackPointer - 1];
	}
	else
	{
		throw underflow_error("Stack is currently empty.");
	}
}