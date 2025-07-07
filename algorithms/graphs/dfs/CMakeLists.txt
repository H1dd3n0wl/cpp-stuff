add_executable(dfs test_dfs.cpp)
target_link_libraries(dfs gtest_main)

add_test(NAME dfs_test COMMAND dfs)