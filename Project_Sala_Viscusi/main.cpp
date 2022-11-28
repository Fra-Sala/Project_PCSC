#include <iostream>
#include <fstream>
#include "fparser.hh"
#include "AdamsBashforth.h"
#include "ForwardEuler.h"
#include <cassert>
#include "AbstractOdeSolver.h"
#include <limits>
#include <string>

/////////////////////////
// REMEMBER TO RUN THE CODE, AFTER COMPILING, FROM THE TERMINAL!!!!!
/////////////////////////





int main(int argc, char* argv[]) {


    auto *f_RHS = new FunctionParser;
    double t0, tf, h, y0;
    std::string fun;


    if (argc == 1) {

        std::cout << "--- Ode solver ---\n\nThis program solves the Cauchy problem equation in the form dy/dt = f(t,y), y in [t0, tf], y(t0) = y0\n";
        std::cout << "Please enter an initial time t0:\n";

        std::cin >> t0;
        std::cout << "Please enter a final time tf:\n";

        std::cin >> tf;
        std::cout << "Please enter a stepsize h:\n";

        std::cin >> h;
        std::cout << "Please enter an initial value y0:\n";

        std::cin >> y0;
        std::cout << "Please enter f(t,y) between quotation marks:\n";

        std::cin >> fun;
        f_RHS->Parse(fun, "t,y");   //create a pointer to an object FunctionParser, which will be the function
    } else
    {
    // the user can also run the program declaring t0, tf,  h, y0, "f(t,y)"
        t0 = (double) atof(argv[1]);
        tf =(double) atof(argv[2]);
        h =  (double) atof(argv[3]);
        y0 = (double) atof(argv[4]);
        fun = argv[5];
        f_RHS->Parse(fun, "t,y");

    }





    std::cout << t0 << " " << tf << " " << h << " " << y0 << " " << fun << std::endl;





    ForwardEuler Eq(h, y0, t0, tf, f_RHS);

    Eq.solve();

    std::cout << "Where would you like to print the solution?\n1) Screen\n2) File\n";

    int num;
    std::cin >> num;
    num --;
    Eq.VisualizeSolution(num);





    return 0;
}


