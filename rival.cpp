#include "rival.h"
#include "iostream"
using namespace std;

Rival::Rival(string in_name, char in_code, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int id, BattleArena * arena) :GameObject(arena->GetLocation(), id, 'R') {
    name = in_name;
    speed = in_speed;
    health = hp;
    physical_damage = phys_dmg;
    magical_damage = magic_dmg;
    defense = def;
    is_in_arena = true;
    current_arena = arena;
    state = ALIVE_RIVAL;

    cout<<"Rival constructed"<<endl;
}

void Rival::TakeHit(double phys_dmg, double magic_dmg, double def){
    int a = rand()%2; //randomly choosing the attack option
    if(a == 1){ //if a = 1, do physical damage
        health -= ((100.0 - def) / 100* phys_dmg);
        cout<<name<<": Aghhh! I am hit!"<<endl;
        cout<<"Damage: "<<phys_dmg<<endl;
        cout<<"Health: "<<health<<endl;
        cout<<"********"<<endl;
    }
    else{ // if a = 2, do magical damage
        health -= ((100.0 - def) / 100.0 * magic_dmg);
        cout<<name<<": He used magic! It was super effective!"<<endl;
        cout<<"Damage: "<<magic_dmg<<endl;
        cout<<"Health: "<<health<<endl;
        cout<<"********"<<endl;
    }
}

double Rival::get_phys_dmg(){
    return physical_damage;
}

double Rival::get_magic_dmg(){
    return magical_damage;
}

double Rival::get_defense(){
    return defense;
}

double Rival::get_health(){
    return health;
}

string Rival::GetName(){
    return name;
}

double Rival::GetSpeed(){
    return speed;
}

bool Rival::Update(){
   while(state == ALIVE_RIVAL){
        if(health<=0){
            state = FAINTED_RIVAL;
            return true;
            break;
        }
        else{
            state = ALIVE_RIVAL;
            return false;
            break;
        }
    }
    return false;
}

void Rival::ShowStatus(){
    cout<<name<<" status: ";
    GameObject::ShowStatus();
    switch (state)
    {
    case ALIVE_RIVAL:
        cout<<"        Currently alive and still able to fight"<<endl;
        cout<<"        Remaining health: "<<health<<endl;
        break;
    case FAINTED_RIVAL:
        cout<<"        Fainted..."<<endl;
        break;
    default:
        break;
    }

}

bool Rival::isAlive(){
    if(health<=0){
        state = FAINTED_RIVAL;
        return false;
    }
    else
    {
        state = ALIVE_RIVAL;
        return true;
    }   
}

bool Rival::ShouldBeVisible(){
    if(isAlive()){
        return true;
    }
    else
    {
        return false;
    } 
}

Rival::~Rival(){
    cout<<"Rival destructed"<<endl;
}

void Rival::set_health(double hp){
    health = hp; 
}