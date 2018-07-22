cmake_minimum_required(VERSION 3.0)
project(symbol_table_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES symbol.cpp symbol.h symbol_table_exception.cpp symbol_table_exception.h symbol_table.cpp symbol_table.h)
add_library(symbol_table_cpp STATIC ${SOURCE_FILES})
add_library(symbol_table_cpp_shared SHARED ${SOURCE_FILES})

set(SYMBOL_TABLE_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE STRING "Symbol table include path.")

install(TARGETS symbol_table_cpp symbol_table_cpp_shared
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
