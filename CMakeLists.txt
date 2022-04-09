cmake_minimum_required(VERSION 3.16.0)

project(ExpressionParser)


add_library(ExpressionParser STATIC 
    src/ExpressionParser.cpp
    src/Node.cpp
    src/Operators.cpp
    src/OperatorToken.cpp
    src/SToken.cpp
    src/Token.cpp
    src/ShuntingYard.cpp)

target_include_directories(ExpressionParser PUBLIC include)


enable_testing()
add_subdirectory(Tests)