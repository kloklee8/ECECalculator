#include <cstdlib>
#include <sstream>
#include <cmath>
#include "EquivIndParser.hpp"

EquivIndParser::EquivIndParser(string infix) : EquivComponentParser(infix)
{

}

exp_element EquivIndParser::executeOperator(const exp_element op, const exp_element leftOp, const exp_element rightOp)
{
	//Check if the operator is valid
    char curOp = (op.data)[0];

    if (!isOperator(curOp))
    {
        return newElement(INVALID, 0);
    }

	//Convert ascii to floating point.
    double left = atof(leftOp.data.c_str());
    double right = atof(rightOp.data.c_str());
    double result = 0;
    
	//Peform defined operation
    switch (curOp)
    {
        case '+':
            result = (left + right);
            break;
        case '|':
            result = (left * right) / (left + right);
            break;
        default:
            break;
    }
    
	//stuff result back into a stream.
    std::ostringstream resultStr;
    resultStr << result;

	//Replace the operation performed with it's equivalent.
    return newElement(OPERAND, resultStr.str());
}
