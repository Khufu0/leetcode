cmake_minimum_required(VERSION 3.16)

project(Study++ LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU OR CMAKE_CXX_COMPILER_ID MATCHES Clang)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
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
add_executable(arithmeticProgression1502 arithmeticProgression1502.cpp)
add_executable(monotonicArray896 monotonicArray896.cpp)
add_executable(romanToInt13 romanToInt13.cpp)
add_executable(lengthOfLastWord58 lengthOfLastWord58.cpp)
add_executable(toLower709 toLower709.cpp)
add_executable(baseball682 baseball682.cpp)
add_executable(robot657 robot657.cpp)
add_executable(ticTacToe1275 ticTacToe1275.cpp)
add_executable(robot1041 robot1041.cpp)
add_executable(wealth1672 wealth1672.cpp)
add_executable(diagonalSum1572 diagonalSum1572.cpp)
add_executable(spiralMatrix54 spiralMatrix54.cpp)
add_executable(zeroMatrix73 zeroMatrix73.cpp)
add_executable(odd1523 odd1523.cpp)
add_executable(salary1491 salary1491.cpp)
add_executable(lemonade860 lemonade860.cpp)
add_executable(lpt976 lpt976.cpp)
add_executable(line1232 line1232.cpp)#
add_executable(binary67 binary67.cpp)
add_executable(multiply43 multiply43.cpp)
add_executable(pow50 pow50.cpp)#
add_executable(merge21 merge21.cpp)
add_executable(reverseList206 reverseList206.cpp)
add_executable(add2 add2.cpp)
add_executable(add445 add445.cpp)
add_executable(gcds1071 gcds1071.cpp)

# leetcode 75
add_executable(candy1431 candy1431.cpp)
add_executable(flower605 flower605.cpp)
add_executable(vowels345 vowels345.cpp)
add_executable(words151 words151.cpp)

# Concurrency
add_executable(fizzBuzz1195 fizzBuzz1195.cpp)
add_executable(inOrder1114 inOrder1114.cpp)
add_executable(fooBar1115 fooBar1115.cpp)
add_executable(zeroEvenOdd1116 zeroEvenOdd1116.cpp)
add_executable(h2o1117 h2o1117.cpp)
add_executable(diningPhilosophers1226 diningPhilosophers1226.cpp)#

#
add_executable(add415 add415.cpp)
add_executable(median4 median4.cpp)#
