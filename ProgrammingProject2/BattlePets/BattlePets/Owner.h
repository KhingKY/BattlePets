#pragma once
#include <iostream>
#include <cstdlib>
#include "Pets.h"
#include "Moves.h"
#include "PetStack.h"
using namespace std;
//this class is used to create the trainer's Pets team which is stored in a queue
class Owner
{
private:
	string name;
	Pets* petTeam;
	//the fields below are used later on in the implementation to access the queue
	int capacity;
	int front;
	int rear;
	int count;

public:
	Owner();
	Owner(string n);
	void setName(string n);
	string getName();
	//queue implementations
	void enqueue(Pets Pets);
	void dequeue();
	Pets& peek();
	int getTeamSize();
	bool isEmpty();
	bool isFull();
	~Owner();
};

