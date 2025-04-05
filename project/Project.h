#ifndef PROJECT_H
#define PROJECT_H

class Project {
public:
    int id;
    double budget;
    Project(const int id, const double budget) : id(id), budget(budget) {}
};

#endif
