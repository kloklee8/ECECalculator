#include <cstdlib>
#include <string>
#include "ExpressionParser.hpp"
#include "Exceptions.hpp"

using std::string;

ExpressionParser::ExpressionParser()
{
    infix = "";
    prevAnswer = "0";
}

ExpressionParser::ExpressionParser(string exp_infix)
{
    infix = exp_infix;
    prevAnswer = "0";
}

string ExpressionParser::convertToPostfix()
{
    infix = convertFuncsToChar(infix);
    // replace all instances of '#' with the value of the previous answer.
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
                processOperand(current, it, operandBuffer, operators);
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
    
    //pushes the rest of the operators stack to the end of the expression queue
    while (!operators.empty())
    {
        postfixExpression.push_back(operators.top());
        operators.pop();
    }
    
    // create the postfix expression from the expression queue.
    string postfix = "";
    deque<exp_element>::iterator expIt;
    for (expIt = postfixExpression.begin(); expIt != postfixExpression.end(); expIt++)
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
    emptyPostfixExpressionQueue();
    convertToPostfix();
}

string ExpressionParser::evaluateExpression()
{
    if (infix == "")
    {
        throw NoExpressionException();
    }
    if (postfixExpression.size() == 0)
    {
        convertToPostfix();
    }

    stack<exp_element> operands;

    deque<exp_element>::iterator it;
    for (it = postfixExpression.begin(); it != postfixExpression.end(); it++)
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

void ExpressionParser::processOperand(const char current, string::iterator it, string& curBuffer, stack<exp_element>& operators)
{
    if (current == '-' && curBuffer != "")
    {
        exp_element newOperand = newElement(OPERAND, curBuffer);
        postfixExpression.push_back(newOperand);
        curBuffer = "";
        
        processOperator(current, operators);
    }
    else
    {
        string::iterator nextIt = it;
        curBuffer += current;
        nextIt++;
        
        if ((nextIt == infix.end()) || (!isOperand(*(nextIt))))
        {
            exp_element newOperand = newElement(OPERAND, curBuffer);
            postfixExpression.push_back(newOperand);
            curBuffer = "";
        }
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
            if (isLeftAssociative(current) ? 
                    precedenceOf(current) <= precedenceOf(operators.top().data[0]) : // left associative
                    precedenceOf(current) < precedenceOf(operators.top().data[0]))  // right associative
            {
                postfixExpression.push_back(operators.top());
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
            postfixExpression.push_back(operators.top());
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
                postfixExpression.push_back(operators.top());
                operators.pop();
            }
        }
    }
}

void ExpressionParser::emptyPostfixExpressionQueue()
{
    postfixExpression.erase(postfixExpression.begin(), postfixExpression.end());
}
