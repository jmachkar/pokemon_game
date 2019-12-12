#include "model.h"
#include <iostream>
#include "input_handling.h"
using namespace std;

//Constructor
Model::Model(){
    time =0;

    // pokemon_ptrs[0] = new Pokemon("Pikachu", 1, 'P', 2, 20, 4, 6, 15, Point2D(5, 1));
    // object_ptrs[0] = pokemon_ptrs[0];
    // pokemon_ptrs[1] = new Pokemon("Bulbasaur", 2, 'P', 1, 20, 6, 4, 15, Point2D(10, 1));
    // object_ptrs[1] = pokemon_ptrs[1];
    // center_ptrs[0] = new PokemonCenter(1, 1, 100, Point2D(1, 20));
    // object_ptrs[2] = center_ptrs[0];
    // center_ptrs[1] = new PokemonCenter(2, 2, 200, Point2D(10, 20));
    // object_ptrs[3] = center_ptrs[1];
    // gym_ptrs[0] = new PokemonGym(10, 1, 2, 3, 1, Point2D());
    // object_ptrs[4] = gym_ptrs[0];
    // gym_ptrs[1] = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5,5));
    // object_ptrs[5] = gym_ptrs[1];
    // arena_ptrs[0]= new BattleArena(3, 3, 4, 1, Point2D(16,18));
    // object_ptrs[6] = arena_ptrs[0];
    // rival_ptrs[0] = new Rival("haba", 'R', 2, 20, 3, 7, 15, 1, arena_ptrs[0]);
    // object_ptrs[7] = rival_ptrs[0];
    // rival_ptrs[1] = new Rival("chaka", 'R', 1, 25, 5, 2, 15, 2, arena_ptrs[0]);
    // object_ptrs[8] = rival_ptrs[1];
    // rival_ptrs[2] = new Rival("laka", 'R', 3, 15, 3, 8, 15, 3, arena_ptrs[0]);
    // object_ptrs[9] = rival_ptrs[2];

    //making the pointers
    Pokemon* p1 = new Pokemon("Pikachu", 1, 'P', 2, 20, 4, 6, 15, Point2D(5, 1));
    Pokemon* p2 = new Pokemon("Bulbasaur", 2, 'P', 1, 20, 6, 4, 15, Point2D(10, 1));
    PokemonCenter* pc1 = new PokemonCenter(1, 1, 100, Point2D(1, 20));
    PokemonCenter* pc2 = new PokemonCenter(2, 2, 200, Point2D(10, 20));
    PokemonGym* pg1 = new PokemonGym(10, 1, 2, 3, 1, Point2D());
    PokemonGym* pg2 = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5,5));
    BattleArena* ba1 = new BattleArena(10, 3, 4, 1, Point2D(16,18));
    Rival* r1 = new Rival("haba", 'R', 2, 20, 3, 7, 15, 1, ba1  );
    Rival* r2 = new Rival("chaka", 'R', 1, 25, 5, 2, 15, 2, ba1);
    Rival* r3 = new Rival("laka", 'R', 3, 15, 3, 8, 15, 3, ba1);

    // num_objects = 10;
    // num_pokemon = 2;
    // num_centers = 2;
    // num_gyms = 2; 
    // num_rivals = 3;
    // num_arenas = 1;

    //making the list object_ptrs and putting the pointers inside
    object_ptrs.push_back(p1);
    object_ptrs.push_back(p2);
    object_ptrs.push_back(pc1);
    object_ptrs.push_back(pc2);
    object_ptrs.push_back(pg1);
    object_ptrs.push_back(pg2);
    object_ptrs.push_back(ba1);
    object_ptrs.push_back(r1);
    object_ptrs.push_back(r2);
    object_ptrs.push_back(r3);

    
    //doing the rest of the pointers
    active_ptrs.assign(object_ptrs.begin(), object_ptrs.end());
    pokemon_ptrs.push_back(p1);
    pokemon_ptrs.push_back(p2);
    center_ptrs.push_back(pc1);
    center_ptrs.push_back(pc2);
    gym_ptrs.push_back(pg1);
    gym_ptrs.push_back(pg2);
    arena_ptrs.push_back(ba1);
    rival_ptrs.push_back(r1);
    rival_ptrs.push_back(r2);
    rival_ptrs.push_back(r3);

    o = object_ptrs.begin();
    a = active_ptrs.begin();
    p = pokemon_ptrs.begin();
    c = center_ptrs.begin();
    g = gym_ptrs.begin();
    r = rival_ptrs.begin();
    b = arena_ptrs.begin();


    cout<<"Model default constructed"<<endl;
    cout<<"Time: " <<time<<endl<<endl;

}

