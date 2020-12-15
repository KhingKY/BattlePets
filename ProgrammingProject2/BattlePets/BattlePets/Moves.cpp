#include "Moves.h"
Moves::Moves()
{

}

Moves::Moves(string name, int dmg, string type)
{
	moveName = name;
	damage = dmg;
	moveType = type;
}

string Moves::getName()
{
	return moveName;
}

string Moves::getType()
{
	return moveType;
}

int Moves::getdmg()
{
	return damage;

}
Moves::~Moves() {}