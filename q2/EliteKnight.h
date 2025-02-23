//
// Created by slend on 21.02.2025.
//

#ifndef ELITEKNIGHT_H
#define ELITEKNIGHT_H
#include "Warrior.h"


class EliteKnight : public Warrior{
    int specialAttackPower;
public:
    EliteKnight(
        string _name,
        const int _health,
        const int _strength,
        const int _armor,
        const int _specAttPower)
    : Warrior(_name, _health, _strength, _armor), specialAttackPower(_specAttPower) {}

    void useSpecialAttack(Character &target);
};



#endif //ELITEKNIGHT_H
