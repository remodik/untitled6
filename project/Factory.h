#ifndef FACTORY_H
#define FACTORY_H
#include "Employee.h"

class StaffFactory {
public:
    static vector<Employee*> makeStaff(const string& filename);
    static void saveStaff(const string& filename, const vector<Employee*>& staff);
};

#endif
