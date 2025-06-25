#include "src/Employee.h"

void Employee::printInfo() const {
    cout << id << "\t" << name << "\t" << position << "\t" << worktime << "\t" << payment << endl;
}