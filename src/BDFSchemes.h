//
// Created by parallels on 12/4/22.
//

// here Backward Differentiation Formulas (BDF) up to 4 steps is implemented

#ifndef PROJECT_PCSC_BDFSCHEMES_H
#define PROJECT_PCSC_BDFSCHEMES_H

#include "AbstractImplicitOdeSolver.h"

//class BDFSchemes : public AbstractImplicitOdeSolver {
//
//private:
//    int steps;
//
//public:
//    // Customized constructor inherited drom AbstractImplicitOdeSolver
//    BDFSchemes(const double stepsize, const double initval, const double inittime, const double fintime,
//                  AbstractParser* fun_obj, int nSteps, const double tolmax = 1e-8, const double max_iter = 1000) : AbstractImplicitOdeSolver(stepsize, initval, inittime, fintime, fun_obj, tolmax, max_iter) {this->steps = nSteps;};
//
//    // Here we override the method inherited from AbstractOdeSolver
//    void solve() override;
//
//    // Here we override the methods inherited from AbstractImplicitOdeSolver
//
//};

#endif //PROJECT_PCSC_BDFSCHEMES_H
