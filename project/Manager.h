#pragma once
#include "Employee.h"
#include "Interfaces.h"
#include "Project.h"
#include <vector>

class Manager : public Employee, public ProjectBudget, public Heading {
protected:
    vector<Project*> projects;

public:
    Manager(const int id, string name, string position) : Employee(id, std::move(name), std::move(position)) {}

    void addProject(Project* prj) { projects.push_back(prj); }
    const vector<Project*>& getProjects() const {
        return projects;
    }
};

class ProjectManager final : public Manager {
public:
    ProjectManager(const int id, string name) : Manager(id, std::move(name), "project_manager") {}

    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override { return 0; }
    int calcHeads() override;
    void calc() override;
    void printInfo() const override;
};

class SeniorManager final : public Manager {
public:
    SeniorManager(const int id, string name) : Manager(id, std::move(name), "senior_manager") {}

    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override { return 0; }
    int calcHeads() override;
    void calc() override;
    void printInfo() const override;
};