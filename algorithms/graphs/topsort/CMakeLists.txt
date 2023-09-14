add_executable(topsort test_topsort.cpp)
target_link_libraries(topsort ${GTEST_LIBRARIES} pthread)

add_test(NAME topsort_test COMMAND topsort)