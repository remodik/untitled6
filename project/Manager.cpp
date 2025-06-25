#include "src/Manager.h"

int ProjectManager::calcBudgetPart(float, const int budget) {
    return static_cast<int>(budget * 0.15);
}

int ProjectManager::calcHeads() {
    return 50000;
}

void ProjectManager::calc() {
    int total = 0;
    for (auto* p : projects) {
        total += calcBudgetPart(0.15f, p->budget);
    }
    payment = total + calcHeads();
}

void ProjectManager::printInfo() const {
    cout << id << "\t" << name << "\tProjectManager\t" << worktime << "\t" << payment << endl;
}

int SeniorManager::calcBudgetPart(float, const int budget) {
    return static_cast<int>(budget * 0.05);
}

int SeniorManager::calcHeads() {
    return 60000;
}

void SeniorManager::calc() {
    int total = 0;
    for (const auto* p : projects) {
        total += calcBudgetPart(0.05f, p->budget);
    }
    payment = total + calcHeads();
}

void SeniorManager::printInfo() const {
    cout << id << "\t" << name << "\tSeniorManager\t" << worktime << "\t" << payment << endl;
}