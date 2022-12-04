//
// Created by francesco on 02/12/22.
//
#include "BackwardEuler.h"

void BackwardEuler::solve() {

    int N = static_cast<int>(std::floor((this->tf - this->t0) / this->h));

    this->sol.emplace(this->t0, this->y0);

    for (int i = 0; i<=N; i++){

        double t_new = this->t0 + this->h * i;
        double y = this->SolveNonLinearEquation(t_new, sol.rbegin()->second);

        this->sol.emplace(t_new, y);
    }

}


double BackwardEuler::FixedPoint(double t_new, double y) {

    double it = 0.0;
    double err, y_new;
    double y_old = y;
    do {

        y_new = y + this->h*this->funObject->EvaluateFun(t_new, y_old);
        err = fabs(y_new - y_old);
        it ++;
        y_old = y_new;

    } while ((it < this->nmax) && (err > this->tol));

    return y_new;
}


// to be implemented
double BackwardEuler::Broyden(double t_new, double y) {


    return 0;
}

