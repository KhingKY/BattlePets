#pragma once
template<class T>
class BattledexList
{//this class is used as the doubly linked list for the different type of Pets
	//it involves template class as well
public:
	typedef BattledexList<T> Pets;
private:
	T fPet;
	Pets* fNext;
	Pets* fPrevious;

public:
	BattledexList()
	{
		fPet = T();
		fNext = &NIL;
		fPrevious = &NIL;
	}//default constructor
	static Pets NIL;

	BattledexList(T aPet);//overload constructor

	//appending and prepending the nodes into the linked list
	void prepend(Pets& aPets);
	void append(Pets& aPets);
	void remove();//removes nodes from the linked list

	T getPet() const//gets the data in the current node
	{
		return fPet;
	}
	Pets& getNext() const
	{
		return *fNext;
	}
	Pets& getPrevious() const
	{
		return *fPrevious;
	}
};

template<class T>
BattledexList<T> BattledexList<T>::NIL;

template<class T>
BattledexList<T>::BattledexList(T aPet)
{
	fPet = aPet;
	fNext = &NIL;
	fPrevious = &NIL;
}

template<class T>
void BattledexList<T>::prepend(Pets& aPets)
{
	aPets.fNext = this; // points this as the next node of aPets
	if (fPrevious != &NIL)
		//this makes it so the current node is the backwards pointer of aPet and if pointer forwards, it will be aPet
	{
		aPets.fPrevious = fPrevious;
		fPrevious->fNext = &aPets;
	}
	fPrevious = &aPets;
}

template<class T>
void BattledexList<T>::append(Pets& aPets)
{
	aPets.fPrevious = this; // points this as the previous node of aPets
	if (fNext != &NIL)
		//this makes it so the current node is the forwards pointer of aPets which will be behind aPet
	{
		aPets.fNext = fNext;
		fNext->fPrevious = &aPets;
	}
	fNext = &aPets;
}

template<class T>
void BattledexList<T>::remove()
{
	if (fNext == &NIL)
	{
		fPrevious->fNext = &NIL;
	}
	else if (fPrevious == &NIL)
	{
		fNext->fPrevious = &NIL;
	}
	else
	{
		fPrevious->fNext = fNext;
		fNext->fPrevious = fPrevious;
	}

	//delete this;
}
