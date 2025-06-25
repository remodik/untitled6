#include <gtest/gtest.h>
#include "Employee.h"
#include "../src/Employee.h"

// Фикстура (необязательно), когда нужно разделяемое состояние
class EmployeeTest : public ::testing::Test {
protected:
    Employee emp {1, "Ivan", "programmer"};
};

TEST_F(EmployeeTest, ConstructorSetsFieldsCorrectly) {
    EXPECT_EQ(emp.getFirstName(), "Иван");
    EXPECT_EQ(emp.getLastName(), "Иванов");
    EXPECT_EQ(emp.getSalary(), 1000);
}

TEST(EmployeeLogicTest, GiveRaiseIncreasesSalary) {
    Employee e{"Пётр", "Петров", 2000};
    e.giveRaise(500);
    ASSERT_EQ(e.getSalary(), 2500);
}

// … другие тесты
