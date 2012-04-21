#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "ExpressionParser.h"
#include "SciCalcParser.h"

using namespace std;

enum MODE
{
    MENU,
    SCI_CALC,
    EXIT
};

int main()
{
    MODE currentMode = MENU;

        while (currentMode != EXIT)
    {
        string choice;
        switch (currentMode)
        {
            case MENU:
            {
                cout << "1. Scientific Calculator" << endl <<
                        "-1. Help" << endl <<
                        "0. Exit" << endl;
                getline(cin, choice);
                switch (choice[0] - '0')
                {
                    case -1:
                        break;
                    case 0:
                        currentMode = EXIT;
                        break;
                    case 1: 
                        currentMode = SCI_CALC;
                        cout << "Enter an expression to calculate or type \"exit\" to return to the menu." << endl;
                        break;
                    default:
                        cout << "Error: Invalid choice\n" << endl;;
                }
                break;
            }
            case SCI_CALC:
            {
                SciCalcParser calcParser;
                
                string exp;
                getline(cin, exp);

                if (exp.find("exit") == string::npos && exp.find("EXIT") == string::npos)
                {
                    //cout << calcParser.convertToPostfix(exp) << endl;
                    calcParser.convertToPostfix(exp);
                    cout << calcParser.evaluatePostFix() << endl;
                }
                else
                {
                    cout << endl;
                    currentMode = MENU;
                }

                break;
            }
            case EXIT:
            {
                break;
            }
        }
    }
        
    return 0;
}
