#ifndef CONCRETE_AGENT_H
#define CONCRETE_AGENT_H

#include "Agent.h"
#include <iostream>
#include <memory>
#include <vector>

class ConcreteAgent final : public Agent {
public:
    explicit ConcreteAgent(const shared_ptr<State> &initialState) : currentState(initialState) {}

    void changeState(const shared_ptr<State> newState) override {
        currentState = newState;
        cout << "Agent changed to state: " << currentState->getStateName() << endl;
    }

    void handleEvent(const Event &event) override {
        currentState->handleEvent(*this, event.getEventDetails());
    }

    void performAction() override {
        cout << "Agent is performing action in state: " << currentState->getStateName() << endl;
    }

private:
    shared_ptr<State> currentState;
};

#endif
