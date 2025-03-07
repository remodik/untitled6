#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <format>

using namespace std;

class Employee{
protected:
    int id{};
    string name;
    string position;
    double workTime{};
    double paymant{};
public:
    ~Employee() = default;

    void setWorkTime();
    virtual void calc() = 0;
    virtual void printInfo() const = 0;

};

#endif