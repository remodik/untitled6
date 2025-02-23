#include "Transport.h"

Transport::Transport(const int cap, const double spd): capacity(cap), speed(spd) {}

void Transport::getInfo() {
    cout << format("Макс. пассажиров: {}\n", capacity);
    cout << format("Скорость: {} км/ч\n", speed);
}
