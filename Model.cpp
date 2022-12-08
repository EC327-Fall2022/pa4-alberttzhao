
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
    


    cout << "Model default constructed" << endl << endl;

    ShowStatus();

}

Model::~Model()
{
    // for(list <GameObject*> :: iterator iter1 = object_ptrs.begin(); iter1 != object_ptrs.end(); iter1++)
    // {
    //     delete *iter1;
    // }
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
    // auto trainer_ptrs_front = trainer_ptrs.begin();
    // if(next(*trainer_ptrs_front, id) != NULL)
    // {
    //     return next(*trainer_ptrs_front, id);
    // }
    // else
    // {
    //     return 0;
    // }

    for (list <Trainer*> :: iterator iter1 = trainer_ptrs.begin(); iter1 != trainer_ptrs.end(); iter1++)
    {
    if ((*iter1)->GetId() == id)
        return *iter1;
    }

    return nullptr;

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
    // auto center_ptrs_front = center_ptrs.begin();
    // if(next(*center_ptrs_front, id) != NULL)
    // {
    //     return next(*center_ptrs_front, id);
    // }
    // else
    // {
    //     return 0;
    // }

    for(list <PokemonCenter*> :: iterator iter1 =center_ptrs.begin(); iter1 != center_ptrs.end(); iter1++)
    {
        if((*iter1)->GetId() == id)
            return *iter1;
    }
    return nullptr;

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
    // auto gym_ptrs_front = gym_ptrs.begin();
    // if(next(*gym_ptrs_front , id) != NULL)
    // {
    //     return next(*gym_ptrs_front , id);
    // }
    // else
    // {
    //     return 0;
    // }

    for(list <PokemonGym*> :: iterator iter1 = gym_ptrs.begin(); iter1 != gym_ptrs.end(); iter1++)
    {
    if((*iter1)->GetId() == id)
            return *iter1; 
    }
    return nullptr;
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
    // auto WildPokemon_ptrs_front = WildPokemon_ptrs.begin();
    // if(next(*WildPokemon_ptrs_front , id) != NULL)
    // {
    //     return next(*WildPokemon_ptrs_front , id);
    // }
    // else
    // {
    //     return 0;
    // }

    for(list <WildPokemon*> :: iterator iter1 = WildPokemon_ptrs.begin(); iter1 != WildPokemon_ptrs.end(); iter1++)
    {
    if((*iter1)->GetId() == id)
        return *iter1; 
    }
    return nullptr;
}



