add_executable(unit_tests
        EmployeeTest.cpp
)

target_link_libraries(unit_tests
        PRIVATE
        core
        GTest::gtest_main
)

target_include_directories(unit_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

add_test(NAME all_unit_tests COMMAND unit_tests)
