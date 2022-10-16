//
// Created by Maciek on 16.10.2022.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
//#include "../utils.h"

struct Customer
{
    int age;
    std::string name;
};

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

void sortPresentation();

void stableSortPresentation();

void partialSortPresentation();

void nthElementPresentation();

void sortHeapPresentation();


bool customCompare(const Customer &customer1, const Customer &customer2)
{
    return customer1.age < customer2.age;
}

int main()
{
    sortPresentation();
    stableSortPresentation();
    partialSortPresentation();
    nthElementPresentation();
    sortHeapPresentation();
    return 0;
}


void sortPresentation()
{
    std::cout << std::endl << "======sort======" << std::endl;

    std::array<int, 10> collection{2, 7, 4, 0, 1, 5, 3, 1, 1, 4};
    //There is no guarantee about repeating items positions
    std::cout << "Array content before sort: " << utils::printContainer(collection) << std::endl;
    std::sort(collection.begin(), collection.end()); // std::sort modify original collection
    std::cout << "Array content after sort: " << utils::printContainer(collection) << std::endl;
}

void stableSortPresentation()
{
    std::cout << std::endl << "======stable_sort======" << std::endl;

    std::array<Customer, 4> customerList{Customer{12, "John"}, Customer{2, "Bob"}, Customer{12, "Alice"},
                                         Customer{15, "Elise"}};

    std::stable_sort(customerList.begin(), customerList.end(), customCompare);

    for (const auto client : customerList)
    {
        std::cout << client.name << " age: " << client.age << std::endl;
    }
    //Order is set, John is before Alice
}

void partialSortPresentation()
{
    std::cout << std::endl << "======partial_sort======" << std::endl;

    std::array<int, 12> collection{2, 7, 4, 0, 1, 5, 3, 1, 1, 4, 5, 3};
    std::cout << "Array content before partial sort: " << utils::printContainer(collection) << std::endl;
    std::partial_sort(collection.begin(), collection.begin()+3,collection.end());
    std::cout << "Array content after partial sort till index 3: " << utils::printContainer(collection) << std::endl; //items at indexes 0-2 are sorted

}

void nthElementPresentation()
{
    std::cout << std::endl << "======nth_element======" << std::endl;

    std::array<int, 12> collection{2, 7, 4, 0, 1, 5, 3, 1, 1, 4, 5, 3};
    std::cout << "Array content before nth_element: " << utils::printContainer(collection) << std::endl;
    std::partial_sort(collection.begin(), collection.begin()+7,collection.end());
    std::cout << "Array content after nth_element at index 7: " << utils::printContainer(collection) << std::endl; //items at indexes 0-6 are smaller or equal than item on index 7
    //order of lest side of right side elements are not guaranteed
}

void sortHeapPresentation()
{
    std::cout << std::endl << "======sort_heap======" << std::endl;
    std::vector<int> rankingList{1, 3, 4, 1, 5, 9}; //unordered container
    std::make_heap(rankingList.begin(), rankingList.end());
    std::cout << "Heap content: " << utils::printContainer(rankingList) << std::endl;

    std::sort_heap(rankingList.begin(), rankingList.end());
    std::cout << "Container content after heap sort: " << utils::printContainer(rankingList) << std::endl;
}