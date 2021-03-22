#include "Token.hpp"
#include "OperatorToken.hpp"
#include <cstdlib>
#include <map>

std::unique_ptr<Node> TokenToNode(std::unique_ptr<IToken>& token);


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

    while(str[0] != '\0')
    {
        if((op = OperatorLookUp(str[0])) != OperatorType::None)
        {
            str++;
            q.push(std::unique_ptr<IToken>(new OperatorToken(op)));
        }
        else
        {
            auto num = std::strtod(str, (char**) &str);
            q.push(std::unique_ptr<IToken>(new NumberToken(num)));
        }
    }
    return q;
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
    
    
    
    // tokens_out.push(std::unique_ptr<IToken>(new NumberToken(4)));
    // tokens_out.push(std::unique_ptr<IToken>(new NumberToken(3)));
    // tokens_out.push(std::unique_ptr<IToken>(new OperatorToken(OperatorType::Add)));
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

std::vector<std::string> STokens(const char* str)
{
    std::vector<std::string> stokens;
    std::string expr(str);
    size_t index = 0;

    while (index < expr.length())
    {
        auto pos = expr.find('+', index);

        if(pos == std::string::npos) // no more operators
        {
            stokens.push_back(expr.substr(index));
            break;    
        }

        stokens.push_back(expr.substr(index, pos-index));
        stokens.push_back(expr.substr(pos, 1));
        
        index = pos+1;
    }

    return stokens;
}