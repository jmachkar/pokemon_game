
#ifndef BUILDING_H
#define BUILDING_H
#include "gameobject.h"

class Building : public GameObject {
    private:
    unsigned int pokemon_count;

    public:
    Building();
    Building(char in_code, int in_id, Point2D in_loc);

    ~Building();

    void AddOnePokemon();
    void RemoveOnePokemon();
    void ShowStatus();
    bool ShouldBeVisible();

    friend class PokemonCenter;
    friend class PokemonGym;

};

#endif
