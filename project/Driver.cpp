#include "Driver.h"

void Driver::calc() {
    payment = calcBase(salary, worktime) + calcBonus();
}

int Driver::calcBonus() {
    int bonus = 1000;
    if (worktime > 40) {
        bonus += 200;
    }
    return bonus;
}

void Driver::printInfo() const {
    cout << format("Водитель: {} | Зарплата: {}", name, payment) << endl;
}
