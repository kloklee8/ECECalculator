#include <iostream>
#include <string>
#include "Help.hpp"
#include "Menus.hpp"
#include "enum.hpp"

using std::cout;
using std::endl;
using std::string;

void getMenuHelp();
void getSciHelp();
void getEquivHelp();
void getDividerHelp();
void getConvHelp();
void getFormulaHelp();
void getOptionHelp();
void getCommandLineHelp();

//Current calculator mode that the user is in.
MAIN_MODE helpMode;

//Modes that make up a MODE.  Put all sub-modes here, 
//no matter which mode your in.
SUB_MODE helpSubMode;

void getHelp()
{
    helpMode = MENU;
    while (1)
    {
        switch (helpMode)
        {
            case MENU:
                getMenuHelp();
                break;
            case SCI_CALC:
                getSciHelp();
                break;
            case EQ_COMPONENT:
                getEquivHelp();
                break;
            case DIVIDER:
                getDividerHelp();
                break;
            case CONVERSION:
                getConvHelp();
                break;
            case FORMULA:
                getFormulaHelp();
                break;
            case OPTION:
                getOptionHelp();
                break;
            case HELP:
                getCommandLineHelp();
                break;
            default:
                cout << "\nExited help, returning to ECE Calculator...\n\n\n";
                return;
        }
    }
            
}

//Return help corresponding to the menu screen and how to use the entire 
//calculator.
void getMenuHelp()
{
    helpMainMenu(helpMode);    
}

//Return help corresponding to the scientific calculator mode.
void getSciHelp()
{
    cout << endl << "Scientific Calculator Help:" << endl
         << "   The scientific calculator is similar to any basic scientific calculator you have used." << endl
         << "   You enter an expression, and the result from the calculations will be displayed." << endl << endl
         << "   The features you can use in the calculator includes:" << endl
         << "       ------------------------------------------------------------------------------------------------" << endl
         << "       Evaluate basic expressions involving positive and negative numbers, and the following operators:" << endl
         << "       ------------------------------------------------------------------------------------------------" << endl
         << "           -addition: +" << endl
         << "           -subtraction: -" << endl
         << "           -multiplication: *" << endl
         << "           -division: /" << endl
         << "           -integer modulus: %" << endl
         << "           -exponents: ^" << endl << endl
         << "           Note:Any combination can be included in one expression. Parentheses are supported." << endl
         << "               Example: (5 + 3) * (10/2) - 2 + 5^2" << endl << endl
         << "       ---------------------------------" << endl
         << "       Evaluate the following functions:" << endl
         << "       ---------------------------------" << endl
         << "           Function            Word to use     Example" << endl
         << "           --------            -----------     -------" << endl
         << "           -sine               sin(x)          sin(3.14)" << endl
         << "           -cosine             cos(x)          cos(0)" << endl
         << "           -tangent            tan(x)          tan(-45)" << endl
         << "           -inverse sine       arcsin(x)       arcsin(0)" << endl
         << "           -inverse cosine     arccos(x)       arccos(0.5)" << endl
         << "           -inverse tangent    arctan(x)       arctan(1)" << endl
         << "           -logarithm base 10  log(x)          log(95)" << endl
         << "           -natural logarithm  ln(x)           ln(2.7)" << endl
         << "           -exponential (e^x)  exp(x)          exp(4)" << endl
         << "           -square root        sqrt(x)         sqrt(49)" << endl
         << "           -factorial          fact(x)         fact(5)" << endl
         << "           -absolute value     abs(x)          abs(-9)" << endl
         << "           -floor              floor(x)        floor(8.85)" << endl
         << "           -ceiling            ceil(x)         ceil(7.28)" << endl << endl
         << "           Notes: " << endl
         << "               -x can be either a number or an expression as specified in the previous bullet." << endl
         << "               -Any of the functions can be combined into one expression, as in the previous bullet." << endl
         << "                   Example: 2 * sin(3.14 / 4) + sqrt(95 + 5)" << endl
         << "               -The default units for the trig functions is radians." << endl
         << "                   To change to degrees, go to Options via the main menu, run this application" << endl
         << "                   with the -d switch. See the Help documentation via the main menu for more information." << endl << endl
         << "       -------------------------" << endl
         << "       ***ADDITIONAL FEATURES***" << endl
         << "       -------------------------" << endl
         << "           -To use the value of the previous answer, use the # sign." << endl
         << "               Example: " << endl
         << "                   10 + 2" << endl
         << "                   =12" << endl
         << "                   # * 4" << endl
         << "                   =48" << endl
         << "           -To use the constant pi, enter \"p\". Example: cos(p), tan(-p)" << endl << endl;
         
    waitForUser();
    helpMode = MENU;
}

