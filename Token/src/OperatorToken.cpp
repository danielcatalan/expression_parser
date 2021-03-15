#include "OperatorToken.hpp"

double Add(double l, double r)
{
    return l+r;
}

OperatorToken::OperatorToken(OperatorType type) : op(type), IToken(TokenType::Operator)
{
    this->func = Add;
}

bool OperatorToken::IsNumber()
{
    return false;
}
