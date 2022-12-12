//
// Created by francesco on 02/12/22.
//

// This class, which inherits from AbstractOdeSolver, solves an ode with
// backward (implicit) Euler method. At each time step, the implicit equation
// is solved using the fixed point algorithm, which is stopped by either the number
// of iterations exceeding nmax or by the difference between two consecutive iterations
// smaller than a given tolerance tol.
// Both the values of nmax and tol can be either specified by the user, or left as default
// (nmax = 1000, tol = 1e-8)
//
//


#ifndef PROJECT_PCSC_BACKWARDEULER_H
#define PROJECT_PCSC_BACKWARDEULER_H


#include "AbstractImplicitOdeSolver.h"

/*! \class BackwardEuler class
    \brief Class derived from AbstractImplicitOdeSolver. Implicit Euler method to solve ODE

    This class features the backward Euler algorithm.
*/

class BackwardEuler : public AbstractImplicitOdeSolver {

public:
    //! Customized constructor inherited from AbstractImplicitOdeSolver.
    /*!
      This customized constructor allows to initialize all the members contained in the mother class, apart from the
      standard map containing the solution. Here, the number of steps desired is to be specified too. The value of tolerance
      tol and maximum number of iterations max_iter (stopping criteria for the nonlinear equation solver) can be either specified,
      or left as default values (tol = 1e-8, max_iter = 1000).
    */
    BackwardEuler(const double stepsize, const double initval, const double inittime, const double fintime,
                   AbstractParser* fun_obj, const double tolmax = 1e-8, const double max_iter = 1000) : AbstractImplicitOdeSolver(stepsize, initval, inittime, fintime, fun_obj, tolmax, max_iter) {};

    /*! This method applies the Backward Euler algorithm, as follows:
    *
    *  \f$y_{n+1} = y_n + hf(t_{n+1}, y_{n+1})    \f$
     *
     * Hence at each time step a non-linear equation needs to be solved. Therefore
     * members \f$a \f$ and \f$b \f$ which characterize the equation at each time step
     * are set as \f$  a = - y_n  \f$ and \f$ b = -h \f$.
     * \see SolveNonLinearEquation()
     * @param
     * @return the solution of the nonlinear equation at timestep \f$t_{n+1}\f$.
     */
    void solve() override;




};
#endif //PROJECT_PCSC_BACKWARDEULER_H
