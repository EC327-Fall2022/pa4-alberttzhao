
#include "Model.h"



Model::Model()
{
    time = 0;

    /*
    creating objects: 
    */

    //C1 is a PokemonCenter:
    Point2D C1_initial_location;
    C1_initial_location.x = 1;
    C1_initial_location.y = 20;
    PokemonCenter* center1_ptr = new PokemonCenter(1, 1, 100, C1_initial_location);
    object_ptrs.push_back(center1_ptr);
    active_ptrs.push_back(center1_ptr);
    center_ptrs.push_back(center1_ptr);

    //C2 is a PokemonCenter:
    Point2D C2_initial_location;
    C2_initial_location.x = 10;
    C2_initial_location.y = 20;
    PokemonCenter* center2_ptr = new PokemonCenter(2, 2, 200, C2_initial_location);
    object_ptrs.push_back(center2_ptr);
    active_ptrs.push_back(center2_ptr);
    center_ptrs.push_back(center2_ptr);

    //T1 is a Trainer:
    Point2D T1_initial_location;
    T1_initial_location.x = 5;
    T1_initial_location.y = 1;
    Trainer* trainer1_ptr = new Trainer("Ash", 1, 'T', 1, T1_initial_location);
    object_ptrs.push_back(trainer1_ptr);
    active_ptrs.push_back(trainer1_ptr);
    trainer_ptrs.push_back(trainer1_ptr);
    
    //T2 is a trainer:
    Point2D T2_initial_location;
    T2_initial_location.x = 10;
    T2_initial_location.y = 1;
    Trainer* trainer2_ptr = new Trainer("Misty", 2, 'T', 2, T2_initial_location);
    object_ptrs.push_back(trainer2_ptr);
    active_ptrs.push_back(trainer2_ptr);
    trainer_ptrs.push_back(trainer2_ptr);

    //G1 is a PokemonGym:
    Point2D G1_initial_location;
    G1_initial_location.x = 0;
    G1_initial_location.y = 0;
    PokemonGym* gym1_ptr = new PokemonGym(2, 1, 2, 3, 1, G1_initial_location); //remember to change it back to 10
    object_ptrs.push_back(gym1_ptr);
    active_ptrs.push_back(gym1_ptr);
    gym_ptrs.push_back(gym1_ptr);

    //G2 is a PokemonGym:
    Point2D G2_initial_location;
    G2_initial_location.x = 5;
    G2_initial_location.y = 5;
    PokemonGym* gym2_ptr = new PokemonGym(2, 5, 7.5, 4, 2, G2_initial_location); // remember to change it back to 20
    object_ptrs.push_back(gym2_ptr);
    active_ptrs.push_back(gym2_ptr);
    gym_ptrs.push_back(gym2_ptr);

    
    //Making WildPokemon1: 
    Point2D WildPokemon1_location;
    WildPokemon1_location.x = 10;
    WildPokemon1_location.y = 12;
    WildPokemon* WildPokemon1_ptr = new WildPokemon("Eevee", 2, 4, false, 1, WildPokemon1_location); //using default constructor? 
    object_ptrs.push_back(WildPokemon1_ptr);
    active_ptrs.push_back(WildPokemon1_ptr);
    WildPokemon_ptrs.push_back(WildPokemon1_ptr);

    //Making WildPokemon2: 
    Point2D WildPokemon2_location;
    WildPokemon2_location.x = 15;
    WildPokemon2_location.y = 5;
    WildPokemon* WildPokemon2_ptr = new WildPokemon("Charizard", 2, 5, false, 2, WildPokemon2_location); //using default constructor? 
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

    for (list <Trainer*> :: iterator iter1 = trainer_ptrs.begin(); iter1 != trainer_ptrs.end(); iter1++)
    {
    if ((*iter1)->GetId() == id)
        return *iter1;
    }

    return nullptr;

}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    for(list <PokemonCenter*> :: iterator iter1 =center_ptrs.begin(); iter1 != center_ptrs.end(); iter1++)
    {
        if((*iter1)->GetId() == id)
            return *iter1;
    }
    return nullptr;

}

PokemonGym* Model::GetPokemonGymPtr(int id)
{

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
        if((*iter)->ShouldBeVisible() == false)
        {
            cout << (*iter)->GetState() << (*iter)->GetId() << " GameObject Removed" << endl; 
            active_ptrs.erase(iter);
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

    view.Clear();

    for ( list<GameObject*> :: iterator iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++)
    {
        view.Plot(*iter1);
    }

    view.Draw();

}


void Model::ShowStatus()
{
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
                throw Invalid_Input("Sorry but please enter a Unique PokemonCenter ID");
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
            Trainer* T = new Trainer("NewTrainer",in_id,'T',1,Point2D(x,y));
            object_ptrs.push_back(T);
            active_ptrs.push_back(T);
            trainer_ptrs.push_back(T);
            cout << "New Trainer created" << endl;
            break;
        } 

        case 'w':
        {
            for(list <WildPokemon*> :: iterator iter1 = WildPokemon_ptrs.begin(); iter1 != WildPokemon_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique Trainer ID");
            }
            WildPokemon* W = new WildPokemon("NewWildPokemon", 5, 2, false, in_id, Point2D(x,y));
            object_ptrs.push_back(W);
            active_ptrs.push_back(W);
            WildPokemon_ptrs.push_back(W);
            cout << "New WildPokemon created" << endl;
            break;
        }
        default:
        cout << "Unrecognized command code for creating new object" << endl;
    }
}