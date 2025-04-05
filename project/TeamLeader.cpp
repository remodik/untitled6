#include "TeamLeader.h"

int TeamLeader::calcHeads() {
    return 1500;
}

void TeamLeader::calc() {
    const int projectPart = calcBudgetPart(0.12f, static_cast<int>(project.budget));
    payment = projectPart + calcHeads();
}

void TeamLeader::printInfo() const {
    cout << format("Руководитель команды: {} | Зарплата: {}\n", name, payment);
}
