#include "Manager.h"

ProjectManager::ProjectManager(const int id, const string& name, const string& position)
    : Employee(id, name, position) {}

void ProjectManager::addProject(Project* prj) {
    projects.push_back(prj);
}

int ProjectManager::calcBudgetPart(const double part, const int budget) {
    return static_cast<int>(part * budget);
}

int ProjectManager::calcProAdditions() {
    int total = 0;
    for (const Project* project : projects) {
        total += static_cast<int>(0.05 * project->budget);
    }
    return total;
}

int ProjectManager::calcHeads() {
    return 0;
}

void ProjectManager::calc() {
    int total = 0;
    for (const Project* project : projects) {
        total += calcBudgetPart(0.1, project->budget);
    }
    total += calcHeads();
    payment = total;
}

SeniorManager::SeniorManager(const int id, const string& name, const string& position)
    : ProjectManager(id, name, position) {}

void SeniorManager::calc() {
    int total = 0;
    for (const Project* project : projects) {
        total += calcBudgetPart(0.05, project->budget);
    }
    total += calcHeads();
    payment = total;
}