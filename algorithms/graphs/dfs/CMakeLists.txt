add_executable(dfs test_dfs.cpp)
target_link_libraries(dfs ${GTEST_LIBRARIES} pthread)

add_test(NAME dfs_test COMMAND dfs)