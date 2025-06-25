#include "src/Engineer.h"

int Programmer::calcBudgetPart(float, const int budget) {
    return static_cast<int>(budget * 0.1);
}

int Programmer::calcProAdditions() {
    return static_cast<int>(calcBase(salary, worktime) * 0.05);
}

void Programmer::calc() {
    const int base = calcBase(salary, worktime);
    const int budgetPart = project ? calcBudgetPart(0.1f, project->budget) : 0;
    const int additions = calcProAdditions();
    payment = base + budgetPart + additions;
}

void Programmer::printInfo() const {
    cout << id << "\t" << name << "\tProgrammer\t" << worktime << "\t" << payment << endl;
}

int Tester::calcBudgetPart(float, int budget) {
    return static_cast<int>(budget * 0.05);
}

int Tester::calcProAdditions() {
    return 10000;
}

void Tester::calc() {
    const int base = calcBase(salary, worktime);
    const int budgetPart = project ? calcBudgetPart(0.05f, project->budget) : 0;
    const int additions = calcProAdditions();
    payment = base + budgetPart + additions;
}

void Tester::printInfo() const {
    cout << id << "\t" << name << "\tTester\t" << worktime << "\t" << payment << endl;
}

int TeamLeader::calcHeads() {
    return 25000;
}

void TeamLeader::calc() {
    Programmer::calc();
    payment += calcHeads();
}

void TeamLeader::printInfo() const {
    cout << id << "\t" << name << "\tTeamLeader\t" << worktime << "\t" << payment << endl;
}