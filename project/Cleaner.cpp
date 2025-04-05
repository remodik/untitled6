#include "Cleaner.h"

void Cleaner::calc() {
    const int basePayment = calcBase(salary, worktime);
    int overtimePayment = 0;
    if (worktime > 40) {
        overtimePayment = (worktime - 40) * static_cast<int>(salary * 0.5);
    }
    payment = basePayment + overtimePayment;
}

void Cleaner::printInfo() const {
    cout << format("Уборщик: {} | Зарплата: {}\n", name, salary);
}
