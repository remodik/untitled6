#include "Employee.h"
#include "Cleaner.h"
#include "Driver.h"
#include "Project.h"
#include "Engineer.h"
#include "ProjectManager.h"
#include "SeniorManager.h"
#include "TeamLeader.h"

int main() {
    // Создаем уборщика и рассчитываем оплату с учетом сверхурочных
    Cleaner cleaner(1, "John", 15);
    cleaner.setWorkTime(45);
    cleaner.calc();
    cleaner.printInfo();

    // Создаем водителя с переработкой
    Driver driver(2, "Alex", 20);
    driver.setWorkTime(42);
    driver.calc();
    driver.printInfo();

    // Создаем проект и инженера, работающего над ним
    const Project project1(101, 120000);
    Engineer engineer(3, "Mike", 25, project1);
    engineer.setWorkTime(40);
    engineer.calc();
    engineer.printInfo();

    // Создаем менеджера проекта с несколькими проектами
    std::vector<Project> projects = { Project(201, 80000), Project(202, 150000) };
    ProjectManager pm(4, "Sara", projects);
    pm.setWorkTime(40); // если нужно учитывать рабочее время, можно добавить дополнительную логику
    pm.calc();
    pm.printInfo();

    return 0;
}