
#pragma once

#include <iostream>
#include <string>

#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "Trainer.h"
#include "Model.h"

using namespace std;

class Trainer; //forward declaration

class WildPokemon : public GameObject
{
protected:
    int attack;
    int health;
    bool variant;
    bool in_combat;
    //Point2D location;
    string name;
    Trainer* current_trainer;

public:
    //default constructor:
    WildPokemon();

    //destructor:
    ~WildPokemon();

    //para constructor:
    WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc);

    void follow(Trainer* t);
    bool get_variant();
    int get_attack();
    double get_health();
    bool get_in_combat();
    bool Update();
    void ShowStatus();
    bool isAlive();
    bool ShouldBeVisible();
    string GetName();


    //PA4: 
    //follow, don't know if any of these are needed 
    Trainer* GetFollowingTrainer();
    Point2D GetWildPokemonLocation();

    void UpdateLocation(Point2D trainer_location_update);

};

enum WildPokemonStates
{
    IN_ENVIRONMENT = 0,
    DEAD = 1,
    IN_TRAINER = 2
};