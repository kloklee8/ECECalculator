#include <cstdlib>
#include <sstream>
#include <cmath>
#include "SciCalcParser.hpp"
#include "Exceptions.hpp"

static const double PI = std::atan(1.0)*4;

char SciCalcParser::validOps[NUMSCIOPS] = {'+', '-', '*', '/', '%', '^'};
char SciCalcParser::validFuncts[NUMSCIFUNCTS] = {'B', 'D', 'G', 'S', 'C', 'T', 'L', 'N', 'E', 'R', 'F', 'A', 'O', 'I'};
string SciCalcParser::validFunctWords[NUMSCIFUNCTS] = {"arcsin", "arccos", "arctan", "sin", "cos", "tan", "log", "ln", "exp", "sqrt", "fact", "abs", "floor", "ceil"};

SciCalcParser::SciCalcParser() : ExpressionParser() {}
SciCalcParser::SciCalcParser(string infix) : ExpressionParser(infix) {}

bool SciCalcParser::isOperand(const char op)
{
    // allows . for floating points, and p is the constant PI.
    return (((op >= '0') && (op <= '9')) || op == '.' || op == 'p');
}

bool SciCalcParser::isOperator(const char op)
{
    for (int i = 0; i < NUMSCIOPS; i++)
    {
        if (op == validOps[i])
        {
            return true;
        }
    }
    return false;
}

bool SciCalcParser::isFunction(const char func)
{
    for (int i = 0; i < NUMSCIFUNCTS; i++)
    {
        if (func == validFuncts[i])
        {
            return true;
        }
    }
    return false;
}

int SciCalcParser::precedenceOf(const char op)
{
    switch (op)
    {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
        case '%':
            return 2;
            break;
        case '^':
            return 3;
            break;
        default:
            return -1;
    }   
}

bool SciCalcParser::isLeftAssociative(const char op)
{
    switch (op)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return true;
            break;
        default:
            return false;
    }
}

exp_element SciCalcParser::executeOperator(const exp_element op, const exp_element leftOp, const exp_element rightOp)
{
    char curOp = (op.data)[0];

    if (!isOperator(curOp))
    {
        return newElement(INVALID, 0);
    }
    
    double left, right;
    if (leftOp.data == "p")
    {
        left = PI;
    }
    else
    {
        left = atof(leftOp.data.c_str());
    }
    if (rightOp.data == "p")
    {
        right = PI;
    }
    else
    {
        right = atof(rightOp.data.c_str());
    }
    double result = 0;
    
    switch (curOp)
    {
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            result = left / right;
            break;
        case '%':
            result = fmod(left, right);
            break;
        case '^': 
            result = pow(left, right);
            break;
        default:
            throw InvalidOperatorException();
            break;
    }
    
    std::ostringstream resultStr;
    resultStr << result;

    return newElement(OPERAND, resultStr.str());
}

exp_element SciCalcParser::executeFunction(const exp_element funct, const exp_element foperand)
{
    char curFunct = (funct.data)[0];

    if (!isFunction(curFunct))
    {
        return newElement(INVALID, 0);
    }
    
    double foper;
    if (foperand.data == "p")
    {
        foper = PI;
    }
    else
    {
        foper = atof(foperand.data.c_str());
    }
    double result = 0;
    
    switch (curFunct)
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
        case 'B':
            result = asin(foper);
            break;
        case 'D':
            result = acos(foper);
            break;
        case 'G':
            result = atan(foper);
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
            result = factorial((int)foper);
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
    }

    std::ostringstream resultStr;
    resultStr << result;

    return newElement(OPERAND, resultStr.str());
}

string SciCalcParser::convertFuncsToChar(string infix)
{
    for (int i = 0; i < NUMSCIFUNCTS; i++)
    {
        while (infix.find(validFunctWords[i]) != string::npos)
        {
            infix.replace(infix.find(validFunctWords[i]), validFunctWords[i].length(), string(1, validFuncts[i]));
        }
    }

    return infix;
}

int SciCalcParser::factorial(int op)
{
    if (op <= 1)
    {
        return 1;
    }

    return op * factorial(op - 1);
}
