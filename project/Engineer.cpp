#include "Engineer.h"

Engineer::Engineer(const int id, const string& name, const string& position, const int salary)
    : Personal(id, name, position, salary), project(nullptr) {}

void Engineer::setProject(Project* prj) {
    project = prj;
}

int Engineer::calcBudgetPart(const double part, const int budget) {
    return static_cast<int>(part * budget);
}

void Engineer::calc() {
    const int base = calcBase(salary, worktime);
    const int bonus = calcBonus();
    const int proAdditions = calcProAdditions();
    payment = base + bonus + proAdditions;
}

Programmer::Programmer(const int id, const string& name, const int salary)
    : Engineer(id, name, "Programmer", salary) {}

int Programmer::calcProAdditions() {
    if (project) {
        return calcBudgetPart(0.1, project->budget);
    }
    return 0;
}

Tester::Tester(const int id, const string& name, const int salary)
    : Engineer(id, name, "Tester", salary) {}

int Tester::calcProAdditions() {
    return 0;
}

TeamLeader::TeamLeader(const int id, const string& name, const int salary)
    : Engineer(id, name, "TeamLeader", salary) {}

int TeamLeader::calcProAdditions() {
    if (project) {
        return static_cast<int>(0.05 * project->budget);
    }
    return 0;
}

int TeamLeader::calcHeads() {
    return 0;
}

void TeamLeader::calc() {
    const int base = calcBase(salary, worktime);
    const int bonus = calcBonus();
    const int proAdditions = calcProAdditions();
    const int heads = calcHeads();
    payment = base + bonus + proAdditions + heads;
}