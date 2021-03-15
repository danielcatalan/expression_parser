#include <gtest/gtest.h>
#include "Token.hpp"
#include "OperatorToken.hpp"

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