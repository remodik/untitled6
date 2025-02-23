#ifndef AGENT_DECORATOR_H
#define AGENT_DECORATOR_H

#include "Agent.h"
#include <iostream>

class AgentDecorator : public Agent {
protected:
    shared_ptr<Agent> decoratedAgent;

public:
    explicit AgentDecorator(const std::shared_ptr<Agent> &agent) : decoratedAgent(agent) {}

    void changeState(const std::shared_ptr<State> newState) override {decoratedAgent->changeState(newState);}

    void handleEvent(const Event &event) override {decoratedAgent->handleEvent(event);}

    void performAction() override {decoratedAgent->performAction();}
};

class ShieldedAgent final : public AgentDecorator {
public:
    explicit ShieldedAgent(const shared_ptr<Agent> &agent) : AgentDecorator(agent) {}

    void performAction() override {
        cout << "Shielded agent performing action with extra defense!" << endl;
        decoratedAgent->performAction();
    }
};

#endif
