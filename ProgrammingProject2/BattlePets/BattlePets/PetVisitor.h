#pragma once 
#include <iostream>
#include <fstream>
using namespace std;
template <class T>
class PetVisitor {
public:
	virtual ~PetVisitor() {} //virtual default destructor 

	virtual void visit(const T& aKey) const{}
};

template <class T>
class PreviewVisitor : public PetVisitor<T> {
public:
	//this visit is used to print out all the keys inside of the tree
	virtual void visit(const T& aKey) const
	{
		cout << aKey << " ";
	}
};

template <class T>
class DisplayVisitor : public PetVisitor<T> {
public:
	//this visit is used to write data into a text file
	virtual void visit(const T& aKey) const
	{
		
		ofstream myfile;
		myfile.open("BattlePetsData.txt", ios_base::app);
		myfile << aKey << "\n";
		myfile.close();
	}
};
