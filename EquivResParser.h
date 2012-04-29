#ifndef TESTEXTENSION_H
#define TESTEXTENSION_H
#include "EquivComponentParser.h"

class EquivResParser : public EquivComponentParser
{
public:
	exp_element executeOperator(const exp_element op, const exp_element leftOp, const exp_element rightOp);
};

#endif
