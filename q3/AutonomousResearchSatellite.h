//
// Created by slend on 23.02.2025.
//

#ifndef AUTONOMOUSRESEARCHSATELLITE_H
#define AUTONOMOUSRESEARCHSATELLITE_H
#include <iostream>
#include <format>

#include "ScientificSatellite.h"
using namespace std;

class AutonomousResearchSatellite : public ScientificSatellite {
    string aiVersion;
    bool selfRepairCapability;
public:
    AutonomousResearchSatellite(
        const double orbitHeight,
        const double weight,
        const double powerConsumption,
        const string &sensorType,
        const string &researchField,
        const string &aiVersion,
        const bool selfRepairCapability
        )
    : ScientificSatellite(orbitHeight, weight, powerConsumption, sensorType, researchField),
    aiVersion(aiVersion), selfRepairCapability(selfRepairCapability) {}

    void selfRepair() const;
    void getStatus() const;
};



#endif
