#pragma once
#include <iostream>
using namespace std;
class Moves //this class is used to create moves for the Pets to use
{
private:
	
public:
	string moveName;
	int damage;
	string moveType;
	Moves();
	Moves(string name, int dmg, string type);//overload constructor
	//getters
	string getName();
	string getType();
	int getdmg();
	~Moves();
};

