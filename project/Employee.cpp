#include "Employee.h"

Employee::Employee(const int id, const string& name, const string& position) : id(id), name(name), position(position), worktime(0), payment(0) {}

void Employee::setWorkTime(const int hours) {
    worktime = hours;
}

void Employee::printInfo() const {
    cout << id << "\t" << name << "\t" << position << "\t" << worktime << "\t" << payment << endl;
}

int Employee::getId() const {
    return id;
}
string Employee::getName() const {
    return name;
}
string Employee::getPosition() const {
    return position;
}
int Employee::getWorkTime() const {
    return worktime;
}
int Employee::getPayment() const {
    return payment;
}