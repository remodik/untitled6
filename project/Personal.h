#ifndef PERSONAL_H
#define PERSONAL_H
#include "Interfaces.h"
#include "Employee.h"

class Personal : public Employee, public WorkBaseTime {
protected:
    int salary;
    int nightBonus = 1000;
public:
    Personal(int id, const string& name, const string& position, int salary);

    static double calcBase(int salary, int worktime);
    double calcBonus() override;
    void calc() override;
};

class Cleaner final : public Personal {
public:
    Cleaner(int id, const string& name, int salary);

    double calcBase() override;
};

class Driver final : public Personal {
    int nightHours;
public:
    Driver(const int id, const string &name, const string &position, const int salary, const int night_hours)
        : Personal(id, name, position, salary),
          nightHours(night_hours) {
    }

    Driver(int id, const string &name, int salary);

    void setNightHours(const int hours) {
        nightHours = hours;
    }
    double calcBonus() override {
        return nightBonus * nightHours;
    }

    double calcBase() override;
};

#endif
