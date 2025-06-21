#include "Personal.h"

Personal::Personal(const int id, const string& name, const string& position, const int salary)
    : Employee(id, name, position), salary(salary) {}

double Personal::calcBase(const int salary, const int worktime) {
    return salary * worktime;
}

double Personal::calcBonus() {
    return 0;
}

void Personal::calc() {
    payment = calcBase(salary, worktime) + calcBonus();
}

Cleaner::Cleaner(const int id, const string& name, const int salary)
    : Personal(id, name, "Cleaner", salary) {}

double Cleaner::calcBase() {
    return 0;
}

Driver::Driver(const int id, const string& name, const int salary)
    : Personal(id, name, "Driver", salary), nightHours(0) {
}

double Driver::calcBase() {
    nightHours = static_cast<int>(worktime * 0.2);
    return salary * 0.5 * nightHours;
}
