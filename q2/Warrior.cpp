//
// Created by slend on 21.02.2025.
//

#include "Warrior.h"

void Warrior::blockDamage(const int amount) {
    int reduceDamage = amount - armor;
    if (reduceDamage < 0) reduceDamage = 0;
    takeDamage(reduceDamage);
}
