add_executable(fenwick test_fenwick.cpp)
target_link_libraries(fenwick ${GTEST_LIBRARIES} pthread)

add_test(NAME fenwick_test COMMAND fenwick)