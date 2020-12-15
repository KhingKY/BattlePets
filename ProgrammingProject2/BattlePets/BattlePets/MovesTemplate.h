#pragma once

template <class T>
class MovesNode
{//this class is used for creating the singly link list nodes 
public:
	T fMoves;
	MovesNode* fNext;
	MovesNode(const T& aMoves, MovesNode* aNext = (MovesNode*)0)
		//this is the constructor used to create the nodes and also link the next node to it
	{
		fMoves = aMoves;
		fNext = aNext;
	}
};