#ifndef INTERFACES_H
#define INTERFACES_H

class WorkBaseTime {
public:
    virtual double calcBase() = 0;
    virtual double calcBonus() = 0;
    virtual ~WorkBaseTime() = default;
};

class ProjectBudget {
public:
    virtual int calcBudgetPart() = 0;
    virtual int calcProAdditions() = 0;
    virtual ~ProjectBudget() = default;
};

class Heading {
public:
    virtual int calcHeads() = 0;
    virtual ~Heading() = default;
};

#endif
