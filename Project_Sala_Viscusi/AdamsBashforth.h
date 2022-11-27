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
        s = steps;
    }

    void solve() ;
};


#endif //PROJECT_SALA_VISCUSI_ADAMSBASHFORTH_H
