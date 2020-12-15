#include "Owner.h"
Owner::Owner() 
{
    petTeam = new Pets[3];
    capacity = 3;
    front = 0;
    rear = -1;
    count = 0;
}
Owner::Owner(string n)
{
    name = n;
    petTeam = new Pets[3];
    capacity = 3;
    front = 0;
    rear = -1;
    count = 0;
}

void Owner::setName(string n)
{
    name = n;
}

string Owner::getName()
{
    return name;
}

//adding elements into the queue
void Owner::enqueue(Pets pets)
{
    if (isFull())
    {
        cout << "Your pets are at full capacity!" << endl;
    }
    //calculates the last index inside of the queue and then places the element into that index
    rear = (rear + 1) % capacity;
    petTeam[rear] = pets;
    count++;//increase count which will be used to getTeamSize
    
}

//gets rid elements inside of the queue one by one
void Owner::dequeue()
{
    if (isEmpty())
    {
        cout << "No pets in the queue!" << endl;
    }
    
    front = (front + 1) % capacity;
    count--;

    
}

//this looks at the first element of the queue 
Pets& Owner::peek()
{
    if (isEmpty())
    {
        cout << "No pets in the queue!" << endl;
    }
    return petTeam[front];
}

//returns count which is every time a enqueue or dequeu happens
int Owner::getTeamSize()
{
    return count;
}

//if the team size equals to 0, return true
bool Owner::isEmpty()
{
    return (getTeamSize() == 0);
}

//if the team size is equal to capacity, return true
bool Owner::isFull()
{
    return (getTeamSize() == capacity);
}

Owner::~Owner() {}
