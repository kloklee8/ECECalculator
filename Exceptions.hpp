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