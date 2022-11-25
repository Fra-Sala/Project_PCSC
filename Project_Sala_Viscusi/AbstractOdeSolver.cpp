#include "AbstractOdeSolver.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include <algorithm>

AbstractOdeSolver::AbstractOdeSolver() {
    h = 0;
    y0 = 0;
    t0 = 0;
    tf = 0;
    rhs = nullptr;
    // the map in not initialized here
}

// customized constructor to initialize all variables
AbstractOdeSolver::AbstractOdeSolver(const double stepsize, const double initval, const double inittime,
                                     const double fintime, double (*f)(const double y, const double t)) {
    h = stepsize;
    y0 = initval;
    t0 = inittime;
    tf = fintime;
    rhs = f;
}

// solution visualization
void AbstractOdeSolver::VisualizeSolution(bool flag) {
    if (flag) {
        std::ofstream write_sol("solution.dat");

        assert(write_sol.is_open());

        write_sol << "t " << "y" << std::endl;
        std::for_each(sol.begin(), sol.end(), [&write_sol](auto& map) {write_sol << map.first << map.second << std::endl;});

    } else {

        std::cout << "The solution will be displayed below" << std::endl << std::endl << "t " << "y" << std::endl;
        std::for_each(sol.begin(), sol.end(), [](auto& map) {std::cout << map.first << map.second << std::endl;});

    }
}



