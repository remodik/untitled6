#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <utility>
#include "Interfaces.h"

using namespace std;

class Employee {
protected:
    int id;
    string name;
    int worktime;
    int payment;
    string position;

public:
    Employee(const int id, string name, string position)
        : id(id), name(std::move(name)), worktime(0), payment(0), position(std::move(position)) {}

    virtual void setWorkTime(const int wt) { worktime = wt; }
    virtual void calc() = 0;
    virtual void printInfo() const = 0;
    virtual ~Employee() = default;

    int getId() const { return id; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    int getWorktime() const { return worktime; }
    int getPayment() const { return payment; }
};

#endif