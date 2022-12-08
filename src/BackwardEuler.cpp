//
// Created by francesco on 02/12/22.
//

#include "BackwardEuler.h"


void BackwardEuler::solve() {

    int N = static_cast<int>(std::floor((this->tf - this->t0) / this->h));

    this->sol.emplace(this->t0, this->y0);

    for (int i = 0; i<=N; i++)
    {
        double t_new = this->t0 + this->h * i;
        this->a = -this->sol.rbegin()->second;
        this->b = -this->h;
        double y = this->SolveNonLinearEquation(t_new, sol.rbegin()->second);
        this->sol.emplace(t_new, y);
    }
}


