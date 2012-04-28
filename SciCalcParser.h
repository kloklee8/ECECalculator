#ifndef SCICALCPARSER_H
#define SCICALCPARSER_H
#include "ExpressionParser.h"

#define NUMOPS 6
#define NUMFUNCTS 11

class SciCalcParser : public ExpressionParser
{
    public:
        bool isOperand(const char op);
        bool isOperator(const char op); 
        bool isFunction(const char op);
        bool isLeftAssociative(const char op);
        int precedence(const char op);
        exp_element executeOperator(const exp_element op, const exp_element leftOp, const exp_element rightOp);
        exp_element executeFunction(const exp_element funct, const exp_element foperand);
        string convertFuncsToChar(string infix);

    private:
        static char validOps[NUMOPS];
        static char validFuncts[NUMFUNCTS];
        static string validFunctWords[NUMFUNCTS];

        int fact(int op);
};

#endif
