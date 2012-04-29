#ifndef SCICALCPARSER_H
#define SCICALCPARSER_H
#include "ExpressionParser.hpp"

#define NUMSCIOPS 6
#define NUMSCIFUNCTS 11

class SciCalcParser : public ExpressionParser
{
    public:
        SciCalcParser(string infix);
        bool isOperand(const char op);
        bool isOperator(const char op); 
        bool isFunction(const char op);
        bool isLeftAssociative(const char op);
        int precedenceOf(const char op);
        exp_element executeOperator(const exp_element op, const exp_element leftOp, const exp_element rightOp);
        exp_element executeFunction(const exp_element funct, const exp_element foperand);
        string convertFuncsToChar(string infix);

    private:
        static char validOps[NUMSCIOPS];
        static char validFuncts[NUMSCIFUNCTS];
        static string validFunctWords[NUMSCIFUNCTS];

        int factorial(int op);
};

#endif
