# kniznice
add_library(
    lib
    lib/math.h
    lib/math.cpp
)

target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(calc calc.cpp)

target_link_libraries(calc PRIVATE lib)
