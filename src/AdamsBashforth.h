//
// Created by parallels on 11/25/22.
//

#ifndef PROJECT_SALA_VISCUSI_ADAMSBASHFORTH_H
#define PROJECT_SALA_VISCUSI_ADAMSBASHFORTH_H

#include "AbstractOdeSolver.h"
#include <cmath>

class AdamsBashforth : public AbstractOdeSolver {

private:
    int s;              // number of steps [0, 4]

public:

    void SetSteps(const int steps) {
        this->s = steps;
    }

    AdamsBashforth(const double stepsize, const double initval, const double inittime, const double fintime,
                   AbstractParser* fun_obj) : AbstractOdeSolver(stepsize, initval, inittime, fintime, fun_obj) {}
    void solve() override;
};


#endif //PROJECT_SALA_VISCUSI_ADAMSBASHFORTH_H