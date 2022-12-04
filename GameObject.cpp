#include <iostream>
#include <string>

#include "GameObject.h"

using namespace std;

//deconstructor:
GameObject::~GameObject()
{
    cout << "GameObject destructed" << endl;
}

GameObject::GameObject(char in_code)
{
    display_code = in_code;
    id_num = 1;
    state = 0;
    cout << "GameObject constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    state = 0;
    cout << "GameObject constructed" << endl;
}

Point2D GameObject::GetLocation()
{  
    return location;
}

int GameObject::GetId()
{
    return id_num;
}

char GameObject::GetState()
{
    return display_code;
}

//make ShowStatus to be virtual: 
void GameObject::ShowStatus()
{
    cout << display_code << id_num << " at " << location << endl;
    return;
}


//instruction from view:
//don't know if this is correct:
void GameObject::DrawSelf(char* ptr)
{
    ptr[0] = display_code;

    char id_num_in_char = '0' + id_num;
    ptr[1] = id_num_in_char;
}


