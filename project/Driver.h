#ifndef DRIVER_H
#define DRIVER_H
#include "Personal.h"

class Driver : public Personal {
public:
    Driver(int id, const std::string& name, int salary);
    int calcBonus() override;
};


#endif
