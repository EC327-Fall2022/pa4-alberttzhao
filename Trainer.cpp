
#include "Trainer.h"

//destructor:
Trainer::~Trainer()
{
    cout << "Trainer destructed" << endl;
}


//default constructor:

Trainer::Trainer() : GameObject('B') //verify this later 
{
    speed = 5;
    cout << "Trainer default constructed. " << endl;

    //initialize other variables:
    is_at_center = false;
    is_IN_GYM = false;
    health = 25;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    //name
    current_center = NULL;
    current_gym = NULL;
    following_wild_pokemon = false;
    //destination;
    //delta;
    //state = STOPPED; //newly added...don't know if this works or if it is necessary
}

Trainer::Trainer(char in_code) : GameObject(in_code)
{
    speed = 5;
    cout << "Trainer constructed." << endl;

    //initialize other variables:
    is_at_center = false;
    is_IN_GYM = false;
    health = 25;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    //name
    current_center = NULL;
    current_gym = NULL;
    following_wild_pokemon = false; 
    //destination;
    //delta;
    //state = STOPPED; 
}

Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
    speed = in_speed;
    name = in_name;
    cout << "Trainer constructed." << endl;

    //initialize other variables:
    is_at_center = false;
    is_IN_GYM = false;
    health = 25;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    //name
    current_center = NULL;
    current_gym = NULL;
    following_wild_pokemon = false; 
    //destination;
    //delta;
    //state = STOPPED;
}


void Trainer::SetupDestination(Point2D dest)
//delta = (destination – location) * (speed / GetDistanceBetween(destination, location))
{
    destination = dest;
    delta = (dest - location) * (speed / GetDistanceBetween(dest , location));

    if(state == AT_CENTER)
    {
        current_center->RemoveOneTrainer();
    }

    if(state == IN_GYM)
    {
        current_gym->RemoveOneTrainer();
    }
}

void Trainer::StartMoving(Point2D dest)
{
    SetupDestination(dest);
    if(GetDistanceBetween(location, destination) == 0.0) 
    {
        cout << display_code << id_num << ": I'm already there. See?" << endl;
    }
    else if(state == FAINTED)
    {
       cout << display_code << id_num << ": My pokemon have fainted. I may move but you cannot see me." << endl;
    }
    else
    {
        state = MOVING;
        cout << display_code << id_num << ": On my way." << endl;
    }
}

void Trainer::StartMovingToGym(PokemonGym* gym)
{
    SetupDestination(gym->GetLocation());
    current_gym = gym;
    if(state == FAINTED)
    {
        cout << display_code << id_num << ": My Pokemon have fainted so I can't move to gym... " << endl;
    }
    else if(GetDistanceBetween(location, destination) == 0.0)
    {
        state = IN_GYM;
        current_gym = gym;
        cout << display_code << id_num << ": I am already at the PokemonGym! " << endl;
    }
    else
    {
        state = MOVING_TO_GYM;
        current_gym = gym; //testing
        cout << display_code << id_num << ": on my way to gym " <<  gym->GetId() << endl;
    }
}

void Trainer::StartMovingToCenter(PokemonCenter* center)
{
    SetupDestination(center->GetLocation());
    current_center = center;
    if(state == FAINTED)
    {
        cout << display_code << id_num << ": My pokemon have fainted so I should have gone to the center.." << endl;
    }
    else if(GetDistanceBetween(location, destination) == 0.0)
    {
        state = AT_CENTER;
        current_center = center;
        cout << display_code << id_num << ": I am already at the Center! " << endl;

    }
    else
    {
        state = MOVING_TO_CENTER;
        current_center = center;
        cout << display_code << id_num << ": On my way to Center " << center->GetId() << endl;
    }
}


void Trainer::StartBattling(unsigned int num_battles)
{
    if(state != IN_GYM)
    {
        cout << display_code << id_num << ": I can only battle in a PokemonGym!" << endl;
    }
    else if(state == FAINTED)
    {
        cout << display_code << id_num << ": My Pokemon have fainted so no more battles for me... " << endl;
    }
    else if(PokeDollars < current_gym->GetPokeDollarCost(num_battles)) //?
    {
        cout << display_code << id_num << ": Not enough money for battles" << endl;
    }
    else if(current_gym->GetNumBattlesRemaining() < num_battles) //?
    {
        cout << display_code << id_num << ": Cannot battle! This PokemonGym has no more trainers to battle" << endl;
    }
    else
    {
        //is_IN_GYM = true;

        state = BATTLING_IN_GYM;
        cout << display_code << id_num << ": started to battle at the PokemonGym " << current_gym->GetId() << " with " << num_battles << " battles" << endl;


        battles_to_buy = num_battles; //?
        //need to add: update the remaining battles in the gym . This will be used when its Update() function is called.
    }
}

