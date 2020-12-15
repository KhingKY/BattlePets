#pragma once
#include "MovesTemplate.h"
#include <iostream>

using namespace std;
//this class uses a template class and is used as an iterator for the singly link list
template <class T>
class MovesIterator
{
private:
	MovesNode<T>* fNode; //this stores the data for each node in the singly link list
public:
	typedef MovesIterator<T> Iterator; //defines the name to describe  MovesIterator<T> as Iterator for easier use

	MovesIterator(MovesNode<T>* aNode);//default constructor

	//an overload operator for pointers where it will return the address of the data from the node
	const T& operator*() const;

	//overload operators used for iterating through the nodes through incrementing
	//this also contains both prefix and postfix methods
	Iterator& operator++();
	Iterator operator++(int);

	//overload comparison operators used to compare between different nodes to see whether they are equal or not
	bool operator==(const Iterator& aOther) const;
	bool operator!=(const Iterator& aOther) const;

	//detects the end of the link
	Iterator end();

	T getMoves() const
	{
		return fNode->fMoves;
	}
};

//implementation is done inside the header file 
template <class T>
MovesIterator<T>::MovesIterator(MovesNode<T>* aNode)
{
	fNode = aNode;
}

//all the implementation needs to have the template <class T> declaration in order to work
template <class T>
const T& MovesIterator<T>::operator*() const
{
	return fNode->fMoves;
}

//this is the prefix incremental operator
template <class T>
MovesIterator<T>& MovesIterator<T>::operator++()
{
	fNode = fNode->fNext; //moves from one node to the next node and returns it
	return *this;
}

//this is the postfix incremental operator
template <class T>
MovesIterator<T> MovesIterator<T>::operator++(int)
{
	MovesIterator<T> temp = *this;
	fNode = fNode->fNext;
	return temp;
}

//comparison overload operators
template <class T>
bool MovesIterator<T>::operator==(const Iterator& aOther) const
{
	return (fNode == aOther.fNode);
}

template <class T>
bool MovesIterator<T>::operator!=(const Iterator& aOther) const
{
	return !(*this == aOther);
}

//detects the end of the singly link list
template <class T>
MovesIterator<T> MovesIterator<T>::end()
{
	MovesIterator<T> temp = *this;
	while (temp.fNode != NULL)
	{
		temp++;
	}//keeps increasing the node until a NULL is met
	return temp;
}

