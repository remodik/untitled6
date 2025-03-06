#ifndef WORKER_H
#define WORKER_H
#include <vector>
#include <iostream>
#include <format>
#include <algorithm>
using namespace std;

class Worker {
    string fio;
    string position;
    int year;
    double salary;

public:
    Worker(const string& fio,const string& position, int hireYear, double salary)
        : fio(fio), position(position), year(hireYear), salary(salary) {}

    string getPosition() const;
    int getExperience(int curYear) const;
    double getSalary() const;

    void printWorkersByExperience(const vector<Worker>& workers, int years, int curYear);
    void printWorkersBySalary(const vector<Worker>& workers, double minSalary);
    void printWorkersByPosition(const vector<Worker>& workers, const string& position);

    void display() const;
};

#endif
