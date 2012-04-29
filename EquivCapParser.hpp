#ifndef EQUIVCAPPARSER_H
#define EQUIVCAPPARSER_H
#include "EquivComponentParser.hpp"

class EquivCapParser : public EquivComponentParser
{
public:
    EquivCapParser(string infix);
    exp_element executeOperator(const exp_element op, const exp_element leftOp, const exp_element rightOp);
};

#endif
