#ifndef IDLE_STATE_H
#define IDLE_STATE_H

#include "State.h"
#include <iostream>
#include <memory>
#include "ActiveState.h"
#include "Agent.h"

class IdleState final : public State {
public:
    void handleEvent(Agent &agent, const string &eventDetails) override {
        cout << "Idle agent handling event: " << eventDetails << endl;
        agent.changeState(make_shared<ActiveState>());
    }

    string getStateName() const override {
        return "Idle";
    }
};

#endif
