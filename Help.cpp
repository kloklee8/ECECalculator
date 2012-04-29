#include "Help.hpp"

string getHelp(MODE mode, SUB_MODE submode)
{
    string help = "";
    switch (mode)
    {
        case MENU:
            help += "Menu help:";
        case SCI_CALC:
            help += "Scientific Calculator help:";
            break;
        case EQ_COMPONENT:
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
            break;
    }
    
    return help;
}
