#ifndef ENGINEER_H
#define ENGINEER_H
#include "ProjectBudget.h"
#include "Personal.h"
#include "Project.h"

class Engineer : public Personal, public ProjectBudget {
protected:
    Project project;
public:
    Engineer(const int id, const string &name, const double salary, const Project project)
    : Personal(id, name, "Engineer", salary), project(project) {}

    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    void calc() override;
    void printInfo() const override;
};



#endif
