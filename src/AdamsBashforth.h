//
// Created by parallels on 11/25/22.
//

#ifndef PROJECT_SALA_VISCUSI_ADAMSBASHFORTH_H
#define PROJECT_SALA_VISCUSI_ADAMSBASHFORTH_H

#include "AbstractOdeSolver.h"
#include <cmath>

class AdamsBashforth : public AbstractOdeSolver {

private:
    unsigned int s;              // number of steps [0, 4]

public:

    AdamsBashforth(const double stepsize, const double initval, const double inittime, const double fintime,
                   AbstractParser* fun_obj, unsigned int steps) : AbstractOdeSolver(stepsize, initval, inittime, fintime, fun_obj) {s = steps;};
    void solve() override;
};


#endif //PROJECT_SALA_VISCUSI_ADAMSBASHFORTH_H