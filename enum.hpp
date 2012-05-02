#ifndef ENUM_H
#define ENUM_H

//This file is purely for defining enums that will be used across the program.

enum DATA_TYPE
{
    OPERAND,
    OPERATOR,
    FUNCTION,
    PAREN,
    INVALID
};

//Current calculator mode that the user is in.
enum MAIN_MODE
{
    MENU,
    SCI_CALC,
    EQ_COMPONENT,
    DIVIDER,
    CONVERSION,
    FORMULA,
    OPTION,
    HELP,
    EXIT
};

//Modes that make up a MODE.  Put all sub-modes here, 
//no matter which mode your in.
enum SUB_MODE
{
    NONE,
    RESISTANCE,
    CAPACITANCE,
    INDUCTANCE,
    
    CURRENT,
    VOLTAGE
};

enum ANGLE
{
    DEGREE,
    RADIAN
};

struct MODES
{
    MAIN_MODE mainMode;
    SUB_MODE subMode;
};

struct OPTIONS
{
    ANGLE angleMode;
    // if true, display help on entrance to each mode. If false, only display help at beginning of program.
    bool helpDisplay;
    int precision;
    bool scientificNotation;
};

#endif
