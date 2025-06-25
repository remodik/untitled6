cmake_minimum_required(VERSION 3.14)
project(MyCompanyProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(core
        Employee.cpp
)

