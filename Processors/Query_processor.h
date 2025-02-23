#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H

#include <string>
#include <iostream>
#include <memory>
#include <future>

class QueryProcessor {
public:
    virtual ~QueryProcessor() = default;

    virtual std::future<void> processQuery(const std::string &query) = 0;
    [[nodiscard]] virtual std::string getType() const = 0;
};

#endif
