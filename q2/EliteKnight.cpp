//
// Created by slend on 21.02.2025.
//

#include "EliteKnight.h"

void EliteKnight::useSpecialAttack(Character &target) {
    target.takeDamage(specialAttackPower);
}
