//
// Created by parallels on 12/4/22.
//

#include <iostream>
#include "AbstractImplicitOdeSolver.h"

double AbstractImplicitOdeSolver::SolveNonLinearEquation(double t, double y) {

    double ySol;
    try{
        ySol = FixedPoint(t,y);

    } catch(int i)
    {
        std::cout << "Warning " << i << ": fixed point iterations are not converging, switching to Broyden solver\n";
        ySol = Broyden(t,y);
    }
    return ySol;

}


double AbstractImplicitOdeSolver::FixedPoint(double t, double y) {

    double it = 0.0;
    double err, y_new;
    double y_old = y;
    std::vector<double> errVect;
    do {
        y_new = y_old - this->NonLinearEquation(t,y_old);
        errVect.push_back(fabs(y_new - y_old));
        it ++ ;
        y_old = y_new;

        if(it > 3 && (errVect.back() > errVect.back()-1) && (errVect.back()-1 > errVect.back()-2)) {
            throw 101;

        }
    } while ((it < this->nmax) && (errVect.back() > this->tol));


    return y_new;
}

double AbstractImplicitOdeSolver::Broyden(double t, double y) {

    double it = 0;
    double y_oldold = y;
    double y_old = y_oldold+this->h;
    double err, fprime, y_new;
    do {
        fprime = (this->NonLinearEquation(t,y_old) - this->NonLinearEquation(t,y_oldold ))/(y_old - y_oldold);
        y_new = y_old - this->NonLinearEquation(t,y_old)/fprime;
        y_old = y_new;
        y_oldold = y_old;
        it++;
        err = fabs(y_new - y_old);

    } while ((it < this->nmax) && (err > this->tol));
    return y_new;
}
