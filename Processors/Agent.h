#ifndef AGENT_H
#define AGENT_H

#include "State.h"
#include "Event.h"
#include <memory>

class Agent {
public:
    virtual ~Agent() = default;

    virtual void changeState(shared_ptr<State> newState) = 0;
    virtual void handleEvent(const Event &event) = 0;
    virtual void performAction() = 0;
};

#endif
