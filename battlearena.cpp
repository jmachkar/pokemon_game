#include "battlearena.h"
#include <iostream>
using namespace std;

BattleArena::BattleArena() :Building(){
    display_code = 'A';
    pokemon_count = 0;
    max_num_rivals = 3;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = 4;
    stamina_cost_per_fight = 3;
    state = RIVALS_AVAILABLE;

    cout<<"BattleArena default constructed"<<endl;
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc) :Building('A', in_id, in_loc){
    pokemon_count = 0;
    max_num_rivals = max_rivals;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = dollar_cost;
    stamina_cost_per_fight = stamina_cost;
    state = RIVALS_AVAILABLE;

    cout<<"BattleArena constructed"<<endl;
}

unsigned int BattleArena::GetNumRivalsRemaining(){
    return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals(){
    if(num_rivals_remaining)
        return true;
    else
        return false;
    
}

double BattleArena::GetDollarCost(){
    return dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost(){
    return stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina){
    if(budget>=dollar_cost_per_fight && stamina>=stamina_cost_per_fight)
        return true;
    else 
        return false;
}

bool BattleArena::Update(){
    while(state == RIVALS_AVAILABLE){
        if(HasEnoughRivals()){
            return false;
            break;
        }
        else
        {
            state = NO_RIVALS_AVAILABLE;
            display_code ='a';
            cout<<"Battle Arena "<<id_num<<" has no more rivals."<<endl;
            return true;
        }  
    }
    return false;
}

bool BattleArena::IsBeaten(){
    if(num_rivals_remaining == 0)
        return true;
    else
        return false;
}

void BattleArena::ShowStatus(){
    cout<<"Battle  Arena status: ";
    Building::ShowStatus();
    cout<<"        Max number of rivals: "<<max_num_rivals<<endl;
    cout<<"        Stamina cost per fight: "<<stamina_cost_per_fight<<endl;
    cout<<"        Pokemon dollar cost per fight: "<<dollar_cost_per_fight<<endl;
    cout<<"        "<<num_rivals_remaining<<" rival(s) are remaining in this Arena"<<endl;

}

Point2D BattleArena::GetLocation(){
    return location;
}

BattleArena::~BattleArena(){
    cout<<"BattleArena destructed"<<endl;
}