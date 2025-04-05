#ifndef TESTER_H
#define TESTER_H
#include "Engineer.h"

class Tester final : public Engineer {
public:
    Tester(const int id, const string &name, const double salary, const Project project)
    : Engineer(id, name, salary, project) {}

    int calcProAdditions() override;
};

#endif
