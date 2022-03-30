
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(Test test_token.cpp test_expression_parser.cpp test_stoken.cpp)

target_link_libraries(Test  ExpressionParser GTest::gtest_main)

gtest_discover_tests(Test)