//Destructor
Model::~Model(){

for(o = object_ptrs.begin(); o != object_ptrs.end() ; o++){
    o = object_ptrs.erase(o);
}
    cout<<"Model destructed"<<endl;
}

//Pointer getters
Pokemon* Model::GetPokemonPtr(int id){

    //cout << "id is " <<id<< endl; 
    for(auto &poke : pokemon_ptrs){
        if(poke->GetId() == id){
            return (poke);
        }     
    }
    return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id){

    for(c =center_ptrs.begin(); c != center_ptrs.end(); c++){
        if((*c)->GetId() == id){
            return (*c);
        }
    }
    return 0;
}

PokemonGym* Model::GetPokemonGymPtr(int id){

    for(g = gym_ptrs.begin(); g != gym_ptrs.end(); g++){
        if((*g)->GetId() == id){
            return (*g);
        }
    }
    return 0; //returns 0 if none of the objects'id match the user input

}

Rival* Model::GetRivalPtr(int id){

    for(r = rival_ptrs.begin(); r != rival_ptrs.end(); r++){
        if((*r)->GetId() == id){
            return (*r);
        }
    }
    return 0;
}

BattleArena* Model::GetBattleArenaPtr(int id){

    for(b = arena_ptrs.begin(); b != arena_ptrs.end(); b++){
        if((*b)->GetId() == id){
            return (*b);
        }
    }
    return 0;
}


//Model member functions
bool Model::Update(){

    time++;
    cout<<"Time: "<<time<<endl;
    bool u;
    int count =0;
    for(b= arena_ptrs.begin(); b!=arena_ptrs.end(); b++){
        if(!((*b)->IsBeaten())){
            break;
        }
        else
        {
            count++;
        } 
        if(count == arena_ptrs.size()){
            cout<<"GAME OVER: You win! All the Battle Arenas have been beaten!\n";
            exit(0);
        } 
    }

        count = 0;
        for(p = pokemon_ptrs.begin(); p != pokemon_ptrs.end(); p++){
        if(!((*p)->isExhausted()) && ((*p)->isAlive())){
            break;
        }
        else
        {
            count++;
        } 
        if(count == pokemon_ptrs.size()){
            cout<<"GAME OVER: You lose! All of your Pokemon are exhausted/fainted!\n";
            exit(0);
        } 
    }

    for(a = active_ptrs.begin(); a != active_ptrs.end(); a++){
        u = (*a)->Update();
        if(u){
            if((*a)->GetState()== FAINTED || (*a)->GetState()== EXHAUSTED || (*a)->GetState()== BEATEN ||  (*a)->GetState()== NO_RIVALS_AVAILABLE || (*a)->GetState()== NO_STAMINA_POINTS_AVAILABLE || (*a)->GetState()== FAINTED_RIVAL){
                a = active_ptrs.erase(a);
                cout<<"Dead object removed"<<endl;
            }
            return true;
        }
    }
    return false;
}

void Model::Display(View& view){
    view.Clear();

    for(a = active_ptrs.begin(); a != active_ptrs.end(); a++){
        view.Plot(*a);
    }

    view.Draw();
}

