#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <iostream>
#include <format>

using namespace std;

class Transport {
protected:
    int capacity;
    double speed;
public:
    Transport(int cap, double spd);
    void getInfo();
    ~Transport();
};



#endif