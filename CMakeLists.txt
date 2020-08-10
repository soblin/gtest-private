project(gtest-private)

cmake_minimum_required(VERSION 2.8.3)

if(NOT without-test)
  enable_testing()
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-std=c++11 -Wall -g -DUTEST)

add_library(gtest STATIC IMPORTED)

set_property(
  TARGET gtest
  PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/build/libgtest.a
  )

add_library(gtest_main STATIC IMPORTED)

set_property(
  TARGET gtest_main
  PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/build/libgtest_main.a
  )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include)

add_executable(gtest_private_test test.cpp)

target_link_libraries(gtest_private_test
  gtest
  gtest_main
  pthread
  )

add_test(
  NAME gtest-private-test
  COMMAND $<TARGET_FILE:gtest_private_test>
  )
