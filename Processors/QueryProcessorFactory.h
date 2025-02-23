#ifndef QUERY_PROCESSOR_FACTORY_H
#define QUERY_PROCESSOR_FACTORY_H

#include "ConcreteQueryProcessors.h"
#include <unordered_map>
#include <functional>
#include <memory>
using namespace std;
class QueryProcessorFactory {
public:
    using ProcessorCreator = function<unique_ptr<QueryProcessor>()>;

    QueryProcessorFactory() {
        registerProcessor("Text", []() {return make_unique<TextQueryProcessor>();});
        registerProcessor("Image", []() {return make_unique<ImageQueryProcessor>();});
        registerProcessor("Database", []() {return make_unique<DatabaseQueryProcessor>();});
    }

    void registerProcessor(const string &type, const ProcessorCreator &creator) {creators[type] = creator;}

    unique_ptr<QueryProcessor> createProcessor(const string &type) {
        if (creators.contains(type)) return creators[type]();
        throw runtime_error("Неизвестный тип запроса: " + type);
    }

private:
    unordered_map<string, ProcessorCreator> creators;
};

#endif
