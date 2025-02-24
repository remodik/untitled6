#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H

#include <string>
#include <iostream>
#include <memory>
#include <future>

class QueryProcessor {
public:
    virtual ~QueryProcessor() = default;

    virtual future<void> processQuery(const string &query) = 0;
    [[nodiscard]] virtual string getType() const = 0;
};

#endif
