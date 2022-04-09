#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <queue>
#include <memory>
#include <stack>
#include "Node.hpp"

enum class TokenType
{
    None,
    Number,
    Operator
};



class IToken
{
protected:
    TokenType type;

public:
    IToken(TokenType t);
    virtual ~IToken() = default;
    bool IsNumber();
    bool IsOperator();
    TokenType getType();

};

class NumberToken : public IToken
{
public:
    NumberToken(double number);
    double value;
};



using TokenQueue = std::queue<std::unique_ptr<IToken>>;
using TokenStack = std::stack<std::unique_ptr<IToken>>;

TokenQueue ExpressionToTokens(const char * str);

NodeStack TokensToNodes(TokenQueue& tokens_in);



#endif // TOKEN_HPP