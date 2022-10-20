//
// Created by Maciek on 16.10.2022.
//

#include <algorithm>
#include <iostream>
//#include "../utils.h"

struct Message
{
    enum type
    {
        Error, Warning
    };
    type msgType;
    std::string payload;
};

bool partitionCompare(const Message &message1)
{
    return message1.msgType == Message::type::Error;
}

template<class Container>
void checkIfPartitioned(Container container);

template<class Container>
void printMessages(Container container, const std::string &additionalText = "Printing container");

int main()
{
    using type = Message::type;

    //Creating container to be partitioned
    std::array<Message, 5> messages{Message{type::Error, "Error 1"},
                                    Message{type::Warning, "Warning 1"},
                                    Message{type::Warning, "Warning 2"},
                                    Message{type::Error, "Error 2"},
                                    Message{type::Warning, "Warning 3"}};


    auto messagesCopy{messages}; // copy of messages to be used on stable_partition
    printMessages(messages, "Container before partition: ");

    //Check if container is partitioned (Errors first, warnings later)
    checkIfPartitioned(messages);


    //partition container
    std::partition(messages.begin(), messages.end(), partitionCompare);

    //Check if container is partitioned (Errors first, warnings later)

    printMessages(messages, "Container after partition: ");

    checkIfPartitioned(messages);

    //stable_partition keeps the original collection order.

    auto partitionPoint{std::stable_partition(messagesCopy.begin(), messagesCopy.end(), partitionCompare)};

    printMessages(messagesCopy, "Container after stable_partition: ");

    checkIfPartitioned(messagesCopy);


    //std::partition_point can be used to get index of transition between two sets
    std::cout << (partitionPoint == std::partition_point(messagesCopy.begin(), messagesCopy.end(), partitionCompare))
              << std::endl; //True

    return 0;
}

template<class Container>
void checkIfPartitioned(Container container)
{
    std::cout << std::endl << "Is container partitioned: " << std::boolalpha
              << std::is_partitioned(container.begin(), container.end(), partitionCompare) << std::endl;
}

template<class Container>
void printMessages(Container container, const std::string &additionalText)
{
    using type = Message::type;
    std::cout << std::endl << additionalText << std::endl;
    for (const auto &message : container)
    {
        auto messageType{message.msgType == type::Error ? "Error" : "Warning"};
        std::cout << messageType << " message with content " << message.payload << std::endl;
    }
}