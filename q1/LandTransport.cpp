#include "LandTransport.h"

LandTransport::LandTransport(
    const int cap,
    const double spd,
    const int wheels
    ) : Transport(cap, spd), numWheels(wheels) {}

void LandTransport::getInfo() {
    Transport::getInfo();
    cout << format("Кол-во колёс: {}\n", numWheels);
}