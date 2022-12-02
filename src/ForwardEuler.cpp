//
// Created by francesco on 27/11/22.
//

#include "ForwardEuler.h"

void ForwardEuler::solve() {

    int N = static_cast<int>(std::floor((this->tf - this->t0) / this->h));

    this->sol.emplace(this->t0, this->y0);

    for (int i = 1; i <= N; i++) {
        double t = this->t0 + this->h * i;
        double y = sol.rbegin()->second + h * this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second);
        sol.emplace(t, y);
    }
}

