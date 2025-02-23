//
// Created by slend on 21.02.2025.
//

#include "Archer.h"

void Archer::shoot(Character &target) const {
    const int damage = rand() % 100 < accuracy ? strength : 0;
    target.takeDamage(damage);
}
