#include "pokemoncenter.h"

//constructors
PokemonCenter::PokemonCenter() : Building(){
    display_code = 'C';
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = 5;
    state = STAMINA_POINTS_AVAILABLE;
    cout<<"PokemonCenter default constructed"<<endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc) : Building('C', in_id, in_loc){
    stamina_capacity = stamina_cap;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = stamina_cost;
    state = STAMINA_POINTS_AVAILABLE;
    cout<<"PokemonCenter constructed"<<endl;
}

//public member functions
bool PokemonCenter::HasStaminaPoints(){
    if(num_stamina_points_remaining)
        return true;
    else 
        return false;
}
unsigned int PokemonCenter::GetNumStaminaPointsRemaining(){
    return num_stamina_points_remaining;
}
bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget){
    if(budget >= dollar_cost_per_stamina_point*stamina_points)
        return true;
    else
        return false;
    
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points){
    return dollar_cost_per_stamina_point*stamina_points;
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed){
    if(points_needed<=num_stamina_points_remaining){
        num_stamina_points_remaining -= points_needed;
        return points_needed;
    }
    else{
        points_needed = num_stamina_points_remaining;
        num_stamina_points_remaining = 0;
        return points_needed;
    }
}

bool PokemonCenter::Update(){
    while(state == STAMINA_POINTS_AVAILABLE){
        if(!num_stamina_points_remaining){
            state = NO_STAMINA_POINTS_AVAILABLE;
            display_code ='c';
            cout << "PokemonCenter "<< id_num <<" has ran out of stamina points." << endl;
            return true;
            break;
        }
        else 
            return false;
            break;
    }
    return false;
}

void PokemonCenter::ShowStatus(){
    cout<< "Pokemon Center status: ";
    Building::ShowStatus();
    cout<< "        Pokemon dollars per stamina point: "<< dollar_cost_per_stamina_point <<endl;
    cout<< "        Has " <<num_stamina_points_remaining << " stamina point(s) remaining."<<endl;
}

PokemonCenter::~PokemonCenter(){
    cout<<"PokemonCenter destructed"<<endl;
}