bool Model::Update()
{
    //increment time:
    time = time + 1;

    //From Thomas:
    // bool valid_thomas = false;

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
    // int object_size = object_ptrs.size();
    // for(int i = 1; i <= object_size; i++)
    // {
    //     auto object_ptrs_front1 = object_ptrs.begin();
    //     if(next(*object_ptrs_front1 , i)->Update() == true)
    //     {
    //         int num_gyms_without_battles = 0;

    //         int gym_size = gym_ptrs.size();
    //         for(int j=1; j<= gym_size; j++)
    //         {
    //             auto gym_ptrs_front1 = gym_ptrs.begin();
    //             if(next(*gym_ptrs_front1 , j)->passed() == true)
    //             {
    //                 num_gyms_without_battles++;
    //             }
    //         }

    //         if(num_gyms_without_battles == gym_size)
    //         {
    //             cout << "GAME OVER: You win! All battles done! " << endl;
    //             exit(0);
    //         }

    //         valid_thomas = true;
    //     }
    // }

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
    // int num_trainers_fainted = 0;
    
    // int trainer_size = trainer_ptrs.size();
    // for(int k = 0; k <= trainer_size; k++)
    // {
    //     auto trainer_ptrs_front1 = trainer_ptrs.begin();
    //     if(next(*trainer_ptrs_front1 , k)->HasFainted() == true)
    //     {
    //         num_trainers_fainted++;
    //     }
    // }

    // if(num_trainers_fainted == num_trainers)
    // {
    //     cout << "GAME OVER: You lose! All of your Trainers' Pokemon have fainted! " << endl;
    //     exit(0);
    // }

    
    // return valid_thomas;

    time++;
    int output = 0;
    int temp1 = 0;
    int temp2 = 0;
    list <GameObject*> :: iterator iter1;
    for(iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++)
    {
        if((*iter1)->Update() == true)
        {
            output++;
        }
    }

    for(list <GameObject*> :: iterator iter = active_ptrs.begin(); iter != active_ptrs.end(); iter++)
    {
        if(!(*iter)->ShouldBeVisible())
        {
            active_ptrs.erase(iter);
            cout << "GameObject Removed" << endl; //testing
            break;
        }
    }
    
    list <PokemonGym*> :: iterator iter2;
    for(iter2 = gym_ptrs.begin(); iter2 != gym_ptrs.end(); iter2++)
    {
        if((*iter2)->GetNumBattlesRemaining() == 0)
        {
            temp1++;
        }
    }

    list<Trainer*> :: iterator iter3;
    for(iter3 = trainer_ptrs.begin(); iter3 != trainer_ptrs.end(); iter3++)
    {
        if((*iter3)->HasFainted())
        {
            temp2++;
        }
    }

    CheckTrainerWildPokemon();

    if (temp1 == gym_ptrs.size())
    {
        cout << "GAME OVER: You win! All battles done!" << endl;
        exit(0);
    }

    if(temp2 == trainer_ptrs.size())
    {
        cout << "GAME OVER: You lose! All of your Trainers have lost!" << endl;
        exit(0);
    }

    if(output > 0)
    {
        return true;
    }

    return false;

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
    // view.Clear();

    // for(int i = 1; i <= object_ptrs.size(); i++)
    // {
    //     auto object_ptrs_front2 = object_ptrs.begin();
    //     view.Plot(next(*object_ptrs_front2 , i));
    // }

    // view.Draw();

    view.Clear();

    for ( list<GameObject*> :: iterator iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++)
    {
        view.Plot(*iter1);
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
    // cout << "Time: " << time << endl;

    // for(int i = 1; i <= object_ptrs.size(); i++)
    // {
    //     auto object_ptrs_front3 = object_ptrs.begin();
    //     next(*object_ptrs_front3 , i)->ShowStatus();
    // }

    cout << "Time: " << time << endl;

    //visial:
    cout << "---" << endl;
    
    for(list<GameObject*> :: iterator iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++ )
    {
        (*iter1)->ShowStatus();
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



//PA4:
void Model::NewCommand(char type, int in_id, double x, double y)
{
    switch(type)
    {
        case 'c': 
        {
            for(list <PokemonCenter*> :: iterator iter1 = center_ptrs.begin(); iter1 != center_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique Doctor's Office ID");
            }
            PokemonCenter* C = new PokemonCenter(in_id, 100, 2, Point2D(x,y));
            object_ptrs.push_back(C);
            active_ptrs.push_back(C);
            center_ptrs.push_back(C);
            cout << "New PokemonCenter created" << endl;
            break;
        }

        case 'g':
        {    
            for(list <PokemonGym*> :: iterator iter1 = gym_ptrs.begin(); iter1 != gym_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique PokemonGym ID");
            }
            PokemonGym* G = new PokemonGym(25,2,10,5,in_id,Point2D(x,y));
            object_ptrs.push_back(G);
            active_ptrs.push_back(G);
            gym_ptrs.push_back(G);
            cout << "New PokemonGym created" << endl;
            break;
        }

        case 't':
        {
            for(list <Trainer*> :: iterator iter1 = trainer_ptrs.begin(); iter1 != trainer_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique Trainer ID");
            }
            Trainer* T = new Trainer("NewTrainer",in_id,'S',1,Point2D(x,y));
            object_ptrs.push_back(T);
            active_ptrs.push_back(T);
            trainer_ptrs.push_back(T);
            cout << "New Trainer created" << endl;
            break;
        } 
        default:
        cout << "Unrecognized command code for creating new object" << endl;
    }
}