#ifndef PESONAL_H
#define PESONAL_H
#include "Employee.h"

class Personal : public Employee {
protected:
    int salary{};
public:
    void calcBase(...);
};



#endif
