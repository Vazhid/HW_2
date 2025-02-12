cmake_minimum_required(VERSION 3.9.2)
project(hw2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "-g -Wall -Werror -Wextra -O3 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-g -Wall -O3 -fprofile-arcs -ftest-coverage")

find_package(GTest REQUIRED)
message(STATUS "test path ${GTEST_INCLUDE_DIRS}")

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

set(INC_DIR ${DIR}/project/include)
set(SRC_DIR ${DIR}/project/src)
set(TESTS_DIR ${DIR}/tests)

include_directories(
    ${SRC_DIR}
    ${INC_DIR}
    ${GTEST_INCLUDE_DIRS})

add_library(foo STATIC
        ${INC_DIR}/foo.h
        ${SRC_DIR}/foo.c)

add_executable(TEST tests/main.cpp)

target_include_directories(TEST PUBLIC ${INC_DIR})

target_link_libraries(TEST ${GTEST_LIBRARIES})

target_link_libraries(TEST ${GTEST_LIBRARIES} Threads::Threads pthread -ldl foo)

enable_testing()

add_executable(hw2 ${SRC_DIR}/main.c ${SRC_DIR}/foo.c ${INC_DIR}/foo.h)

target_link_libraries(hw2 Threads::Threads pthread -ldl foo)
