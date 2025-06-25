#include "Employee.h"
#include "Factory.h"
#include <iostream>
#include <vector>
#include "Engineer.h"
#include "Manager.h"
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <format>

void printAll(const vector<Employee*>& staff) {
    cout << left
              << setw(5) << "ID"
              << setw(20) << "Name"
              << setw(20) << "Position"
              << setw(10) << "Worktime"
              << setw(15) << "Payment"
              << "\n";

    cout << setfill('-')
              << setw(5) << ""
              << setw(20) << ""
              << setw(20) << ""
              << setw(10) << ""
              << setw(15) << ""
              << "\n"
              << setfill(' ');

    for (const auto* emp : staff) {
        cout << left
                  << setw(5) << emp->getId()
                  << setw(20) << emp->getName()
                  << setw(20) << emp->getPosition()
                  << setw(10) << emp->getWorktime()
                  << setw(15) << emp->getPayment()
                  << "\n";
    }
}

void findByProject(const vector<Employee*>& staff, const string& project) {
    cout << "Employees on project " << project << ":\n";
    for (auto* emp : staff) {
        if (const auto e = dynamic_cast<Engineer*>(emp)) {
            if (e->getProject() && e->getProject()->name == project) {
                emp->printInfo();
            }
        } else if (const auto m = dynamic_cast<Manager*>(emp)) {
            for (const auto* p : m->getProjects()) {
                if (p->name == project) {
                    emp->printInfo();
                    break;
                }
            }
        }
    }
}

void findByPosition(const vector<Employee*>& staff, const string& position) {
    cout << "Employees with position " << position << ":\n";
    for (const auto* emp : staff) {
        if (emp->getPosition() == position) {
            emp->printInfo();
        }
    }
}

void findByName(const vector<Employee*>& staff, const string& name) {
    cout << format("Employees with name {0}:\n", name);

    string lowerName = name;
    ranges::transform(lowerName, lowerName.begin(), ::tolower);

    for (const auto* emp : staff) {
        string empName = emp->getName();
        ranges::transform(empName, empName.begin(), ::tolower);

        if (empName.rfind(lowerName, 0) == 0) emp->printInfo();
    }
}

void createProject() {
    string name;
    int budget;

    cout << "Enter project name: ";
    getline(cin, name);
    cout << "Enter project budget: ";
    cin >> budget;
    cin.ignore();

    const auto newProject = new Project{name, budget};
    StaffFactory::addProject(newProject);
    cout << "Project " << name << " created successfully.\n";
}

void addEmployeeToProject(const vector<Employee*>& staff) {
    int id;
    string projectName;

    cout << "Enter employee ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter project name: ";
    getline(cin, projectName);

    Project* project = StaffFactory::getProject(projectName);
    if (!project) {
        cout << "Project not found.\n";
        return;
    }

    for (auto* emp : staff) {
        if (emp->getId() == id) {
            if (auto* engineer = dynamic_cast<Engineer*>(emp)) {
                engineer->setProject(project);
                cout << "Employee " << emp->getName() << " added to project " << projectName << ".\n";
            } else {
                cout << "Employee " << emp->getName() << " cannot be added to a project.\n";
            }
            return;
        }
    }
    cout << "Employee not found.\n";
}

void transferEmployeeToProject(const vector<Employee*>& staff) {
    int id;
    string newProjectName;

    cout << "Enter employee ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter new project name: ";
    getline(cin, newProjectName);

    Project* newProject = StaffFactory::getProject(newProjectName);
    if (!newProject) {
        cout << "Project not found.\n";
        return;
    }

    for (auto* emp : staff) {
        if (emp->getId() == id) {
            if (auto* engineer = dynamic_cast<Engineer*>(emp)) {
                engineer->setProject(newProject);
                cout << "Employee " << emp->getName() << " transferred to project " << newProjectName << ".\n";
            } else {
                cout << "Employee " << emp->getName() << " cannot be transferred to a project.\n";
            }
            return;
        }
    }
    cout << "Employee not found.\n";
}

void findBySalary(const vector<Employee*>& staff, const int threshold, const bool greater) {
    cout << "Employees with salary " << (greater ? "> " : "< ") << threshold << ":\n";
    for (const auto* emp : staff) {
        if ((greater && emp->getPayment() > threshold) ||
            (!greater && emp->getPayment() < threshold)) {
            emp->printInfo();
        }
    }
}

int main() {
    vector<Employee*> staff;
    const string filename = "staff.txt";

    try {
        staff = StaffFactory::makeStaff(filename);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    for (auto* emp : staff) {
        emp->setWorkTime(160);
    }

    for (auto* emp : staff) {
        emp->calc();
    }

    string command;
    while (true) {
        cout << "\nCommands: all, project, position, name, salary, create_project, add_to_project, transfer_project, save, exit\n> ";
        getline(cin, command);

        if (command == "exit") break;

        if (command == "all") {
            printAll(staff);
        } else if (command == "project") {
            cout << "Enter project name: ";
            string project;
            getline(cin, project);
            findByProject(staff, project);
        } else if (command == "position") {
            cout << "Enter position: ";
            string position;
            getline(cin, position);
            findByPosition(staff, position);
        } else if (command == "name") {
            cout << "Enter name: ";
            string name;
            getline(cin, name);
            findByName(staff, name);
        } else if (command == "salary") {
            cout << "Enter threshold: ";
            int threshold;
            cin >> threshold;
            cin.ignore();
            cout << "Greater (1) or less (0)? ";
            bool greater;
            cin >> greater;
            cin.ignore();
            findBySalary(staff, threshold, greater);
        } else if (command == "create_project") {
            createProject();
        } else if (command == "add_to_project") {
            addEmployeeToProject(staff);
        } else if (command == "transfer_project") {
            transferEmployeeToProject(staff);
        } else if (command == "save") {
            StaffFactory::saveToFile(filename, staff);
            cout << "Data saved to " << filename << endl;
        }
    }

    for (const auto* emp : staff) delete emp;
}