//
// Created by francesco on 08/12/22.
//

#ifndef PROJECT_PCSC_ADAMSMOULTON_H
#define PROJECT_PCSC_ADAMSMOULTON_H

// This class, which inherits from AbstractOdeSolver, solves an ode with the (implicit)
// Adams-Moulton multistep method. At each time step, the implicit equation
// is solved using the fixed point algorithm, which is stopped by either the number
// of iterations exceeding nmax or by the difference between two consecutive iterations
// smaller than a given tolerance tol.
// Both the values of nmax and tol can be either specified by the user, or left as default
// (nmax = 1000, tol = 1e-8)
//
//

/*! \class AbstractImplicitOdeSolver
    \brief Abstract class derived from AbstractOdeSolver. All implicit-solver classes derive from this class.

    This class is Abstract. It allows to initialize every field common to the different implicit methods that will be
    implemented in daughter classes.
*/


#include "AbstractImplicitOdeSolver.h"

class AdamsMoulton : public AbstractImplicitOdeSolver {

private:
    int steps;    /// < number of steps for this multistep method
public:
    // Customized constructor inherited from AbstractImplicitOdeSolver
    AdamsMoulton(const double stepsize, const double initval, const double inittime, const double fintime,
                  AbstractParser* fun_obj, int nSteps, const double tol = 1e-8, const double max_iter = 1000) : AbstractImplicitOdeSolver(stepsize, initval, inittime, fintime, fun_obj, tol, max_iter) {this->steps = nSteps;};

    // override the solve() method inherited from AbstractOdeSolver
    void solve() override;

    double AdamsMoultonNstep(int nSteps);
};





#endif //PROJECT_PCSC_ADAMSMOULTON_H
