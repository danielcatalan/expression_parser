#include <gtest/gtest.h>
#include "Token.hpp"
#include "OperatorToken.hpp"
#include "SToken.hpp"

TEST(TokenTest, Str2Tk1)
{
    auto q = StringToTokenQueue("4+3");
    ASSERT_EQ(3, q.size());

    auto x = std::move(q.front());
    q.pop();
    EXPECT_EQ(4, dynamic_cast<NumberToken*>(x.get())->value );

    auto y = std::move(q.front());
    q.pop();
    EXPECT_EQ(OperatorType::Add, dynamic_cast<OperatorToken*>(y.get())->op);

    auto z = std::move(q.front());
    q.pop();
    EXPECT_EQ(3, dynamic_cast<NumberToken*>(z.get())->value );
}

TEST(TokenTest, Str2Tk)
{
    auto q = StringToTokenQueue("5-2");
    ASSERT_EQ(3, q.size());

    auto x = std::move(q.front());
    q.pop();
    EXPECT_EQ(5, dynamic_cast<NumberToken*>(x.get())->value );

    auto y = std::move(q.front());
    q.pop();
    EXPECT_EQ(OperatorType::Subtract, dynamic_cast<OperatorToken*>(y.get())->op);

    auto z = std::move(q.front());
    q.pop();
    EXPECT_EQ(2, dynamic_cast<NumberToken*>(z.get())->value );
}

TEST(StringTokens, FindPositions)
{
    std::vector<int> expected ={1,3};
    auto x = GetOperatorMarkers("3+4+5");

    EXPECT_EQ(expected, x);
}

TEST(StringTokens, SimplePlus)
{
    std::vector<std::string> expected;
    expected.push_back("3");
    expected.push_back("+");
    expected.push_back("4");

    auto x = STokens("3+4");
    EXPECT_EQ(expected, x);
}

TEST(StringTokens, DecimalPlus)
{
    std::vector<std::string> expected;
    expected.push_back("5.3");
    expected.push_back("+");
    expected.push_back("2.1");

    auto x = STokens("5.3+2.1");
    EXPECT_EQ(expected, x);
}

TEST(StringTokens, MultiplePluses)
{
    std::vector<std::string> expected;
    expected.push_back("4");
    expected.push_back("+");
    expected.push_back("5");
    expected.push_back("+");
    expected.push_back("2");
    expected.push_back("+");
    expected.push_back("3");

    auto x = STokens("4+5+2+3");
    EXPECT_EQ(expected, x);
}