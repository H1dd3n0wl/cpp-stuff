add_executable(runTests test_dfs.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_test(NAME dfs_test COMMAND runTests)