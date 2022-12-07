
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
    //object_ptrs[2] = center1_ptr;
    //center_ptrs[0] = center1_ptr;

    //PA4: 
    object_ptrs.push_back(center1_ptr);
    active_ptrs.push_back(center1_ptr);
    center_ptrs.push_back(center1_ptr);

    //C2 is a PokemonCenter:
    Point2D C2_initial_location;
    C2_initial_location.x = 10;
    C2_initial_location.y = 20;
    PokemonCenter* center2_ptr = new PokemonCenter(2, 2, 200, C2_initial_location);
    // object_ptrs[3] = center2_ptr;
    // center_ptrs[1] = center2_ptr;

    //PA4:
    object_ptrs.push_back(center2_ptr);
    active_ptrs.push_back(center2_ptr);
    center_ptrs.push_back(center2_ptr);

    //T1 is a Trainer:
    Point2D T1_initial_location;
    T1_initial_location.x = 5;
    T1_initial_location.y = 1;
    Trainer* trainer1_ptr = new Trainer("Ash", 1, 'T', 1, T1_initial_location);
    // object_ptrs[0] = trainer1_ptr;
    // trainer_ptrs[0] = trainer1_ptr; 

    //PA4:
    object_ptrs.push_back(trainer1_ptr);
    active_ptrs.push_back(trainer1_ptr);
    trainer_ptrs.push_back(trainer1_ptr);
    
    //T2 is a trainer:
    Point2D T2_initial_location;
    T2_initial_location.x = 10;
    T2_initial_location.y = 1;
    Trainer* trainer2_ptr = new Trainer("Misty", 2, 'T', 2, T2_initial_location);
    // object_ptrs[1] = trainer2_ptr;
    // trainer_ptrs[1] = trainer2_ptr;

    //PA4:
    object_ptrs.push_back(trainer2_ptr);
    active_ptrs.push_back(trainer2_ptr);
    trainer_ptrs.push_back(trainer2_ptr);

    //G1 is a PokemonGym:
    Point2D G1_initial_location;
    G1_initial_location.x = 0;
    G1_initial_location.y = 0;
    PokemonGym* gym1_ptr = new PokemonGym(2, 1, 2, 3, 1, G1_initial_location); //remember to change it back to 10
    // object_ptrs[4] = gym1_ptr;
    // gym_ptrs[0] = gym1_ptr;

    //PA4: 
    object_ptrs.push_back(gym1_ptr);
    active_ptrs.push_back(gym1_ptr);
    gym_ptrs.push_back(gym1_ptr);

    //G2 is a PokemonGym:
    Point2D G2_initial_location;
    G2_initial_location.x = 5;
    G2_initial_location.y = 5;
    PokemonGym* gym2_ptr = new PokemonGym(2, 5, 7.5, 4, 2, G2_initial_location); // remember to change it back to 20
    // object_ptrs[5] = gym2_ptr;
    // gym_ptrs[1] = gym2_ptr;

    //PA4: 
    object_ptrs.push_back(gym2_ptr);
    active_ptrs.push_back(gym2_ptr);
    gym_ptrs.push_back(gym2_ptr);

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
    // object_ptrs[6] = WildPokemon1_ptr;
    // WildPokemon_ptrs[0] = WildPokemon1_ptr;

    object_ptrs.push_back(WildPokemon1_ptr);
    active_ptrs.push_back(WildPokemon1_ptr);
    WildPokemon_ptrs.push_back(WildPokemon1_ptr);

    Point2D WildPokemon2_location;
    WildPokemon2_location.x = 15;
    WildPokemon2_location.y = 5;
    WildPokemon* WildPokemon2_ptr = new WildPokemon("Charizard", 5.0, 5.0, false, 2, WildPokemon2_location); //using default constructor? 
    // object_ptrs[7] = WildPokemon2_ptr;
    // WildPokemon_ptrs[1] = WildPokemon2_ptr;

    object_ptrs.push_back(WildPokemon2_ptr);
    active_ptrs.push_back(WildPokemon2_ptr);
    WildPokemon_ptrs.push_back(WildPokemon2_ptr);
    


    cout << "Model default constructed" << endl;

    ShowStatus();

}

Model::~Model()
{
    cout << "Model destructed" << endl;
}


Trainer* Model::GetTrainerPtr(int id)
{
    // From PA3: 
    // if(trainer_ptrs[id-1] != NULL)
    // {
    //     //return if pointer is found:
    //     return trainer_ptrs[id-1];
    // }
    // else
    // {
    //     //return 0 if pointer is not found:
    //     return 0;
    // }

    //PA4: modified from above:
    auto trainer_ptrs_front = trainer_ptrs.begin();
    if(next(*trainer_ptrs_front, id) != NULL)
    {
        return next(*trainer_ptrs_front, id);
    }
    else
    {
        return 0;
    }

}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    // From PA3: 
    // if(center_ptrs[id-1] != NULL)
    // {
    //     return center_ptrs[id-1];
    // }
    // else
    // {
    //     return 0;
    // }

    //PA4: modified from above:
    auto center_ptrs_front = center_ptrs.begin();
    if(next(*center_ptrs_front, id) != NULL)
    {
        return next(*center_ptrs_front, id);
    }
    else
    {
        return 0;
    }
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
    // From PA3: 
    // if(gym_ptrs[id-1] != NULL)
    // {
    //     return gym_ptrs[id-1];
    // }
    // else
    // {
    //     return 0;
    // }

    //PA4: modified from above:
    auto gym_ptrs_front = gym_ptrs.begin();
    if(next(*gym_ptrs_front , id) != NULL)
    {
        return next(*gym_ptrs_front , id);
    }
    else
    {
        return 0;
    }
}


