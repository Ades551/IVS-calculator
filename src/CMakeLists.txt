cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

# sudo apt-get install qt5-default
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# add gtest
add_subdirectory(build/libs/googletest)

# libraries
add_library(
    lib
    lib/cmath.h
    lib/cmath.cpp
)

target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# calc executable
add_executable(ivs-calc
    calc.ui
    calc.cpp
    calc.h
    main.cpp
)

# test executable
add_executable(math_test ${CMAKE_CURRENT_SOURCE_DIR}/tests/math_test.cpp)

# profiling executable
#add_executable(stddev ${CMAKE_CURRENT_SOURCE_DIR}/profiling/stddev.cpp)

#target_link_libraries(stddev lib)
target_link_libraries(math_test PRIVATE lib gtest gtest_main)
target_link_libraries(ivs-calc Qt5::Widgets lib)
