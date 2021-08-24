cmake_minimum_required(VERSION 3.15)

project(testBitPack)

set(CXX_STANDARD 11)

add_compile_options(-g -Wfatal-errors)

include_directories(.)

file(GLOB SRCS ./*cpp)

add_executable(test ${SRCS})
