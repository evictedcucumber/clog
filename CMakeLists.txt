cmake_minimum_required(VERSION 3.30)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  clog
  VERSION 1.0.0
  LANGUAGES C CXX)

add_compile_options(-Wall -Wextra -Werror -pedantic -DCLOG_IMPLEMENTATION)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(C_TEST_SOURCE tests/main.c)

set(C_TEST clog_c_test)
add_executable(${C_TEST} ${C_TEST_SOURCE})

set(C_TEST_COLOURS clog_c_test_colours)
add_executable(${C_TEST_COLOURS} ${C_TEST_SOURCE})
target_compile_definitions(${C_TEST_COLOURS} PRIVATE CLOG_ENABLE_COLOURS)

set(C_TEST_DEBUG clog_c_test_debug)
add_executable(${C_TEST_DEBUG} ${C_TEST_SOURCE})
target_compile_definitions(${C_TEST_DEBUG} PRIVATE CLOG_ENABLE_DEBUG)

set(C_TEST_DEBUG_WITH_COLOURS clog_c_test_debug_with_colours)
add_executable(${C_TEST_DEBUG_WITH_COLOURS} ${C_TEST_SOURCE})
target_compile_definitions(${C_TEST_DEBUG_WITH_COLOURS}
                           PRIVATE CLOG_ENABLE_DEBUG CLOG_ENABLE_COLOURS)

set(C_TEST_TIMESTAMPS clog_c_test_timestamp)
add_executable(${C_TEST_TIMESTAMPS} ${C_TEST_SOURCE})
target_compile_definitions(${C_TEST_TIMESTAMPS} PRIVATE CLOG_ENABLE_TIMESTAMPS)

set(C_TEST_COLOURS_AND_TIMESTAMPS clog_c_test_colours_and_timestamps)
add_executable(${C_TEST_COLOURS_AND_TIMESTAMPS} ${C_TEST_SOURCE})
target_compile_definitions(${C_TEST_COLOURS_AND_TIMESTAMPS}
                           PRIVATE CLOG_ENABLE_TIMESTAMPS CLOG_ENABLE_COLOURS)

set(CXX_TEST_SOURCE tests/main.cpp)

set(CXX_TEST clog_cxx_test)
add_executable(${CXX_TEST} ${CXX_TEST_SOURCE})

set(CXX_TEST_COLOURS clog_cxx_test_colours)
add_executable(${CXX_TEST_COLOURS} ${CXX_TEST_SOURCE})
target_compile_definitions(${CXX_TEST_COLOURS} PRIVATE CLOG_ENABLE_COLOURS)

set(CXX_TEST_DEBUG clog_cxx_test_debug)
add_executable(${CXX_TEST_DEBUG} ${CXX_TEST_SOURCE})
target_compile_definitions(${CXX_TEST_DEBUG} PRIVATE CLOG_ENABLE_DEBUG)

set(CXX_TEST_DEBUG_WITH_COLOURS clog_cxx_test_debug_with_colours)
add_executable(${CXX_TEST_DEBUG_WITH_COLOURS} ${CXX_TEST_SOURCE})
target_compile_definitions(${CXX_TEST_DEBUG_WITH_COLOURS}
                           PRIVATE CLOG_ENABLE_DEBUG CLOG_ENABLE_COLOURS)

set(CXX_TEST_TIMESTAMPS clog_cxx_test_timestamp)
add_executable(${CXX_TEST_TIMESTAMPS} ${CXX_TEST_SOURCE})
target_compile_definitions(${CXX_TEST_TIMESTAMPS}
                           PRIVATE CLOG_ENABLE_TIMESTAMPS)

set(CXX_TEST_COLOURS_AND_TIMESTAMPS clog_cxx_test_colours_and_timestamps)
add_executable(${CXX_TEST_COLOURS_AND_TIMESTAMPS} ${CXX_TEST_SOURCE})
target_compile_definitions(${CXX_TEST_COLOURS_AND_TIMESTAMPS}
                           PRIVATE CLOG_ENABLE_TIMESTAMPS CLOG_ENABLE_COLOURS)
