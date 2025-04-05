#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <format>

using namespace std;

class Employee {
protected:
    int id;
    string name;
    string position;
    int worktime;
    double payment;

public:
    virtual ~Employee() = default;

    Employee(const int id, string name, string position) :
    id(id), name(std::move(name)), position(std::move(position)), worktime(0), payment(0) {}
    virtual void setWorkTime(const int hours) { worktime = hours; }
    virtual void calc() = 0;
    virtual void printInfo() const = 0;

};

#endif