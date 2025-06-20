#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Project.h"

using namespace std;

void addEmployeeToProject(const vector<Employee*>& staff, vector<Project>& projects) {
    cout << "Enter employee ID: ";
    int empId;
    cin >> empId;
    cin.ignore();

    cout << "Enter project name: ";
    string projectName;
    getline(cin, projectName);

    Employee* foundEmp = nullptr;
    for (const auto emp : staff) {
        if (emp->getId() == empId) {
            foundEmp = emp;
            break;
        }
    }

    if (!foundEmp) {
        cout << "Employee not found!" << endl;
        return;
    }

    Project* targetProject = nullptr;
    for (auto& prj : projects) {
        if (prj.name == projectName) {
            targetProject = &prj;
            break;
        }
    }

    if (!targetProject) {
        cout << "Project not found!" << endl;
        return;
    }

    if (const string position = foundEmp->getPosition(); position == "Programmer" || position == "Tester" || position == "TeamLeader") {
        if (const auto engineer = dynamic_cast<Engineer*>(foundEmp)) {
            engineer->setProject(targetProject);
            engineer->calc();
            cout << "Engineer added to project successfully!" << endl;
        }
    }
    else if (position == "ProjectManager" || position == "SeniorManager") {
        if (const auto manager = dynamic_cast<ProjectManager*>(foundEmp)) {
            manager->addProject(targetProject);
            manager->calc();
            cout << "Manager added to project successfully!" << endl;
        }
    }
    else {
        cout << "This employee type cannot be assigned to projects!" << endl;
    }
}

void printMenu() {
    cout << "\n========== Staff Management System ==========\n";
    cout << "1. Show all employees\n";
    cout << "2. Show project employees\n";
    cout << "3. Search by position\n";
    cout << "4. Search by name\n";
    cout << "5. Search by salary (>)\n";
    cout << "6. Search by salary (<)\n";
    cout << "7. Create project\n";
    cout << "8. Add employee to project\n";
    cout << "9. Change employee's project\n";
    cout << "10. Save & Exit\n";
    cout << "Enter your choice (1-10): ";
}

void assignToProject(Employee* emp, Project* prj) {
    if (const auto engineer = dynamic_cast<Engineer*>(emp)) {
        engineer->setProject(prj);
    } else if (const auto manager = dynamic_cast<ProjectManager*>(emp)) {
        manager->addProject(prj);
    } else {
        cout << "This employee type cannot be assigned to projects.\n";
    }
}

Project* findProject(const vector<Project>& projects, const string& name) {
    for (auto& prj : projects) {
        if (prj.name == name) return const_cast<Project*>(&prj);
    }
    return nullptr;
}

vector<Employee*> findProjectEmployees(const vector<Employee*>& staff,
                                     const string& projectName) {
    vector<Employee*> result;

    for (auto emp : staff) {
        if (string position = emp->getPosition(); position == "Programmer" ||
                                                  position == "Tester" ||
                                                  position == "TeamLeader" ||
                                                  position == "ProjectManager" ||
                                                  position == "SeniorManager") {
            result.push_back(emp);
            }
    }

    return result;
}

int main() {
    vector<Employee*> staff;
    vector<Project> projects;

    try {
        staff = StaffFactory::makeStaff("staff.txt");
        cout << "Loaded " << staff.size() << " employees from file.\n";
    } catch (const exception& e) {
        cerr << "Error loading staff: " << e.what() << endl;
        return 1;
    }

    if (projects.empty()) {
        projects.push_back({"Alpha", 1000000});
        projects.push_back({"Beta", 750000});
        projects.push_back({"Gamma", 500000});
    }

    for (const auto emp : staff) {
        emp->setWorkTime(160);
        emp->calc();
    }

    int choice;
    do {
        printMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "\n=== All Employees ===\n";
                cout << "ID\tName\t\tPosition\t\tWorktime\tPayment\n";
                cout << "--------------------------------------------------------\n";
                for (const auto emp : staff) {
                    emp->printInfo();
                }
                break;
            }
            case 2: {
                string projectName;
                cout << "Enter project name: ";
                getline(cin, projectName);

                auto projectStaff = findProjectEmployees(staff, projectName);
                if (projectStaff.empty()) {
                    cout << "No project employees found.\n";
                } else {
                    cout << "=== Project Employees ===\n";
                    for (const auto emp : projectStaff) {
                        emp->printInfo();
                    }
                }
                break;
            }
            case 3: {
                string position;
                cout << "Enter position to search: ";
                getline(cin, position);

                cout << "\n=== Employees with Position " << position << " ===\n";
                bool found = false;
                for (const auto emp : staff) {
                    if (emp->getPosition() == position) {
                        emp->printInfo();
                        found = true;
                    }
                }
                if (!found) cout << "No employees found with position " << position << "\n";
                break;
            }
            case 4: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);

                cout << "\n=== Employees Matching \"" << name << "\" ===\n";
                bool found = false;
                for (const auto emp : staff) {
                    if (emp->getName().find(name) != string::npos) {
                        emp->printInfo();
                        found = true;
                    }
                }
                if (!found) cout << "No employees found matching \"" << name << "\"\n";
                break;
            }
            case 5: {
                int salary;
                cout << "Enter minimum salary: ";
                cin >> salary;

                cout << "\n=== Employees Earning > $" << salary << " ===\n";
                bool found = false;
                for (const auto emp : staff) {
                    if (emp->getPayment() > salary) {
                        emp->printInfo();
                        found = true;
                    }
                }
                if (!found) cout << "No employees earn more than $" << salary << "\n";
                break;
            }
            case 6: {
                int salary;
                cout << "Enter maximum salary: ";
                cin >> salary;

                cout << "\n=== Employees Earning < $" << salary << " ===\n";
                bool found = false;
                for (const auto emp : staff) {
                    if (emp->getPayment() < salary) {
                        emp->printInfo();
                        found = true;
                    }
                }
                if (!found) cout << "No employees earn less than $" << salary << "\n";
                break;
            }
            case 7: {
                string name;
                int budget;
                cout << "Enter new project name: ";
                getline(cin, name);
                cout << "Enter project budget: $";
                cin >> budget;

                projects.push_back({name, budget});
                cout << "Project '" << name << "' created with budget $" << budget << "\n";
                break;
            }
            case 8: {
                addEmployeeToProject(staff, projects);
                break;
            }
            case 9: {
                int empId;
                string newProjectName;
                cout << "Enter employee ID to change project: ";
                cin >> empId;
                cin.ignore();

                auto it = ranges::find_if(staff,
                                          [empId](const Employee* e) { return e->getId() == empId; });

                if (it == staff.end()) {
                    cout << "Employee with ID " << empId << " not found.\n";
                    break;
                }

                cout << "Enter new project name: ";
                getline(cin, newProjectName);

                Project* newPrj = findProject(projects, newProjectName);
                if (!newPrj) {
                    cout << "Project '" << newProjectName << "' not found.\n";
                    break;
                }

                assignToProject(*it, newPrj);
                (*it)->calc();
                cout << "Employee " << (*it)->getName() << " moved to project " << newProjectName << "\n";
                break;
            }
            case 10: {
                try {
                    StaffFactory::saveStaff("staff_updated.txt", staff);
                    cout << "Data saved successfully. Exiting...\n";
                } catch (const exception& e) {
                    cerr << "Error saving data: " << e.what() << endl;
                }

                for (const auto emp : staff) delete emp;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 10.\n";
            }
        }
    } while (true);
}