cmake_minimum_required(VERSION 3.16.0)

project(ExpressionParser)

# TODO: Simplify this. Use src/ and include/ only remove subdirectories
add_subdirectory(Operators)
add_subdirectory(Token)
add_subdirectory(Node)
add_subdirectory(ExpressionParser)

add_library(ExpressionParser STATIC "")
target_link_libraries(ExpressionParser expression_parser operators token node)

add_subdirectory(Tests)