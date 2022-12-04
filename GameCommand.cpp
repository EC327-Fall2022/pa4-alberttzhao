
#include "GameCommand.h"
#include <stdio.h>
#include <string.h>

/*
void DoMoveCommand(Model& model, int trainer_id, Point2D p1);
void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id);
void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id);
void DoStopCommand(Model& model, int trainer_id);
void DoBattleCommand(Model& model, int trainer_id, unsigned int battles);
void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed);
void DoAdvanceCommand(Model& model, View& view);
void DoRunCommand(Model& model, View& view);
*/



void DoMoveCommand(Model& model, int trainer_id, Point2D p1)
{
    if(model.GetTrainerPtr(trainer_id) == 0)
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else
    {
        model.GetTrainerPtr(trainer_id)->StartMoving(p1);

        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetName() << " to " << p1 << endl;
        return;
    }
}


void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id)
{
    if((model.GetTrainerPtr(trainer_id) == 0) || (model.GetPokemonCenterPtr(center_id) == 0))
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartMovingToCenter(model.GetPokemonCenterPtr(center_id));

        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetName() << " to Pokemon Center " << center_id << endl; 

        return;
    }
}

void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id)
{
    if(model.GetTrainerPtr(trainer_id) == 0 || model.GetPokemonGymPtr(gym_id) == 0)
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartMovingToGym(model.GetPokemonGymPtr(gym_id));

        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetName() << " to gym " << gym_id << endl;

        return;
    }
}

void DoStopCommand(Model& model, int trainer_id)
{
    if(model.GetTrainerPtr(trainer_id) == 0)
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->Stop();

        cout << "Stopping " << model.GetTrainerPtr(trainer_id)->GetName() << endl;

        return;
    }
}


void DoBattleCommand(Model& model, int trainer_id, unsigned int battles)
{
    if(model.GetTrainerPtr(trainer_id) == 0)
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartBattling(battles);

        if((model.GetTrainerPtr(trainer_id)->GetState()) == BATTLING_IN_GYM)
        {
            cout << model.GetTrainerPtr(trainer_id)->GetName() << " is battling. " << endl; 
        }
    
        return;
    }
}

 void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed)
 {
    if(model.GetTrainerPtr(trainer_id) == 0)
    {
        cout << "Error: Please enter a valid command! " << endl;
        return;
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartRecoveringHealth(potions_needed);

        if(model.GetTrainerPtr(trainer_id)->GetState() == RECOVERING_HEALTH)
        {
            cout << "Recovering " << model.GetTrainerPtr(trainer_id)->GetName() << "'s Pokemon's health. " << endl;
        }
        else
        {
            return;
        }

        return;
    }
 }

void DoAdvanceCommand(Model& model, View& view)
{
    cout << "Advancing one tick" << endl;
    model.Update();
    model.ShowStatus();
    model.Display(view);
}

void DoRunCommand(Model& model, View& view)
{
    cout << "Advancing to next event" << endl;

    for(int i = 0; i < 5; i++)
    {
        model.Update();
    }
    model.Display(view);
}

