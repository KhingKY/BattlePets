#include "FirePet.h"
FirePet::FirePet() //default constructo do not possess any actions
{

}

FirePet::FirePet(int ID, string petname, int hp, int currenthp, Moves movea, Moves moveb, Moves movec, Moves moved) :Pets(ID, petname, hp, currenthp, movea, moveb, movec, moved) //inheriting the fields from its parent class
{
	type = "Fire";
}

void FirePet::printType()
{
	cout << " \tFire Type" << endl;//this prints the type of the pets (fire) which overrides the function in its parent class
}

FirePet::~FirePet()
{

}
