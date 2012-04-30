#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <string>
#include <deque>
#include <stack>
#include <iterator>
#include "enum.hpp"

using std::deque;
using std::stack;
using std::string;

struct exp_element
{
    DATA_TYPE dataType;

    string data;
};

class ExpressionParser
{
    public:
        ExpressionParser();
        ExpressionParser(string infix);
        
        void setExpression(string exp);
        string evaluateExpression();
        
        exp_element newElement(const DATA_TYPE type, const string data);

        // abstract functions; defined by child classes, but declared here
        // because it is required by the convertToPostfix() and evaluateExpression()
        // functions, which are completely implemented in this class.
        virtual bool isOperand(const char op) = 0;
        virtual bool isOperator(const char op) = 0;
        virtual bool isFunction(const char op) = 0;
        virtual bool isLeftAssociative(const char op) = 0;
        virtual int precedenceOf(const char op) = 0;
        virtual exp_element executeOperator(const exp_element op, const exp_element leftOp, const exp_element rightOp) = 0;
        virtual exp_element executeFunction(const exp_element funct, const exp_element foperand) = 0;
        virtual string convertFuncsToChar(string infix) = 0;

    private:
        string infix;
        string prevAnswer;
        deque<exp_element> postfixExpression;
        
        string convertToPostfix();
        void replaceWithPrevAnswer();
        void emptyPostfixExpressionQueue();
        
        void processOperand(const char current, string::iterator it, string& curBuffer);
        void processOperator(const char current, stack<exp_element>& operators);
        void processFunction(const char current, stack<exp_element>& operators);
        void processParen(const char current, stack<exp_element>& operators);
};

#endif
