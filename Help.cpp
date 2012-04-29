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
            help += "Equivalent Resistance help:";
            break;
        case CAPACITANCE:
            help += "Equivalent Capacitance help:";
            break;
        case INDUCTANCE:
            help += "Equivalent Component help: \nThis mode is used to" 
                    " determine the equivalence of multiple inductor components"
                    " that are in series or parallel.  For example, if "
                    " inductor 1 (1mH)is in series with the parallel combination of"
                    " inductor 2 (2mH) and 3 (3mH), the following syntax can be user:\n"
                    " ";
            break;
        case NONE:
            help += "Equivalent Component help: \nThis mode is used to" 
                    " determine the equivalence of multiple circuit components"
                    " that are in series or parallel.  For example, you may " 
                    " want to know the equivalence of five resistors in that" 
                    " are in a complex parallel and series network.";
            break;
    }
}
