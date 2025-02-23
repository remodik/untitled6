#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
    int damage;
    int durability;
public:
    Weapon(const int _damage, const int _durability) : damage(_damage), durability(_durability) {}

    int getDamage() const;
    void attack();
};

#endif
