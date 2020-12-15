#include "Battledex.h"

//these global objects are created in order to be used by the below methods as many of the methods require it to run properly
//these objects are the moves that are to be added into the singly linked list

Moves Tackle("Tackle", 10, "Normal");
Moves Cut("Cut", 15, "Normal");
Moves Water_whip("Water Whip", 20, "Water");
Moves Water_wave("Water Wave", 50, "Water");
Moves Vortex("Vortex", 65, "Water");
Moves Flaming_breath("Flaming Breath", 65, "Fire");
Moves Ember_bite("Ember Bite", 65, "Fire");
Moves Combustion("Combustion", 20, "Fire");
Moves Plant_protection("Plant protetion", 30, "Grass");
Moves Seed_gun("Seed gun", 50, "Grass");
Moves Flower_power("Flower power", 60, "Grass");
Moves Dance("Dance", 0, "Water");

//these objects are the various pokemon to be added into the doubly linked list
GrassPet Mew(1, "Mew", 100, 100, Plant_protection, Seed_gun, Flower_power, Tackle);
GrassPet Mewmew(2, "Mewmew", 100, 100, Plant_protection, Seed_gun, Flower_power, Tackle);
GrassPet Mewmian(3, "Mewmian", 100, 100, Plant_protection, Seed_gun, Flower_power, Tackle);
FirePet Leo(4, "Leo", 100, 100, Flaming_breath, Ember_bite, Combustion, Cut);
FirePet Leon(5, "Leon", 100, 100, Flaming_breath, Ember_bite, Combustion, Cut);
FirePet Leoreon(6, "Leoreon", 100, 100, Flaming_breath, Ember_bite, Combustion, Cut);
WaterPet Aqua(7, "Aqua", 100, 100, Water_whip, Water_wave, Vortex, Tackle);
WaterPet Aquality(8, "Aquality", 100, 100, Water_whip, Water_wave, Vortex, Tackle);
WaterPet Aquanox(9, "Aquanox", 100, 100, Water_whip, Water_wave, Vortex, Tackle);
WaterPet Starprince(129, "Starprince", 50, 50, Dance, Dance, Dance, Dance);
WaterPet Starking(130, "Starking", 100, 100, Water_whip, Water_wave, Vortex, Tackle);
WaterPet Splashy(134, "Splashy", 100, 100, Water_whip, Water_wave, Vortex, Tackle);
FirePet Fierry(136, "Fierry", 100, 100, Flaming_breath, Ember_bite, Combustion, Cut);
GrassPet Leafy(135, "Leafy", 100, 100, Plant_protection, Seed_gun, Flower_power, Tackle);

//creating the nodes for each pokemon for the doubly linked list
BattledexList<WaterPet> Aqua_Battledex(Aqua);
BattledexList<WaterPet> Aquality_Battledex(Aquality);
BattledexList<WaterPet> Aquanox_Battledex(Aquanox);
BattledexList<WaterPet> Starprince_Battledex(Starprince);
BattledexList<WaterPet> Starking_Battledex(Starking);
BattledexList<WaterPet> Splashy_Battledex(Splashy);
BattledexList<FirePet> Leo_Battledex(Leo);
BattledexList<FirePet> Leon_Battledex(Leon);
BattledexList<FirePet> Leoreon_Battledex(Leoreon);
BattledexList<FirePet> Fierry_Battledex(Fierry);
BattledexList<GrassPet> Mew_Battledex(Mew);
BattledexList<GrassPet> Mewmew_Battledex(Mewmew);
BattledexList<GrassPet> Mewmian_Battledex(Mewmian);
BattledexList<GrassPet> Leafy_Battledex(Leafy);


Battledex::Battledex() //when this object gets instantiated for the 1st time, it appends all the pokemon nodes 
{
	Water_Battledex.append(Aqua_Battledex);
	Aqua_Battledex.append(Aquality_Battledex);
	Aquality_Battledex.append(Aquanox_Battledex);
	Aquanox_Battledex.append(Starprince_Battledex);
	Starprince_Battledex.append(Starking_Battledex);
	Starking_Battledex.append(Splashy_Battledex);

	Fire_Battledex.append(Leo_Battledex);
	Leo_Battledex.append(Leon_Battledex);
	Leon_Battledex.append(Leoreon_Battledex);
	Leoreon_Battledex.append(Fierry_Battledex);

	Grass_Battledex.append(Mew_Battledex);
	Mew_Battledex.append(Mewmew_Battledex);
	Mewmew_Battledex.append(Mewmian_Battledex);
	Mewmian_Battledex.append(Leafy_Battledex);

}

void Battledex::getMoves()
{//gets the moves based on the moves name
	typedef MovesNode<Moves> Move_Node;
	
	Move_Node move12(Dance);
	Move_Node move11(Flower_power, &move12);
	Move_Node move10(Seed_gun, &move11);
	Move_Node move9(Plant_protection, &move10);
	Move_Node move8(Combustion, &move9);
	Move_Node move7(Ember_bite, &move8);
	Move_Node move6(Flaming_breath, &move7);
	Move_Node move5(Vortex, &move6);
	Move_Node move4(Water_wave, &move5);
	Move_Node move3(Water_whip, &move4);
	Move_Node move2(Cut, &move3);
	Move_Node move1(Tackle, &move2);
	
	for (MovesIterator<Moves> iter(&move1); iter != iter.end(); ++iter)
	{
		cout << "Move Name: " << iter.getMoves().getName() << "\tDamage: " << iter.getMoves().getdmg() << "\tType: " << iter.getMoves().getType() << endl;
	}
}

