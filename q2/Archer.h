//
// Created by slend on 21.02.2025.
//

#ifndef ARCHER_H
#define ARCHER_H
#include "Character.h"

class Archer : public Character {
protected:
    int accuracy;
public:
    Archer(
        string _name,
        const int _health,
        const int _strength,
        const int _armor
        )
    : Character(_name, _health, _strength), accuracy(_armor) {};

    void shoot(Character &target) const;
};



#endif //ARCHER_H
