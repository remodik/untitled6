#ifndef CONCRETE_QUERY_PROCESSORS_H
#define CONCRETE_QUERY_PROCESSORS_H
#include "Query_processor.h"
#include <chrono>
#include <thread>
using namespace std;
class TextQueryProcessor final : public QueryProcessor {
public:
    future<void> processQuery(const string &query) override {
        return async(launch::async, [query] {
            cout << "[TextProcessor] Обработка текста: " << query << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "[TextProcessor] Завершено: " << query << endl;
        });
    } [[nodiscard]] string getType() const override {return "Text";}
};

class ImageQueryProcessor final : public QueryProcessor {
public:
    future<void> processQuery(const string &query) override {
        return async(launch::async, [query] {
            cout << "[ImageProcessor] Обработка изображения: " << query << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << "[ImageProcessor] Завершено: " << query << endl;
        });
    } [[nodiscard]] string getType() const override {return "Image";}
};

class DatabaseQueryProcessor final : public QueryProcessor {
public:
    future<void> processQuery(const string &query) override {
        return async(launch::async, [query] {
            cout << "[DatabaseProcessor] Обработка запроса к базе данных: " << query << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "[DatabaseProcessor] Завершено: " << query << endl;
        });
    } [[nodiscard]] string getType() const override {return "Database";}
};

#endif
