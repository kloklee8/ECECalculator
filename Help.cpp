#include "Help.hpp"

string Help::getHelp(MODE mode, SUB_MODE submode)
{
    string help = "";
    switch (mode)
    {
        case MENU:
            getMenuHelp(help);
            break;
        case SCI_CALC:
            getSciHelp(help);
            break;
        case EQ_COMPONENT:
            getEquivHelp(help, submode);
            break;
    }
    help += "\n";
    return help;
}

//Return help corresponding to the menu screen and how to use the entire 
//calculator.
void Help::getMenuHelp(string& help)
{
    help += "Menu help:";
}

//Return help corresponding to the scientific calculator mode.
void Help::getSciHelp(string& help)
{
    help += "Scientific Calculator help:";
}

//Return help corresponding to the equivalence component mode.
void Help::getEquivHelp(string& help, SUB_MODE submode)
{
    switch (submode) 
    {
        case RESISTANCE:
            help += "Equivalent Resistance help: \nThis mode is used to" 
                    " determine the equivalence of multiple resistor components"
                    " that are in series or parallel.  Operators include \'+\' for"
                    " series and \'|\' for parallel.  For example, if "
                    " resistor 1 (1 ohms)is in series with the parallel combination of"
                    " resistor 2 (2 ohms) and 3 (3 ohms), the following syntax can be used"
                    " to determine the equivalent resistance:\n"
                    " .001 + .002|.003";
            break;
        case CAPACITANCE:
            help += "Equivalent Capacitance help: \nThis mode is used to" 
                    " determine the equivalence of multiple capacitor components"
                    " that are in series or parallel.  Operators include \'+\' for"
                    " series and \'|\' for parallel.  For example, if "
                    " capacitor 1 (1mF)is in series with the parallel combination of"
                    " capacitor 2 (2mF) and 3 (3mF), the following syntax can be used"
                    " to determine the equivalent capacitance:\n"
                    " .001 + .002|.003";
            break;
        case INDUCTANCE:
            help += "Equivalent Inductance help: \nThis mode is used to" 
                    " determine the equivalence of multiple inductor components"
                    " that are in series or parallel.  Operators include \'+\' for"
                    " series and \'|\' for parallel.For example, if "
                    " inductor 1 (1mH)is in series with the parallel combination of"
                    " inductor 2 (2mH) and 3 (3mH), the following syntax can be used"
                    " to determine the equivalent inductance:\n"
                    " .001 + .002|.003";
            break;
        case NONE:
            help += "Equivalent Component help: \nThis mode is used to" 
                    " determine the equivalence of multiple circuit components"
                    " that are in series or parallel.  For example, you may " 
                    " want to know the equivalence of five resistors that" 
                    " are in a complex network.  Operators include \'+\' for"
                    " series and \'|\' for parallel.";
            break;
    }
}
