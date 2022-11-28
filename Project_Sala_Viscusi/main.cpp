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

/////////////////////////
// REMEMBER TO RUN THE CODE, AFTER COMPILING, FROM THE TERMINAL!!!!!
/////////////////////////





int main(int argc, char* argv[]) {


    auto *f_RHS = new FunctionParser;
    double t0, tf, h, y0;
    std::string fun;


    if (argc == 1) {

        std::cout << "\t\t------------- Ode solver -------------\n\n"
                     "This program solves the Cauchy problem in the form:\n"
                     "\t\t dy/dt = f(t,y)\n"
                     "\t y in [t0, tf], y(t0) = y0\n";
        std::cout << "Please enter an initial time t0:\n";

        std::cin >> t0;
        std::cout << "Please enter a final time tf:\n";

        std::cin >> tf;
        std::cout << "Please enter a stepsize h:\n";

        std::cin >> h;
        std::cout << "Please enter an initial value y0:\n";

        std::cin >> y0;
        std::cout << "Please enter f(t,y) between quotation marks:";

        std::cin >> fun;


    } else
    {
    // the user can also run the program declaring t0, tf,  h, y0, "f(t,y)"
        t0 = (double) atof(argv[1]);
        tf =(double) atof(argv[2]);
        h =  (double) atof(argv[3]);
        y0 = (double) atof(argv[4]);
        fun = argv[5];


    }


    f_RHS->Parse(fun, "t,y");   //create a pointer to an object FunctionParser, which will be the function
    std::cout << f_RHS << std::endl;

    double v[2] = {0,1};

    std::cout <<f_RHS->Eval(v);


    ForwardEuler Eq((double) h, (double) y0, (double) t0, (double) tf, f_RHS);

    Eq.solve();

    std::cout << "Where would you like to print the solution?\n1) Screen\n2) Matlab file\n";

    int num;
    std::cin >> num;
    num --;
    Eq.VisualizeSolution(num);





    return 0;
}


