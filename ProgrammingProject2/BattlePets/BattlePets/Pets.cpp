#include "Pets.h"
#include <iostream>
using namespace std;

Pets::Pets() {}

//overload constructor
Pets::Pets(int ID, string petname, int hp, int currenthp, Moves movea, Moves moveb, Moves movec, Moves moved)
{
	petID = ID;
	name = petname;
	MaxHP = hp;
	CurrentHP = currenthp;
	move1 = movea;
	move2 = moveb;
	move3 = movec;
	move4 = moved;

}

//used in polymorphism
void Pets::printType()
{

}

string Pets::getName()
{
	return name;
}

int Pets::getID()
{
	return petID;
}

//the setHP function is used to change the hp of the Pets 
void Pets::setHP(int hp)
{
	CurrentHP = CurrentHP - hp;
}

int Pets::getMaxHP()
{
	return MaxHP;
}

int Pets::getCurrentHP()
{
	return CurrentHP;
}

//this getter is used to return the moves of the Pets based on the move number 
Moves Pets::getMove(int moveNo)
{
	Moves move;
	if (moveNo == 1) {
		move = move1;
	}
	else if (moveNo == 2) {
		move = move2;
	}
	else if (moveNo == 3) {
		move = move3;
	}
	else if (moveNo == 4) {
		move = move4;
	}
	return move;
}

Pets::~Pets() {}