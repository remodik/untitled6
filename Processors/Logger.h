#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
using namespace std;
class Logger {
    ofstream logFile;
    mutex mtx;

public:
    explicit Logger(const string &filename) {
        logFile.open(filename, ios::app);
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void log(const string &message) {
        lock_guard<mutex> guard(mtx);
        if (logFile.is_open()) {
            logFile << message << endl;
        }
        cout << message << endl;
    }
};

#endif
