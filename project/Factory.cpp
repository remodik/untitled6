#include "Factory.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include "Project.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "Cleaner.h"
#include "Driver.h"
#include "Programmer.h"
#include "ProjectManager.h"
#include "SeniorManager.h"
#include "TeamLeader.h"
#include "Tester.h"

static unordered_map<string, Project*> projects;

vector<Employee*> StaffFactory::makeStaff(const string& filename) {
    vector<Employee*> staff;
    ifstream file(filename);
    string line;
    
    while (getline(file, line)) {
        istringstream ss(line);
        int id;
        string name, position, project_name;
        int salary = 0;
        
        ss >> id;
        ss.ignore();
        getline(ss, name, ';');
        getline(ss, position, ';');
        
        if (position != "ProjectManager" && position != "SeniorManager") {
            ss >> salary;
        }
        
        if (ss.peek() != EOF) {
            ss.ignore();
            getline(ss, project_name);
        }

        if (position == "Cleaner") {
            staff.push_back(new Cleaner(id, name, salary));
        }
        else if (position == "Driver") {
            staff.push_back(new Driver(id, name, salary));
        }
        else if (position == "Programmer") {
            Programmer* p = new Programmer(id, name, salary);
            if (!project_name.empty()) {
                if (projects.find(project_name) == projects.end()) {
                    projects[project_name] = new Project(project_name, 0);
                }
                p->setProject(projects[project_name]);
            }
            staff.push_back(p);
        }
        else if (position == "Tester") {
            Tester* t = new Tester(id, name, salary);
            if (!project_name.empty()) {
                if (projects.find(project_name) == projects.end()) {
                    projects[project_name] = new Project(project_name, 0);
                }
                t->setProject(projects[project_name]);
            }
            staff.push_back(t);
        }
        else if (position == "TeamLeader") {
            TeamLeader* tl = new TeamLeader(id, name, salary);
            if (!project_name.empty()) {
                if (projects.find(project_name) == projects.end()) {
                    projects[project_name] = new Project(project_name, 0);
                }
                tl->setProject(projects[project_name]);
            }
            staff.push_back(tl);
        }
        else if (position == "ProjectManager") {
            ProjectManager* pm = new ProjectManager(id, name);
            if (!project_name.empty()) {
                if (projects.find(project_name) == projects.end()) {
                    projects[project_name] = new Project(project_name, 0);
                }
                pm->addProject(projects[project_name]);
            }
            staff.push_back(pm);
        }
        else if (position == "SeniorManager") {
            SeniorManager* sm = new SeniorManager(id, name);
            if (!project_name.empty()) {
                istringstream projects_ss(project_name);
                string prj_name;
                while (getline(projects_ss, prj_name, ',')) {
                    if (projects.find(prj_name) == projects.end()) {
                        projects[prj_name] = new Project(prj_name, 0);
                    }
                    sm->addProject(projects[prj_name]);
                }
            }
            staff.push_back(sm);
        }
    }
    return staff;
}

void StaffFactory::saveToFile(const string& filename, const vector<Employee*>& staff) {
    ofstream file(filename);
    for (const auto& emp : staff) {
        file << emp->getId() << ";"
             << emp->getName() << ";"
             << emp->getPosition() << ";";

        if (Personal* p = dynamic_cast<Personal*>(emp)) {
            file << p->getSalary();
        } else if (Engineer* e = dynamic_cast<Engineer*>(emp)) {
            file << e->getSalary();
        } else {
            file << "0";
        }

        if (Engineer* e = dynamic_cast<Engineer*>(emp)) {
            if (e->getProject()) {
                file << ";" << e->getProject()->name;
            }
        } else if (Manager* m = dynamic_cast<Manager*>(emp)) {
            const auto& prjs = m->getProjects();
            if (!prjs.empty()) {
                file << ";";
                for (size_t i = 0; i < prjs.size(); ++i) {
                    if (i > 0) file << ",";
                    file << prjs[i]->name;
                }
            }
        }
        file << "\n";
    }
}