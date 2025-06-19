#ifndef ENGINEER_H
#define ENGINEER_H
#include "Employee.h"
#include "Project.h"
#include "Interfaces.h"

class Engineer : public Employee, public WorkBaseTime, public ProjectBudget {
protected:
    int salary;
    Project* project;

public:
    Engineer(int id, const string& name, const string& position, int salary);
    virtual ~Engineer() = default;

    void setProject(Project* prj);
    void calc() override;
    int calcBase(int salary, int worktime) override;
    int calcBonus() override;
    virtual int calcBudgetPart(float part, int budget) override;
    virtual int calcProAdditions() override = 0;
};

#endif
