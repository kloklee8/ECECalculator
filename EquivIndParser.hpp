#ifndef EQUIVINDPARSER_H
#define EQUIVINDPARSER_H
#include "EquivComponentParser.hpp"

class EquivIndParser : public EquivComponentParser
{
public:
    EquivIndParser(string infix);
    exp_element executeOperator(const exp_element op, const exp_element leftOp, const exp_element rightOp);
};

#endif
