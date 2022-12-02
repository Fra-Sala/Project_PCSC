//
// Created by francesco on 02/12/22.
//

// This class, which inherits from AbstractOdeSolver, solves an ode with
// backward (implicit) Euler method. At each time step, the implicit equation
// is solved using the fixed point algorithm, which is stopped by either the number
// of iterations exceeding nmax or by the difference between two consecutive iterations
// smaller than a given tolerance tol.
// Both the values of nmax and tol can be either specified by the user, or left as default
// (nmax = 1000, tol = 1e-8)
//
//


#ifndef PROJECT_PCSC_BACKWARDEULER_H
#define PROJECT_PCSC_BACKWARDEULER_H


#include "AbstractOdeSolver.h"

class BackwardEuler : public AbstractOdeSolver {

private:
    double tol;
    double nmax;

public:

    BackwardEuler(const double stepsize, const double initval, const double inittime, const double fintime,
                   AbstractParser* fun_obj, const double tolmax = 1e-8, const double max_iter = 1000) : AbstractOdeSolver(stepsize, initval, inittime, fintime, fun_obj) {this->tol = tol, this->nmax = nmax;}
    void solve() override;
};
#endif //PROJECT_PCSC_BACKWARDEULER_H
