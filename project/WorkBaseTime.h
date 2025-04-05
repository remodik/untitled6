#ifndef WORKBASETIME_H
#define WORKBASETIME_H

class WorkBaseTime {
public:
    virtual ~WorkBaseTime() = default;

    virtual int calcBase(int salary, int wtime) = 0;
    virtual int calcBonus() = 0;
};

#endif
