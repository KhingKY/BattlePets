#include "GrassPet.h"
GrassPet::GrassPet() //default constructor do not possess any actions
{

}

GrassPet::GrassPet(int ID, string petname, int hp, int currenthp, Moves movea, Moves moveb, Moves movec, Moves moved) :Pets(ID, petname, hp, currenthp, movea, moveb, movec, moved)//inheriting the fields from its parent class
{
	type = "Grass";
}

void GrassPet::printType()
{
	cout << " \tGrass Type" << endl;//this prints the type of the pets (grass) which overrides the function in its parent class
}

GrassPet::~GrassPet()
{

}
