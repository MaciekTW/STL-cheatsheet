cmake_minimum_required(VERSION 3.19)
project(STL)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Algorithms)
add_subdirectory(Containers)

add_executable(Heap Algorithms/Heaps/Heap.cpp utils.cpp)
add_executable(HeapEventHandling Algorithms/Heaps/HeapPractical.cpp utils.cpp)
add_executable(Sorting Algorithms/Sorting/Sorting.cpp utils.cpp)
add_executable(Partition Algorithms/Sorting/Partition.cpp utils.cpp)