#ifndef PERSONAL_H
#define PERSONAL_H
#include "Interfaces.h"
#include "Employee.h"

class Personal : public Employee, public WorkBaseTime {
protected:
    int salary;

public:
    Personal(int id, const string& name, const string& position, int salary);

    int calcBase(int salary, int worktime) override;
    int calcBonus() override;
    void calc() override;
};

class Cleaner : public Personal {
public:
    Cleaner(int id, const string& name, int salary);
};

class Driver : public Personal {
public:
    Driver(int id, const string& name, int salary);
    int calcBonus() override;
};

#endif