void Model::ShowStatus(){
    for(o = object_ptrs.begin(); o != object_ptrs.end(); o++){
        (*o)->ShowStatus();
        cout<<endl;
    }
}

void Model::NewCommand(char type, int id, int x, int y){ 
        switch (type)
        {
        case 'g':
            if (GetPokemonGymPtr(id) != 0)
            {
                throw Invalid_Input("Unable to create object with same id as other object of same type!");
                // cout<<"Unable to create object with same id as other object of same type!"<<endl;
                // cout<<"Choose different id number"<<endl;
                break;
            }
            else if (id > 9)
            {
                throw Invalid_Input("Unable to create object with id bigger than 9!");
                // cout<<"Unable to create object with id bigger than 9"<<endl;
                // cout<<"Choose different id number"<<endl;
                break;
            }
            else
            {
                cout<<"Valid id!"<<endl<<"Constructing new object"<<endl;
                PokemonGym* g  = new PokemonGym(100, 2, 1, 1, id, Point2D(x,y));
                object_ptrs.push_back(g);
                active_ptrs.push_back(g);
                gym_ptrs.push_back(g);
            } 
            break;
        case 'c':
            if (GetPokemonCenterPtr(id) != 0)
            {
                throw Invalid_Input("Unable to create object with same id as other object of same type!");
                // cout<<"Unable to create object with same id as other object of same type!"<<endl;
                // cout<<"Choose different id number"<<endl;
                break;
            }
            else if (id > 9)
            {
                throw Invalid_Input("Unable to create object with id bigger than 9!");
                // cout<<"Unable to create object with id bigger than 9"<<endl;
                // cout<<"Choose different id number"<<endl;
                break;
            }
            else
            {
                cout<<"Valid id!"<<endl<<"Constructing new object"<<endl;
                PokemonCenter* c  = new PokemonCenter(id, 1, 15, Point2D(x,y));
                object_ptrs.push_back(c);
                active_ptrs.push_back(c);
                center_ptrs.push_back(c);
            } 
            break;
        case 'p':
            if (GetPokemonPtr(id) != 0)
            {
                throw Invalid_Input("Unable to create object with same id as other object of same type!");
                // cout<<"Unable to create object with same id as other object of same type!"<<endl;
                // cout<<"Choose different id number"<<endl;
                break;
            }
            else if (id > 9)
            {
                throw Invalid_Input("Unable to create object with id bigger than 9!");
                // cout<<"Unable to create object with id bigger than 9"<<endl;
                // cout<<"Choose different id number"<<endl;
                break;
            }
            else
            {
                cout<<"Valid id!"<<endl<<"Constructing new object"<<endl;
                Pokemon * p = new Pokemon("Ghost Pokemon", id, 'P', 2, 10, 3, 5, 15, Point2D(x,y));
                object_ptrs.push_back(p);
                active_ptrs.push_back(p);
                pokemon_ptrs.push_back(p);
            } 
            break;
        case 'r':
            if (GetRivalPtr(id) != 0)
            {
                throw Invalid_Input("Unable to create object with same id as other object of same type!");
                // cout<<"Unable to create object with same id as other object of same type!"<<endl;
                // cout<<"Choose different id number"<<endl;
                break;
            }
            else if (id > 9)
            {
                throw Invalid_Input("Unable to create object with id bigger than 9!");
                // cout<<"Unable to create object with id bigger than 9"<<endl;
                // cout<<"Choose different id number"<<endl;
                break;
            }
            else
            {
                cout<<"Valid id!"<<endl<<"Constructing new object"<<endl;
                Rival * r = new Rival("Ghost Rival", 'R', 2, 10, 4, 4, 15, id, *(arena_ptrs.begin()));
                object_ptrs.push_back(r);
                active_ptrs.push_back(r);
                rival_ptrs.push_back(r);
            } 
            break;   
        default:
            throw Invalid_Input("No such type of object");
            // cout<<"No such type of object"<<endl;
            break;
        }
}