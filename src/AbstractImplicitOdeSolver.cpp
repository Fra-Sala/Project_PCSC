//
// Created by parallels on 12/4/22.
//

#include <iostream>
#include "AbstractImplicitOdeSolver.h"
#include "Exception.h"


/* Solves a non-linear equation in the form g(t, y) = 0. It takes as input
 * the values the current values of t_n+1 and y_n (initial guess), and first tries
 * to solve the equation using fixed point iteration and, if such algorithm fails to converge,
 * an exception is thrown, and the method switches to Broyden algorithm. */
double AbstractImplicitOdeSolver::SolveNonLinearEquation(double t, double y) {

    double ySol;
    try
    {
        ySol = FixedPoint(t,y);
    }
    catch(Exception& e)
    {
        std::cout << e.what() <<std::endl;
        ySol = Broyden(t,y);
    }
    return ySol;

}

/*Solves a non-linear equation in the form y_n+1 + a+ b*f(t_n+1, y_n+1) = 0 using
 * fixed point itearations. The stopping criteria is both the difference between two consequent
 * iterations and the nmax, maximum number of iterations allowed. If the difference between two iterations
 * grows, in absolute value, three times in a row, the algorithm is stopped, since it is considered not
 * to be convergindeemedg. */
double AbstractImplicitOdeSolver::FixedPoint(double t, double y) {

    double it = 0.0;
    double y_new;
    double y_old = y;
    std::vector<double> errVect;
    do
    {
        y_new = y_old - this->NonLinearEquation(t,y_old);
        errVect.push_back(fabs(y_new - y_old));
        it ++ ;
        y_old = y_new;

        if(it > 3 && (errVect.back() > errVect.back()-1) && (errVect.back()-1 > errVect.back()-2))
        {
            throw Exception("Warning: fixed point is not converging, switching to Broyden solver\n");
        }
    } while ((it < this->nmax) && (errVect.back() > this->tol));


    return y_new;
}

double AbstractImplicitOdeSolver::Broyden(double t, double y) {

    double it = 0;
    double y_oldold = y;
    double y_old = y_oldold+this->h;
    double err, fprime, y_new;
    do
    {
        fprime = (this->NonLinearEquation(t,y_old) - this->NonLinearEquation(t,y_oldold ))/(y_old - y_oldold);
        y_new = y_old - this->NonLinearEquation(t,y_old)/fprime;
        y_old = y_new;
        y_oldold = y_old;
        it++;
        err = fabs(y_new - y_old);
    } while ((it < this->nmax) && (err > this->tol));
    return y_new;
}


double AbstractImplicitOdeSolver::NonLinearEquation(double t, double y) {

    return (y + this->a + this->b*this->funObject->EvaluateFun(t,y));    // this is the f(y) for which we look for y such that f(y)=0
}

