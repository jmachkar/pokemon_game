#include "pokemon.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Poemon constructor
Pokemon::Pokemon() : GameObject(){
    srand((unsigned)time(NULL));
    speed = 5;
    state = STOPPED;
    is_in_gym = false;
    is_in_center = false;
    is_in_arena = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = 0;
    current_gym = 0;
    current_arena = 0;
    destination = Point2D();
    health = 20;
    store_health = health;
    physical_damage = 5;
    magical_damage = 4;
    defense = 15;
    target = 0;
    cout<<"Pokemon default constructed"<<endl;
}

Pokemon::Pokemon(char in_code) : GameObject(in_code){
    srand((unsigned)time(NULL));
    display_code = in_code;
    state = STOPPED;
    speed = 5;
    is_in_gym = false;
    is_in_center = false;
    is_in_arena = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = 0;
    current_gym = 0;
    current_arena = 0;
    destination = Point2D();
    health = 20;
    store_health = health;
    physical_damage = 5;
    magical_damage = 4;
    defense = 15;
    target = 0;
    cout << "Pokemon constructed"<<endl;
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, Point2D in_loc) : GameObject(in_loc, in_id, 'P'){
    srand((unsigned)time(NULL));
    speed = in_speed;
    name = in_name;
    state = STOPPED;
    is_in_gym = false;
    is_in_center = false;
    is_in_arena = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = 0;
    current_gym = 0;
    current_arena = 0;
    destination = Point2D();    
    health = hp;
    store_health = health;
    physical_damage = phys_dmg;
    magical_damage = magic_dmg;
    defense = def;
    target = 0;
    cout<<"Pokemon constructed"<<endl;
}

//Member functions
void Pokemon::StartMoving(Point2D dest){

    if(GetDistanceBetween(location, dest)==0){
        cout<<display_code<<id_num<<": I'm already there. See?"<<endl;
    }
    else if(isExhausted()){
        cout<<display_code<<id_num<<": I am exhausted. I may move but you cannot see me."<<endl;
    }   
    else{
        if (is_in_gym)
        {
            current_gym->RemoveOnePokemon();
            current_gym = 0;
            is_in_gym = false;
        }
        else if (is_in_center)
        {
            current_center->RemoveOnePokemon();
            current_center = 0;
            is_in_center = false;
        }
        else if (is_in_arena)
        {
            current_arena->RemoveOnePokemon();
            current_arena = 0;
            is_in_arena = false;
        }
        cout<<display_code<<id_num<<": On my way."<<endl;
        destination = dest;   
        SetupDestination(dest);
        state = MOVING;   
    }

}

void Pokemon::StartMovingToCenter(PokemonCenter* center){
    destination = center->GetLocation();

    if(GetDistanceBetween(location, destination)==0){
        is_in_center = true;
        state = IN_CENTER;
        cout<<display_code<<id_num<<": I'm already at the Pokemon Center!"<<endl;
    }
    else if(isExhausted()){
        cout<<display_code<<id_num<<": I am exhausted so i can't move to recover stamina..."<<endl;
    }
    else{
        if (is_in_gym)
        {
            current_gym->RemoveOnePokemon();
            current_gym = 0;
            is_in_gym = false;
        }
        else if (is_in_center)
        {
            current_center->RemoveOnePokemon();
            current_center = 0;
            is_in_center = false;
        }
        else if (is_in_arena)
        {
            current_arena->RemoveOnePokemon();
            current_arena = 0;
            is_in_arena = false;
        }

        cout<<display_code<<id_num<<": On my way to center "<<center->GetId()<<"."<<endl;
        current_center = center;
        SetupDestination(destination);
        state = MOVING_TO_CENTER;
    }
 
}

void Pokemon::StartMovingToGym(PokemonGym* gym){
    destination = gym->GetLocation();

    if(GetDistanceBetween(location, destination)==0){
        is_in_gym = true;
        state = IN_GYM;
        cout<<display_code<<id_num<<": I'm already at the Pokemon Gym!"<<endl;
    }
    else if(isExhausted()){
        cout<<display_code<<id_num<<": I am exhausted so i shouldn't be going to the gym..."<<endl;
    }
    else{
        if (is_in_gym)
        {
            current_gym->RemoveOnePokemon();
            current_gym = 0;
            is_in_gym = false;
        }
        else if (is_in_center)
        {
            current_center->RemoveOnePokemon();
            current_center = 0;
            is_in_center = false;
        }
        else if (is_in_arena)
        {
            current_arena->RemoveOnePokemon();
            current_arena = 0;
            is_in_arena = false;
        }

        cout<<display_code<<id_num<<": On my way to gym "<<gym->GetId()<<"."<<endl;
        current_gym = gym;
        SetupDestination(destination); 
        state = MOVING_TO_GYM;
    }

}

