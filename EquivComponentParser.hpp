#ifndef EQUIVCOMPONENTPARSER_H
#define EQUIVCOMPONENTPARSER_H
#include "ExpressionParser.hpp"

#define NUMEQOPS 2
#define NUMEQFUNCTS 0

class EquivComponentParser : public ExpressionParser
{
    public:
        EquivComponentParser();
        EquivComponentParser(string infix);
        bool isOperand(const char op);
        bool isOperator(const char op); 
        bool isFunction(const char op);
        bool isLeftAssociative(const char op);
        int precedenceOf(const char op);
        
        void setMode(SUB_MODE mode);
        
        exp_element executeOperator(const exp_element op, const exp_element leftOp, const exp_element rightOp);
        exp_element executeOperator(SUB_MODE mode, const exp_element op, const exp_element leftOp, const exp_element rightOp);
		exp_element executeFunction(const exp_element funct, const exp_element foperand);
        string convertFuncsToChar(string infix);

    private:
        static char validOps[NUMEQOPS];
        SUB_MODE currentMode;
        
        double calculateSeries(double left, double right);
        double calculateParallel(double left, double right);
};

#endif
