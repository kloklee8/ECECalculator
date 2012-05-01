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
void pressAny();

//Current calculator mode that the user is in.
MAIN_MODE helpMode;

//Modes that make up a MODE.  Put all sub-modes here, 
//no matter which mode your in.
SUB_MODE helpSubMode;

void getHelp()
{
    string input = "";
    helpMode = MENU;
    //getline(cin, input);
    //(input[0] != 'm' && exp[0] != 'q')
    while (1)
    {
        string help = "Looking for help?  Choose from the following topics you wish"
                        "to find more information about: ";
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
            default:
                return;
        }
    }
    
    
    
}

//Return help corresponding to the menu screen and how to use the entire 
//calculator.
void getMenuHelp()
{
}

//Return help corresponding to the scientific calculator mode.
void getSciHelp()
{
}

//Return help corresponding to the equivalence component mode.
void getEquivHelp()
{
    helpEqComponentSubMenu(helpMode, helpSubMode);
                
    if (helpSubMode == NONE)
        return;
    else
    {
        switch (helpSubMode) 
        {
            case RESISTANCE:
                cout << ("Equivalent Resistance help: \nThis mode is used to" 
                        " determine the equivalence of multiple resistor components"
                        " that are in series or parallel.  Operators include \'+\' for"
                        " series and \'|\' for parallel.  For example, if "
                        " resistor 1 (1 ohms)is in series with the parallel combination of"
                        " resistor 2 (2 ohms) and 3 (3 ohms), the following syntax can be used"
                        " to determine the equivalent resistance:\n"
                        " .001 + .002|.003\n\n");
                break;
            case CAPACITANCE:
                cout << ("Equivalent Capacitance help: \nThis mode is used to" 
                        " determine the equivalence of multiple capacitor components"
                        " that are in series or parallel.  Operators include \'+\' for"
                        " series and \'|\' for parallel.  For example, if "
                        " capacitor 1 (1mF)is in series with the parallel combination of"
                        " capacitor 2 (2mF) and 3 (3mF), the following syntax can be used"
                        " to determine the equivalent capacitance:\n"
                        " .001 + .002|.003");
                break;
            case INDUCTANCE:
                cout << ("Equivalent Inductance help: \nThis mode is used to" 
                        " determine the equivalence of multiple inductor components"
                        " that are in series or parallel.  Operators include \'+\' for"
                        " series and \'|\' for parallel.For example, if "
                        " inductor 1 (1mH)is in series with the parallel combination of"
                        " inductor 2 (2mH) and 3 (3mH), the following syntax can be used"
                        " to determine the equivalent inductance:\n"
                        " .001 + .002|.003");
                break;
        }
        pressAny();
    }
}

void getDividerHelp()
{
    
}

void getConvHelp()
{
    
}
    
void getFormulaHelp()
{
    
}

void getOptionHelp()
{
    
}

void pressAny()
{
    cout << "\n\nPress any key to return to the previous menu." << endl;
    waitForUser();
}