//PA4:
WildPokemon* Model::GetWildPokemonPtr(int id)
{
    // From PA3: 
    // if(WildPokemon_ptrs[id-1] != NULL)
    // {
    //     return WildPokemon_ptrs[id-1];
    // }
    // else
    // {
    //     return 0;
    // }

    //PA4: modified from above:
    auto WildPokemon_ptrs_front = WildPokemon_ptrs.begin();
    if(next(*WildPokemon_ptrs_front , id) != NULL)
    {
        return next(*WildPokemon_ptrs_front , id);
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

    //From Thomas:
    bool valid_thomas = false;

    // PA3: 
    // for(int i = 0; i < num_objects; i++)
    // {


    //     if(object_ptrs[i]->Update() == true)
    //     {
    //         //write two more for loops and use exit(0):
    //         int num_gyms_without_battles = 0;
    //         for(int j = 0; j < num_gyms; j++)
    //         {
    //             if(gym_ptrs[j]->passed() == true)
    //             {
    //                 num_gyms_without_battles = num_gyms_without_battles + 1;
    //             }
    //         }

    //         if(num_gyms_without_battles == num_gyms)
    //         {
    //             cout << "GAME OVER: You win! All battles done! " << endl;
    //             exit(0);
    //         }

    //         valid_thomas = true; //thomas fixed
    //     }

    // }

    //PA4 modified:
    int object_size = object_ptrs.size();
    for(int i = 1; i <= object_size; i++)
    {
        auto object_ptrs_front1 = object_ptrs.begin();
        if(next(*object_ptrs_front1 , i)->Update() == true)
        {
            int num_gyms_without_battles = 0;

            int gym_size = gym_ptrs.size();
            for(int j=1; j<= gym_size; j++)
            {
                auto gym_ptrs_front1 = gym_ptrs.begin();
                if(next(*gym_ptrs_front1 , j)->passed() == true)
                {
                    num_gyms_without_battles++;
                }
            }

            if(num_gyms_without_battles == gym_size)
            {
                cout << "GAME OVER: You win! All battles done! " << endl;
                exit(0);
            }

            valid_thomas = true;
        }
    }
    CheckTrainerWildPokemon();

    // PA3: 
    // int num_trainers_fainted = 0;
    // for(int k = 0; k < num_trainers; k++)
    // {
    //     if(trainer_ptrs[k]->HasFainted() == true)
    //     {   
    //         num_trainers_fainted = num_trainers_fainted + 1;
    //     }
    // }

    // if(num_trainers_fainted == num_trainers)
    // {
    //     cout << "GAME OVER: You lose! All of your Trainers' Pokemon have fainted! " << endl;
    //     exit(0);
    // }

    
    //PA4 modified:
    int num_trainers_fainted = 0;
    
    int trainer_size = trainer_ptrs.size();
    for(int k = 0; k <= trainer_size; k++)
    {
        auto trainer_ptrs_front1 = trainer_ptrs.begin();
        if(next(*trainer_ptrs_front1 , k)->HasFainted() == true)
        {
            num_trainers_fainted++;
        }
    }

    if(num_trainers_fainted == num_trainers)
    {
        cout << "GAME OVER: You lose! All of your Trainers' Pokemon have fainted! " << endl;
        exit(0);
    }

    
    return valid_thomas;
}



void Model::Display(View& view)
{

    //PA3: 
    // view.Clear();

    
    // for(int i = 0; i < num_objects; i++)
    // {
    //     view.Plot(object_ptrs[i]);
    // }

    // view.Draw();


    //PA4 modified: 
    view.Clear();

    for(int i = 1; i <= object_ptrs.size(); i++)
    {
        auto object_ptrs_front2 = object_ptrs.begin();
        view.Plot(next(*object_ptrs_front2 , i));
    }

    view.Draw();
}


void Model::ShowStatus(){

    // PA3: 

    // cout << "Time: " << time << endl; 

    // for (int i = 0; i < num_objects; i++)
    // {
    //     object_ptrs[i]->ShowStatus();
    // }

    //PA4 modified: 
    cout << "Time: " << time << endl;

    for(int i = 1; i <= object_ptrs.size(); i++)
    {
        auto object_ptrs_front3 = object_ptrs.begin();
        next(*object_ptrs_front3 , i)->ShowStatus();
    }
}


//PA4:
void Model::CheckTrainerWildPokemon()
{
    Point2D trainer1_location = GetTrainerPtr(1)->GetLocation();
    Point2D trainer2_location = GetTrainerPtr(2)->GetLocation();
    Point2D wildpokemon1_location = GetWildPokemonPtr(1)->GetLocation();
    Point2D wildpokemon2_location = GetWildPokemonPtr(2)->GetLocation();

    if(GetDistanceBetween(trainer1_location , wildpokemon1_location) == 0)
    {
        GetTrainerPtr(1)->StartFollowingWildPokemon(this, 1, 1);
        return;
    }
    else if(GetDistanceBetween(trainer1_location , wildpokemon2_location) == 0)
    {
        GetTrainerPtr(1)->StartFollowingWildPokemon(this, 1, 2);
        return;
    }
    else if(GetDistanceBetween(trainer2_location , wildpokemon1_location) == 0)
    {
        GetTrainerPtr(2)->StartFollowingWildPokemon(this, 2, 1);
        return;
    }
    else if(GetDistanceBetween(trainer2_location , wildpokemon2_location) == 0)
    {
        GetTrainerPtr(2)->StartFollowingWildPokemon(this, 2, 2);
        return;
    }
    else
    {
        //do nothing
        return;
    }

}