#include "ExpressionParser.hpp"
#include <cmath>
#include "Token.hpp"
#include "OperatorToken.hpp"
#include "ShuntingYard.hpp"


ExpressionParser::ExpressionParser(const char* expression)
{
    // convert string to queue of tokens
    auto tokens_in = StringToTokenQueue(expression);

    // Use Shunting-Yard Algorithm
    auto tokens_out = ShuntingYard(tokens_in);

    //Covert Tokens to Nodes
    auto node_stack = TokensToNodes(tokens_out);
    
    this->node = std::move(node_stack.top());
    node_stack.pop();
    this->node->MapTree(node_stack);
}


double ExpressionParser::Calculate()
{
    if(node.get() != nullptr)
    {
        return this->node->Calculate();
    }
    else
    {
        return NAN;
    }
}