void Pokemon::StartTraining(unsigned int num_training_units){
    
    if(isExhausted()){
        cout<<display_code<<id_num<<": I am exhausted so no more training for me..."<<endl;
    }
    else if(state != IN_GYM){
        cout<<display_code<<id_num<<": I can only train in a Pokemongym!"<<endl;
    }
    else if(!(current_gym->IsAbleToTrain(num_training_units, pokemon_dollars, stamina))){
        cout<<display_code<<id_num<<": Not enough money and/or stamina for training"<<endl;
    }
    else if(current_gym->GetState() == BEATEN){
        cout<<display_code<<id_num<<": Cannot train! This Pokemon Gym is already beaten!"<<endl;
    }
    else
    {
        state = TRAINING_IN_GYM;
        cout<<display_code<<id_num<<": Started to train at Pokemon Gym "<<current_gym->GetId()<<" with "<<num_training_units<< " training units."<<endl;
        if(num_training_units<=current_gym->GetNumTrainingUnitsRemaining()){
            training_units_to_buy = num_training_units;
        }
        else
        {
            training_units_to_buy = current_gym->GetNumTrainingUnitsRemaining();
        }
        
    }
    
}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points){
    
    if(state != IN_CENTER){
        cout<<display_code<<id_num<<": I can only recover stamina in a Pokemon Center!"<<endl;
    }
    else if(!(current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars))){
        cout<<display_code<<id_num<<": Not enough money to recover stamina."<<endl;
    }
    else if(current_center->GetState()==NO_STAMINA_POINTS_AVAILABLE){
        cout<<display_code<<id_num<<": Cannot recover! No stamina points remaining in this Pokemon Center!"<<endl;
    }
    else
    {
        state = RECOVERING_STAMINA;
        cout<<display_code<<id_num<<": Started recovering "<<num_stamina_points<<" stamina point(s) at Pokemon Center"<<current_center->GetId()<<endl;
        if(num_stamina_points<=current_center->GetNumStaminaPointsRemaining()){
            stamina_points_to_buy = num_stamina_points;
        }
        else
        {
            stamina_points_to_buy = current_center->GetNumStaminaPointsRemaining();
        }
        
    }
    
}

void Pokemon::Stop(){
    state = STOPPED;
    cout<<display_code<<id_num<<": Stopping..."<<endl;
}

bool Pokemon::isExhausted(){
    if(!stamina)
        return true;
    else
        return false;
}

bool Pokemon::ShouldBeVisible(){
    if(!isExhausted() && isAlive())
        return true;
    else
        return false;
}

void Pokemon::ShowStatus(){
    cout<<name<<" status: ";
    GameObject::ShowStatus();
    cout<<"        Stamina: "<<stamina<<endl<<"        Pokemon Dollars: "<<pokemon_dollars<<endl<<"        Experience Points: "<<experience_points<<endl;
    cout<<"        Health: "<<health<<endl<<"        Physical damage: "<<physical_damage<<endl;
    cout<<"        Magical damage: "<<magical_damage<<endl<<"        Defense: "<<defense<<endl;

    switch (state)
    {
    case STOPPED:
        cout<<"        Stopped"<<endl;
        break;
    case MOVING:
        cout<<"        Moving at a speed of "<<speed<<" to destination "<<destination<<" at each step of "<<delta<<"."<<endl;
        break;
    case MOVING_TO_CENTER:
        cout<<"        Heading to Pokemon Center "<<current_center->GetId()<<" at a speed of "<<speed<<" at each step of "<<delta<<"."<<endl;
        break;
    case MOVING_TO_GYM:
        cout<<"        Heading to Pokemon Gym "<<current_gym->GetId()<<" at a speed of "<<speed<<" at each step of "<<delta<<"."<<endl;
        break;
    case IN_CENTER:  
        cout<<"        Inside Pokemon Center "<<current_center->GetId()<<"."<<endl;
        break;
    case IN_GYM:
        cout<<"        Inside Pokemon Gym "<<current_gym->GetId()<<"."<<endl;
        break;
    case TRAINING_IN_GYM:
        cout<<"        Training in Pokemon Gym "<<current_gym->GetId()<<"."<<endl;
        break;
    case RECOVERING_STAMINA:
        cout<<"        Recovering stamina in Pokemon Center "<<current_center->GetId()<<"."<<endl;
        break;
    case IN_ARENA:
        cout<<"        Inside Battle Arena "<<current_arena->GetId()<<"."<<endl;
        break;
    case MOVING_TO_ARENA:
        cout<<"        Heading to Battle Arena "<<current_arena->GetId()<<" at a speed of "<<speed<<" at each step of "<<delta<<"."<<endl; 
        break;
    case FAINTED:
        cout<<"        Fainted...there is nothing that can be done anymore..."<<endl;
        break;
    case BATTLE:
        cout<<"        CURRENTLY FIGHTING "<<target->GetName()<<"!"<<endl;
        break;
    case EXHAUSTED:
        cout<<"        Out of stamina and can no longer move..."<<endl;
        break;
    }

}

