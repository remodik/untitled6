#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;
class Event {
public:
    virtual ~Event() = default;
    virtual string getEventType() const = 0;
    virtual string getEventDetails() const = 0;
};

#endif
