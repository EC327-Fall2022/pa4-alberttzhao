

#include <iostream>

#include "PokemonCenter.h"

using namespace std;

//destructor:
PokemonCenter::~PokemonCenter()
{
    cout << "PokemonCenter destructed" << endl;
}

PokemonCenter::PokemonCenter() : Building()
{
    display_code = 'C';
    potion_capacity = 100;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = 5;
    state = POTIONS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}

//no idea about default if not declared here
//^ fixed 
PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc) : Building('C',in_id, in_loc)
{
    id_num = in_id;
    location = in_loc;
    pokedollar_cost_per_potion = potion_cost;
    potion_capacity = potion_cap;
    display_code = 'C';
    num_potions_remaining = potion_capacity;
    state = POTIONS_AVAILABLE;
    cout << "PokemonCenter constructed" << endl;
}

//no idea
//returns true if this PokemonCenter contains at least one potion
//returns false otherwise
bool PokemonCenter::HasPotions()
{
    if(state == POTIONS_AVAILABLE)
        return true;
    else
        return false;
}

//this should be right
unsigned int PokemonCenter::GetNumPotionRemaining()
{
    return num_potions_remaining;
}

//finished but no idea if this is right
bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget)
{
    double total_cost = potion * pokedollar_cost_per_potion;
    if(budget > total_cost)
        return true;
    else
        return false;
}

//no idea
//returns the pokedollar cost for the specified number of potions
double PokemonCenter::GetPokeDollarCost(unsigned int potion)
{
    double total_cost = potion * pokedollar_cost_per_potion;
    return total_cost;
}


//finished it but need to check later
//fixed it but the instruction might be wrong
//check later
unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed)
{
    if(num_potions_remaining >= potion_needed)
    {
        num_potions_remaining = num_potions_remaining - potion_needed;
        return potion_needed;
    }
    else
    {
        unsigned int num_potions_remaining_copy = num_potions_remaining;
        num_potions_remaining = 0;
        return num_potions_remaining_copy;
    }
}

//finished but need to check if it is correct
bool PokemonCenter::Update()
{
    if(num_potions_remaining == 0)
    {
        state = NO_POTIONS_AVAILABLE;
        display_code = 'c';
        cout << "PokemonCenter " << id_num << " has ran out of potions." << endl;
        return true;
    }
    else
    {
        return false;
    }

}

//dont know how this works
//finished but need to check if it is correct
void PokemonCenter::ShowStatus()
{
    cout << "PokemonCenter Status: " << endl;
    Building::ShowStatus();
    cout << "PokeDollars per potion: " << pokedollar_cost_per_potion << endl;
    if(num_potions_remaining <= 1)
        cout << "has " << num_potions_remaining << " potion remaining." << endl;
    else
        cout << "have " << num_potions_remaining << " potions remaining." << endl;

    return;
}

