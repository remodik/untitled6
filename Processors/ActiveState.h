#ifndef ACTIVE_STATE_H
#define ACTIVE_STATE_H

#include "State.h"
#include <iostream>

#include "Agent.h"
#include "IdleState.h"

class ActiveState final : public State {
public:
    void handleEvent(Agent &agent, const string &eventDetails) override {
        cout << "Active agent handling event: " << eventDetails << endl;
        agent.changeState(make_shared<IdleState>());
    }

    string getStateName() const override {
        return "Active";
    }
};

#endif
