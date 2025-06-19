cmake_minimum_required(VERSION 3.30)
project(untitled6)

file(GLOB SOURCES
        "q1/*.cpp"
        "q2/*.cpp"
        "q3/*.cpp"
        "q1/*.h"
        "q2/*.h"
        "q3/*.h"
        "Processors/*.cpp"
        "Processors/*.h"
        "project/*.h"
        "project/*.cpp"
)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled6 ${SOURCES} project/main.cpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/q1
        ${CMAKE_CURRENT_SOURCE_DIR}/q2
        ${CMAKE_CURRENT_SOURCE_DIR}/q3
)
