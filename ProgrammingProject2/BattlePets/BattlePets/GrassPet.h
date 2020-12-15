#pragma once
#include "Pets.h"
class GrassPet :public Pets//this class inherits from the Pokemon Class
{
private:
	string type;
public:
	GrassPet();
	GrassPet(int ID, string petname, int hp, int currenthp, Moves movea, Moves moveb, Moves movec, Moves moved);
	//function overriding to signify polymorphism
	void printType();
	~GrassPet();//destructor

};

