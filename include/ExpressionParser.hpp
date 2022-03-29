#ifndef EXPRESSIONPARSER_HPP
#define EXPRESSIONPARSER_HPP

#include <memory>
#include "Node.hpp"

using NodePtr = std::unique_ptr<Node>;

class ExpressionParser
{
private:
     NodePtr node = 0;
public:
    ExpressionParser(const char* expression);
    ~ExpressionParser();

    double Calculate();
};



#endif // EXPRESSIONPARSER_HPP