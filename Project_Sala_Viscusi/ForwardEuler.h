//
// Created by parallels on 11/25/22.
//

#ifndef PROJECT_SALA_VISCUSI_FORWARDEULER_H
#define PROJECT_SALA_VISCUSI_FORWARDEULER_H

#include "AbstractOdeSolver.h"
#include <cmath>

class ForwardEuler : public AbstractOdeSolver {

public:
    void solve() {
        int N = round((tf - t0) / h);

        sol.insert({t0, y0});

        for(int i = 1; i <= N; i++) {
            double t = t0 + h * i;
            double y = sol.end()->second + h * rhs(sol.end()->second, sol.end()->first);

            sol.insert({t, y});
        }
    }
};


#endif //PROJECT_SALA_VISCUSI_FORWARDEULER_H
