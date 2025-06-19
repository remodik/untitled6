#include <iostream>
#include <string>
#include <vector>

// Перечисление для ролей сотрудников
enum Position {
    PROJECT_MANAGER,
    SENIOR_MANAGER,
    TEAM_LEADER,
    ENGINEER,
    PROGRAMMER,
    TESTER,
    DRIVER,
    CLEANER
};

// Абстрактный класс Heading
class Heading {
public:
    virtual int calcHeads() = 0;
    virtual ~Heading() {}
};

// Абстрактный класс WorkBaseTime
class WorkBaseTime {
public:
    virtual int calcBase(int salary, int wtime) = 0;
    virtual int calcBonus() = 0;
    virtual ~WorkBaseTime() {}
};

// Абстрактный класс ProjectBudget
class ProjectBudget {
public:
    virtual int calcBudgetPart(float part, int budget) = 0;
    virtual ~ProjectBudget() {}
};

// Абстрактный класс Project
class Project {
protected:
    int id;
public:
    Project(int id) : id(id) {}
    virtual int calcProAdditions() = 0;
    virtual ~Project() {}
};

// Базовый класс Employee
class Employee {
protected:
    int id;
    std::string name;
    Position position;
    int worktime;
    double payment;
public:
    Employee(int id, std::string name, Position pos, int worktime, double payment)
        : id(id), name(name), position(pos), worktime(worktime), payment(payment) {}
    virtual ~Employee() {}
    void setWorkTime(int time) { worktime = time; }
    virtual void calc() = 0;
    virtual void printInfo() = 0;
};

// Класс Personal, наследуется от Employee
class Personal : public Employee {
protected:
    double salary;
public:
    Personal(int id, std::string name, Position pos, int worktime, double payment, double salary)
        : Employee(id, name, pos, worktime, payment), salary(salary) {}
    virtual int calcBase() = 0;
};

// Класс Engineer, наследуется от Personal
class Engineer : public Personal {
protected:
    ProjectBudget* budget;
public:
    Engineer(int id, std::string name, Position pos, int worktime, double payment, double salary, ProjectBudget* budget)
        : Personal(id, name, pos, worktime, payment, salary), budget(budget) {}
    virtual int calcBudgetPart(float part, int budget) { return this->budget->calcBudgetPart(part, budget); }
    virtual void calc() = 0;
    virtual ~Engineer() { delete budget; }
};

// Класс Programmer, наследуется от Engineer
class Programmer : public Engineer {
public:
    Programmer(int id, std::string name, Position pos, int worktime, double payment, double salary, ProjectBudget* budget)
        : Engineer(id, name, pos, worktime, payment, salary, budget) {}
    void calc() override {
        payment = calcBase() + calcProAdditions();
    }
    int calcProAdditions() {
        return 500; // Доплата за сложность задач
    }
    int calcBase() override {
        return static_cast<int>(salary * worktime);
    }
    void printInfo() override {
        std::cout << "Programmer ID: " << id << ", Name: " << name << ", Payment: " << payment << std::endl;
    }
};

// Класс Tester, наследуется от Engineer
class Tester : public Engineer {
public:
    Tester(int id, std::string name, Position pos, int worktime, double payment, double salary, ProjectBudget* budget)
        : Engineer(id, name, pos, worktime, payment, salary, budget) {}
    void calc() override {
        payment = calcBase() + calcProAdditions();
    }
    int calcProAdditions() {
        return 400; // Доплата за количество найденных багов
    }
    int calcBase() override {
        return static_cast<int>(salary * worktime);
    }
    void printInfo() override {
        std::cout << "Tester ID: " << id << ", Name: " << name << ", Payment: " << payment << std::endl;
    }
};

// Класс Driver, наследуется от Personal
class Driver : public Personal {
public:
    Driver(int id, std::string name, Position pos, int worktime, double payment, double salary)
        : Personal(id, name, pos, worktime, payment, salary) {}
    void calc() override {
        payment = calcBase() + calcBonus();
    }
    int calcBase() override {
        return static_cast<int>(salary * worktime);
    }
    int calcBonus() {
        return 200; // Бонус за количество поездок
    }
    void printInfo() override {
        std::cout << "Driver ID: " << id << ", Name: " << name << ", Payment: " << payment << std::endl;
    }
};

