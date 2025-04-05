#ifndef SENIORMANAGER_H
#define SENIORMANAGER_H

#include "ProjectManager.h"

class SeniorManager final : public ProjectManager {
public:
    using ProjectManager::ProjectManager;
    void calc() override;
    void printInfo() const override;

private:
    static int calcBudgetPart(float part, int budget);
};

#endif
