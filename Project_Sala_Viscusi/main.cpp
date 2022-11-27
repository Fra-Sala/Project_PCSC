#include <iostream>
#include <fstream>
#include "fparser.hh"
#include "AdamsBashforth.h"
#include "ForwardEuler.h"
#include <cassert>
#include "AbstractOdeSolver.h"

/////////////////////////
// REMEMBER TO RUN THE CODE, AFTER COMPILING, FROM THE TERMINAL!!!!!
/////////////////////////
int main(int argc, char* argv[]) {

    // The code must be called specifing a function

    if (argc > 2) {

        std::cout << "we are gonna use a file" << std::endl;
    } else
    {
        std::cout << "we are gonna use the screen to print the solution" << std::endl;
    }


    auto *f_RHS = new FunctionParser;           //create a pointer to an object FunctionParser, which will be the function
    f_RHS->Parse(argv[1], "t,y");

    auto *v = new double[2] {3,0};

    double h = 0.1;
    double y0 = 0.7;
    double t0 = 0;
    double tf = 2;



    ForwardEuler Eq(h, y0, t0, tf, f_RHS);

    Eq.solve();

    int flag;
    if (*argv[2] != '1') {
        flag = 0;
    } else {
        flag = 1;
    }
    Eq.VisualizeSolution(flag);





    return 0;
}


