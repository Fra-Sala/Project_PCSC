//
// Created by parallels on 11/25/22.
//

#ifndef PROJECT_SALA_VISCUSI_FORWARDEULER_H
#define PROJECT_SALA_VISCUSI_FORWARDEULER_H

#include "AbstractOdeSolver.h"
#include <cmath>

class ForwardEuler : public AbstractOdeSolver {

public:
    ForwardEuler(const double stepsize, const double initval, const double inittime, const double fintime,
                      FunctionParser *rhs);

    void solve() ;

};


#endif //PROJECT_SALA_VISCUSI_FORWARDEULER_H