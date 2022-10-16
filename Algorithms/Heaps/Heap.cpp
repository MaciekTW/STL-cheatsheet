//
// Created by Maciek on 15.10.2022.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
//#include "../utils.h"

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

void checkingIfContainerIsAHeap();
void creatingHeapFromContainer();
void addNewElementToHeap();
void removeLargestElementFromHeap();
void sortHeap();
void findLongestHeapInContainer();

int main()
{
    //checking if container is a heap
    checkingIfContainerIsAHeap();

    //Creating heap from container
    creatingHeapFromContainer();

    //Adding new element to heap
    addNewElementToHeap();

    //Removing first heap element
    removeLargestElementFromHeap();

    //Transforming a heap into a sorted collection
    sortHeap();

    //look for longest heap in container
    findLongestHeapInContainer();
    return 0;
}

void checkingIfContainerIsAHeap()
{
    std::vector<int> rankingList{}; //It might be an array or other container as well

    bool isRankingListHeap{std::is_heap(rankingList.begin(), rankingList.end())};

    std::cout << "Is empty vector a heap: " << std::boolalpha << isRankingListHeap << std::endl; //TRUE

    rankingList.push_back(1);
    rankingList.push_back(1);

    isRankingListHeap = std::is_heap(rankingList.begin(), rankingList.end());

    std::cout << "Is vector with equal element a heap: " << std::boolalpha << isRankingListHeap << std::endl; //TRUE

    rankingList.push_back(2);
    isRankingListHeap = std::is_heap(rankingList.begin(), rankingList.end());

    std::cout << "Is vector {1,1,2} a heap: " << std::boolalpha << isRankingListHeap << std::endl; //False
}

void creatingHeapFromContainer()
{
    std::vector<int> rankingList{1, 3, 4, 1, 5, 9 }; //unordered container

    bool isRankingListHeap{std::is_heap(rankingList.begin(), rankingList.end())};

    std::cout << "Container before make_heap:" << utils::printContainer(rankingList) << " is a heap: "
              << std::boolalpha
              << isRankingListHeap << std::endl; //FALSE

    std::make_heap(rankingList.begin(), rankingList.end());
    isRankingListHeap =std::is_heap(rankingList.begin(), rankingList.end());

    std::cout << "Container after make_heap:" << utils::printContainer(rankingList) << " is a heap: "
              << std::boolalpha
              << isRankingListHeap << std::endl; //TRUE
}

void addNewElementToHeap()
{
    std::vector<int> rankingList{3, 2, 1}; //ordered container (heap)

    rankingList.push_back(5);
    bool isRankingListHeap{std::is_heap(rankingList.begin(), rankingList.end())};
    std::cout << "Is vector " << utils::printContainer(rankingList) << " before push_heap a heap: "
              << std::boolalpha << isRankingListHeap << std::endl; //False

    std::push_heap(rankingList.begin(), rankingList.end()); //Only last element can be not in order
    isRankingListHeap = std::is_heap(rankingList.begin(), rankingList.end());

    std::cout << "Is vector " << utils::printContainer(rankingList) << " after push_heap a heap: " << std::boolalpha
              << isRankingListHeap << std::endl; //True
}

void removeLargestElementFromHeap()
{
    std::vector<int> rankingList{1, 3, 4, 8, 5, 9 }; //unordered container
    std::make_heap(rankingList.begin(), rankingList.end()); //creating heap
    std::cout << "Heap content: " << utils::printContainer(rankingList) << std::endl;
    std::pop_heap(rankingList.begin(),rankingList.end()); //first item (largest) goes at the end
    std::cout << "Heap content after heap pop: " << utils::printContainer(rankingList) << std::endl;
    rankingList.pop_back(); //delete largest element
    std::cout << "Heap content after vector pop: " << utils::printContainer(rankingList) << std::endl;
}

void sortHeap()
{
    std::vector<int> rankingList{1, 3, 4, 1, 5, 9 }; //unordered container
    std::make_heap(rankingList.begin(), rankingList.end());
    std::cout << "Heap content: " << utils::printContainer(rankingList) << std::endl;

    std::sort_heap(rankingList.begin(),rankingList.end());
    std::cout << "Container content after heap sort: " << utils::printContainer(rankingList) << std::endl;
}

void findLongestHeapInContainer()
{
    std::vector<int> rankingList{1, 3, 4, 1, 5, 9 }; //unordered container
    auto noRange {std::is_heap_until(rankingList.begin(),rankingList.end())}; // returns iterator to element one ahead of heap subrange upper bound
    std::cout<<"Last element of heap range: "<<*noRange<<std::endl;


    std::make_heap(rankingList.begin(), rankingList.end());
    std::pop_heap(rankingList.begin(), rankingList.end());
    rankingList.push_back(2);

    std::cout << "Container content: " << utils::printContainer(rankingList) << std::endl; // 5 3 4 1 1 9 heap is 5 3 4 1 1
    auto upperBound {std::is_heap_until(rankingList.begin(),rankingList.end())}; // returns iterator to element one ahead of heap subrange upper bound
    std::cout<<"Last element of heap range: "<<*upperBound<<std::endl;
}