void Trainer::StartRecoveringHealth(unsigned int num_potions)
{

    if(state != AT_CENTER)
    {
        cout << display_code << id_num << ": I can only recover health at a Pokemon Center! " << endl;
        return;
    }
    else if(current_center->CanAffordPotion(num_potions , PokeDollars) == false)
    {
        cout << display_code << id_num << ": Not enough money to recover health. " << endl;
        return;
    }
    else if(current_center->HasPotions() == false)
    {
        cout << display_code << id_num << ": Cannot recover! No potion remaining in this Pokemon Center " << endl;
        return;
    }
    else
    {
        state = RECOVERING_HEALTH;
        cout << display_code << id_num << ": Started recovering " << num_potions << " potions at Pokemon Center " << current_center->GetId() << endl;
        //the trainer can start recovering health
        //potions_to_buy = num_potions;
        //need to add: update the remaining potions in the center. This will be used when its Update() function is called
        
        //add 5 health for every potion used:

        potions_to_buy = current_center->DistributePotion(num_potions); //this is good

        health = health + (5 * potions_to_buy); //?

        return;
    }
}

void Trainer::Stop()
{
    state = STOPPED;
    cout << display_code << id_num << ": Stopping..." << endl;
}


bool Trainer::HasFainted()
{
    if(health == 0)
    {
        state = FAINTED; 
        return true;
    }
    else
        return false;
}

bool Trainer::ShouldBeVisible()
{
    // if(state == FAINTED)
    //     return false;
    // else
    //     return true;

    if(health > 0)
    {
        return true;
    }
    else
    {
        state = FAINTED; 
        return false;
    }
}

/*
    STOPPED = 0,
    MOVING = 1,
    FAINTED = 2,
    AT_CENTER = 3,
    IN_GYM = 4,
    MOVING_TO_CENTER = 5,
    MOVING_TO_GYM = 6,
    BATTLING_IN_GYM = 7,
    RECOVERING_HEALTH = 8
*/

void Trainer::ShowStatus()
{
    cout << name << " status: ";
    GameObject::ShowStatus();
    switch(state)
    {
        case 0:
            cout << "stopped" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            cout << "---" << endl;
            break;
        case 1:
            cout << "moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            cout << "---" << endl;
            break;
        case 6:
            cout << "heading to PokemonGym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            cout << "---" << endl;
            break;
        case 5:
            cout << "heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            cout << "---" << endl;
            break;
        case 4:
            cout << "inside PokemonGym " << current_gym->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            cout << "---" << endl;
            break;
        case 3:
            cout << "inside PokemonCenter " << current_center->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            cout << "---" << endl;
            break;
        case 7:
            cout << "battling in PokemonGym " << current_gym->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            cout << "---" << endl;
            break;
        case 8:
            cout << "recovering health in Pokemon Center " << current_center->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            cout << "---" << endl;
            break;
        case 2:
            cout << "fainted" << endl;
            cout << "---" << endl;
            
    }
}


