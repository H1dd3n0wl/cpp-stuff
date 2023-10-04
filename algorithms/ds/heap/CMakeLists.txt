add_executable(heap test_heap.cpp)
target_link_libraries(heap ${GTEST_LIBRARIES} pthread)

add_test(NAME heap_test COMMAND heap)