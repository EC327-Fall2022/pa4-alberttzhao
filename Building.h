
#pragma once

#include "GameObject.h"
#include "Point2D.h"

class Building : public GameObject 
{
private:
    
    unsigned int trainer_count;

public: 

    //destructor:
    virtual ~Building();

    Building();
    Building(char in_code, int in_Id, Point2D in_loc);


    void AddOneTrainer();
    void RemoveOneTrainer();
    void ShowStatus();
    bool ShouldBeVisible();

};