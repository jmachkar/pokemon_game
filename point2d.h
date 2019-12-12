#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include "vector2d.h"
using namespace std;

class Point2D{
    public:

    double x; 
    double y; 
    
    Point2D(); //default constructor
    Point2D(double in_x, double in_y); //constructor #1

};

//function prototypes
double GetDistanceBetween(Point2D p1, Point2D p2);
ostream &operator<<(ostream &os, Point2D p1);
Point2D operator+(Point2D p1, Vector2D v1);
Vector2D operator-(Point2D p1, Point2D p2);

#endif