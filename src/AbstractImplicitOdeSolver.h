//
// Created by parallels on 12/4/22.
//

// this class inherits from AbstractOdeSolver and is required for all the implicit methods

#ifndef PROJECT_PCSC_ABSTRACTIMPLICITODESOLVER_H
#define PROJECT_PCSC_ABSTRACTIMPLICITODESOLVER_H

#include "AbstractOdeSolver.h"

class AbstractImplicitOdeSolver : public AbstractOdeSolver {

protected:
    double nmax;
    double tol;
    double a;
    double b;


public:
    AbstractImplicitOdeSolver(const double stepsize, const double initval, const double inittime, const double fintime,
                              AbstractParser* fun_obj, const double tolmax = 1e-8, const double max_iter = 1000) : AbstractOdeSolver(stepsize, initval, inittime, fintime, fun_obj) {this->tol = tolmax, this->nmax = max_iter, this->a = 0.0, this->b = 0.0;}

    // fixed point algorithm for implicit equations
    double NonLinearEquation(double t, double y) ;
    // virtual methods that are to be overridden in each implicit method

    double SolveNonLinearEquation(double t, double y);

    double FixedPoint(double t, double y);
    double Broyden(double t, double y);
    //double Bisection(double t, double y);

};

#endif //PROJECT_PCSC_ABSTRACTIMPLICITODESOLVER_H
