add_executable(zfunc test_zfunc.cpp)
target_link_libraries(zfunc gtest_main)

add_test(NAME zfunc_test COMMAND zfunc)