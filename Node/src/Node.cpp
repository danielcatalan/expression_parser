#include "Node.hpp"

NumberNode::NumberNode(double val) : value(val)
{

}

double NumberNode::Calculate()
{
    return this->value;
}

void NumberNode::MapTree(NodeStack& stack)
{
    // do nothing
}

OperatorNode::OperatorNode(double(*f)(double,double)): func(f)
{

}

double OperatorNode::Calculate()
{
    auto lvalue = this->lnode->Calculate();
    auto rvalue = this->rnode->Calculate();
    return this->func(rvalue, lvalue);
}

void OperatorNode::MapTree(NodeStack& stack)
{
    this->rnode = std::move(stack.top());
    stack.pop();
    this->rnode->MapTree(stack);
    
    this->lnode = std::move(stack.top());
    stack.pop();
    this->lnode->MapTree(stack);
}