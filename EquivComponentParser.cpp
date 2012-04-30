#include <cstdlib>
#include <sstream>
#include <cmath>
#include "EquivComponentParser.hpp"
#include "Exceptions.hpp"

char EquivComponentParser::validOps[NUMEQOPS] = {'+', '|'};

EquivComponentParser::EquivComponentParser() : ExpressionParser() 
{
    currentMode = RESISTANCE;
}
EquivComponentParser::EquivComponentParser(string infix) : ExpressionParser(infix) 
{
    currentMode = RESISTANCE;
}

void EquivComponentParser::setMode(SUB_MODE mode)
{
    currentMode = mode;
}

/*
 * Operands include any floating point numbers and integers.
 */
bool EquivComponentParser::isOperand(const char op)
{
    return (((op >= '0') && (op <= '9')) || op == '.');
}

/*
 * Runs through validOps array to matach op with a valid operator.
 */
bool EquivComponentParser::isOperator(const char op)
{
    for (int i = 0; i < NUMEQOPS; i++)
    {
        if (op == validOps[i])
        {
            return true;
        }
    }
    return false; 

}

/*
 * Higher numbers are higher precedence.  In this case 
 * we want to perform all parallel calculations before series.
 */
int EquivComponentParser::precedenceOf(const char op)
{ 
    switch (op)
    {
        case '+':
            return 1;
            break;
        case '|':
            return 2;
            break;
        default:
            return -1;
    }
}

bool EquivComponentParser::isLeftAssociative(const char op)
{
    switch (op)
    {
        case '+':
        case '|':
            return true;
            break;
        default:
            return false;
    }
}

exp_element EquivComponentParser::executeOperator(const exp_element op, const exp_element leftOp, const exp_element rightOp)
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
            result = calculateSeries(left, right);
            break;
        case '|':
            result = calculateParallel(left, right);
            break;
        default:
            throw InvalidOperatorException();
            break;
    }
    
	//stuff result back into a stream.
    std::ostringstream resultStr;
    resultStr << result;

	//Replace the operation performed with it's equivalent.
    return newElement(OPERAND, resultStr.str());
}

double EquivComponentParser::calculateSeries(double left, double right)
{
    double result = 0;
    switch (currentMode)
    {
        case RESISTANCE:
        case INDUCTANCE:
            result = (left + right);
            break;
        case CAPACITANCE:
            result = (left * right) / (left + right);
            break;
        default:
            throw InvalidModeException();
    }
    
    return result;
}

double EquivComponentParser::calculateParallel(double left, double right)
{
    double result;
    switch (currentMode)
    {
        case RESISTANCE:
        case INDUCTANCE:
            result = (left * right) / (left + right);
            break;
        case CAPACITANCE:
            result = (left + right);
            break;
        default:
            throw InvalidModeException();
    }
    
    return result;
}

// no valid functions for equivalent calculations
bool EquivComponentParser::isFunction(const char func)
{
    return false;
}
exp_element EquivComponentParser::executeFunction(const exp_element funct, const exp_element foperand)
{
    return newElement(INVALID, "");
}
string EquivComponentParser::convertFuncsToChar(string infix)
{
    return infix;
}
