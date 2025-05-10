cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  clog
  VERSION 1.0.0
  LANGUAGES C CXX)

add_compile_options(-Wall -Wextra -Werror -pedantic)

file(GLOB_RECURSE SOURCE src/*.c)

set(LIB_STATIC clog_static)
add_library(${LIB_STATIC} STATIC ${SOURCE})
set(LIB_SHARED clog_shared)
add_library(${LIB_SHARED} SHARED ${SOURCE})

target_include_directories(${LIB_STATIC} PUBLIC src)
target_include_directories(${LIB_SHARED} PUBLIC src)

set_target_properties(${LIB_STATIC} PROPERTIES OUTPUT_NAME ${PROJECT_NAME}
                                               DEBUG_POSTFIX d)
set_target_properties(${LIB_SHARED} PROPERTIES OUTPUT_NAME ${PROJECT_NAME}
                                               DEBUG_POSTFIX d)

option(BUILD_TESTS "Build test exectuables" OFF)

if(BUILD_TESTS)
  set(C_TEST clog_c_test)
  add_executable(${C_TEST} tests/main.c tests/module.c)
  target_link_libraries(${C_TEST} PRIVATE ${LIB_STATIC})
  target_compile_options(${C_TEST} PRIVATE -DCLOG_ENABLE_DEBUG)
  target_include_directories(
    ${C_TEST} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
                      ${CMAKE_CURRENT_SOURCE_DIR}/tests)

  set(C_TEST_NO_DEBUG clog_c_test_no_debug)
  add_executable(${C_TEST_NO_DEBUG} tests/main.c tests/module.c)
  target_link_libraries(${C_TEST_NO_DEBUG} PRIVATE ${LIB_STATIC})
  target_include_directories(
    ${C_TEST_NO_DEBUG} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
                               ${CMAKE_CURRENT_SOURCE_DIR}/tests)

  set(CPP_TEST clog_cpp_test)
  add_executable(${CPP_TEST} tests/main.cpp tests/module.cpp)
  target_link_libraries(${CPP_TEST} PRIVATE ${LIB_STATIC})
  target_compile_options(${CPP_TEST} PRIVATE -DCLOG_ENABLE_DEBUG)
  target_include_directories(
    ${CPP_TEST} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
                        ${CMAKE_CURRENT_SOURCE_DIR}/tests)

  set(CPP_TEST_NO_DEBUG clog_cpp_test_no_debug)
  add_executable(${CPP_TEST_NO_DEBUG} tests/main.cpp tests/module.cpp)
  target_link_libraries(${CPP_TEST_NO_DEBUG} PRIVATE ${LIB_STATIC})
  target_include_directories(
    ${CPP_TEST_NO_DEBUG} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
                                 ${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()
