cmake_minimum_required(VERSION 3.7)
project(symbol_table_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES symbol.cpp symbol.h symbol_table_exception.cpp symbol_table_exception.h symbol_table.cpp symbol_table.h)
add_library(symbol_table_cpp STATIC ${SOURCE_FILES})
