#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Weapon.h"
using namespace std;

class Character {
protected:
    string name;
    int health;
    int strength;
public:
    Character(
        string _name,
        const int _health,
        const int _strength
        )
    : name(_name), health(_health), strength(_strength) {}

    void takeDamage(int amount);
    string getName();
    int getHealth() const;
    int getStrength() const;

    void attack(Character &target, Weapon &weapon);
};


#endif
