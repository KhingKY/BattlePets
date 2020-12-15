#pragma once
#include "Pets.h"
class WaterPet :public Pets//this class inherits from the Pokemon Class
{
private:
	string type;

public:
	WaterPet();
	WaterPet(int ID, string petname, int hp, int currenthp, Moves movea, Moves moveb, Moves movec, Moves moved);
	//function overriding to signify polymorphism
	void printType();
	~WaterPet();//destructor

};

