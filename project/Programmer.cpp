#include "Programmer.h"

int Programmer::calcProAdditions() {
    int addition = 1000;
    if (worktime > 40) {
        addition += 300;
    }
    return addition;
}
