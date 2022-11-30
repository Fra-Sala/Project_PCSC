#include <iostream>
#include <fstream>
#include "fparser.hh"
#include "AdamsBashforth.h"
#include "ForwardEuler.h"
#include <cassert>
#include "AbstractOdeSolver.h"
#include <limits>
#include <string>
#include <typeinfo>
#include <cstring>

/////////////////////////
// REMEMBER TO RUN THE CODE, AFTER COMPILING, FROM THE TERMINAL!!!!!
/////////////////////////

using namespace std;                // we may use this too, so we don't have to write std:: every time

int main(int argc, char* argv[]) {


    auto *f_RHS = new FunctionParser;
    double t0, tf, h, y0;
    std::string fun;
    int method;

    if (argc == 1) {

        std::cout << "\t\t------------- Ode solver -------------\n\n"
                     "This program solves the Cauchy problem in the form:\n"
                     "\t\t dy/dt = f(t,y)\n"
                     "\t y in [t0, tf], y(t0) = y0\n";

        std::cout << "Please choose a solving method:\n-1) forward euler\n- 2) AdamsBashforth\n";

        std::cin >> method;
        std::cin.ignore(1000,'\n');

        std::cout << "Please enter f(t,y) with no spaces (only one string):";              // no quotation marks & no spaces


        std::getline(std::cin, fun);

        std::cout << fun << std::endl;
        std::cout << "Please enter an initial time t0:\n";
        std::cin >> t0;

        std::cout << "Please enter a final time tf:\n";
        std::cin >> tf;

        std::cout << "Please enter a stepsize h:\n";
        std::cin >> h;

        std::cout << "Please enter an initial value y0:\n";
        std::cin >> y0;

    } else {

    // the user can also run the program declaring "method", "f(t,y)", t0, tf,  h, y0
        method = (double) atof(argv[1]);
        fun = argv[2];
        t0 = (double) atof(argv[3]);
        tf =(double) atof(argv[4]);
        h =  (double) atof(argv[5]);
        y0 = (double) atof(argv[6]);

    }


    f_RHS->Parse(fun, "t,y");       // create a pointer to an object FunctionParser, which will be the function

    if(method == 1) {
        ForwardEuler Eq((double) h, (double) y0, (double) t0, (double) tf, f_RHS);
        Eq.solve();
        std::cout << "Where would you like to print the solution?\n1) Screen\n2) Matlab file\n";
        int num;
        std::cin >> num;
        num--;                          // since bool must be 0 or 1
        Eq.VisualizeSolution(num);
    }





    return 0;
}


