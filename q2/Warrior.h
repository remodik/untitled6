//
// Created by slend on 21.02.2025.
//

#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"


class Warrior : public Character {
protected:
    int armor{};
public:
    Warrior(
        string _name,
        const int _health,
        const int _strength,
        const int _armor)
    : Character(_name, _health, _strength), armor(_armor) {}

    void blockDamage(int amount);

};



#endif //WARRIOR_H
