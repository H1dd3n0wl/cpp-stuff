cmake_minimum_required(VERSION 3.26)

project(cpp_stuff)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory("algorithms/graphs/dfs")
add_subdirectory("algorithms/graphs/bfs")
