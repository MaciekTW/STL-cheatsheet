//
// Created by Maciek on 15.10.2022.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
//#include "../utils.h"

//Practical usage: Handling warning Events and solving them in order of priorities

namespace utils
{
    template<typename Container>
    std::string printContainer(const Container &container)
    {
        std::stringstream stream;
        stream << "{ ";
        for (const auto el: container)
        { stream << el << " "; }
        stream << "}";

        return stream.str();
    }
}

struct Event
{
    int priority;
    int ErrorCode;
};

void reportNewEvent(std::vector<Event> &eventHandler, const Event &newEvent);

bool customCompare(const Event &event1, const Event &event2)
{
    return event1.priority <= event2.priority;
}

int main()
{
    constexpr int HighestPriority{12};
    constexpr int HighPriority{10};
    constexpr int MidPriority{5};
    constexpr int LowPriority{1};

    constexpr int errorCode1{1};
    constexpr int errorCode2{2};

    std::vector<Event> eventHandler{}; //Error heap at the beginning

    std::make_heap(eventHandler.begin(), eventHandler.end(), customCompare);

    //Gather new Event warnings during program execution
    reportNewEvent(eventHandler, Event{HighPriority, errorCode1});
    reportNewEvent(eventHandler, Event{LowPriority, errorCode1});
    reportNewEvent(eventHandler, Event{HighestPriority, errorCode1});
    reportNewEvent(eventHandler, Event{MidPriority, errorCode2});

    //Solve problem in order of priority

    while (not eventHandler.empty())
    {
        std::pop_heap(eventHandler.begin(), eventHandler.end(), customCompare);
        const auto event{eventHandler.back()};
        eventHandler.pop_back();
        std::cout << "Solving problem with error code " << event.ErrorCode << " and priority: " << event.priority
                  << std::endl;
    }

    return 0;
}

void reportNewEvent(std::vector<Event> &eventHandler, const Event &newEvent)
{
    std::cout << "New warning error occurred with priority " << newEvent.priority << std::endl;
    eventHandler.push_back(newEvent);
    std::push_heap(eventHandler.begin(), eventHandler.end(), customCompare);
}