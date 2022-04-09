#include "ShuntingYard.hpp"
#include "OperatorToken.hpp"

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
        else if(token->IsOperator())
        {
            if((!operator_stack.empty()) && operator_stack.top()->IsOperator())
            {
                OperatorToken* ptoken = dynamic_cast<OperatorToken*>(token.get());
                OperatorToken* ptoken_top = dynamic_cast<OperatorToken*>(operator_stack.top().get());
                if(ptoken_top->Precedence() >= ptoken->Precedence())
                {
                    tokens_out.push(std::move(operator_stack.top()));
                    operator_stack.pop();
                    operator_stack.push(std::move(token));
                }
            }
            else
            {
                operator_stack.push(std::move(token));
            }
        }
    }

    while (!operator_stack.empty())
    {
        tokens_out.push(std::move(operator_stack.top()));
        operator_stack.pop();
    }
    
    return tokens_out;
}