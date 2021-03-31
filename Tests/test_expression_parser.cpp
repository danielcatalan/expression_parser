#include <gtest/gtest.h>
#include "ExpressionParser.hpp"

TEST(ExpressionParser, SimpleAdd)
{
    ExpressionParser ep("4+3");
    EXPECT_EQ(7, ep.Calculate());

}


TEST(ExpressionParser, SimpleSubtract)
{
    ExpressionParser ep("4-5");
    EXPECT_EQ(-1, ep.Calculate());

}

TEST(ExpressionParser, AddSubtract)
{
    ExpressionParser ep("3-4+5");
    EXPECT_EQ(4, ep.Calculate());
}