#include <cstdlib>
#include <sstream>
#include <cmath>
#include "EquivComponentParser.hpp"

EquivComponentParser::EquivComponentParser(string infix) : ExpressionParser(infix)
{

}

char EquivComponentParser::validOps[NUMEQOPS] = {'+', '|'};
//char EqResParser::validFuncts[NUMEQFUNCTS] = {'S', 'C', 'T', 'L', 'N', 'E', 'R', 'F', 'A', 'O', 'I'};
//string EqResParser::validFunctWords[NUMEQFUNCTS] = {"sin", "cos", "tan", "log", "ln", "exp", "sqrt", "fact", "abs", "floor", "ceil"};

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
 *	
 */
bool EquivComponentParser::isFunction(const char func)
{
    /*for (int i = 0; i < NUMEQFUNCTS; i++)
    {
        if (func == validFuncts[i])
        {
            return true;
        }
    }*/
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
    /*switch (curOp)
    {
        case '+':
            result = left + right;
            break;
        case '|':
            result = (left * right) / (left + right);
            break;
        default:
            break;
    }*/
    
	//stuff result back into a stream.
    std::ostringstream resultStr;
    resultStr << result;

	//Replace the operation performed with it's equivalent.
    return newElement(OPERAND, resultStr.str());
}

exp_element EquivComponentParser::executeFunction(const exp_element funct, const exp_element foperand)
{
    /*char curFunct = (funct.data)[0];

    if (!isFunction(curFunct))
    {
        return newElement(INVALID, 0);
    }

    double foper = atof(foperand.data.c_str());*/
    double result = 0;

    /*switch (curFunct)
    {
        case 'S':
            result = sin(foper);
            break;
        case 'C':
            result = cos(foper);
            break;
        case 'T':
            result = tan(foper);
            break;
        case 'L':
            result = log10(foper);
            break;
        case 'N':
            result = log(foper);
            break;
        case 'E':
            result = exp(foper);
            break;
        case 'R':
            result = sqrt(foper);
            break;
        case 'F':
            result = fact((int)foper);
            break;
        case 'A':
            result = abs(foper);
            break;
        case 'O':
            result = floor(foper);
            break;
        case 'I':
            result = ceil(foper);
            break;
        default:
            break;
    }*/

    std::ostringstream resultStr;
    resultStr << result;

    return newElement(OPERAND, resultStr.str());
}

string EquivComponentParser::convertFuncsToChar(string infix)
{
    /*for (int i = 0; i < NUMEQFUNCTS; i++)
    {
        while (infix.find(validFunctWords[i]) != string::npos)
        {
            infix.replace(infix.find(validFunctWords[i]), validFunctWords[i].length(), string(1, validFuncts[i]));
        }
    }*/

    return infix;
}
