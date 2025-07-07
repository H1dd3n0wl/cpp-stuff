add_executable(fenwick test_fenwick.cpp)
target_link_libraries(fenwick gtest_main)

add_test(NAME fenwick_test COMMAND fenwick)