#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <vector>

using namespace std;

class Employee {
protected:
    int id;
    string name;
    string position;
    int worktime;
    int payment;

public:
    Employee(int id, const string& name, const string& position);
    virtual ~Employee() = default;

    void setWorkTime(int hours);
    virtual void calc() = 0;
    virtual void printInfo() const;

    int getId() const;
    string getName() const;
    string getPosition() const;
    int getWorkTime() const;
    int getPayment() const;
};

#endif
