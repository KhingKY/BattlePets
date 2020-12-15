#include "WaterPet.h"
WaterPet::WaterPet() //default constructor do not possess any actions
{

}

WaterPet::WaterPet(int ID, string petname, int hp, int currenthp, Moves movea, Moves moveb, Moves movec, Moves moved) :Pets(ID, petname, hp, currenthp, movea, moveb, movec, moved)//inheriting the fields from its parent class
{
	type = "Water";
}

void WaterPet::printType()
{
	cout << " \tWater Type" << endl;//this prints the type of the pet (water) which overrides the function in its parent class
}

WaterPet::~WaterPet()
{

}
