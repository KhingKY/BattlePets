#pragma once 
#include <stdexcept> 
#include "PetVisitor.h" 
using namespace std;

template<class T>
class PetTree {
private:
	const T* fKey;
	PetTree <T>* fLeft;
	PetTree <T>* fRight;

	PetTree() :fKey((T*)0)
	{
		fLeft = &NIL;
		fRight = &NIL;
	}
public:
	static PetTree<T> NIL; //sentinel
	PetTree(const T& aKey) : fKey(&aKey)
	{
		fLeft = &NIL;
		fRight = &NIL;
	}//(complete this) 

	~PetTree()
	{
		if (fLeft != &NIL)
			delete fLeft;
		if (fRight != &NIL)
			delete fRight;
	}//(complete this)

	bool isEmpty() const
	{
		return this == &NIL;
	}//(complete this)

	const T& key() const
	{
		if (isEmpty())
			throw domain_error("Empty PetTree");
		return *fKey;
	}//(complete this)

	PetTree& left() const
	{
		if (isEmpty())
			throw domain_error("Empty PetTree");
		return *fLeft;
	}

	PetTree& right() const
	{
		if (isEmpty())
			throw std::domain_error("Empty PetTree");
		return *fRight;
	}

	void attachLeft(PetTree<T>* aPetTree)
	{
		if (isEmpty())
			throw domain_error("Empty PetTree");
		if (fLeft != &NIL)
			throw domain_error("Non-empty sub tree");
		fLeft = new PetTree<T>(*aPetTree);
	}//(complete this)

	void attachRight(PetTree<T>* aPetTree) {
		if (isEmpty())
			throw std::domain_error("Empty PetTree");
		if (fRight != &NIL)
			throw std::domain_error("Non-empty sub tree");
		fRight = new PetTree<T>(*aPetTree);//makes allocation on heap 

	}
	PetTree* detachLeft()
	{
		if (isEmpty())
			throw std::domain_error("Empty PetTree");
		PetTree<T>& Result = *fLeft; //changed to pointer variable
		fLeft = &NIL;
		return &Result;
	}

	PetTree* detachRight() {
		if (isEmpty())
			throw std::domain_error("Empty PetTree");
		PetTree<T>& Result = *fRight; //changed to pointer variable 
		fRight = &NIL;
		return &Result;
	}

	//calls the visit method based on the type of class parsed in and moves to the next node and does a recurssion
	void accept(const PetVisitor<T>& aVisitor) const
	{
		if (!isEmpty())
		{
			
			aVisitor.visit(key());
			left().accept(aVisitor);
			right().accept(aVisitor);
		}
	}
};

template<class T>
PetTree<T> PetTree<T>::NIL;
