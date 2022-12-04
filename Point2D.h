
#pragma once

#include "Vector2D.h"

using namespace std;


class Point2D
{
public:

    double x;
    double y;

    //default constructor:
    Point2D();

    //parameterized constructor:
    Point2D(double in_x, double in_y);

};

ostream& operator << (ostream& os, Point2D& point);

const Point2D operator + (const Point2D& point, const Vector2D& vector);

const Vector2D operator - (const Point2D& p1, const Point2D& p2);

double GetDistanceBetween(Point2D, Point2D);

