#include "SeniorManager.h"

void SeniorManager::calc() {
    int totalBudgetPart = 0;
    for (const auto &p : projects) {
        totalBudgetPart += calcBudgetPart(0.15f, static_cast<int>(p.budget));
    }
    payment = totalBudgetPart + calcHeads();
}

void SeniorManager::printInfo() const {
    cout << format("Старший менеджер: {} | Зарплата: {}\n", name, payment);
}

int SeniorManager::calcBudgetPart(const float part, const int budget) {
    return static_cast<int>(part * budget);
}
