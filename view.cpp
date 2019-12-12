#include "view.h"
#include <iostream>
using namespace std;

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location){
    out_x = (location.x - origin.x)/scale;
    out_y = (location.y - origin.y)/scale;

    if(out_x > view_maxsize || out_x < 0 || out_y > view_maxsize || out_y < 0) {
        cout<<"An object is outside the display"<<endl;
        return false;
    }
    else
    {
        return true;
    }
    
}

View::View(){
    size = 11;
    scale = 2;
    origin = Point2D();
}

void View::Clear(){
    for (int i = 0; i < view_maxsize; i++)
    {
        for (int j = 0; j < view_maxsize; j++)
        {
            grid[j][i][0] = '.';
            grid[j][i][1] = ' '; 
        }
    }
}

void View::Plot(GameObject* ptr){

    int out_x;
    int out_y;
    if((GetSubscripts(out_x, out_y, ptr->GetLocation()))==true){

        if(grid[out_x][out_y][0]=='.' && grid[out_x][out_y][1]==' '){
            ptr->DrawSelf(grid[out_x][out_y]);
        }
        else{
            grid[out_x][out_y][0] = '*';
            grid[out_x][out_y][1] = ' ';  
        }
    }
}

void View::Draw(){
    for(int i=(size-1); i>=0; i--){
        switch(i){
            case 10:{
                cout<<2*i;
                break;
            }
            case 8:{
                cout<<2*i;
                break;
            }
            case 6:{
                cout<<2*i;
                break;
            }
            case 4:{
                cout<<2*i<<" ";
                break;
            }
            case 2:{
                cout<<2*i<<" ";
                break;
            }
            case 0:{
                cout<<2*i<<" ";
                break;
            }
            default:{
                cout<<"  ";
                break;
            }
        }
        for(int j =0; j<size; j++){
            cout<<grid[j][i][0];
            cout<<grid[j][i][1];
        }
        cout<<endl;
    }
    cout<<"  ";
    for (int i = 0; i < size; i++){
        switch(i){
            case 10:{
                cout<<2*i<<"  ";
                break;
            }
            case 8:{
                cout<<2*i<<"  ";
                break;
            }
            case 6:{
                cout<<2*i<<"  ";
                break;
            }
            case 4:{
                cout<<2*i<<"   ";
                break;
            }
            case 2:{
                cout<<2*i<<"   ";
                break;
            }
            case 0:{
                cout<<2*i<<"   ";
                break;
            }
            default:{
                break;
            }
        }
    }
    cout<<endl;
}

