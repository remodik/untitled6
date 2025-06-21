#ifndef ENGINEER_H
#define ENGINEER_H
#include "Personal.h"
#include "Interfaces.h"
#include "Project.h"

class Engineer : public Personal, public ProjectBudget, public WorkBaseTime {
protected:
    Project* project{};
    double salary;
public:
    Engineer(int id, const string& name, const string& position, int salary);
    void setProject(Project* prj);

    static int calcBudgetPart(double part, int budget);
    int calcProAdditions() override = 0;
    void calc() override;
};

class Programmer : public Engineer {
public:
    Programmer(int id, const string& name, int salary);
    int calcProAdditions() override;
};

class Tester : public Engineer {
public:
    Tester(int id, const string& name, int salary);
    int calcProAdditions() override;
};

class TeamLeader : public Engineer, public Heading {
public:
    TeamLeader(int id, const string& name, int salary);
    int calcProAdditions() override;
    int calcHeads() override;
    void calc() override;
};

#endif
