#pragma once
#include <vector>
#include <fstream>
#include "Pets.h"
#include "FirePet.h"
#include "WaterPet.h"
#include "GrassPet.h"
#include "BattledexList.h"
#include "Moves.h"
#include "MovesTemplate.h"
#include "MovesIterator.h"
using namespace std;

class Battledex
{//this class is essentially used to create all the data required to create the Pet and moves into a Battledex
	//this class includes a few concepts including singly linked list, doubly linked list, iterator, template class and singleton
	//this class uses the singleton design pattern to instantiate the data as only one instance is required for these data

public:
	static Battledex& Get()
	{
		static Battledex PokeInstance;
		return PokeInstance;
	}//this gets the instance in the class
	void printWaterPet();//prints all water Pet in the Battledex as a preview
	void printGrassPet();//prints all grass Pet in the Battledex as preview
	void printFirePet();//prints all fire Pet in the Battledex as preview

	//gets specific Pet from the doubly linked list based on the Pet name passed into the parameter
	//theres three getters for the three different  doubly linked list
	BattledexList<WaterPet>::Pets getWaterPet(string Pet);
	BattledexList<FirePet>::Pets getFirePet(string Pet);
	BattledexList<GrassPet>::Pets getGrassPet(string Pet);

	//iterates through water Pet doubly linked list
	BattledexList<WaterPet>::Pets PreviousWaterPet(string Pet);
	BattledexList<WaterPet>::Pets NextWaterPet(string Pet);

	//iterates through water Pet doubly linked list
	BattledexList<FirePet>::Pets PreviousFirePet(string Pet);
	BattledexList<FirePet>::Pets NextFirePet(string Pet);

	//iterates through water Pet doubly linked list
	BattledexList<GrassPet>::Pets PreviousGrassPet(string Pet);
	BattledexList<GrassPet>::Pets NextGrassPet(string Pet);

	void getMoves();

	Battledex(const Battledex&) = delete; //this prevents the creation of an object class that doesnt point to the instance

private:
	Battledex();//constructor is placed in private so that no one can initialize it from other classes

	//these are three different doubly linked list to store the three Pet types
	BattledexList<WaterPet> Water_Battledex;
	BattledexList<FirePet> Fire_Battledex;
	BattledexList<GrassPet> Grass_Battledex;



};

