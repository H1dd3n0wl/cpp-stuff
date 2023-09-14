add_executable(bfs test_bfs.cpp)
target_link_libraries(bfs ${GTEST_LIBRARIES} pthread)

add_test(NAME bfs_test COMMAND bfs)