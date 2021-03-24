cmake_minimum_required(VERSION 3.10)
project(Calculator)

# prehlada
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/libs/googletest)
    message(STATUS "googletest found!")
else()
    execute_process(
        COMMAND git clone https://github.com/google/googletest.git ${CMAKE_CURRENT_SOURCE_DIR}/libs/googletest
    )
endif()

add_subdirectory(libs/googletest)
add_subdirectory(src)
add_subdirectory(tests)
