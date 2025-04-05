#ifndef TEAMLEADER_H
#define TEAMLEADER_H
#include "Programmer.h"
#include "Heading.h"

class TeamLeader final : public Programmer, public Heading {
public:
    TeamLeader(const int id, const string &name, const double salary, const Project project)
        : Programmer(id, name, salary, project) {}

    int calcHeads() override;
    void calc() override;
    void printInfo() const override;
};

#endif
