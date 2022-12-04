
#pragma once

#include "Point2D.h"
#include "GameObject.h"
#include "Point2D.h"

class GameObject
{
protected:

    Point2D location;
    int id_num;
    char display_code;
    char state;

public:

    GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    Point2D GetLocation();
    int GetId();
    char GetState();
    virtual void ShowStatus(); //declare show status to be virtual

    //GameObject deconstructor:
    virtual ~GameObject();

    //bool Update():
    //virtual:
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;

    //from view:
    void DrawSelf(char *ptr);

    
};