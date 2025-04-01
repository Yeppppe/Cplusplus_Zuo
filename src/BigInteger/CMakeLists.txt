cmake_minimum_required(VERSION 3.10)
# 项目名称和版本
project(BigInteger)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
    src/BigInteger.cpp
    src/SignedBigInteger.cpp
)

set(TEST_SOURCE
    src/test.cpp    
)

add_library(biginteger ${SOURCES})

add_executable(biginteger_test src/test.cpp)

target_link_libraries(biginteger_test biginteger)