bool Trainer::Update()
{
    switch(state)
    {
        case 0: //stopped
        {
            return false;
            break;
        } 

        case 1: //moving
        {
            if(UpdateLocation() == true) //? 
            {
                state = STOPPED;
                return true;
                break;
            }
            else
            {
                state = MOVING; //is this necessary?
                return false; 
                break;
            }
        }

        case 6: //moving_to_gym
        {
            if(UpdateLocation() == true)
            {
                current_gym->AddOneTrainer(); //testing...worked!!

                state = IN_GYM;
                return true;
                break;
            }
            else
            {
                state = MOVING_TO_GYM;
                return false;
                break;
            }
        }

        case 5: //moving to center
        {
            if(UpdateLocation() == true)
            {
                current_center->AddOneTrainer(); //testing...worked!!

                state = AT_CENTER;
                return true;
                break;
            }
            else
            {
                state = MOVING_TO_CENTER;
                return false;
                break;
            }
        }

        case 4: //in gymn
        {
            return false;
            break;
        }  

        case 3: //at center
        {
            return false;
            break;
        }

        case 7: //battling in gym
        {
            unsigned int current_health_cost =  current_gym->GetHealthCost(battles_to_buy);
            health = health - current_health_cost;//? reduce Trainer health based on total health cost for the current gym request

            unsigned int current_dollar_cost = current_gym->GetPokeDollarCost(battles_to_buy);
            PokeDollars = PokeDollars - current_dollar_cost;

            unsigned int current_experience_gain = current_gym->TrainPokemon(battles_to_buy);
            experience = experience + current_experience_gain;

            if(battles_to_buy <= 1)
                cout << "** " << name << " completed " << battles_to_buy << " battle! **" << endl;
            else 
                cout << "** " << name << " completed " << battles_to_buy << " battles! **" << endl;

            cout << "** " << name << " gained " << current_experience_gain << " experiences! **" << endl;

            state = IN_GYM;
            //state = BATTLING_IN_GYM;
            return true;
            break;
        }

        case 8: //recovering_health
        {

            unsigned int healthpoints_recovered = potions_to_buy * 5;
            
            unsigned int current_dollar_cost = current_center->GetPokeDollarCost(potions_to_buy);

            PokeDollars = PokeDollars - current_dollar_cost;

            cout << "** " << name << " recovered " << healthpoints_recovered << " health! **" << endl;
            if(potions_to_buy <= 1)
            {
                cout << "** " << name << " bought " << potions_to_buy << " potion! **" << endl;
            }
            else 
                cout << "** " << name << " bought " << potions_to_buy << " potions! **" << endl;

            state = AT_CENTER;
            return true;
            break;  
        }

        default:
        {
            state = STOPPED;
            return false;
        }
    }
}



//protected members:

bool Trainer::UpdateLocation()
//update the location while the object is moving
{
    if((fabs(destination.x - location.x) <= fabs(delta.x)) && (fabs(destination.y - location.y) <= fabs(delta.y)))
    {
        cout << display_code << id_num << ": I'm there!" << endl;
        location = destination; //? don't know if I have to do location.x = destination.x or not

        //visial:
        cout << "---" << endl;

        return true;
    }
    else
    {

        location = location + delta;
        for(int i = 0; i < bundledWildPokemon.size(); i++)
        {
            cout << "RUNNINGGGGG: " << i << endl;
            bundledWildPokemon[i]->UpdateLocation(location);

            //visial:
            cout << "---" << endl;
        }


        cout << "---" << endl;

        PokeDollars = PokeDollars + GetRandomAmountOfPokeDollars(); //should be right? get random dollar everytime the trainer takes a step

        if(health != 0){

            health = health - 1; //lose one health everytime you move

        }

        cout << display_code << id_num << ": step..." << endl;
        //visial:
        cout << "---" << endl;
        return false;
    }
}

string Trainer::GetName()
{
    return name;
}


//non-member function
double GetRandomAmountOfPokeDollars()
{
    srand (time (NULL) );
    float low_offet = 0.0; //change values later!!!!!
    float high_offet = 2.0; //change values later!!!!
    float random_PokeDollar = low_offet + static_cast<float>(rand()) * static_cast<float>(high_offet - low_offet) / RAND_MAX;

    return random_PokeDollar;
} 



// //Added for PA4: 
void Trainer::StartFollowingWildPokemon(Model* model, int trainer_id, int wildpokemon_id)
{
    bundledWildPokemon.push_back(model->GetWildPokemonPtr(wildpokemon_id));

    model->GetWildPokemonPtr(wildpokemon_id)->follow(model->GetTrainerPtr(trainer_id));

    following_wild_pokemon = true; 

    if(model->GetWildPokemonPtr(wildpokemon_id)->ShouldBeVisible() == true)
    {
        display_code = 't'; 
    }
    else
    {
        display_code = 'T';
    }

    if(state != FAINTED)
    {
        cout << "WildPokemon " << model->GetWildPokemonPtr(wildpokemon_id)->GetName() << " is in combat with trainer: " << model->GetTrainerPtr(trainer_id)->GetName() << endl;
    }

    return;
}

void Trainer::ReduceHealth(int reduction)
{
    health = health - reduction;
}