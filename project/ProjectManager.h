#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include "Employee.h"
#include "Heading.h"
#include "Project.h"

class ProjectManager : public Employee, public Heading {
protected:
    vector<Project> projects;
public:
    ProjectManager(const int id, const string &name, const vector<Project> &projects)
        : Employee(id, name, "ProjectManager"), projects(projects) {}

    int calcHeads() override;
    void calc() override;

    void printInfo() const override;
};

#endif
