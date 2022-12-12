//
// Created by parallels on 12/4/22.
//

// here Backward Differentiation Formulas (BDF) up to 4 steps is implemented

#ifndef PROJECT_PCSC_BDFSCHEMES_H
#define PROJECT_PCSC_BDFSCHEMES_H

#include "ImplicitOdeSolver.h"

class BDFSchemes : public ImplicitOdeSolver {

private:
    int steps;

public:
    // Customized constructor inherited from ImplicitOdeSolver
    BDFSchemes(const double stepsize, const double initval, const double inittime, const double fintime,
                  AbstractParser* fun_obj, int nSteps, const double tolmax = 1e-8, const double max_iter = 1000) : ImplicitOdeSolver(stepsize, initval, inittime, fintime, fun_obj, tolmax, max_iter) { this->steps = nSteps;};

    // Here we override the method inherited from AbstractOdeSolver
    void solve() override;

    double BDFSchemesNsteps(int nSteps);


};

#endif //PROJECT_PCSC_BDFSCHEMES_H
