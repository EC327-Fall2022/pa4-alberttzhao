
#pragma once

#include <iostream>
#include <ostream>
#include <string> 

#include "Model.h"
#include "Point2D.h"
#include "string"
#include "View.h"

//function prototypes:
void DoMoveCommand(Model& model, int trainer_id, Point2D p1);
void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id);
void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id);
void DoStopCommand(Model& model, int trainer_id);
void DoBattleCommand(Model& model, int trainer_id, unsigned int battles);
void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed);
void DoAdvanceCommand(Model& model, View& view);
void DoRunCommand(Model& model, View& view);


//PA4:
// void DoSaveCommand(Model& model, string file_name);
