#ifndef PROJECTBUDGET_H
#define PROJECTBUDGET_H

class ProjectBudget {
public:
    virtual ~ProjectBudget() = default;

    virtual int calcBudgetPart(float part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

#endif
