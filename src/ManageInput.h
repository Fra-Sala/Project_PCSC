//
// Created by francesco on 07/12/22.
//

#ifndef PROJECT_PCSC_MANAGEINPUT_H
#define PROJECT_PCSC_MANAGEINPUT_H

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdlib>     /* strtod */

#include <fparser.hh>
#include <gtest/gtest.h>
#include "AbstractParser.h"
#include "Fparser.h"
#include "ManageInput.h"

#include "AbstractOdeSolver.h"
#include "ForwardEuler.h"
#include "AdamsBashforth.h"
#include "BackwardEuler.h"
#include "ExplicitRungeKutta.h"
#include "BDFSchemes.h"

class ManageInput {

private:
    unsigned int method;
    double t0;
    double tf;
    double y0;
    double h;
    std::string fun;

    // For multisteps methods
    unsigned int s = 0;

    // For Runge-Kutta methods
    unsigned int stages = 0;

public:
    ManageInput(int Nargs, const char* args[]);

    AbstractOdeSolver* ConstructSolver();

};
#endif //PROJECT_PCSC_MANAGEINPUT_H
