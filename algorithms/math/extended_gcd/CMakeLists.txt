add_executable(extended_gcd test_extended_gcd.cpp)
target_link_libraries(extended_gcd ${GTEST_LIBRARIES} pthread)

add_test(NAME extended_gcd_test COMMAND extended_gcd)