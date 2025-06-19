#ifndef TEAMLEADER_H
#define TEAMLEADER_H
#include "Programmer.h"
#include "Heading.h"

class TeamLeader : public Programmer, public Heading {
    int programmersCount;
public:
    TeamLeader(int id, const string& name, int salary);
    void setProgrammersCount(int count);
    int calcHeads() override;
    void calc() override;
};

#endif
