#include <exception>

using std::exception;

struct ParenthesesException : public exception
{
    const char* what() const throw()
    {
        return "Invalid placement of parentheses.";
    }
};

struct InvalidCharException : public exception
{
    const char* what() const throw()
    {
        return "Invalid character(s) detected.";
    }
};

struct InvalidPostfixException : public exception
{
    const char* what() const throw()
    {
        return "Attempted to evaluate invalid postfix expression.";
    }
};

struct NoExpressionException : public exception
{
    const char* what() const throw()
    {
        return "Cannot evaluate without an expression.";
    }
};

struct InvalidModeException : public exception
{
    const char* what() const throw()
    {
        return "Attempted calculations on an invalid mode.";
    }
};

struct InvalidOperatorException : public exception
{
    const char* what() const throw()
    {
        return "Attempted to evaluate with an invalid operator.";
    }
};
