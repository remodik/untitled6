#ifndef SENIORMANAGER_H
#define SENIORMANAGER_H
#include "ProjectManager.h"

class SeniorManager : public ProjectManager {
protected:
    ~SeniorManager() = default;

    double projects[];
};

#endif
