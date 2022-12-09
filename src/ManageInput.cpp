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


        std::cout << "Please choose a solving method:\n1) Forward Euler\n2) Adams Bashforth\n3) Backward Euler\n"
                     "4) Explicit Runge Kutta\n5) BDF schemes\n6) Adams-Moulton\n\n";
        std::cin >> method;

        std::cin.ignore(1000, '\n');
        std::cout << "\nPlease enter f(t,y): ";              // no quotation marks needed
        std::getline(std::cin, fun);

        std::cout << "Function read: " << fun << std::endl;
        std::cout << "Please enter an initial time t0: ";
        std::cin >> t0;

        std::cout << "Please enter a final time tf: ";
        std::cin >> tf;

        std::cout << "Please enter a stepsize h: ";
        std::cin >> h;

        std::cout << "Please enter an initial value y0: ";
        std::cin >> y0;

        // If the method is a multistep method, we look for a number of steps between 1 and 4 too
        // or, if the method is the Runge-Kutta, we look for the number of stages
        if (method == 2 || method == 5 || method == 6) {
            std::cout << "Please enter the number of steps: ";
            std::cin >> s;
        } else if (method == 4) {
            std::cout << "Please enter the number of stages: ";
            std::cin >> stages;
        }

    } else if (strcmp(args[1], "FILE") == 0 || strcmp(args[1], "file") == 0) {

        std::ifstream read_param(args[2]);
        assert(read_param.is_open());
        read_param >> method >> fun >> t0 >> tf >> h >> y0;

        if (method == 2 || method == 5 || method == 6) {
            read_param >> s;
        } else if (method == 4) {
            read_param >> stages;
        }
        read_param.close();

    } else {

        method = (int) atof(args[1]);
        fun = args[2];
        t0 = (double) atof(args[3]);
        tf = (double) atof(args[4]);
        h = (double) atof(args[5]);
        y0 = (double) atof(args[6]);

        if (method == 2 || method == 5 || method == 6) {
            s = atoi(args[7]);
        } else if (method == 4) {
            stages = atoi(args[7]);
        }

    }
}



AbstractOdeSolver* ManageInput::ConstructSolver() {

    // bunch of assertion before the equation is solved
    assert(method >= 1 && method <= 6);
    if (method == 2 || method == 5 || method == 6) {
        assert(s <= 4 && s >= 1);
    } else if (method == 4) {
        assert(stages <= 4 && stages >= 1);
    }

    // Now, the parameters are set, hence we have to create an object of the type required
    Fparser* fparser_pointer = new Fparser(fun);      // create a pointer to an object Fparser, which will be the function

    switch(method) {
        case 1: {
            ForwardEuler *Eq = new ForwardEuler(h, y0, t0, tf, fparser_pointer);
            return Eq;
        } case 2: {
            AdamsBashforth *Eq = new AdamsBashforth(h, y0, t0, tf, fparser_pointer, s);
            return Eq;
        } case 3: {
            // Here it is possible to specify the tolerance and the number of max iterations as additional
            // arguments
            BackwardEuler *Eq;
            char choice;
            std::cout << "Do you want to specify a tolerance and a number of max iterations for the resolution of"
                         "the non-linear equation? Default values are tol = 1e-8 and nmax = 1000. [type y/n]" << std::endl;
            std::cin >> choice;
            if (choice == 'y') {
                std::cout << "Specify tolerance and max number of iterations: ";
                std::cin >> tol >> nmax;
                Eq = new BackwardEuler(h, y0, t0, tf, fparser_pointer, tol, nmax);
            } else {
                Eq = new BackwardEuler(h, y0, t0, tf, fparser_pointer);
            }
            return Eq;
        } case 4: {
            ExplicitRungeKutta *Eq = new ExplicitRungeKutta(h, y0, t0, tf, fparser_pointer, stages);
            return Eq;
        } case 5: {
            BDFSchemes *Eq;
            char choice;
            std::cout << "Do you want to specify a tolerance and a number of max iterations for the resolution of"
                         "the non-linear equation? Default values are tol = 1e-8 and nmax = 1000. [type y/n]" << std::endl;
            std::cin >> choice;
            if (choice == 'y') {
                std::cout << "Specify tolerance and max number of iterations: ";
                std::cin >> tol >> nmax;
                Eq = new BDFSchemes(h, y0, t0, tf, fparser_pointer, s, tol, nmax);
            } else {
                Eq = new BDFSchemes(h, y0, t0, tf, fparser_pointer, s);
            }
            return Eq;
        } case 6: {
            AdamsMoulton *Eq;
            char choice;
            std::cout << "Do you want to specify a tolerance and a number of max iterations for the resolution of"
                         "the non-linear equation? Default values are tol = 1e-8 and nmax = 1000. [type y/n]" << std::endl;
            std::cin >> choice;
            if (choice == 'y') {
                std::cout << "Specify tolerance and max number of iterations: ";
                std::cin >> tol >> nmax;
                Eq = new AdamsMoulton(h, y0, t0, tf, fparser_pointer, s, tol, nmax);
            } else {
                Eq = new AdamsMoulton(h, y0, t0, tf, fparser_pointer, s);
            }
            return Eq;
        }
    }
    return nullptr;
}
