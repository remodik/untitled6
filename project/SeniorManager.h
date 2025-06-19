#ifndef SENIORMANAGER_H
#define SENIORMANAGER_H
#include "Manager.h"

class SeniorManager : public Manager {
public:
    SeniorManager(int id, const string& name);
    int calcHeads() override;
};

#endif
