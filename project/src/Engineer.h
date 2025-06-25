#ifndef ENGINEER_H
#define ENGINEER_H
#include "Employee.h"
#include "Project.h"

class Engineer : public Employee, public WorkBaseTime, public ProjectBudget {
protected:
    int salary;
    Project* project;

public:
    Engineer(const int id, string name, string position, const int salary)
        : Employee(id, std::move(name), std::move(position)), salary(salary), project(nullptr) {}

    int calcBase(const int salary, const int wtime) override {
        return salary * wtime;
    }
    int calcBonus() override { return 0; }
    void setProject(Project* prj) { project = prj; }
    Project* getProject() const { return project; }
};

class Programmer : public Engineer {
public:
    Programmer(const int id, string name, const int salary)
        : Engineer(id, std::move(name), "programmer", salary) {}

    int calcBonus() override { return 0; }
    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    void calc() override;
    void printInfo() const override;
};

class Tester final : public Engineer {
public:
    Tester(const int id, string name, const int salary): Engineer(id, std::move(name), "tester", salary) {}

    int calcBonus() override { return 0; }
    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    void calc() override;
    void printInfo() const override;
};

class TeamLeader final : public Programmer, public Heading {
public:
    TeamLeader(const int id, string name, const int salary) : Programmer(id, std::move(name), salary) {
        position = "team_leader";
    }

    int calcHeads() override;
    void calc() override;
    void printInfo() const override;
};

#endif