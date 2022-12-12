//
// Created by francesco on 08/12/22.
//

#include "AdamsBashforth.h"
#include "AdamsMoulton.h"
#include <iostream>

/* The ::solve() method of this class applies the Adams-Moulton multistep method using the speciefied number of steps.
 * For the initial steps, the very same Adams-Moulton method is called, using an increasing number of steps, until
 * a sufficient number of y_i has been computed in order to apply the chosen method. */

void AdamsMoulton::solve() {

    int N = static_cast<int>(std::floor((this->tf - this->t0) / this->h));


    sol.emplace(t0, y0);
    // The first n steps are solved using the corresponding Adams-Moulton method
    for (int i = 1; i < this->steps; i++) {
        double y = this->AdamsMoultonNstep(i);
        sol.emplace(this->sol.rbegin()->first + this->h, y);
    }


// Now, depending on the particular numbers of steps,
// a different implementation of Adams-Bashforth method is applied

    for (int i = this->steps; i <= N; i++) {

        double y = this->AdamsMoultonNstep(this->steps);
        sol.emplace(this->sol.rbegin()->first + this->h, y);

    }



}

double AdamsMoulton::AdamsMoultonNstep(int nSteps) {

    double y_new = 0.0;
    double t_new = this->sol.rbegin()->first + this->h;
    if (nSteps == 1) {

        this->a = -sol.rbegin()->second -
                  this->h / 2 * this->funObject->EvaluateFun(this->sol.rbegin()->first, this->sol.rbegin()->second);
        this->b = -this->h / 2.0;
        y_new = this->SolveNonLinearEquation(t_new, sol.rbegin()->second);
        // sol.rbegin()->second + h * this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second);
    } else if (nSteps == 2) {
        this->a = -sol.rbegin()->second - this->h*(8.0/12.0*this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second) +
                -1.0/12.0*this->funObject->EvaluateFun(std::prev(sol.rbegin(), -1)->first, std::prev(sol.rbegin(), -1)->second));
        this->b = -this->h*5.0/12.0;
        y_new = this->SolveNonLinearEquation(t_new, sol.rbegin()->second);
    } else if (nSteps == 3) {

        this->a = -sol.rbegin()->second - this->h*(19.0/24.0*this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second)
                        -5.0/24.0*this->funObject->EvaluateFun(std::prev(sol.rbegin(), -1)->first, std::prev(sol.rbegin(), -1)->second)+
                        1.0/24.0*this->funObject->EvaluateFun(std::prev(sol.rbegin(), -2)->first, std::prev(sol.rbegin(), -2)->second));
        this->b = -this->h*9.0/24.0;
        y_new = this->SolveNonLinearEquation(t_new, sol.rbegin()->second);

    } else if (nSteps == 4) {
        this->a = -sol.rbegin()->second - this->h*(646.0/720.0*this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second)  -
                                                   264.0/720.0*this->funObject->EvaluateFun(std::prev(sol.rbegin(), -1)->first, std::prev(sol.rbegin(), -1)->second)+
                                                    106.0/720.0*this->funObject->EvaluateFun(std::prev(sol.rbegin(), -2)->first, std::prev(sol.rbegin(), -2)->second)
                                                    -19.0/720.0*this->funObject->EvaluateFun(std::prev(sol.rbegin(), -3)->first, std::prev(sol.rbegin(), -3)->second));
        this->b = -this->h*251.0/720.0;
        y_new = this->SolveNonLinearEquation(t_new, sol.rbegin()->second);

    }

    return y_new;
}
