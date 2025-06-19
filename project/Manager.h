#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
#include "Interfaces.h"
#include <vector>
#include "Project.h"

class Manager : public Employee, public ProjectBudget, public Heading {
protected:
    vector<Project*> projects;
    vector<Employee*> team;

public:
    Manager(int id, const string& name, const string& position);
    virtual ~Manager() = default;

    void addProject(Project* prj);
    void addTeamMember(Employee* emp);
    void calc() override;
    virtual int calcBudgetPart(float part, int budget) override;
    virtual int calcProAdditions() override;
    virtual int calcHeads() override = 0;
};

#endif
