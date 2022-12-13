//
// Created by parallels on 12/4/22.
//

#include "BDFSchemes.h"


void BDFSchemes::solve() {

    int N = static_cast<int>(std::floor((this->tf - this->t0) / this->h));
    sol.emplace(t0, y0);
    // The first n steps are solved using the corresponding Adams-Moulton method
    for (int i = 1; i < this->steps; i++)
    {
        double y = this->BDFSchemesNstep(i);
        sol.emplace(this->sol.rbegin()->first + this->h, y);
    }

   /* Now, depending on the particular numbers of steps,
      a different implementation of Adams-Bashforth method is applied */

    for (int i = this->steps; i <= N; i++)
    {
        double y = this->BDFSchemesNstep(this->steps);
        sol.emplace(this->sol.rbegin()->first + this->h, y);

    }
}


double BDFSchemes::BDFSchemesNstep(int nSteps)
{

    double y_new = 0.0;
    double t_new = this->sol.rbegin()->first + this->h;
    if (nSteps == 1) {

        this->a = -sol.rbegin()->second;
        this->b = -this->h;
        y_new = this->SolveNonLinearEquation(t_new, sol.rbegin()->second);
        // sol.rbegin()->second + h * this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second);
    } else if (nSteps == 2) {
        this->a = -4.0/3.0*sol.rbegin()->second +1.0/3.0*std::prev(sol.rbegin(),-1)->second;
        this->b = -this->h*2.0/3.0;
        y_new = this->SolveNonLinearEquation(t_new, sol.rbegin()->second);
    } else if (nSteps == 3) {

        this->a = -18.0/11.0*sol.rbegin()->second  +9.0/11.0*std::prev(sol.rbegin(),-1)->second -2.0/11.0*std::prev(sol.rbegin(),-2)->second;
        this->b = -this->h*6.0/11.0;
        y_new = this->SolveNonLinearEquation(t_new, sol.rbegin()->second);

    } else if (nSteps == 4) {
        this->a = -48.0/25.0*sol.rbegin()->second + 36.0/25.0*std::prev(sol.rbegin(),-1)->second - 16.0/25.0*std::prev(sol.rbegin(),-2)->second
                   + 3.0/25.0*std::prev(sol.rbegin(),-3)->second ;
        this->b = -this->h*12.0/25.0;
        y_new = this->SolveNonLinearEquation(t_new, sol.rbegin()->second);

    }

    return y_new;
}

