cmake_minimum_required(VERSION 3.16.0)

project(ExpressionParser)

# TODO: Simplify this. Use src/ and include/ only remove subdirectories
add_subdirectory(Operators)
add_subdirectory(Token)

add_library(ExpressionParser STATIC 
    src/ExpressionParser.cpp)
target_include_directories(ExpressionParser PUBLIC include)

target_link_libraries(ExpressionParser token)

add_subdirectory(Tests)