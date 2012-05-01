#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "ExpressionParser.hpp"
#include "SciCalcParser.hpp"
#include "EquivComponentParser.hpp"
#include "enum.hpp"
#include "Help.hpp"
#include "Divider.hpp"
#include "PrefixConverter.hpp"
#include "Menus.hpp"
#include "Formulas.hpp"
#include "CalculationHandler.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::ios;
using std::fixed;
using std::setprecision;

MODES currentModes;
OPTIONS currentOptions;	

int main()
{
    currentModes.mainMode = MENU;
    currentModes.subMode = NONE;
    
    setOptions(RADIAN, true, -1, false);
    
    SciCalcParser calcParser;
    EquivComponentParser eqComponentParser;

    while (currentModes.mainMode != EXIT)
    {
        switch (currentModes.mainMode)
        {
            case MENU:
                menu();
                break;
            case SCI_CALC:
                sci_calculator(calcParser);
                break;
            case EQ_COMPONENT:
                equivalent_component(eqComponentParser);
                break;
            case DIVIDER:
                divider();
                break;
            case CONVERSION:
                convertPrefixes();
                break;
            case FORMULA:
            {
                printFormulas();
                waitForUser();
                break;
            }
            case OPTION:
                options(calcParser);
                break;
            case EXIT:
                break;
        }
    }
    
    return 0;
}


