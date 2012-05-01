#include "Help.hpp"

//Current calculator mode that the user is in.
MAIN_MODE menuMode;

//Modes that make up a MODE.  Put all sub-modes here, 
//no matter which mode your in.
SUB_MODE menuSubMode;

void Help::getHelp()
{
    string input = "";
    menuMode = MENU;
    //getline(cin, input);
    //(input[0] != 'm' && exp[0] != 'q')
    while (1)
    {
        string help = "Looking for help?  Choose from the following topics you wish"
                        "to find more information about: ";
        switch (menuMode)
        {
            case MENU:
                getMenuHelp();
                break;
            case SCI_CALC:
                getSciHelp();
                break;
            case EQ_COMPONENT:
                getEquivHelp();
            case DIVIDER:
                getDividerHelp();
                break;
            case CONVERSION:
                getConvHelp();
                break;
            case FORMULA:
                getFormulaHelp();
            case OPTIONS:
                getOptionHelp();
                break;
            default:
                return;
        }
    }
    
    
    
}

//Return help corresponding to the menu screen and how to use the entire 
//calculator.
void Help::getMenuHelp()
{
}

//Return help corresponding to the scientific calculator mode.
void Help::getSciHelp()
{
}

//Return help corresponding to the equivalence component mode.
void Help::getEquivHelp()
{
//    helpEqComponentSubMenu(menuSubMode);
//                cout << ("Equivalent Component help: \nThis mode is used to" 
//                        " determine the equivalence of multiple circuit components"
//                        " that are in series or parallel.  For example, you may " 
//                        " want to know the equivalence of five resistors that" 
//                        " are in a complex network.  Operators include \'+\' for"
//                        " series and \'|\' for parallel.");
    if (menuSubMode == NONE)
        return;
    else
    {
        switch (menuSubMode) 
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

getDividerHelp()
{
    
}
getConvHelp()
{
    
}
    
getFormulaHelp()
{
    
}

getOptionHelp()
{
    
}

void pressAny()
{
    cout << "\n\nPress any key to return to the previous menu." << endl;
    waitForUser();
}
