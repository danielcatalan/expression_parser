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
    virtual ~IToken(){};
    virtual bool IsNumber()=0;
    TokenType getType();

};

class NumberToken : public IToken
{
public:
    NumberToken(double number);
    double value;
    bool IsNumber() override;

};



using TokenQueue = std::queue<std::unique_ptr<IToken>>;
using TokenStack = std::stack<std::unique_ptr<IToken>>;

TokenQueue StringToTokenQueue(const char * str);

TokenQueue ShuntingYard(TokenQueue& tokens_in);

NodeStack TokensToNodes(TokenQueue& tokens_in);



#endif // TOKEN_HPP