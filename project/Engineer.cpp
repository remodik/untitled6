#include "Engineer.h"

int Engineer::calcBudgetPart(const float part, const int budget) {
    return static_cast<int>(part * budget);
}

int Engineer::calcProAdditions() {
    return 500;
}


void Engineer::calc() {
    const int budgetPart = calcBudgetPart(0.1f, static_cast<int>(project.budget));
    int performanceBonus = calcProAdditions();
    if (project.budget > 100000) {
        performanceBonus += 500;
    }
    payment = budgetPart + performanceBonus;
}

void Engineer::printInfo() const {
    cout << format("Инженер: {} | Зарплата: {}", name, payment)<< endl;
}
