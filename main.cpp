#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
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

using std::cout;
using std::cin;
using std::endl;

MODES currentModes;
OPTIONS currentOptions;

bool processCommandLineArguments(int argc, const char* argv[], SciCalcParser& calcParser);

int main(int argc, const char* argv[])
{
    currentModes.mainMode = MENU;
    currentModes.subMode = NONE;
    
    setOptions(RADIAN, true, -1, false);
    
    SciCalcParser calcParser;
    EquivComponentParser eqComponentParser;
    
    if (argc > 1)
    {
        if (!(processCommandLineArguments(argc, argv, calcParser)))
        {
            return 1;
        }
    }

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
                currentModes.mainMode = MENU;
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

bool processCommandLineArguments(int argc, const char* argv[], SciCalcParser& calcParser)
{
    // TODO: Implement command lines
    for (int i = 0; i < argc; i++)
    {
        if (argv[i] == "-a")
        {
            
        }
        else if (argv[i] == "-h")
        {
        
        }
        else if (argv[i] == "-p")
        {
        
        }
        else if (argv[i] == "-s")
        {
        
        }
        else
        {
            cout << "Error: Invalid switch" << endl;
            return false;
        }
    }
    return true;
}
