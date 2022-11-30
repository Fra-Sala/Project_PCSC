#include "AbstractOdeSolver.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>

AbstractOdeSolver::AbstractOdeSolver() {
    this->h = 0.0;
    this->y0 = 0.0;
    this->t0 = 0.0;
    this->tf = 0.0;
    this->rhs = nullptr;
    // the map in not initialized here
}

// customized constructor to initialize all variables
AbstractOdeSolver::AbstractOdeSolver(const double stepsize, const double initval, const double inittime,
                                     const double fintime, FunctionParser *f_rhs) {
    this->h = stepsize;
    this->y0 = initval;
    this->t0 = inittime;
    this->tf = fintime;
    this->rhs = f_rhs;
}

// solution visualization
void AbstractOdeSolver::VisualizeSolution(bool flag) {
    if (flag) {
        std::ofstream write_sol("solution.m");

        assert(write_sol.is_open());

        write_sol << "clear\nclose all\nclc\n";
        write_sol << "S = [";
        std::for_each(sol.begin(), sol.end(), [&write_sol](auto& map) {write_sol << map.first << "," << map.second << ";\n";});

        write_sol << "];\n";

        write_sol << "plot(S(:,1), S(:,2), \"Linewidth\", 2)\ngrid on\ntitle(\"Solution of the ODE\")" << std::endl;

        write_sol.close();

    } else {

        std::cout << "The solution will be displayed below" << std::endl << std::endl << "t " << "y" << std::endl;
        std::for_each(sol.begin(), sol.end(), [](auto& map) {std::cout << map.first << " " << map.second << std::endl;});

    }
}


double AbstractOdeSolver::FixedPoint(double x0, FunctionParser *phi, int nmax, double tol) {

    double err;
    int it = 0;
    double x = x0;


    do {

        double x_new = phi->Eval(&x);

        err = fabs(x_new - x);
        it = it + 1;

        x = x_new;

    } while ((it < nmax) && (err > tol));

    return x;
}


