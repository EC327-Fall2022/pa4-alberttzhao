
#include "WildPokemon.h"

WildPokemon::WildPokemon() : GameObject('W')
{
    attack = 5;
    health = 2;
    variant = false;
    in_combat = false;
    state = IN_ENVIRONMENT;
    //name;
    //Trainer* current_trainer

    cout << "WildPokemon default constructed" << endl;
}

WildPokemon::WildPokemon(string in_name, double in_attack, double in_health, bool in_variant, int id, Point2D in_loc) : GameObject(in_loc, id, 'W')
{
    name = in_name;
    attack = in_attack;
    health = in_health;
    variant = in_variant;
    state = IN_ENVIRONMENT;

    cout << "WildPokemon constructed" << endl;
}

//destructor:
WildPokemon::~WildPokemon()
{
    cout << "WildPokemon destructed " << endl;
}

//don't know if this is correct: 
void WildPokemon::follow(Trainer* t)
{
    current_trainer = t; //holds the current trainer it is following
    //we got to do something else in here but I will code it later
}

//dont know if this is needed
Trainer* WildPokemon::GetFollowingTrainer()
{
    return current_trainer;
}

//don't know if this is needed
Point2D WildPokemon::GetWildPokemonLocation()
{
    return location;
}


bool WildPokemon::get_variant()
{
    return variant;
}

double WildPokemon::get_attack()
{
    return attack;
}

double WildPokemon::get_health()
{
    return health;
}

bool WildPokemon::get_in_combat()
{
    return in_combat;
}

bool WildPokemon::Update()
{
    if(health == 0)
    {
        state = DEAD;
    }
    // else if
    // {
    //     //state 'IN_TRAINER': when the Wild Pokemon is following a trainer 
    // }
    return true;
}

void WildPokemon::ShowStatus()
{
    cout << "Wild Pokemon " << name << " Status: " << endl;
    GameObject::ShowStatus();
}

bool WildPokemon::isAlive()
{
    if(health != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool WildPokemon::ShouldBeVisible()
{
    if(isAlive() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string WildPokemon::GetName()
{
    return name;
}


void WildPokemon::UpdateLocation(Point2D trainer_location_update)
{   
    location = trainer_location_update;
}


