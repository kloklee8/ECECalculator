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
    
    return help;
}

//Return help corresponding to the menu screen and how to use the entire 
//calculator.
void getMenuHelp(string& help)
{
    help += "Menu help:";
}

//Return help corresponding to the scientific calculator mode.
void getSciHelp(string& help)
{
    help += "Scientific Calculator help:";
}

//Return help corresponding to the equivalence component mode.
void getEquivHelp(string& help, SUB_MODE submode)
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
            help += "Equivalent Inductance help:";
            break;
        case NONE:
            help += "Equivalent Component help:";
            break;
    }
}
