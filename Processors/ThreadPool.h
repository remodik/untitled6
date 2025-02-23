#ifndef ThreadPool_h
#define ThreadPool_h
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <atomic>
using namespace std;
class ThreadPool {
public:
    explicit ThreadPool(const size_t numThreads) : stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    function<void()> task; {
                        unique_lock<mutex> lock(this->queueMutex);
                        this->condition.wait(lock, [this] {return this->stop || !this->taskQueue.empty();});
                        if (this->stop && this->taskQueue.empty()) return;
                        task = move(this->taskQueue.front());
                        this->taskQueue.pop();
                    } task();
                }
            });
        }
    }
    template <class F>
    void enqueue(F&& f) { {
            unique_lock<mutex> lock(queueMutex);
            if (stop) throw runtime_error("enqueue on stopped ThreadPool");
            taskQueue.push(forward<F>(f));
        } condition.notify_one();
    }

    ~ThreadPool() { {
            unique_lock<mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for (thread& worker : workers) worker.join();
    }

private:
    vector<thread> workers;
    queue<function<void()>> taskQueue;
    mutex queueMutex;
    condition_variable condition;
    atomic<bool> stop;
};

#endif