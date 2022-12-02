//
// Created by francesco on 27/11/22.
//

#include "ForwardEuler.h"
#include <iostream>

ForwardEuler::ForwardEuler(const double stepsize, const double initval, const double inittime, const double fintime,
                           AbstractParser* fun_obj) {
    this->h = stepsize;
    this->y0 = initval;
    this->t0 = inittime;
    this->tf = fintime;
    this->funObject = fun_obj;
}

void ForwardEuler::solve() {

        int N = round((this->tf - this->t0) / this->h);

        auto c = this->sol.try_emplace(this->t0, this->y0);

        for(int i = 1; i <= N; i++) {
            double t = this->t0 + this->h * i;
            double y = sol.rbegin()->second + h * this->funObject->EvaluateFun(sol.rbegin()->first, sol.rbegin()->second);
            sol.emplace(t, y);
        }
    }

