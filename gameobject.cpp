#include "gameobject.h"
#include "vector2d.h"
#include "point2d.h"
#include <iostream>
using namespace std;

//constructors

GameObject::GameObject(){
    display_code = ' ';
    state ='0';
    id_num = 1;
    cout<<"GameObject default constructed"<<endl;
}

GameObject::GameObject(char in_code){
    display_code = in_code;
    id_num = 1;
    state = '0';

    cout<<"GameObject constructed"<<endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code){
    location = in_loc;
    id_num = in_id;
    display_code = in_code;
    state = '0';

    cout<<"GameObject constructed"<<endl;
}


//member functions

Point2D GameObject::GetLocation(){
    return location;
}

int GameObject::GetId(){
    return id_num;
}

char GameObject::GetState(){
    return state;
}

void GameObject::ShowStatus(){
    cout<< display_code << id_num << " located at " << location <<endl;
}


//Destructor
GameObject::~GameObject(){
    cout<<"GameObject destructed"<<endl;
}

//Extra member function
void GameObject::DrawSelf(char * ptr){
    ptr[0] = display_code;
    switch (id_num) // For some reason the id wouldn't display unless i hard coded it.
    {
    case 1:
        ptr[1] = '1';
        break;
    case 2:
        ptr[1] = '2';
        break;
    case 3:
        ptr[1] = '3';
        break; 
    case 4:
        ptr[1] = '4';
        break;
    case 5:
        ptr[1] = '5';
        break;
    case 6:
        ptr[1] = '6';
        break;
    case 7:
        ptr[1] = '7';
        break;
    case 8:
        ptr[1] = '8';
        break;  
    case 9:
        ptr[1] = '9';
        break;              
    default:
        ptr[1] = ' ';
        break;
    }
}