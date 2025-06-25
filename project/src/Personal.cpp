#include "Personal.h"

int Driver::calcBonus() {
    return static_cast<int>(calcBase(salary, worktime) * 0.2);
}

void Cleaner::printInfo() const {
    cout << id << "\t" << name << "\tCleaner\t" << worktime << "\t" << payment << endl;
}

void Driver::printInfo() const {
    cout << id << "\t" << name << "\tDriver\t" << worktime << "\t" << payment << endl;
}

int Cleaner::calcBonus() {
    return static_cast<int>(calcBase(salary, worktime) * 0.15);
}
