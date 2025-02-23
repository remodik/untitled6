#include "Character.h"
#include "Weapon.h"

void Character::takeDamage(const int amount) {
    health -= amount;
    if (health <= 0) health = 0;
}

string Character::getName() {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getStrength() const {
    return strength;
}


void Character::attack(Character &target, Weapon &weapon) {
    target.takeDamage(weapon.getDamage());
    weapon.attack();
}

