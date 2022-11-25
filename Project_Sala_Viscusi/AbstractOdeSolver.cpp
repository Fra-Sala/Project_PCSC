#include "AbstractOdeSolver.h"

AbstractOdeSolver::AbstractOdeSolver() {
    h = 0;
    y0 = 0;
    t0 = 0;
    tf = 0;
    rhs = nullptr;
}

AbstractOdeSolver::AbstractOdeSolver(const double stepsize, const double initval, const double inittime,
                                     const double fintime, const double (*f)(const double y, const double t)) {
    h = stepsize;
    y0 = initval;
    t0 = inittime;
    tf = fintime;
    this->rhs = f;
}


