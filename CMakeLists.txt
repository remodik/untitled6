cmake_minimum_required(VERSION 3.30)
project(untitled6)

file(GLOB SOURCES
        "project/*.h"
        "project/*.cpp"
)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled6 ${SOURCES} project/main.cpp)
