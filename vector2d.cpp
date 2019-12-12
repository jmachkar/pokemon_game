#include "vector2d.h"
#include <iostream>
using namespace std;

//constructors

Vector2D::Vector2D(){
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double in_x,double in_y){
    x = in_x;
    y = in_y;
}

//non-member overloaded operators

Vector2D operator*(Vector2D v1, double d){
    Vector2D v2;
    v2.x = v1.x *d;
    v2.y = v1.y *d;
    return v2;
}

Vector2D operator/(Vector2D v1, double d){
    Vector2D v2;
    v2.x = v1.x / d;
    v2.y = v1.y / d;
    return v2;
}

ostream& operator<<(ostream &os, Vector2D v1){
    os << '<' << v1.x << ',' << v1.y << '>';
    return os;
}
