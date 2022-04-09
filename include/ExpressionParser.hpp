#ifndef EXPRESSIONPARSER_HPP
#define EXPRESSIONPARSER_HPP

#include <memory>
#include "Node.hpp"


class ExpressionParser
{
private:
    NodePtr node;
public:
    ExpressionParser(const char* expression);

    double Calculate();
};



#endif // EXPRESSIONPARSER_HPP