BattledexList<WaterPet>::Pets Battledex::getWaterPet(string pokemon)
{
	typedef BattledexList<WaterPet>::Pets Battledex_water;
	//for loop is used to iterate through the doubly link list by using getNext which iterators into the next node
	for (const Battledex_water* pn = &Water_Battledex.getNext(); pn != &Battledex_water::NIL; pn = &pn->getNext())
	{
		if (pn->getPet().getName() == pokemon)
		{
			return pn->getPet();
		}

	}
}


BattledexList<FirePet>::Pets Battledex::getFirePet(string pokemon)
{
	typedef BattledexList<FirePet>::Pets Battledex_fire;
	for (const Battledex_fire* pn = &Fire_Battledex.getNext(); pn != &Battledex_fire::NIL; pn = &pn->getNext())
	{
		if (pn->getPet().getName() == pokemon)
		{
			return pn->getPet();
		}

	}
}

BattledexList<GrassPet>::Pets Battledex::getGrassPet(string pokemon)
{
	typedef BattledexList<GrassPet>::Pets Battledex_grass;
	for (const Battledex_grass* pn = &Grass_Battledex.getNext(); pn != &Battledex_grass::NIL; pn = &pn->getNext())
	{
		if (pn->getPet().getName() == pokemon)
		{
			return pn->getPet();
		}
	}
}

BattledexList<WaterPet>::Pets Battledex::PreviousWaterPet(string pokemon)
{
	typedef BattledexList<WaterPet>::Pets Battledex_water;
	for (const Battledex_water* pn = &Water_Battledex.getNext(); pn != &Battledex_water::NIL; pn = &pn->getNext())
	{
		if (pn->getPet().getName() == pokemon)
		{
			return pn->getPrevious().getPet();
		}
	}
}

BattledexList<WaterPet>::Pets Battledex::NextWaterPet(string pokemon)
{
	typedef BattledexList<WaterPet>::Pets Battledex_water;
	for (const Battledex_water* pn = &Water_Battledex.getNext(); pn != &Battledex_water::NIL; pn = &pn->getNext())
	{
		if (pn->getPet().getName() == pokemon)
		{
			return pn->getNext().getPet();
		}
	}
}

BattledexList<FirePet>::Pets Battledex::PreviousFirePet(string pokemon)
{
	typedef BattledexList<FirePet>::Pets Battledex_fire;
	for (const Battledex_fire* pn = &Fire_Battledex.getNext(); pn != &Battledex_fire::NIL; pn = &pn->getNext())
	{
		if (pn->getPet().getName() == pokemon)
		{
			return pn->getPrevious().getPet();
		}
	}
}

BattledexList<FirePet>::Pets Battledex::NextFirePet(string pokemon)
{
	typedef BattledexList<FirePet>::Pets Battledex_fire;
	for (const Battledex_fire* pn = &Fire_Battledex.getNext(); pn != &Battledex_fire::NIL; pn = &pn->getNext())
	{
		if (pn->getPet().getName() == pokemon)
		{
			return pn->getNext().getPet();
		}
	}
}
BattledexList<GrassPet>::Pets Battledex::PreviousGrassPet(string pokemon)
{
	typedef BattledexList<GrassPet>::Pets Battledex_grass;
	for (const Battledex_grass* pn = &Grass_Battledex.getNext(); pn != &Battledex_grass::NIL; pn = &pn->getNext())
	{
		if (pn->getPet().getName() == pokemon)
		{
			return pn->getPrevious().getPet();
		}
	}
}

BattledexList<GrassPet>::Pets Battledex::NextGrassPet(string pokemon)
{
	typedef BattledexList<GrassPet>::Pets Battledex_grass;
	for (const Battledex_grass* pn = &Grass_Battledex.getNext(); pn != &Battledex_grass::NIL; pn = &pn->getNext())
	{
		if (pn->getPet().getName() == pokemon)
		{
			return pn->getNext().getPet();
		}
	}
}

void Battledex::printWaterPet()
{
	typedef BattledexList<WaterPet>::Pets Battledex_water;
	for (const Battledex_water* pn = &Water_Battledex.getNext(); pn != &Battledex_water::NIL; pn = &pn->getNext())
	{
		cout << "ID: " << pn->getPet().getID() << "\tName: " << pn->getPet().getName() << endl;
	}
}

void Battledex::printFirePet()
{
	typedef BattledexList<FirePet>::Pets Battledex_fire;

	for (const Battledex_fire* pn = &Fire_Battledex.getNext(); pn != &Battledex_fire::NIL; pn = &pn->getNext())
	{
		cout << "ID: " << pn->getPet().getID() << "\tName: " << pn->getPet().getName() << endl;
	}
}

void Battledex::printGrassPet()
{
	typedef BattledexList<GrassPet>::Pets Battledex_grass;

	for (const Battledex_grass* pn = &Grass_Battledex.getNext(); pn != &Battledex_grass::NIL; pn = &pn->getNext())
	{
		cout << "ID: " << pn->getPet().getID() << "\tName: " << pn->getPet().getName() << endl;
	}
}
