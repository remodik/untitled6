#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "Engineer.h"

class Programmer : public Engineer {
public:
    Programmer(const int id, const string &name, const double salary, const Project project)
        : Engineer(id, name, salary, project) {}

    int calcProAdditions() override;
};

#endif