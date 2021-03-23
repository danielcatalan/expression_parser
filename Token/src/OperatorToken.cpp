#include "OperatorToken.hpp"
#include <cmath>

double None(double l, double r)
{
    return NAN;
}

double Add(double l, double r)
{
    return l+r;
}

double Sub(double l, double r)
{
    return l-r;
}

auto GetFunc(OperatorType type)
{
    switch (type)
    {
    case OperatorType::Add:
        return Add;
        break;
    case OperatorType::Subtract:
        return Sub;
        break;
    default:
        return None;
        break;
    }
}

OperatorToken::OperatorToken(OperatorType type) : op(type), IToken(TokenType::Operator)
{
    this->func = GetFunc(type);
}

bool OperatorToken::IsNumber()
{
    return false;
}
