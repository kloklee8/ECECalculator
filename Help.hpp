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
    static string getHelp();
private:
    static void getMenuHelp();
    static void getSciHelp();
    static void getEquivHelp();
    static void getDividerHelp();
    static void getConvHelp();
    static void getFormulaHelp();
    static void getOptionHelp();
    static void pressAny();
};

#endif
