add_executable(heap test_heap.cpp)
target_link_libraries(heap gtest_main)

add_test(NAME heap_test COMMAND heap)