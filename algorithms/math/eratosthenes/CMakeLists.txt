add_executable(eratosthenes test_eratosthenes.cpp)
target_link_libraries(eratosthenes ${GTEST_LIBRARIES} pthread)

add_test(NAME eratosthenes_test COMMAND eratosthenes)