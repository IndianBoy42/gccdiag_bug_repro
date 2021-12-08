cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# add the executable
add_executable(Tutorial tutorial.cpp)

target_include_directories(Tutorial PUBLIC .)

target_compile_definitions(
  Tutorial PUBLIC
  -D__forceinline=__attribute__\(\(always_inline\)\)
  -Dstdio="tutorial.h"
)

add_custom_command(
  TARGET Tutorial POST_BUILD
  COMMAND Tutorial
)
