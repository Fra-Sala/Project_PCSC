//
// Created by parallels on 12/4/22.
//

#include "AbstractImplicitOdeSolver.h"

double AbstractImplicitOdeSolver::SolveNonLinearEquation(double t, double y) {

    int flag = 1;
    double y_sol;

    // Here different methods to solve nonlinear equations will be implemented
    if (flag == 1) {
        y_sol = this->FixedPoint(t,y);
    }

    return y_sol;
}

