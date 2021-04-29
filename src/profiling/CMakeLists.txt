cmake_minimum_required(VERSION 3.10)
project(Calculator)

# libraries
add_library(
    lib
    ../lib/cmath.h
    ../lib/cmath.cpp
)

target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
add_executable(stddev ${CMAKE_CURRENT_SOURCE_DIR}/stddev.cpp)
target_link_libraries(stddev lib)