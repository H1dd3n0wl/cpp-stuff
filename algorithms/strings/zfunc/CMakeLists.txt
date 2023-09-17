add_executable(zfunc test_zfunc.cpp)
target_link_libraries(zfunc ${GTEST_LIBRARIES} pthread)

add_test(NAME zfunc_test COMMAND zfunc)