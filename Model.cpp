
#include "Model.h"



Model::Model()
{
    time = 0;

    //objects:

    //C1 is a PokemonCenter:
    Point2D C1_initial_location;
    C1_initial_location.x = 1;
    C1_initial_location.y = 20;
    PokemonCenter* center1_ptr = new PokemonCenter(1, 1, 100, C1_initial_location);
    object_ptrs[2] = center1_ptr;
    center_ptrs[0] = center1_ptr;

    //C2 is a PokemonCenter:
    Point2D C2_initial_location;
    C2_initial_location.x = 10;
    C2_initial_location.y = 20;
    PokemonCenter* center2_ptr = new PokemonCenter(2, 2, 200, C2_initial_location);
    object_ptrs[3] = center2_ptr;
    center_ptrs[1] = center2_ptr;

    //T1 is a Trainer:
    Point2D T1_initial_location;
    T1_initial_location.x = 5;
    T1_initial_location.y = 1;
    Trainer* trainer1_ptr = new Trainer("Ash", 1, 'T', 1, T1_initial_location);
    object_ptrs[0] = trainer1_ptr;
    trainer_ptrs[0] = trainer1_ptr; 
    
    //T2 is a trainer:
    Point2D T2_initial_location;
    T2_initial_location.x = 10;
    T2_initial_location.y = 1;
    Trainer* trainer2_ptr = new Trainer("Misty", 2, 'T', 2, T2_initial_location);
    object_ptrs[1] = trainer2_ptr;
    trainer_ptrs[1] = trainer2_ptr;

    //G1 is a PokemonGym:
    Point2D G1_initial_location;
    G1_initial_location.x = 0;
    G1_initial_location.y = 0;
    PokemonGym* gym1_ptr = new PokemonGym(2, 1, 2, 3, 1, G1_initial_location); //remember to change it back to 10
    object_ptrs[4] = gym1_ptr;
    gym_ptrs[0] = gym1_ptr;

    //G2 is a PokemonGym:
    Point2D G2_initial_location;
    G2_initial_location.x = 5;
    G2_initial_location.y = 5;
    PokemonGym* gym2_ptr = new PokemonGym(2, 5, 7.5, 4, 2, G2_initial_location); // remember to change it back to 20
    object_ptrs[5] = gym2_ptr;
    gym_ptrs[1] = gym2_ptr;

    //others:
    num_objects = 8; 
    num_trainers = 2;
    num_centers = 2;
    num_gyms = 2;
    num_WildPokemons = 2;

    //PA4: modify the Model class to create two Wild Pokemon objects and put their pointers in the object_ptrs array and the wildpokemon_ptrs array as follow:
    Point2D WildPokemon1_location;
    WildPokemon1_location.x = 10;
    WildPokemon1_location.y = 12;
    WildPokemon* WildPokemon1_ptr = new WildPokemon("Eevee", 5.0, 5.0, false, 1, WildPokemon1_location); //using default constructor? 
    object_ptrs[6] = WildPokemon1_ptr;
    WildPokemon_ptrs[0] = WildPokemon1_ptr;

    Point2D WildPokemon2_location;
    WildPokemon2_location.x = 15;
    WildPokemon2_location.y = 5;
    WildPokemon* WildPokemon2_ptr = new WildPokemon("Charizard", 5.0, 5.0, false, 2, WildPokemon2_location); //using default constructor? 
    object_ptrs[7] = WildPokemon2_ptr;
    WildPokemon_ptrs[1] = WildPokemon2_ptr;


    cout << "Model default constructed" << endl;

    ShowStatus();

}

Model::~Model()
{
    cout << "Model destructed" << endl;
}


Trainer* Model::GetTrainerPtr(int id)
{
    if(trainer_ptrs[id-1] != NULL)
    {
        //return if pointer is found:
        return trainer_ptrs[id-1];
    }
    else
    {
        //return 0 if pointer is not found:
        return 0;
    }
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    if(center_ptrs[id-1] != NULL)
    {
        return center_ptrs[id-1];
    }
    else
    {
        return 0;
    }
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
    if(gym_ptrs[id-1] != NULL)
    {
        return gym_ptrs[id-1];
    }
    else
    {
        return 0;
    }
}


//PA4:
WildPokemon* Model::GetWildPokemonPtr(int id)
{
    if(WildPokemon_ptrs[id-1] != NULL)
    {
        return WildPokemon_ptrs[id-1];
    }
    else
    {
        return 0;
    }
}


bool Model::Update()
{
    //increment time:
    time = time + 1;

    for(int i = 0; i < num_objects; i++)
    {
        if(object_ptrs[i]->Update() == true)
        {
            //write two more for loops and use exit(0):
        int num_gyms_without_battles = 0;
        for(int j = 0; j < num_gyms; j++)
        {
            if(gym_ptrs[j]->passed() == true)
            {
                num_gyms_without_battles = num_gyms_without_battles + 1;
            }
        }

        if(num_gyms_without_battles == num_gyms)
        {
            cout << "GAME OVER: You win! All battles done! " << endl;
            exit(0);
        }
        
        return true;
        }

    }


    int num_trainers_fainted = 0;
    for(int k = 0; k < num_trainers; k++)
    {
        if(trainer_ptrs[k]->HasFainted() == true)
        {   
            num_trainers_fainted = num_trainers_fainted + 1;
        }
    }

    if(num_trainers_fainted == num_trainers)
    {
        cout << "GAME OVER: You lose! All of your Trainers' Pokemon have fainted! " << endl;
        exit(0);
    }

    return false;
}



void Model::Display(View& view)
{

    view.Clear();

    for(int i = 0; i < num_objects; i++)
    {
        view.Plot(object_ptrs[i]);
    }

    view.Draw();
}


void Model::ShowStatus(){

    cout << "Time: " << time << endl; 

    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i]->ShowStatus();
    }
}



