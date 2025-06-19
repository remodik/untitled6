#include "Employee.h"
#include <iostream>
#include <iomanip>

Employee::Employee(int id, const string& name, const string& position) : id(id), name(name), position(position), worktime(0), payment(0) {}

void Employee::setWorkTime(int hours) { 
    worktime = hours; 
}

void Employee::printInfo() const {
    cout << setw(5) << id << setw(20) << name << setw(15) << position
    << setw(6) << worktime << "h" << setw(10) << payment << " руб.\n";
}

int Employee::getId() const { return id; }
string Employee::getName() const { return name; }
string Employee::getPosition() const { return position; }
int Employee::getPayment() const { return payment; }