//
// Created by slend on 23.02.2025.
//

#ifndef SATELLITE_H
#define SATELLITE_H
#include <iostream>
#include <format>
using namespace std;

class Satellite {
    double orbitHeight{};
    double weight{};
    double powerConsumption{};
public:
    Satellite(
        const double orbitHeight,
        const double weight,
        const double powerConsumption
        )
    : orbitHeight(orbitHeight), weight(weight), powerConsumption(powerConsumption) {};
    void getStatus() const;
};



#endif //SATELLITE_H
