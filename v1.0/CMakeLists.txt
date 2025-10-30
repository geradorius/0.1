cmake_minimum_required(VERSION 3.10)
project(v1_0_StudentSorting)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

add_executable(strategija1 strategija1.cpp)
add_executable(strategija2 strategija2.cpp)

add_custom_target(run_all
    COMMAND strategija1
    COMMAND strategija2
    DEPENDS strategija1 strategija2
    COMMENT "Running all strategies"
)

add_custom_target(clean_results
    COMMAND ${CMAKE_COMMAND} -E remove -f *.txt
    COMMENT "Cleaning result files"
)
