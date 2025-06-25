#include "Factory.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include <fstream>
#include <sstream>

using namespace std;

map<string, Project*> StaffFactory::projects;

Project* StaffFactory::getProject(const string& name) {
    const auto it = projects.find(name);
    return (it != projects.end()) ? it->second : nullptr;
}

void StaffFactory::addProject(Project* prj) {
    projects[prj->name] = prj;
}

vector<Employee*> StaffFactory::makeStaff(const string& filename) {
    vector<Employee*> staff;
    ifstream file(filename);
    if (!file) throw runtime_error("File not found");

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ';')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 4) continue;

        int id = stoi(tokens[0]);
        string name = tokens[1];
        string position = tokens[2];
        int salary = tokens[3].empty() ? 0 : stoi(tokens[3]);

        Employee* emp = nullptr;
        if (position == "cleaner") {
            emp = new Cleaner(id, name, salary);
        } else if (position == "driver") {
            emp = new Driver(id, name, salary);
        } else if (position == "programmer") {
            emp = new Programmer(id, name, salary);
        } else if (position == "tester") {
            emp = new Tester(id, name, salary);
        } else if (position == "team_leader") {
            emp = new TeamLeader(id, name, salary);
        } else if (position == "project_manager") {
            emp = new ProjectManager(id, name);
        } else if (position == "senior_manager") {
            emp = new SeniorManager(id, name);
        }

        if (emp && tokens.size() > 4 && !tokens[4].empty()) {
            if (auto engineer = dynamic_cast<Engineer*>(emp)) {
                engineer->setProject(getProject(tokens[4]));
            } else if (auto manager = dynamic_cast<Manager*>(emp)) {
                istringstream projectStream(tokens[4]);
                string projectName;
                while (getline(projectStream, projectName, ',')) {
                    if (Project* p = getProject(projectName)) {
                        manager->addProject(p);
                    }
                }
            }
        }
        if (emp) staff.push_back(emp);
    }
    return staff;
}

void StaffFactory::saveToFile(const string &filename, const vector<Employee *> &staff) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file for saving.");
    }

    for (const auto* emp : staff) {
        file << emp->getId() << ";"
             << emp->getName() << ";"
             << emp->getPosition() << ";"
             << emp->getWorktime() << ";"
             << emp->getPayment() << std::endl;
    }
    file.close();
}