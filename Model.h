#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <iterator>


#include "GameObject.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Point2D.h"
#include "View.h"
#include "WildPokemon.h"

using namespace std;

class Trainer; //forward declaration
class WildPokemon; //forward declaration

class Model
{

private:

    int time;

    /*
    PA4 part 2:
    First, replace your array of Game_object pointers named “object_ptrs” 
    with a linked list named object_ptrs and another called active_ptrs. 
    */
    list<GameObject*> object_ptrs;

    /*
    The object_ptrs list will point to all of the Game_Objects that exist, 
    while the active_ptrs list will point to all of the Game_Objects that are still 
    alive and must be updated and displayed. 
    */

    // GameObject* object_ptrs[10];
    list<GameObject*> active_ptrs;
    int num_objects;


    // Trainer* trainer_ptrs[10];
    list<Trainer*> trainer_ptrs;
    int num_trainers;

    // PokemonCenter* center_ptrs[10];
    list<PokemonCenter*> center_ptrs;
    int num_centers;

    // PokemonGym* gym_ptrs[10];
    list<PokemonGym*> gym_ptrs;
    int num_gyms;
    
    // WildPokemon* WildPokemon_ptrs[10];
    list<WildPokemon*> WildPokemon_ptrs;
    int num_WildPokemons;

public:

    //default constructor:
    Model();
    
    //destructor:
    ~Model();

    //functions:
    Trainer* GetTrainerPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);

    //PA4: 
    WildPokemon* GetWildPokemonPtr(int id);

    bool Update();
    void Display(View& view);
    void ShowStatus();

    //PA4:
    void CheckTrainerWildPokemon();
    
};