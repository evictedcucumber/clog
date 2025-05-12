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

add_compile_options(-Wall -Wextra -Werror -pedantic)

set(LIB_STATIC clog_static)
add_library(${LIB_STATIC} STATIC src/clog.c)
set(LIB_SHARED clog_shared)
add_library(${LIB_SHARED} SHARED src/clog.c)

target_include_directories(${LIB_STATIC} PUBLIC src)
target_include_directories(${LIB_SHARED} PUBLIC src)

set_target_properties(${LIB_STATIC} PROPERTIES OUTPUT_NAME ${PROJECT_NAME}
                                               DEBUG_POSTFIX d)
set_target_properties(${LIB_SHARED} PROPERTIES OUTPUT_NAME ${PROJECT_NAME}
                                               DEBUG_POSTFIX d)

option(BUILD_TESTS "Build test exectuables" OFF)

if(BUILD_TESTS)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

  set(C_TEST_SOURCE src/clog.h src/clog.c tests/main.c)

  set(C_TEST clog_c_test)
  add_executable(${C_TEST} ${C_TEST_SOURCE})

  set(C_TEST_COLOURS clog_c_test_colours)
  add_executable(${C_TEST_COLOURS} ${C_TEST_SOURCE})
  target_compile_definitions(${C_TEST_COLOURS} PUBLIC CLOG_ENABLE_COLOURS)

  set(C_TEST_DEBUG clog_c_test_debug)
  add_executable(${C_TEST_DEBUG} ${C_TEST_SOURCE})
  target_compile_definitions(${C_TEST_DEBUG} PUBLIC CLOG_ENABLE_DEBUG)

  set(C_TEST_DEBUG_WITH_COLOURS clog_c_test_debug_with_colours)
  add_executable(${C_TEST_DEBUG_WITH_COLOURS} ${C_TEST_SOURCE})
  target_compile_definitions(${C_TEST_DEBUG_WITH_COLOURS}
                             PUBLIC CLOG_ENABLE_DEBUG CLOG_ENABLE_COLOURS)

  set(C_TEST_TIMESTAMPS clog_c_test_timestamp)
  add_executable(${C_TEST_TIMESTAMPS} ${C_TEST_SOURCE})
  target_compile_definitions(${C_TEST_TIMESTAMPS} PUBLIC CLOG_ENABLE_TIMESTAMPS)

  set(C_TEST_COLOURS_AND_TIMESTAMPS clog_c_test_colours_and_timestamps)
  add_executable(${C_TEST_COLOURS_AND_TIMESTAMPS} ${C_TEST_SOURCE})
  target_compile_definitions(${C_TEST_COLOURS_AND_TIMESTAMPS}
                             PUBLIC CLOG_ENABLE_TIMESTAMPS CLOG_ENABLE_COLOURS)

  set(CXX_TEST_SOURCE src/clog.h src/clog.c tests/main.cpp)

  set(CXX_TEST clog_cxx_test)
  add_executable(${CXX_TEST} ${CXX_TEST_SOURCE})

  set(CXX_TEST_COLOURS clog_cxx_test_colours)
  add_executable(${CXX_TEST_COLOURS} ${CXX_TEST_SOURCE})
  target_compile_definitions(${CXX_TEST_COLOURS} PUBLIC CLOG_ENABLE_COLOURS)

  set(CXX_TEST_DEBUG clog_cxx_test_debug)
  add_executable(${CXX_TEST_DEBUG} ${CXX_TEST_SOURCE})
  target_compile_definitions(${CXX_TEST_DEBUG} PUBLIC CLOG_ENABLE_DEBUG)

  set(CXX_TEST_DEBUG_WITH_COLOURS clog_cxx_test_debug_with_colours)
  add_executable(${CXX_TEST_DEBUG_WITH_COLOURS} ${CXX_TEST_SOURCE})
  target_compile_definitions(${CXX_TEST_DEBUG_WITH_COLOURS}
                             PUBLIC CLOG_ENABLE_DEBUG CLOG_ENABLE_COLOURS)

  set(CXX_TEST_TIMESTAMPS clog_cxx_test_timestamp)
  add_executable(${CXX_TEST_TIMESTAMPS} ${CXX_TEST_SOURCE})
  target_compile_definitions(${CXX_TEST_TIMESTAMPS}
                             PUBLIC CLOG_ENABLE_TIMESTAMPS)

  set(CXX_TEST_COLOURS_AND_TIMESTAMPS clog_cxx_test_colours_and_timestamps)
  add_executable(${CXX_TEST_COLOURS_AND_TIMESTAMPS} ${CXX_TEST_SOURCE})
  target_compile_definitions(${CXX_TEST_COLOURS_AND_TIMESTAMPS}
                             PUBLIC CLOG_ENABLE_TIMESTAMPS CLOG_ENABLE_COLOURS)
endif()
