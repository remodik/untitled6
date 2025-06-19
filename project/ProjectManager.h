#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include "Manager.h"

class ProjectManager : public Manager {
public:
    ProjectManager(int id, const std::string& name);
    int calcHeads() override;
};

#endif
