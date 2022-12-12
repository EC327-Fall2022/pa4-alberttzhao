
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

int WildPokemon::get_attack()
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
    /*
    IN_ENVIRONMENT = 0,
    DEAD = 1,
    IN_TRAINER = 2
    */
   
    switch(state)
    {
        case 0:
            //cout << "in the environment" << endl;
            return true;
            break;
        case 1:
            cout << "dead" << endl;
            return true;
            break;
        case 2:
            //cout << "in trainer" << endl;
            return true;
            break;
        default:
            state = IN_ENVIRONMENT;
            return false;
            break;
    }
}

void WildPokemon::ShowStatus()
{    
    cout << "Wild Pokemon " << name << " Status: " << endl;
    GameObject::ShowStatus(); 
    switch(state)
    {
        case 0: //IN_ENVIRONMENT
            cout << "in the environment" << endl;
            break;
        case 1: //DEAD
            cout << "dead" << endl;
            break;
        case 2: //IN_TRAINER
            cout << "is following trainer" << endl;
            break;
        default:
            cout << "in the environment" << endl;
            break;
    }


    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
    cout << "Variant: " << variant << endl;

    cout << "---" << endl;
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
    // if(isAlive() == true)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    if(health > 0)
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
    state = IN_TRAINER;
    health = health - 1;
    location = trainer_location_update;

    current_trainer->ReduceHealth(attack);
}