bool Pokemon::Update(){
    bool a, e;
    e = isExhausted();
  switch (state)
    {
    case STOPPED:
        is_in_gym = false;
        is_in_center = false;
        return false;
        break;
    case MOVING:
        if(!e){
            a = UpdateLocation();
            if(is_in_gym){
                current_gym->RemoveOnePokemon();
            }
            else if(is_in_center){
                current_center->RemoveOnePokemon();
            }
            is_in_gym = false;
            is_in_center = false;
            if(a){
                state = STOPPED;
                return true;
            }
            else
            {
                stamina--;
                pokemon_dollars += GetRandomAmountOfPokemonDollars();
                return false;
            }
        }
        else{
            state = EXHAUSTED;
            cout<<display_code<<id_num<<": I ran out of stamina..."<<endl;
            return true;
        }
        break;
    case MOVING_TO_CENTER:
        if(!e){
            a = UpdateLocation();
            if(is_in_gym){
                current_gym->RemoveOnePokemon();
            }
            else if(is_in_arena){
                current_arena->RemoveOnePokemon();
            }
            is_in_gym = false;
            is_in_center = false;
            is_in_arena = false;
            if(a){
                state = IN_CENTER;
                is_in_center = true;
                current_center->AddOnePokemon();
                return true;
            }
            else
            {
                stamina--;
                pokemon_dollars += GetRandomAmountOfPokemonDollars();
                return false;
            }
        }
        else{
            state = EXHAUSTED;
            cout<<display_code<<id_num<<": I ran out of stamina..."<<endl;
            return true;
        }
        break;
    case MOVING_TO_GYM:
        if(!e){
            a = UpdateLocation();
            if(is_in_center){
                current_center->RemoveOnePokemon();
            }
            else if(is_in_arena){
                current_arena->RemoveOnePokemon();
            }
            is_in_gym = false;
            is_in_center = false;
            is_in_arena = false;
            if(a){
                state = IN_GYM;
                is_in_gym = true;
                current_gym->AddOnePokemon();
                return true;
            }
            else
            {
                stamina--;
                pokemon_dollars += GetRandomAmountOfPokemonDollars();
                return false;
            }
        }
        else{
            state = EXHAUSTED;
            cout<<display_code<<id_num<<": I ran out of stamina..."<<endl;
            return true;
        }
        break;
    case IN_CENTER:  
        is_in_center = true;
        return false;
        break;
    case IN_GYM:
        is_in_gym = true;
        return false;
        break;
    case TRAINING_IN_GYM:
        stamina -= current_gym->GetStaminaCost(training_units_to_buy);
        pokemon_dollars -= current_gym->GetDollarCost(training_units_to_buy);
        experience_points += current_gym->TrainPokemon(training_units_to_buy);
        cout<<"**"<<name<<" completed "<<training_units_to_buy<<" training unit(s)!**"<<endl;
        cout<<"**"<<name<<" gained "<<experience_points<<" experience point(s)!**"<<endl;
        state = IN_GYM;
        return true;
        break;
    case RECOVERING_STAMINA:
        stamina += current_center->DistributeStamina(stamina_points_to_buy);
        pokemon_dollars -= current_center->GetDollarCost(stamina_points_to_buy);
        cout<<"**"<<name<<" recovered "<<stamina_points_to_buy<<" stamina point(s)!**"<<endl;
        state = IN_CENTER;
        return true;
        break;
    case FAINTED:
        state = FAINTED;
        return false;
        break;
    case EXHAUSTED:
        state = EXHAUSTED;
        return false;
        break;
    case MOVING_TO_ARENA:
        if(!e){
            a = UpdateLocation();
            if(is_in_center){
                current_center->RemoveOnePokemon();
            }
            else if(is_in_gym){
                current_gym->RemoveOnePokemon();
            }
            is_in_gym = false;
            is_in_center = false;
            is_in_arena = false;
            if(a){
                state = IN_ARENA;
                is_in_arena = true;
                current_arena->AddOnePokemon();
                return true;
            }
            else
            {
                stamina--;
                pokemon_dollars += GetRandomAmountOfPokemonDollars();
                return false;
            }
        }
        else{
            state = EXHAUSTED;
            cout<<display_code<<id_num<<": I ran out of stamina..."<<endl;
            return true;
        }
        break;
    case IN_ARENA:
        is_in_arena = true;
        return false;
        break;
    case BATTLE:
        //fill this up after doing rival and arena
        stamina -= current_arena->GetStaminaCost();
        pokemon_dollars -= current_arena->GetDollarCost();
        bool b = StartBattle();
        if(b){
            health = store_health;
            state = IN_ARENA;
            target->isAlive();
        }
        else{
            state = FAINTED;
            target->isAlive();
        }
        break;
    }
    return false; //should never get here
}

