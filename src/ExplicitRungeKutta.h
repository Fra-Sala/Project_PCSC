//
// Created by parallels on 12/4/22.
//

// a bunch of arbitrary explicit Runge Kutta methods is implemented here
// the user is allowed to select one of these, specifying the variable 'stages' (it corresponds with the order
// of accuracy of the method itself). For each number of stages, one Runge Kutta method is implemented

#ifndef PROJECT_PCSC_EXPLICITRUNGEKUTTA_H
#define PROJECT_PCSC_EXPLICITRUNGEKUTTA_H

#include "AbstractOdeSolver.h"

class ExplicitRungeKutta : public AbstractOdeSolver {

private:
    unsigned int stages;

public:
    ExplicitRungeKutta(const double stepsize, const double initval, const double inittime, const double fintime,
                   AbstractParser* fun_obj, const unsigned int choice) : AbstractOdeSolver(stepsize, initval, inittime, fintime, fun_obj) {this->stages = choice;}
    void solve() override;

};

#endif //PROJECT_PCSC_EXPLICITRUNGEKUTTA_H
