#include "PublicTransport.h"

PublicTransport::PublicTransport(
    const int cap,
    const double spd,
    const int wheels,
    const int route,
    const double price
    ) : LandTransport(cap, spd, wheels), routeNumber(route), ticketPrice(price) {}

double PublicTransport::calculateRevenue(const int passengers) const {
    return passengers * ticketPrice;
}

void PublicTransport::getInfo() {
    LandTransport::getInfo();
    cout << format("Маршрут: {0}, Цена билета: {1} руб.", routeNumber, ticketPrice) << endl;
}
