#include <iostream> 
#include <math.h>
#include <string>

#include "Vector2D.h"

using namespace std;


Vector2D::Vector2D()
{
    x = 0.0;
    y = 0.0;
}


Vector2D::Vector2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}


//non-member overloaded operators:
//definition of multiplication operator:
const Vector2D operator * (const Vector2D& vector, double d)
{
    double x = vector.x * d;
    double y = vector.y * d;

    return Vector2D(x , y); //making a new vector2D with updated value
}

//definition of division operator:
const Vector2D operator / (const Vector2D& vector, double d)
{
    if(d == 0)
    {
        return Vector2D(vector.x, vector.y);
    }else
    {
        double x = vector.x / d;
        double y = vector.y / d;
        return Vector2D(x , y);
    }
}

//definition of stream output operator:
ostream& operator << (ostream& os, Vector2D& vector)
{
    os << '<' << vector.x << ',' << vector.y << '>';
    return os;
}