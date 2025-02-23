#ifndef ELECTRICBUS_H
#define ELECTRICBUS_H
#include "PublicTransport.h"

class ElectricBus : public PublicTransport {
    double batteryCapacity;
    double chargeTime;
public:
    ElectricBus(int cap, double spd, int wheels, int route, double price, double battery, double charge);
    double calculateEnergyConsumption(double distance) const;
    void getInfo();
};

#endif