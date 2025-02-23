cmake_minimum_required(VERSION 3.30)
project(untitled6)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled6 main.cpp
        q1/Transport.cpp
        q1/Transport.h
        q1/LandTransport.cpp
        q1/LandTransport.h
        q1/PublicTransport.cpp
        q1/PublicTransport.h
        q1/ElectricBus.cpp
        q1/ElectricBus.h
        q2/Weapon.h
        q2/Character.cpp
        q2/Character.h
        q2/Warrior.cpp
        q2/Warrior.h
        q2/Archer.cpp
        q2/Archer.h
        q2/EliteKnight.cpp
        q2/EliteKnight.h
        q2/Weapon.cpp
        Processors/Resourse_manager.h
        Processors/Query_processor.h
        Processors/ConcreteQueryProcessors.h
        Processors/QueryProcessorFactory.h
        Processors/Logger.h
        Processors/State.h
        Processors/Event.h
        Processors/Agent.h
        Processors/ConcreteAgent.h
        Processors/IdleState.h
        Processors/ActiveState.h
        Processors/AgentDecorator.h
        Processors/ThreadPoolT.h
        Processors/ThreadPool.h
        Processors/mainT.txt
        q3/Satellite.cpp
        q3/Satellite.h
        q3/CommunicationSatellite.cpp
        q3/CommunicationSatellite.h
        q3/ScientificSatellite.cpp
        q3/ScientificSatellite.h
        q3/AutonomousResearchSatellite.cpp
        q3/AutonomousResearchSatellite.h)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/q1
        ${CMAKE_CURRENT_SOURCE_DIR}/q2
        ${CMAKE_CURRENT_SOURCE_DIR}/q3
)
