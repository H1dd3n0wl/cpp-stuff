add_executable(topsort test_topsort.cpp)
target_link_libraries(topsort gtest_main)

add_test(NAME topsort_test COMMAND topsort)