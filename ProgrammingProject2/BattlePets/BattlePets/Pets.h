#pragma once
using namespace std;
#include <iostream>
#include "Moves.h"
//this is the parent class of the derived classes
class Pets
{
private:
	int petID;
	string name;
	int MaxHP;
	int CurrentHP;
	Moves move1;
	Moves move2;
	Moves move3;
	Moves move4;


public:
	//this class contains most of the methods that are going to be used by the child classes such as the getters and setters
	Pets();
	Pets(int ID, string petname, int hp, int currenthp, Moves movea, Moves moveb, Moves movec, Moves moved);
	string getName();
	int getID();
	void setHP(int hp);
	int getMaxHP();
	int getCurrentHP();
	Moves getMove(int moveNo);
	virtual void printType();
	~Pets();
};

