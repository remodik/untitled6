#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include "Employee.h"

class ProjectManager : public Employee {
protected:
    ~ProjectManager() = default;

    int projects[1] = {};
public:
    void calcHeads();
    void calc() override;
};

#endif
