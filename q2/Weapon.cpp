//
// Created by slend on 21.02.2025.
//
#include "Weapon.h"

void Weapon::attack() {
    if (durability > 0) {
        durability--;
    }
}

int Weapon::getDamage() const {return damage;}
