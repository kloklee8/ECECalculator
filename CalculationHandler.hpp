#ifndef CALCULATIONHANDLER_H
#define CALCULATIONHANDLER_H

#include "SciCalcParser.hpp"
#include "EquivComponentParser.hpp"
#include "Divider.hpp"
#include "enum.hpp"

void sci_calculator(SciCalcParser& calcParse);
void equivalent_component(EquivComponentParser& eqComponentParser);
void divider();
void options(SciCalcParser& calcParser);
void setOptions(ANGLE angleMode, int precision, bool scientificNotation);

#endif
