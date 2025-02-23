//
// Created by slend on 21.02.2025.
//

#ifndef LANDTRANSPORT_H
#define LANDTRANSPORT_H
#include "Transport.h"
using namespace std;

class LandTransport : public Transport {
protected:
    int numWheels;
public:
    LandTransport(int cap, double spd, int wheels);
    void getInfo();
};

#endif