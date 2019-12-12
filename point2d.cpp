#include "point2d.h"
#include "vector2d.h"
#include <math.h>
#include <iostream>
using namespace std;

//constructors

Point2D::Point2D(){; //default constructor
    x = 0;
    y = 0;
}

Point2D::Point2D(double in_x, double in_y){ //constructor #1
    x = in_x;
    y = in_y;
}

//non-member function 

double GetDistanceBetween(Point2D p1, Point2D p2){   
    return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));   
}

//non-member overloaded operators

ostream &operator<<(ostream &os, Point2D p1){
    os << '(' << p1.x << ',' << p1.y << ')';
    return os;
}

Point2D operator+(Point2D p1, Vector2D v1){

    Point2D p2;

    p2.x = p1.x + v1.x;
    p2.y = p1.y + v1.y;

    return p2;

}

Vector2D operator-(Point2D p1, Point2D p2){

    Vector2D v1;

    v1.x = p1.x - p2.x;
    v1.y = p1.y - p2.y;

    return v1;

}