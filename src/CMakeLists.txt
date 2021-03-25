cmake_minimum_required(VERSION 3.10)
project(Calculator)

# prida gtest
add_subdirectory(build/libs/googletest)

# kniznice
add_library(
    lib
    lib/cmath.h
    lib/cmath.cpp
)

target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(calc calc.cpp)
add_executable(math_test ${CMAKE_CURRENT_SOURCE_DIR}/tests/math_test.cpp)

target_link_libraries(math_test PRIVATE lib gtest gtest_main)
target_link_libraries(calc PRIVATE lib)
