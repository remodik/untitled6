#include "Factory.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include <fstream>
#include <sstream>

vector<Employee*> StaffFactory::makeStaff(const string& filename) {
    vector<Employee*> staff;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        istringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 4) continue;

        int id = stoi(tokens[0]);
        string name = tokens[1];
        string position = tokens[2];
        int salary = tokens.size() > 3 ? stoi(tokens[3]) : 0;

        Employee* emp = nullptr;
        if (position == "Cleaner") emp = new Cleaner(id, name, salary);
        else if (position == "Driver") emp = new Driver(id, name, salary);
        else if (position == "Programmer") emp = new Programmer(id, name, salary);
        else if (position == "Tester") emp = new Tester(id, name, salary);
        else if (position == "TeamLeader") emp = new TeamLeader(id, name, salary);
        else if (position == "ProjectManager") emp = new ProjectManager(id, name, position);
        else if (position == "SeniorManager") emp = new SeniorManager(id, name, position);

        if (emp) staff.push_back(emp);
    }

    return staff;
}

void StaffFactory::saveStaff(const string& filename, const vector<Employee*>& staff) {
    ofstream file(filename);
    for (Employee* emp : staff) {
        file << emp->getId() << ","
             << emp->getName() << ","
             << emp->getPosition() << ","
             << "0"
             << "\n";
    }
}