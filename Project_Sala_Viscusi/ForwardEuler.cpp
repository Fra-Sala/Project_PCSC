//
// Created by francesco on 27/11/22.
//

#include "ForwardEuler.h"
#include <iostream>

ForwardEuler::ForwardEuler(const double stepsize, const double initval, const double inittime, const double fintime,
                           FunctionParser *f_rhs) {
    this->h = stepsize;
    this->y0 = initval;
    this->t0 = inittime;
    this->tf = fintime;
    this->rhs = f_rhs;
}

void ForwardEuler::solve() {

        int N = round((this->tf - this->t0) / this->h);

        auto c = this->sol.try_emplace(this->t0, this->y0);
        std::cout << c.second << std::endl;
        std::cout << "ecco i primi elementi della mappa " << this->sol.rbegin()->first << " " << this->sol.rbegin()->second << std::endl;

        for(int i = 1; i <= N; i++) {
            double t = this->t0 + this->h * i;
            std::cout << "at time " << t << " ";
            auto *v = new double [2] {sol.rbegin()->first, sol.rbegin()->second};
            std::cout << "ecco gli ultimi elementi della mappa "<< v[0] << " " << v[1] << std::endl;
            double y = sol.end()->second + h * rhs->Eval(v);

            sol.emplace(t, y);
            std::cout << "I have inserted " << y << std::endl;
            std::cout << rhs->Eval(v)<< std::endl;
            delete[] v;
        }
    }

