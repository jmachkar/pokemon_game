#ifndef RIVAL_H
#define RIVAL_H
#include "battlearena.h"

enum RivalStates{
    ALIVE_RIVAL = 0,
    FAINTED_RIVAL = 1
};

class Rival : public GameObject {
    protected: //variables

    string name;
    double speed;
    double health;
    double physical_damage;
    double magical_damage;
    double defense;
    bool is_in_arena;
    BattleArena * current_arena;

    public:
    
    Rival(string in_name, char in_code, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int id, BattleArena * arena);
    void TakeHit(double phys_dmg, double magic_dmg, double def);
    double get_phys_dmg();
    double get_magic_dmg();
    double get_defense();
    double get_health();
    string GetName();
    double GetSpeed();
    bool Update();
    void ShowStatus();
    bool isAlive();
    bool ShouldBeVisible();
    ~Rival();
    void set_health(double hp);

};

#endif