// Класс Cleaner, наследуется от Personal
class Cleaner : public Personal {
public:
    Cleaner(int id, std::string name, Position pos, int worktime, double payment, double salary)
        : Personal(id, name, pos, worktime, payment, salary) {}
    void calc() override {
        payment = calcBase();
    }
    int calcBase() override {
        return static_cast<int>(salary * worktime);
    }
    void printInfo() override {
        std::cout << "Cleaner ID: " << id << ", Name: " << name << ", Payment: " << payment << std::endl;
    }
};

// Класс ProjectManager, наследуется от Employee и Heading
class ProjectManager : public Employee, public Heading {
protected:
    Project* project;
public:
    ProjectManager(int id, std::string name, Position pos, int worktime, double payment, Project* proj)
        : Employee(id, name, pos, worktime, payment), project(proj) {}
    ~ProjectManager() { delete project; }
    void calc() override {
        payment = 1000 + calcHeads() * 100; // Зарплата зависит от количества подчиненных
    }
    int calcHeads() override {
        return 5; // Пример: 5 подчиненных
    }
    void printInfo() override {
        std::cout << "ProjectManager ID: " << id << ", Name: " << name << ", Payment: " << payment << std::endl;
    }
};

// Класс SeniorManager, наследуется от ProjectManager
class SeniorManager : public ProjectManager {
protected:
    std::vector<Project*> projects;
public:
    SeniorManager(int id, std::string name, Position pos, int worktime, double payment, Project* proj, std::vector<Project*> projs)
        : ProjectManager(id, name, pos, worktime, payment, proj), projects(projs) {}
    ~SeniorManager() {
        for (auto p : projects) delete p;
    }
    void calc() override {
        payment = 2000 + projects.size() * 500; // Зарплата зависит от количества проектов
    }
    void printInfo() override {
        std::cout << "SeniorManager ID: " << id << ", Name: " << name << ", Payment: " << payment << std::endl;
    }
};

// Класс TeamLeader, наследуется от Employee и Heading
class TeamLeader : public Employee, public Heading {
public:
    TeamLeader(int id, std::string name, Position pos, int worktime, double payment)
        : Employee(id, name, pos, worktime, payment) {}
    void calc() override {
        payment = 800 + calcHeads() * 50; // Зарплата зависит от количества подчиненных
    }
    int calcHeads() override {
        return 10; // Пример: 10 подчиненных
    }
    void printInfo() override {
        std::cout << "TeamLeader ID: " << id << ", Name: " << name << ", Payment: " << payment << std::endl;
    }
};

// Конкретный класс Project
class ConcreteProject : public Project {
public:
    ConcreteProject(int id) : Project(id) {}
    int calcProAdditions() override {
        return 1000; // Дополнительные выплаты за проект
    }
};

// Конкретный класс ProjectBudget
class ConcreteProjectBudget : public ProjectBudget {
public:
    int calcBudgetPart(float part, int budget) override {
        return static_cast<int>(part * budget); // Часть бюджета
    }
};

// Главная функция
int main() {
    ProjectBudget* budget = new ConcreteProjectBudget();
    Project* proj1 = new ConcreteProject(1);
    Project* proj2 = new ConcreteProject(2);

    std::vector<Employee*> employees;
    employees.push_back(new Programmer(1, "Alice", PROGRAMMER, 40, 0, 50.0, budget));
    employees.push_back(new Tester(2, "Bob", TESTER, 35, 0, 45.0, budget));
    employees.push_back(new Driver(3, "Charlie", DRIVER, 20, 0, 30.0));
    employees.push_back(new Cleaner(4, "David", CLEANER, 25, 0, 20.0));
    employees.push_back(new ProjectManager(5, "Eve", PROJECT_MANAGER, 40, 0, proj1));
    employees.push_back(new SeniorManager(6, "Frank", SENIOR_MANAGER, 40, 0, proj2, {proj1, proj2}));
    employees.push_back(new TeamLeader(7, "Grace", TEAM_LEADER, 40, 0));

    for (auto emp : employees) {
        emp->calc();
        emp->printInfo();
    }

    for (auto emp : employees) delete emp;
    return 0;
}