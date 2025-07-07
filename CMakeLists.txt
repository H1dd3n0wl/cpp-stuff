cmake_minimum_required(VERSION 3.26)

project(cpp_stuff)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(CTest)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB ALGOS "algorithms/*")
foreach(ALGO ${ALGOS})
  file(GLOB SUBDIRS "${ALGO}/*")
  foreach(SUBDIR ${SUBDIRS})
    if(IS_DIRECTORY ${SUBDIR} AND EXISTS ${SUBDIR}/CMakeLists.txt)
      add_subdirectory(${SUBDIR})
    endif()
  endforeach()
endforeach()
