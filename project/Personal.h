#ifndef PESONAL_H
#define PESONAL_H

#include "Employee.h"
#include "WorkBaseTime.h"


class Personal : public Employee, public WorkBaseTime {
protected:
    double salary;
public:
    Personal(const int id, const string &name, const string &position, const double salary)
        : Employee(id, name, position), salary(salary) {}

    int calcBase(int salary, int wtime) override;
    int calcBonus() override;
};

#endif
