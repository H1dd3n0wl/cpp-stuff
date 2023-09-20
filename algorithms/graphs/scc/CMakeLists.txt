add_executable(scc test_scc.cpp)
target_link_libraries(scc ${GTEST_LIBRARIES} pthread)

add_test(NAME scc_test COMMAND scc)