#include "Help.hpp"

string getHelp(MODE mode, SUB_MODE submode)
{
    string help = "";
    switch (mode)
    {
        case SCI_CALC:
            help += "Scientific Calculator help:";
            break;
        case EQ_COMPONENT:
            switch (submode)
            {
                case RESISTANCE:
                    break;
                case CAPACITANCE:
                    break;
                case INDUCTANCE:
                    break;  
            }
            break;
            
    }
}
