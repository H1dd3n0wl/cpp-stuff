cmake_minimum_required(VERSION 3.26)

project(cpp_stuff)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory("algorithms/graphs/dfs")
add_subdirectory("algorithms/graphs/bfs")
add_subdirectory("algorithms/graphs/topsort")
add_subdirectory("algorithms/ds/fenwick")
add_subdirectory("algorithms/math/eratosthenes")
add_subdirectory("algorithms/strings/zfunc")
add_subdirectory("algorithms/math/extended_gcd")
add_subdirectory("algorithms/graphs/scc")
add_subdirectory("algorithms/ds/heap")