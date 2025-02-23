#ifndef PUBLICTRANSPORT_H
#define PUBLICTRANSPORT_H
#include "LandTransport.h"

class PublicTransport : public LandTransport {
protected:
    int routeNumber;
    double ticketPrice;
public:
    PublicTransport(int cap, double spd, int wheels, int route, double price);
    double calculateRevenue(int passengers) const;
    void getInfo();
};

#endif
