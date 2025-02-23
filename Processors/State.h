#ifndef STATE_H
#define STATE_H

#include <string>

class Agent;
using namespace std;
class State {
public:
    virtual ~State() = default;
    virtual void handleEvent(Agent &agent, const string &eventDetails) = 0;
    virtual string getStateName() const = 0;
};

#endif
