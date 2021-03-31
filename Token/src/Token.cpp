#include "Token.hpp"
#include "OperatorToken.hpp"
#include "SToken.hpp"
#include <cstdlib>
#include <map>

std::unique_ptr<Node> TokenToNode(std::unique_ptr<IToken>& token);

std::unique_ptr<IToken> TokenFactory(const std::string& stoken);


IToken::IToken(TokenType t) : type(t){}

TokenType IToken::getType()
{
    return this->type;
}

NumberToken::NumberToken(double number) : value(number), IToken(TokenType::Number)
{

}

bool NumberToken::IsNumber()
{
    return true;
}


OperatorType OperatorLookUp(char c)
{
    // static std::map<char, OperatorType> op_lut({
    //     {'+', OperatorType::Add},
    //     {'-', OperatorType::Subtract},
    //     {'/', OperatorType::Divide},
    //     {'*', OperatorType::Multiply},
    //     {'^', OperatorType::Exponent}
    // });

    // return op_lut[c];

    switch (c)
    {
    case '+':
        return OperatorType::Add;
        break;
    case '-':
        return OperatorType::Subtract;
        break;
    case '/':
        return OperatorType::Divide;
        break;
    case '*':
        return OperatorType::Multiply;
        break;
    case '^':
        return OperatorType::Exponent;
        break;
    default:
        return OperatorType::None;
        break;
    }
}

TokenQueue StringToTokenQueue(const char * str)
{
    TokenQueue q;
    OperatorType op;

    auto s_tokens = STokens(str); //vector of strings eg: ["3", "+", "4",...]

    for (auto& s_token :s_tokens)
    {
        q.push(TokenFactory(s_token));
    } 

    return q;
}

std::unique_ptr<IToken> TokenFactory(const std::string& stoken)
{
    if(stoken == "+")
    {
        return std::unique_ptr<IToken>(new OperatorToken(OperatorType::Add));
    }
    else if(stoken == "-")
    {
        return std::unique_ptr<IToken>(new OperatorToken(OperatorType::Subtract));
    }
    else
    {
        auto num = std::stod(stoken);
        return std::unique_ptr<IToken>(new NumberToken(num));
    }
}

TokenQueue ShuntingYard(TokenQueue& tokens_in)
{
    // TODO: implement Shunting Yard 
    TokenQueue tokens_out;
    TokenStack operator_stack;

    while (!tokens_in.empty())
    {
        auto token = std::move(tokens_in.front());
        tokens_in.pop();

        if(token->IsNumber())
        {
            tokens_out.push(std::move(token));
        }
        else
        {
            operator_stack.push(std::move(token));
        }
    }

    while (!operator_stack.empty())
    {
        tokens_out.push(std::move(operator_stack.top()));
        operator_stack.pop();
    }
    
    return tokens_out;
}

NodeStack TokensToNodes(TokenQueue& tokens_in)
{
    NodeStack node_stack;

    while (tokens_in.size() > 0 )
    {
        auto token = std::move(tokens_in.front());
        tokens_in.pop();
        node_stack.push(TokenToNode(token));
    }

    return node_stack;
}

std::unique_ptr<Node> TokenToNode(std::unique_ptr<IToken>& token)
{
    std::unique_ptr<Node> node;

    switch(token->getType())
    {
        double value;
        double(*func)(double,double);
    case TokenType::Number:
        value = dynamic_cast<NumberToken*>(token.get())->value;
        node = std::unique_ptr<Node>(new NumberNode(value));
        break;

    case TokenType::Operator:
        func = dynamic_cast<OperatorToken*>(token.get())->func;
        node = std::unique_ptr<Node>(new OperatorNode(func));
        break;
    default:
        break;
    }
    return node;
}

