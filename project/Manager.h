#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
#include "Interfaces.h"
#include "Project.h"
#include <vector>

class ProjectManager : public Employee, public ProjectBudget, public Heading {
protected:
    vector<Project*> projects;

public:
    ProjectManager(int id, const string& name, const string& position);
    void addProject(Project* prj);

    int calcBudgetPart(double part, int budget) override;

    int calcProAdditions() override;

    int calcHeads() override;
    void calc() override;
};

class SeniorManager : public ProjectManager {
public:
    SeniorManager(int id, const string& name, const string& position);
    void calc() override;
};

#endif
