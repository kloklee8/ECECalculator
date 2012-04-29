#include <cstdlib>
#include "ExpressionParser.hpp"
#include "Exceptions.hpp"


ExpressionParser::ExpressionParser() 
{
    infix = "";
    prevAnswer = "";
}

ExpressionParser::ExpressionParser(string exp_infix)
{
    infix = exp_infix;
    prevAnswer = "";
}

string ExpressionParser::convertToPostfix()
{
    infix = convertFuncsToChar(infix);
    replaceWithPrevAnswer();

    stack<exp_element> operators;
    string operandBuffer = "";

    string::iterator it;
    for (it = infix.begin(); it != infix.end(); it++)
    {
        char current = *it;

        if (current != ' ')
        {
            if (isOperand(current))
            {
                processOperand(current, infix, it, operandBuffer);
            }
            else if (isOperator(current))
            {
                processOperator(current, operators);
            }
            else if (isFunction(current))
            {
                processFunction(current, operators);
            }
            else if (current == '(' || current == ')')
            {
                processParen(current, operators);
            }
            else
            {
                throw InvalidCharException();
            }
        }
    }

    while (!operators.empty())
    {
        expression.push_back(operators.top());
        operators.pop();
    }
    
    string postfix = "";
    deque<exp_element>::iterator expIt;
    for (expIt = expression.begin(); expIt != expression.end(); expIt++)
    {
        postfix += (*expIt).data + " ";
    }

    return postfix;
}

void ExpressionParser::replaceWithPrevAnswer()
{
    while (infix.find("#") != string::npos)
    {
        infix.replace(infix.find("#"), 1, prevAnswer);
    }
}

void ExpressionParser::setExpression(string exp)
{
    infix = exp;
    emptyExpressionQueue();
    convertToPostfix();
}

string ExpressionParser::evaluateExpression()
{
    if (expression.size() == 0)
    {
        if (infix == "")
        {
            return "";
        }
        convertToPostfix();
    }

    stack<exp_element> operands;

    deque<exp_element>::iterator it;
    for (it = expression.begin(); it != expression.end(); it++)
    {
        if ((*it).dataType == OPERAND)
        {
            operands.push(*it);
        }
        else if (((*it).dataType == OPERATOR))
        {
            if (operands.size() < 2)
            {
                throw InvalidPostfixException();
            }
            
            exp_element rightOp = operands.top();
            operands.pop();
            exp_element leftOp = operands.top();
            operands.pop();

            exp_element result = executeOperator(*it, leftOp, rightOp);
            operands.push(result);
        }
        else if (((*it).dataType == FUNCTION))
        {
            if (operands.size() < 1)
            {
                throw InvalidPostfixException();
            }

            exp_element foperand = operands.top();
            operands.pop();

            exp_element result = executeFunction(*it, foperand);
            operands.push(result);
        }
    }
    
    if (operands.size() > 1)
    {
        throw InvalidPostfixException();
    }
    
    exp_element finalValue = operands.top();
    operands.pop();
    
    prevAnswer = finalValue.data;
    return finalValue.data;
}

exp_element ExpressionParser::newElement(const DATA_TYPE type, const string data)
{
    exp_element newElement;
    newElement.dataType = type;
    newElement.data = data;

    return newElement;
}

void ExpressionParser::processOperand(const char current, string& infix, string::iterator it, string& curBuffer)
{
    curBuffer += current;
    string::iterator nextIt = it;
    nextIt++;

    if ((nextIt == infix.end()) || (!isOperand(*(nextIt))))
    {
        exp_element newOperand = newElement(OPERAND, curBuffer);
        expression.push_back(newOperand);
        curBuffer = "";
    }
}

void ExpressionParser::processOperator(const char current, stack<exp_element>& operators)
{
    exp_element newOperator = newElement(OPERATOR, string(1, current));

    if (operators.empty())
    {
        operators.push(newOperator);
    }
    else
    {
        while (!operators.empty() && operators.top().dataType == OPERATOR)
        {
            if (operators.top().dataType == OPERATOR &&
                (isLeftAssociative(current) ? 
                    precedenceOf(current) <= precedenceOf(operators.top().data[0]) : // left associative
                    precedenceOf(current) < precedenceOf(operators.top().data[0])))  // right associative
            {
                expression.push_back(operators.top());
                operators.pop();
            }
            else
            {
                break;
            }                     
        }
        operators.push(newOperator);
    }
}

void ExpressionParser::processFunction(const char current, stack<exp_element>& operators)
{
    exp_element newFunct = newElement(FUNCTION, string(1, current));
    operators.push(newFunct);
}

void ExpressionParser::processParen(const char current, stack<exp_element>& operators)
{
    if (current == '(')
    {
        exp_element openParen = newElement(PAREN, "(");
        operators.push(openParen);
    }
    else if (current == ')')
    {
        if (operators.size() == 0)
        {
            throw ParenthesesException();
        }

        while (operators.top().dataType != PAREN)
        {
            expression.push_back(operators.top());
            operators.pop();
            if (operators.size() == 0)
            {
                throw ParenthesesException();
            }
        }
        operators.pop();

        if (!operators.empty())
        {
            if (operators.top().dataType == FUNCTION)
            {
                expression.push_back(operators.top());
                operators.pop();
            }
        }
    }
}

void ExpressionParser::emptyExpressionQueue()
{
    expression.erase(expression.begin(), expression.end());
}
