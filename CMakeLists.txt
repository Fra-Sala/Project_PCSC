
cmake_minimum_required (VERSION 3.0)
project (PCSC-project)

set(CMAKE_CXX_STANDARD 17)

add_library(pcsc
  src/main.cpp
)

add_subdirectory(googletest)

add_executable(main src/main.cpp)
target_link_libraries(main pcsc)

add_executable(test_pcsc test/test.cc)
target_link_libraries(test_pcsc gtest_main gtest pthread pcsc)

add_custom_target(test ./test_pcsc DEPENDS test_pcsc)
