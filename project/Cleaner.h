#ifndef CLEANER_H
#define CLEANER_H
#include "Personal.h"

class Cleaner final : public Personal {
public:
    Cleaner(const int id, const string &name, const double salary) : Personal(id, name, "Уборщик", salary) {}

    void calc() override;
    void printInfo() const override;
};

#endif
