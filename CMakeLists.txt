cmake_minimum_required(VERSION 3.16)

project(Study++ LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU OR CMAKE_CXX_COMPILER_ID MATCHES Clang)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wno-sign-compare")
  if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnrvo")
  elseif(CMAKE_CXX_COMPILER_ID MATCHES Clang)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    add_compile_definitions(_LIBCPP_ENABLE_EXPERIMENTAL)
  endif()
endif()

# Programming skills
add_executable(mergeAlternatively1768 mergeAlternatively1768.cpp)
add_executable(difference389 difference389.cpp)
add_executable(firstOccurrence28 firstOccurrence28.cpp)
add_executable(validAnagram242 validAnagram242.cpp)
add_executable(repeatedSubstring459 repeatedSubstring459.cpp)
add_executable(moveZeros283 moveZeros283.cpp)
add_executable(plusOne66 plusOne66.cpp)
add_executable(sign1822 sign1822.cpp)

# Concurrency
add_executable(fizzBuzz1195 fizzBuzz1195.cpp)
add_executable(inOrder1114 inOrder1114.cpp)
add_executable(fooBar1115 fooBar1115.cpp)
add_executable(zeroEvenOdd1116 zeroEvenOdd1116.cpp)
