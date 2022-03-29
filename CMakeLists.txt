cmake_minimum_required(VERSION 3.16.0)

project(ExpressionParser)

# TODO: Simplify this. Use src/ and include/ only remove subdirectories



add_library(ExpressionParser STATIC 
    src/ExpressionParser.cpp
    src/Node.cpp
    src/Operators.cpp
    src/OperatorToken.cpp
    src/SToken.cpp
    src/Token.cpp)
target_include_directories(ExpressionParser PUBLIC include)

# target_link_libraries(ExpressionParser token)

add_subdirectory(Tests)