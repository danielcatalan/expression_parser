#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <stack>


class Node
{
public:

    virtual double Calculate() = 0;
    virtual void MapTree(std::stack<std::unique_ptr<Node>>& stack) = 0;
    virtual ~Node() = default;
};

using NodePtr = std::unique_ptr<Node>;

using NodeStack = std::stack<NodePtr>;


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
    NodePtr lnode;
    NodePtr rnode;
    double(*func)(double,double);

public:
    OperatorNode(double(*f)(double,double));
    double Calculate() override;
    void MapTree(NodeStack& stack) override;
};
#endif // NODE_HPP