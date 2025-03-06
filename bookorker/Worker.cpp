#include "Worker.h"

string Worker::getPosition() const {
    return position;
}

int Worker::getExperience(const int curYear) const {
    return curYear - year;
}

double Worker::getSalary() const {
    return salary;
}

void Worker::display() const {
    cout << "ФИО: " << fio << ", Должность: " << position
             << ", Год поступления: " << year << ", Зарплата: " << salary << endl;
    cout << format("ФИО: {0}\nДолжность: {1}\nГод поступления: {2}\nЗП: {3}", fio, position, year, salary) << endl;
}

void Worker::printWorkersByExperience(const vector<Worker> &workers, int years, int curYear) {
    cout << format("\nРаботники со стажем более {} лет:\n", years);
    for (const auto& worker : workers) {
        if (worker.getExperience(curYear) > years) {
            worker.display();
        }
    }
}

void Worker::printWorkersByPosition(const vector<Worker> &workers, const string &position) {
    cout << format("\nРаботники на должности {}:\n", position);
    for (const auto& worker : workers) {
        if (worker.getPosition() == position) {
            worker.display();
        }
    }
}

void Worker::printWorkersBySalary(const vector<Worker> &workers, double minSalary) {
    cout << format("\nРаботники с зарплатой выше {}:\n", minSalary);
    for (const auto& worker : workers) {
        if (worker.getSalary() > minSalary) {
            worker.display();
        }
    }
}
