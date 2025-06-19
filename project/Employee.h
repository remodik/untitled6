#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Interfaces.h"

enum Position { CLEANER, DRIVER, PROGRAMMER, TESTER, TEAMLEADER, PROJECTMANAGER, SENIORMANAGER };

class Employee : public WorkBaseTime {
protected:
    int id;
    std::string name;
    Position position;
    int salary;
    int worktime;
    int payment;
public:
    Employee(int id, std::string name, Position pos, int salary)
        : id(id), name(name), position(pos), salary(salary), worktime(0), payment(0) {}
    virtual void calc() = 0;
    virtual void printInfo() = 0;
    void setWorkTime(int time) { worktime = time; }
    int getId() const { return id; }
    std::string getName() const { return name; }
    Position getPosition() const { return position; }
    int getSalary() const { return salary; }
    int getWorkTime() const { return worktime; }
    int getPayment() const { return payment; }
    virtual ~Employee() {}
};

#endif