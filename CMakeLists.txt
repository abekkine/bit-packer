cmake_minimum_required(VERSION 3.15)

project(testBitPack)

set(CXX_STANDARD 11)

add_compile_options(-g -Wfatal-errors)
add_compile_definitions(UNIT_TESTS)

include_directories(.)
include_directories($ENV{EXT_LIB_DIR}/catch2)

add_executable(test unitTests.cpp 
    # dummyTest.cpp
    basicTests.cpp
)
