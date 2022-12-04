
#include <iostream>
#include <math.h>
#include <string>

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "Model.h"
#include "View.h"
#include "GameCommand.h"

using namespace std;

int main()
{

    bool continue_loop = true;
    Model model;

    //displaying initial view:
    View view;
    model.Display(view);


    while(continue_loop == true)
    {
        char command;
        int id1;
        int id2;
        int potion_amount;
        int battle_amount;
        Point2D position1;

        cout << "Enter the game command: ", cin >> command;
        cout << "______________________" << endl;

        switch (command)
        {
        case 'm':
        {
            cin >> id1;
            cin >> position1.x;
            cin >> position1.y;
            DoMoveCommand(model, id1, position1);
            break;
        }
        case 'c':
        {
            cin >> id1;
            cin >> id2;
            DoMoveToCenterCommand(model, id1, id2);

            break;
        }
        case 'g':
        {
            cin >> id1;
            cin >> id2;
            DoMoveToGymCommand(model, id1, id2);
            break;
        }
        case 's':
        {
            cin >> id1;
            DoStopCommand(model, id1);
            break;
        }
        case 'p':
        {
            cin >> id1;
            cin >> potion_amount;
            DoRecoverInCenterCommand(model, id1, potion_amount);
            break;
        }
        case 'b':
        {
            cin >> id1;
            cin >> battle_amount;
            DoBattleCommand(model, id1, battle_amount);
            break;
        }
        case 'a':
        {
            // DoAdvance command
            DoAdvanceCommand(model, view);
            break;
        }
        case 'r':
        {
            // run: advnace on-time step by updating each object once;           
            DoRunCommand(model, view);
            break;
        }
        case 'q':
        {
            // quit: terminate the program
            model.GetTrainerPtr(1)->~Trainer();
            model.GetTrainerPtr(2)->~Trainer();
            model.GetPokemonCenterPtr(1)->~PokemonCenter();
            model.GetPokemonCenterPtr(2)->~PokemonCenter();
            model.GetPokemonGymPtr(1)->~PokemonGym();
            model.GetPokemonGymPtr(2)->~PokemonGym();

            cout << "*** Program Terminated ***" << endl;
            exit(0);
            break;
        }
        default:
        {
            cout << "Invalid Command!" << endl;
            break;
        }
        }//the end of switch statement
    }
}