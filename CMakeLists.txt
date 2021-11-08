cmake_minimum_required(VERSION 3.9.2)
project(hw2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "-g -Wall -Werror -Wextra -O3 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-g -Wall -O3 -fprofile-arcs -ftest-coverage")

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

set(INC_DIR ${DIR}/project/include)
set(SRC_DIR ${DIR}/project/src)

include_directories(
    ${SRC_DIR}
    ${INC_DIR})

add_executable(hw2 ${SRC_DIR}/main.c ${SRC_DIR}/foo.c ${INC_DIR}/foo.h)