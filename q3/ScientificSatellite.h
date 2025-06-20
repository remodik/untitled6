#ifndef SCIENTIFICSATELLITE_H
#define SCIENTIFICSATELLITE_H
#include <iostream>
#include <format>

#include "Satellite.h"
using namespace std;

class ScientificSatellite : public Satellite {
protected:
    string sensorType;
    string researchField;
public:
    ScientificSatellite(
        const double orbitHeight,
        const double weight,
        const double powerConsumption,
        const string &sensorType,
        const string &researchField
        )
    : Satellite(orbitHeight, weight, powerConsumption), sensorType(sensorType), researchField(researchField) {}

    void collectData() const;
    void getStatus() const;
};



#endif
