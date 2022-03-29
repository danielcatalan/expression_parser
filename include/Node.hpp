#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <stack>


class Node
{
private:
    /* data */
public:
    virtual ~Node(){};
    virtual double Calculate() = 0;
    virtual void MapTree(std::stack<std::unique_ptr<Node>>& stack) = 0;
};

using NodeStack = std::stack<std::unique_ptr<Node>>;

class NumberNode : public Node
{
private:
    double value;

public:
    NumberNode(double val);
    double Calculate() override;
    void MapTree(NodeStack& stack) override;
};

class OperatorNode : public Node
{
private:
    std::unique_ptr<Node> lnode;
    std::unique_ptr<Node> rnode;
    double(*func)(double,double);

public:
    OperatorNode(double(*f)(double,double));
    double Calculate() override;
    void MapTree(NodeStack& stack) override;
};
#endif // NODE_HPP