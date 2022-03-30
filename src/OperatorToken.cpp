#include "OperatorToken.hpp"
#include <cmath>

#define CREATE_BINARY_OPERATION(name, result) \
    double name(double A, double B) {return result;}

CREATE_BINARY_OPERATION(None, NAN)
CREATE_BINARY_OPERATION(Add,  A + B)
CREATE_BINARY_OPERATION(Sub,  A - B)
CREATE_BINARY_OPERATION(Mult, A * B)
CREATE_BINARY_OPERATION(Div,  A / B)


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

int OperatorToken::Precedence()
{
    switch (op)
    {
    case OperatorType::Add:
    case OperatorType::Subtract:
        return 2;
        break;
    case OperatorType::Multiply:
    case OperatorType::Divide:
        return 3;
        break;
    case OperatorType::Exponent:
        return 4;
    default:
        return 0;
        break;
    }

}