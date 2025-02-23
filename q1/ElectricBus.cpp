#include "ElectricBus.h"

ElectricBus::ElectricBus(
    const int cap,
    const double spd,
    const int wheels,
    const int route,
    const double price,
    const double battery,
    const double charge
    ) : PublicTransport(cap, spd, wheels, route, price), batteryCapacity(battery), chargeTime(charge) {}

double ElectricBus::calculateEnergyConsumption(const double distance) const {
    return (batteryCapacity / 300.0) * distance;
}

void ElectricBus::getInfo() {
    PublicTransport::getInfo();
    cout << format("Батарея: {0} кВт·ч, Время зарядки: {1} ч", batteryCapacity, chargeTime) << endl;
}