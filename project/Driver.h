#ifndef DRIVER_H
#define DRIVER_H
#include "Personal.h"
class Driver final : public Personal {
public:
    Driver(const int id, const string &name, const double salary) : Personal(id, name, "Водитель", salary) {}

    int calcBonus() override;
    void calc() override;
    void printInfo() const override;
};

#endif
