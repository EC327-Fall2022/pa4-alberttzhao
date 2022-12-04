#include <iostream>
#include <string>
#include <math.h>

#include "Building.h"

using namespace std;

//destructor:
Building::~Building()
{
    cout << "Building destructed" << endl;
}

//default constructor for class Building
Building::Building() : GameObject('B')
{
    trainer_count = 0;
    cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc) : GameObject(in_loc, in_Id, in_code)
{
    trainer_count = 0;
    cout << "Building constructed" << endl;
}

void Building::AddOneTrainer()
{
    trainer_count++;
    return;
}

void Building::RemoveOneTrainer()
{
    trainer_count--;
    return;
}

void Building::ShowStatus()
{
    GameObject::ShowStatus();
    if(trainer_count == 0 || trainer_count == 1)
    {
        cout << trainer_count << " trainer is in this building" << endl;
    }
    else
    {
        cout << trainer_count << " trainers are in this building" << endl;
    }

    return;
}

bool Building::ShouldBeVisible()
{
    return true;
}
