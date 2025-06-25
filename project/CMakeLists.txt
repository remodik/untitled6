cmake_minimum_required(VERSION 3.14)
project(MyCompanyProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(core
        src/Employee.cpp
)
target_include_directories(core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

include(FetchContent)

set(BUILD_GMOCK     OFF CACHE BOOL "Disable GoogleMock" FORCE)
set(BUILD_GTEST     ON  CACHE BOOL "Enable GoogleTest" FORCE)
set(INSTALL_GTEST   OFF CACHE BOOL "Disable install targets" FORCE)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(tests)
