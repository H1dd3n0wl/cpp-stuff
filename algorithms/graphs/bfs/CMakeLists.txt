add_executable(bfs test_bfs.cpp)
target_link_libraries(bfs gtest_main)

add_test(NAME bfs_test COMMAND bfs)