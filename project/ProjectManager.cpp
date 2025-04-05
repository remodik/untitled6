#include "ProjectManager.h"

int ProjectManager::calcHeads() {
    int headBonus = 2000;
    if (projects.size() > 1) {
        headBonus += static_cast<int>((projects.size() - 1) * 500);
    }
    return headBonus;
}

void ProjectManager::calc() {
    int totalBudgetPart = 0;
    for (const auto &p : projects) {
        totalBudgetPart += static_cast<int>(0.2 * p.budget);
    }
    payment = totalBudgetPart + calcHeads();
}

void ProjectManager::printInfo() const {
    cout << format("Менеджер проекта: {} | Payment: {}\n", name, payment);
}
