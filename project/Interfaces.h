#ifndef INTERFACES_H
#define INTERFACES_H

class WorkBaseTime {
public:
    virtual int calcBase(int salary, int worktime) = 0;
    virtual int calcBonus() = 0;
    virtual ~WorkBaseTime() = default;
};

class ProjectBudget {
public:
    virtual int calcBudgetPart(double part, int budget) = 0;
    virtual int calcProAdditions() = 0;
    virtual ~ProjectBudget() = default;
};

class Heading {
public:
    virtual int calcHeads() = 0;
    virtual ~Heading() = default;
};

#endif
