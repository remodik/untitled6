#ifndef FACTORY_H
#define FACTORY_H
#include <map>
#include <vector>
#include "Employee.h"
#include "Project.h"

class StaffFactory {
    static map<string, Project*> projects;

public:
    static vector<Employee*> makeStaff(const string& filename);
    static void saveToFile(const string& filename, const vector<Employee*>& staff);
    static Project* getProject(const string& name);
    static void addProject(Project* prj);
};

#endif
