#ifndef HELP_H
#define HELP_H

#include <string>
#include "enum.hpp"

using std::string;

/*
 * The Help class provides instructions on how to use the current tools 
 * properly.  This includes the syntax to type in an expression within the 
 * current mode.
 */
class Help
{
public:
    static string getHelp(MODE mode, SUB_MODE submode);
private:
    static void getMenuHelp(string&);
    static void getSciHelp(string&);
    static void getEquivHelp(string&, SUB_MODE submode);
};

#endif
