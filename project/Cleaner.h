#ifndef CLEANER_H
#define CLEANER_H
#include "Personal.h"

class Cleaner : public Personal {
public:
    Cleaner(int id, const string& name, int salary);
    int calcBonus() override;
};

#endif