bool Pokemon::UpdateLocation(){
    if(fabs(destination.x - location.x)<=fabs(delta.x)&&fabs(destination.y - location.y)<=fabs(delta.y)){
        location = destination;
        cout<<display_code<<id_num<<": I'm there!"<<endl;
        return true;
    }
    else
    {
        location = location + delta;
        cout<<display_code<<id_num<<": step..."<<endl;
        return false;
    }
}

void Pokemon::SetupDestination(Point2D dest){
    delta = (dest - location)*(speed/GetDistanceBetween(dest,location));
}

double GetRandomAmountOfPokemonDollars(){ 
    double r = 2*((double)rand()/(double)RAND_MAX);
    return r; 
}

string Pokemon::GetName(){
    return name;
}

Point2D Pokemon::GetDest(){
    return destination;
}

char Pokemon::GetCode(){
    return display_code;
}

Pokemon::~Pokemon(){
    cout<<"Pokemon destructed"<<endl;
}
    
bool Pokemon::isAlive(){
    if(state == FAINTED){
        return false;
    }
    else
    {
        return true;
    }
}

void Pokemon::TakeHit(double phys_dmg, double magic_dmg, double def){
    int a = rand()%2; //randomly choosing the attack option
    if(a == 1){ //if a = 1, do physical damage
        health -= ((100.0 - def) / 100* phys_dmg);
        cout<<name<<": Master, physical damage hurts!"<<endl;
        cout<<"Damage: "<<phys_dmg<<endl;
        cout<<"Health: "<<health<<endl;
        cout<<"********"<<endl;
    }
    else{ // if a = 2, do magical damage
        health -= ((100.0 - def) / 100.0 * magic_dmg);
        cout<<name<<": Master, Magic was effective!!"<<endl;
        cout<<"Damage: "<<magic_dmg<<endl;
        cout<<"Health: "<<health<<endl;
        cout<<"********"<<endl;
    }
}

void Pokemon::ReadyBattle(Rival * in_target){
        target = in_target;
    if(state == IN_ARENA && current_arena->IsAbleToFight(pokemon_dollars, stamina) && !(current_arena->IsBeaten()) && in_target->isAlive()){
        state = BATTLE;
        cout<<display_code<<id_num<<": Preparing for battle"<<endl;
    }
    else
    {
        target = 0;
        cout<<display_code<<id_num<<": Unable to fight"<<endl;
        state = IN_ARENA;
    }   
}

bool Pokemon::StartBattle(){
    while(health > 0 && target->get_health() > 0){
        TakeHit(target->get_phys_dmg(), target->get_magic_dmg(), defense);
        if(health<=0){
            cout<<name<<": I lost Master...I am sorry"<<endl;
            cout<<target->GetName()<<": Funny how thought you could defeat me!"<<endl<<endl;
            health  = 0;
            return false;
            break;
        }
        target->TakeHit(physical_damage, magical_damage, target->get_defense());
        if(target->get_health()<=0){
            cout<<target->GetName()<<": aaaahh...you win this time..."<<endl;
            cout<<name<<": Master! We did it!"<<endl<<endl;
            target->set_health(0);
            return true;
            break;
        }
    }
    return false;
}

void Pokemon::StartMovingToArena(BattleArena* arena){
    destination = arena->GetLocation();

    if(GetDistanceBetween(location, destination)==0){
        is_in_arena = true;
        state = IN_ARENA;
        cout<<display_code<<id_num<<": I'm already at the Battle Arena!"<<endl;
    }
    else if(isExhausted()){
        cout<<display_code<<id_num<<": I am exhausted so i shouldn't be battling..."<<endl;
    }
    else{
        cout<<display_code<<id_num<<": On my way to battle arena "<<arena->GetId()<<"."<<endl;
        current_arena = arena;
        SetupDestination(destination); 
        state = MOVING_TO_ARENA;
    }
}




