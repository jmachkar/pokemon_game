#include "building.h"

//constructors
Building::Building() : GameObject('B'){
    pokemon_count = 0;
    cout<< "Building default constructed"<<endl;
}

Building::Building(char in_code, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, in_code){
    pokemon_count = 0;
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    cout<<"Building constructed"<<endl;
}

Building::~Building(){
    cout<<"Building destructed"<<endl;
}

//member functions
void Building::AddOnePokemon(){
    pokemon_count++;
}
void Building::RemoveOnePokemon(){
    pokemon_count--;
}
void Building::ShowStatus(){
    GameObject::ShowStatus();
    if(pokemon_count==1)
        cout<<"        "<<pokemon_count<<" pokemon is in this building"<<endl;
    else
        cout<<"        "<<pokemon_count<<" pokemons are in this building"<<endl;
    
}
bool Building::ShouldBeVisible(){
    return true;
}