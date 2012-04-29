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

		//Make three different 
		exp_element executeFunction(const exp_element funct, const exp_element foperand);
        string convertFuncsToChar(string infix);

    private:
        static char validOps[NUMEQOPS];
        //static char validFuncts[NUMEQFUNCTS];
        //static string validFunctWords[NUMEQFUNCTS];
};

#endif
