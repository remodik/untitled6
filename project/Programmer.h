#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "Engineer.h"

class Programmer : public Engineer {
public:
    Programmer(int id, const string& name, int salary);
    int calcProAdditions() override;
};

#endif