//Return help corresponding to the equivalence component mode.
void getEquivHelp()
{
    helpEqComponentSubMenu(helpMode, helpSubMode);
                
    
    if (helpSubMode == NONE)
        return;
    else
    {
        cout << endl;
        switch (helpSubMode) 
        {
            case RESISTANCE:
                cout << "Equivalent Resistance help: \n"
                     << "   This mode is used to determine the equivalence of multiple" << endl
                     << "   resistor components that are in series or parallel." << endl
                     << "   Operators include \'+\' for series and \'|\' for parallel." << endl
                     << "   For example, if resistor 1 (1 ohms) is in series with the parallel combination of" << endl
                     << "   resistor 2 (2 ohms) and 3 (3 ohms), the following syntax can be used" << endl
                     << "   to determine the equivalent resistance:" << endl
                     << "       1 + 2|3\n";
                break;
            case CAPACITANCE:
                cout << "Equivalent Capacitance help: \n"
                     << "   This mode is used to determine the equivalence of multiple" << endl
                     << "   capacitor components that are in series or parallel." << endl
                     << "   Operators include \'+\' for series and \'|\' for parallel." << endl
                     << "   For example, if capacitor 1 (1mF) is in series with the parallel combination of" << endl
                     << "   capacitor 2 (2mF) and 3 (3mF), the following syntax can be used" << endl
                     << "   to determine the equivalent capacitance:\n"
                     << "   .001 + .002|.003\n";
                break;
            case INDUCTANCE:
                cout << "Equivalent Inductance help: \n"
                     << "   This mode is used to determine the equivalence of multiple" << endl 
                     << "   inductor components that are in series or parallel." << endl
                     << "   Operators include \'+\' for series and \'|\' for parallel." << endl
                     << "   For example, if  inductor 1 (1mH) is in series with the parallel combination of" << endl
                     << "   inductor 2 (2mH) and 3 (3mH), the following syntax can be used" << endl
                     << "   to determine the equivalent inductance:\n"
                     << "   .001 + .002|.003\n";
                break;
        }
        
        waitForUser();
        cout << endl;
        helpSubMode = NONE;
    }
}

void getDividerHelp()
{
    cout << endl << "Divider Help:" << endl
         << "   The Divider mode is used to calculate either" << endl
         << "   current division across two parallel resistors or" << endl
         << "   voltage division across two resistors in series." << endl
         << "   Upon entering, you will be prompted" << endl
         << "   to choose one of the two calculations. The calculator will" << endl
         << "   then prompt you to enter the source value and the values " << endl
         << "   of the two resistors. The division across both resistors is displayed." << endl << endl
         << "   Note: The values of the sources must be in units of Volts or Amps," << endl
         << "   and the value of the resistors must be in Ohms." << endl;
         
    waitForUser();
    helpMode = MENU;
}

void getConvHelp()
{
    cout << endl << "Conversion Help:" << endl
         << "   This mode is used to convert between two unit prefixes." << endl
         << "   The following are the supported units:" << endl;
    prefixMenu();
    cout << "   When entering this mode, you will be prompted to enter the unit" << endl
         << "   (with the corresponding menu #) to convert from, the unit to convert to," << endl
         << "   and the value to convert." << endl;
         
    waitForUser();
    helpMode = MENU;
}
    
void getFormulaHelp()
{
    cout << endl << "Formula Help:" << endl
         << "   The formula mode displays common formulas and constants used in ECE," << endl
         << "   particularly those used in analyzing circuits. When entering this mode," << endl
         << "   you will be prompted to choose which category of formulas you would" << endl
         << "   like to display. You may also choose to display all formulas" << endl
         << "   or return to the main menu." << endl;
    
    waitForUser();
    helpMode = MENU;
}

void getOptionHelp()
{
    cout << endl << "Option Help:" << endl
         << "   The options menu allow you to configure the operation of the calculator." << endl
         << "   Among the options are:" << endl
         << "       1. Angle Units: [radians, degrees]" << endl
         << "       2. Result Precision: [-1, 15], where -1 is the default " << endl
         << "          and 1 to 15 inclusive is the number of digits after the decimal." << endl
         << "       3. Scientific Notation: [On, Off], the format to display the answers." << endl << endl
         << "   To change an option, enter the corresponding number to toggle." << endl
         << "   Some options may prompt you to input the new setting." << endl;
    
    waitForUser();
    helpMode = MENU;
}

void getCommandLineHelp()
{
    cout << endl << "Command Line Help:" << endl
         << "   There are three command line switches available, most corresponding" << endl
         << "   to an option in the option menu." << endl << endl
         << "       -d, --degrees" << endl
         << "           Set the angle units as degrees. Default is radians." << endl << endl
         << "       -p, --precision [NUM]" << endl
         << "           Set the precision of the answers displayed." << endl
         << "           Takes one argument specifying the precision. 0 <= [NUM] <= 15" << endl
         << "           Default is the maximum required to display the results (c++ default)" << endl << endl
         << "       -s, --scientific" << endl
         << "           Display answers in scientific notation. Default is standard decimal notation." << endl << endl
         << "       -h, --help" << endl
         << "           Starts the program to display the help menu first, rather than the main menu" << endl;
    
    waitForUser();
    helpMode = MENU;
}
