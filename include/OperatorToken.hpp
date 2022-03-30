#ifndef OPERATORTOKEN_HPP
#define OPERATORTOKEN_HPP
#include "Token.hpp"

enum class OperatorType // Based on PEMDAS
{
    None,
    Add,
    Subtract,
    Divide,
    Multiply,
    Exponent,
    Parenthesis
};

class OperatorToken : public IToken
{
public:
    OperatorType op;
    double (*func)(double,double);
    OperatorToken(OperatorType type);
    int Precedence();
};

#endif // OPERATORTOKEN_HPP
