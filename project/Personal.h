#ifndef PERSONAL_H
#define PERSONAL_H

#include "Employee.h"

class Personal : public Employee {
public:
    Personal(int id, std::string name, Position pos, int salary) : Employee(id, name, pos, salary) {}
    int calcBase(int s, int w) override;
    int calcBonus() override;
    void calc() override;
    void printInfo() override;
};

class Cleaner : public Personal {
public:
    Cleaner(int id, std::string name, int salary) : Personal(id, name, CLEANER, salary) {}
};

class Driver : public Personal {
public:
    Driver(int id, std::string name, int salary)
        : Personal(id, name, DRIVER, salary) {}
    int calcBonus() override;
};

#endif