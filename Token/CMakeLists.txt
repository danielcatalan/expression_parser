add_library(token OBJECT src/Token.cpp src/OperatorToken.cpp)
target_include_directories(token PUBLIC include)
target_link_libraries(token node)