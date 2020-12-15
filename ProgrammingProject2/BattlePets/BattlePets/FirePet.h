#pragma once
#include "Pets.h"
class FirePet :public Pets //this class inherits from the Pets Class
{
private:
	string type;
public:
	FirePet();
	FirePet(int ID, string pokename, int hp, int currenthp, Moves movea, Moves moveb, Moves movec, Moves moved);
	//function overriding to signify polymorphism
	void printType();
	~FirePet();//destructor

};

