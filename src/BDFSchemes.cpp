//
// Created by parallels on 12/4/22.
//

#include "BDFSchemes.h"

void BDFSchemes::solve() {
    int N = static_cast<int>(std::floor((this->tf - this->t0) / this->h));

    this->sol.emplace(this->t0, this->y0);

    // Now depending on the variable 'steps', a different method will be applied
    if (steps == 1) {
        // This will be Backward Euler
        for (int i = 0; i<=N; i++){

            double t = this->t0 + this->h * i;
            double y = this->SolveNonLinearEquation(t, sol.rbegin()->second);

            this->sol.emplace(t, y);
        }

    } else if (steps == 2) {

    } else if (steps == 3) {

    } else if (steps == 4) {

    }
}