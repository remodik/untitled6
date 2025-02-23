//
// Created by slend on 23.02.2025.
//

#ifndef COMMUNICATIONSATELLITE_H
#define COMMUNICATIONSATELLITE_H
#include "Satellite.h"
#include <iostream>
#include <format>
using namespace std;

class CommunicationSatellite : public Satellite {
    double frequencyRange{};
    double dataRate{};
public:
    CommunicationSatellite(
        const double orbitHeight,
        const double weight,
        const double powerConsumption,
        const double frequencyRange,
        const double dataRate
        )
    : Satellite(orbitHeight, weight, powerConsumption), frequencyRange(frequencyRange), dataRate(dataRate) {}

    void transmitData() const;
    void getStatus() const;
};



#endif //COMMUNICATIONSATELLITE_H
