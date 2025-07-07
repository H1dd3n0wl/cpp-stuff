add_executable(scc test_scc.cpp)
target_link_libraries(scc gtest_main)

add_test(NAME scc_test COMMAND scc)