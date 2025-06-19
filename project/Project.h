#ifndef PROJECT_H
#define PROJECT_H

struct Project {
    string name;
    int budget;
    Project(const string& n, int b) : name(n), budget(b) {}
};

#endif
