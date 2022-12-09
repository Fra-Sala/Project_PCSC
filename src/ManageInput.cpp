//
// Created by parallels on 12/8/22.
//

#include "ManageInput.h"

/// Here the user will be guided through the code and asked to insert inputs
ManageInput::ManageInput(int Nargs, const char* args[]) {

    if (Nargs == 1) {

        std::cout << "\t\t------------- Ode solver -------------\n\n"
                     "This program solves the Cauchy problem in the form:\n"
                     "\t\t dy/dt = f(t,y)\n"
                     "\t y in [t0, tf], y(t0) = y0\n";


        std::cout << "Please choose a solving method:\n1) Forward Euler\n2) AdamsBashforth\n3) Backward Euler\n"
                     "4) Explicit Runge Kutta\n5) BDF schemes\n";


        std::cin >> method;
        std::cin.ignore(1000, '\n');

        std::cout << "Please enter f(t,y): ";              // no quotation marks needed


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

    } else if (strcmp(args[1], "FILE") == 0 || strcmp(args[1], "file") == 0) {

        std::ifstream read_param(args[2]);
        assert(read_param.is_open());
        read_param >> method >> fun >> t0 >> tf >> h >> y0;
        read_param.close();

    } else {

        method = (int) atof(args[1]);
        fun = args[2];
        t0 = (double) atof(args[3]);
        tf = (double) atof(args[4]);
        h = (double) atof(args[5]);
        y0 = (double) atof(args[6]);

    }
}



AbstractOdeSolver* ManageInput::ConstructSolver() {

    // Now, the parameters are set, hence we have to create an object of the type required
    Fparser* fparser_pointer = new Fparser(fun);      // create a pointer to an object Fparser, which will be the function
    assert(method >= 1 && method <= 6);

    if (method == 1) {

        ForwardEuler *Eq = new ForwardEuler(h, y0, t0, tf, fparser_pointer);
        return Eq;

    } else if (method == 2) {

        std::cout << "Select number of steps between 1 and 4: ";
        std::cin >> s;
        assert(s <= 4 && s >= 1);
        AdamsBashforth *Eq = new AdamsBashforth(h, y0, t0, tf, fparser_pointer, s);
        return Eq;

    } else if (method == 3) {

        // Here it is possible to specify the tolerance and the number of max iterations as additional
        // arguments
        BackwardEuler *Eq = new BackwardEuler(h, y0, t0, tf, fparser_pointer);
        return Eq;

    } else if (method == 4) {

        std::cout << "Select number of stages between 1 and 4: ";
        std::cin >> stages;
        ExplicitRungeKutta *Eq = new ExplicitRungeKutta(h, y0, t0, tf, fparser_pointer, stages);
        return Eq;

    } else if (method == 5) {

    } else if (method == 6) {

    }

    return nullptr;
}
