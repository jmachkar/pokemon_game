#ifndef MODEL_H
#define MODEL_H
#include "pokemon.h"
#include "view.h"
#include <stdlib.h>
#include <list>

class Model{
    private:

    int time;
    // template <class T>;

    // GameObject* object_ptrs[10];
    // int num_objects;
    // Pokemon* pokemon_ptrs[10];
    // int num_pokemon;
    // PokemonCenter* center_ptrs[10];
    // int num_centers;
    // PokemonGym* gym_ptrs[10];
    // int num_gyms;
    // Rival* rival_ptrs[10];
    // int num_rivals;
    // BattleArena * arena_ptrs[10];
    // int num_arenas;

    list<GameObject*>object_ptrs;
    list<GameObject*>active_ptrs;
    list<Pokemon*>pokemon_ptrs;
    list<PokemonCenter*>center_ptrs;
    list<PokemonGym*>gym_ptrs;
    list<Rival*>rival_ptrs;
    list<BattleArena*>arena_ptrs;
    
    list<GameObject*> :: iterator o;
    list<GameObject*> :: iterator a;
    list<Pokemon*> :: iterator p;
    list<PokemonCenter*> :: iterator c;
    list<PokemonGym*> :: iterator g;
    list<Rival*> :: iterator r;
    list<BattleArena*> :: iterator b;



    public:

    Model();
    ~Model();
    Pokemon* GetPokemonPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    Rival* GetRivalPtr(int id);
    BattleArena* GetBattleArenaPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
    void NewCommand(char type, int id, int x, int y);


};

#endif