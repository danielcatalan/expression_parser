#include <gtest/gtest.h>
#include "SToken.hpp"

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

TEST(StringTokens, SimpleMinus)
{
    std::vector<std::string> expected;
    expected.push_back("3");
    expected.push_back("-");
    expected.push_back("4");

    auto x = STokens("3-4");
    EXPECT_EQ(expected, x);
}

TEST(StringTokens, SimplePlusMinus)
{
    std::vector<std::string> expected;
    expected.push_back("3");
    expected.push_back("+");
    expected.push_back("4");
    expected.push_back("-");
    expected.push_back("5");

    auto x = STokens("3+4-5");
    EXPECT_EQ(expected, x);
}

TEST(StringTokens, MinusPlus)
{
    std::vector<std::string> expected;
    expected.push_back("3");
    expected.push_back("-");
    expected.push_back("4");
    expected.push_back("+");
    expected.push_back("5");

    auto x = STokens("3-4+5");
    EXPECT_EQ(expected, x);
}