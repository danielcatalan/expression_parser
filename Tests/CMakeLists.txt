
find_package(GTest CONFIG REQUIRED)
add_executable(Test test_token.cpp test_expression_parser.cpp test_stoken.cpp)

target_link_libraries(Test PRIVATE ExpressionParser GTest::gtest_main)
