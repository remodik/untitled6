#include "Personal.h"

Personal::Personal(const int id, const string& name, const string& position, const int salary)
    : Employee(id, name, position), salary(salary) {}

int Personal::calcBase(const int salary, const int worktime) {
    return salary * worktime;
}

int Personal::calcBonus() {
    return 0;
}

void Personal::calc() {
    payment = calcBase(salary, worktime) + calcBonus();
}

Cleaner::Cleaner(const int id, const string& name, const int salary)
    : Personal(id, name, "Cleaner", salary) {}

Driver::Driver(const int id, const string& name, const int salary)
    : Personal(id, name, "Driver", salary) {}

int Driver::calcBonus() {
    const int nightHours = static_cast<int>(worktime * 0.2);
    return static_cast<int>(salary * 0.5 * nightHours);
}