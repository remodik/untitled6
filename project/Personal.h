#ifndef PERSONAL_H
#define PERSONAL_H
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
protected:
    int salary;

public:
    Personal(const int id, string name, string position, const int salary)
        : Employee(id, std::move(name), std::move(position)), salary(salary) {}

    int calcBase(const int salary, const int wtime) override {
        return salary * wtime;
    }

    void calc() override {
        payment = calcBase(salary, worktime) + calcBonus();
    }
};

class Cleaner final : public Personal {
public:
    Cleaner(const int id, string name, const int salary) : Personal(id, std::move(name), "cleaner", salary) {}

    void calc() override {
        payment = static_cast<int>(calcBase(salary, worktime) * 0.1);
    }
    int calcBonus() override;
    void printInfo() const override;
};

class Driver final : public Personal {
public:
    Driver(const int id, string name, const int salary) : Personal(id, std::move(name), "driver", salary) {}

    int calcBonus() override;
    void printInfo() const override;
};

#endif