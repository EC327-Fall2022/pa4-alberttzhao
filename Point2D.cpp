#include <iostream> 
#include <math.h>
#include <string>

#include "Point2D.h"
//#include "Vector2D.h"

using namespace std;

Point2D::Point2D()
{
    x = 0.0;
    y = 0.0;
}

Point2D::Point2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

//non-member function:
double GetDistanceBetween(Point2D p1, Point2D p2)
{
    double calc = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y) , 2)); //distance formula
    return calc;
}

//non-member overloaded operator
ostream& operator<<(ostream& os, Point2D& point)
{
    os << '(' <<  point.x << ',' << point.y << ')';
    return os;

    /*
    for example: 
    if someone calls 
    cout << point 
    then it will print:
    (1,7) ....just using random number as example
    */
}

//additional operator:
const Point2D operator + (const Point2D& point, const Vector2D& vector)
{
    double x = point.x + vector.x;
    double y = point.y + vector.y;
    return Point2D(x , y);
}

const Vector2D operator - (const Point2D& p1, const Point2D& p2)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return Vector2D(x , y);
}
