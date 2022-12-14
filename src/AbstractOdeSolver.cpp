#include "AbstractOdeSolver.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include <algorithm>

AbstractOdeSolver::AbstractOdeSolver() {
    this->h = 0.0;
    this->y0 = 0.0;
    this->t0 = 0.0;
    this->tf = 0.0;
    this->funObject = nullptr;
}


AbstractOdeSolver::AbstractOdeSolver(const double stepsize, const double initval, const double inittime,
                                     const double fintime, AbstractParser *fun_obj) {
    this->h = stepsize;
    this->y0 = initval;
    this->t0 = inittime;
    this->tf = fintime;
    this->funObject = fun_obj;
}

/** The user can choose among two different possibilities:
 *
 * 1) The solution is printed on the screen (two columns format);
 *
 * 2) A '.m' (MATLAB) file is generated that the user may consequently run in order to visualize the solution.
 */
void AbstractOdeSolver::VisualizeSolution() {

    std::cout << "Where would you like to print the solution?\n1) Screen\n2) Matlab file\n";
    int flag;
    std::cin >> flag;
    flag--;                          // since flag must be 0 or 1

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
        std::cout << "The solution is the following:" << std::endl << std::endl << "t " << "y" << std::endl;
        std::for_each(sol.begin(), sol.end(), [](auto& map) {std::cout << map.first << " " << map.second << std::endl;});
    }
}


std::map<double, double> *AbstractOdeSolver::GetSolution() {
    return &this->sol;
}


