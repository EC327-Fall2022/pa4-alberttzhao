
#pragma once

#include <iostream>
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>  
#include <string>
#include <random>
#include <vector>

#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Building.h"
#include "WildPokemon.h"
#include "Model.h"

using namespace std;

class WildPokemon; //forward declaration
class Model;

enum TrainerStates
{
    STOPPED = 0,
    MOVING = 1,
    FAINTED = 2,
    AT_CENTER = 3,
    IN_GYM = 4,
    MOVING_TO_CENTER = 5,
    MOVING_TO_GYM = 6,
    BATTLING_IN_GYM = 7,
    RECOVERING_HEALTH = 8,
    FOLLOWING_WILD_POKEMON = 9
};

class Trainer : public GameObject
{

public:

    Trainer();
    Trainer(char in_code);
    Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);

    void StartMoving(Point2D dest);
    void StartMovingToGym(PokemonGym* gym);
    void StartMovingToCenter(PokemonCenter* center);
    void StartBattling(unsigned int num_battles);
    void StartRecoveringHealth(unsigned int num_potions);
    void Stop();
    bool HasFainted();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    string GetName();

    //PA4: 
    bool FoundWildPokemon(Model& model);
    void StartFollowingWildPokemon(Model* model, int trainer_id, int wildpokemon_id);

    //destructor:
    ~Trainer();

protected:

    bool UpdateLocation();
    void SetupDestination(Point2D dest);

private:

    double speed;
    bool is_at_center;
    bool is_IN_GYM;
    unsigned int health;
    unsigned int experience;
    double PokeDollars;
    unsigned int battles_to_buy;
    unsigned int potions_to_buy;
    string name;
    PokemonCenter* current_center;
    PokemonGym* current_gym;
    Point2D destination;
    Vector2D delta;

    //PA4:
    //From Thomas's suggestion:
    vector<WildPokemon *> bundledWildPokemon;

};


//non-member function (static):
double GetRandomAmountOfPokeDollars();
