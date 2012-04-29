#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <string>
#include <deque>
#include <stack>
#include <iterator>

using std::deque;
using std::stack;
using std::string;

enum DATA_TYPE
{
    OPERAND,
    OPERATOR,
    FUNCTION,
    PAREN,
    INVALID
};
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
        
        exp_element newElement(const DATA_TYPE type, const string data);
        
        string evaluateExpression();
        void setExpression(string exp);

        // abstract functions
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
        deque<exp_element> expression;
        
        string convertToPostfix();
        void replaceWithPrevAnswer();
        
        void emptyExpressionQueue();
        
        void processOperand(const char current, string& infix, string::iterator it, string& curBuffer);
        void processOperator(const char current, stack<exp_element>& operators);
        void processFunction(const char current, stack<exp_element>& operators);
        void processParen(const char current, stack<exp_element>& operators);
};

#endif
