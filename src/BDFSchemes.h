//
// Created by parallels on 12/4/22.
//

// here Backward Differentiation Formulas (BDF) up to 4 steps is implemented

#ifndef PROJECT_PCSC_BDFSCHEMES_H
#define PROJECT_PCSC_BDFSCHEMES_H

#include "AbstractImplicitOdeSolver.h"

/*! \class BDFSchemes class
    \brief Class derived from AbstractImplicitOdeSolver. Implicit multistep method to solve ODE

    This class features the Backward Differantiation Formulae (BDF). Steps until 4 are implemented here.
*/

class BDFSchemes : public AbstractImplicitOdeSolver {

private:
    int steps;                /// < number of steps for this multistep method [1,4]

public:
    //! Customized constructor inherited from AbstractImplicitOdeSolver.
    /*!
      This customized constructor allows to initialize all the members contained in the mother class, apart from the
      standard map containing the solution. Here, the number of steps desired is to be specified too. The value of tolerance
      tol and maximum number of iterations max_iter can be either specified, or left as default values (tol = 1e-8, max_iter
      = 1000).
    */
    BDFSchemes(const double stepsize, const double initval, const double inittime, const double fintime,
                  AbstractParser* fun_obj, int nSteps, const double tolmax = 1e-8, const double max_iter = 1000) : AbstractImplicitOdeSolver(stepsize, initval, inittime, fintime, fun_obj, tolmax, max_iter) { this->steps = nSteps;};

    /*! Here the virtual method from the mother class AbstractOdeSolver is overridden according
    *  to the BDF schemes. The method BDFSchemesNstep() is called varying nSteps.
     *  The first (steps-1) number of steps are computed using an increasing number of steps
     *  then, at each timestep, the same method is called with nSteps = this->steps. The std::map of the solution is
     *  updated accordingly.
     * \see solve() method.
    */
    void solve() override;

    /*! This method applies the BDF scheme with a number of steps specified by nSteps.  Here the algorithm for steps s=1,2,3,4:
    *
    *  \f$s=1\f$: \f$y_{n + 1} - y_n = h\left(f(t_{n+1}, y_{n+1})\right)\f$
    *
    *  \f$s=2\f$: \f$y_{n + 2} - \frac{4}{3}y_{n+1} + \frac{1}{3} y_n = \frac{2}{3} h \left(f (t_{n+2}, y_{n+2})\right)\f$
    *
     *
    *  \f$s=3\f$: \f$y_{n + 3} - \frac{18}{11}y_{n + 2} + \frac{9}{11} y_{n+1}- \frac{2}{11} y_n = \frac{6}{11} h\left(f(t_{n + 3}, y_{n + 3}\right)\f$
    *
    *  \f$s=4\f$: \f$y_{n + 4} -\frac{48}{25} y_{n+3}  + \frac{36}{25} y_{n+2} - \frac{16}{25} y_{n+1} + \frac{3}{25} y_n = \frac{12}{25} h\left(f(t_{n+4}, y_{n+4})\right)\f$,
    *
     * Since the nonlinear equation is in the form \f$g(y_{n+1}) = 0 = y_{n+1} + a + b f(t_{n+1}, y_{n+1})\f$, at each time step the members of the class
     * AbstractImplicitOdeSolver \f$a \f$ and \f$b \f$ are set according to the above algorithm.
     * \see SolveNonLinearEquation()
     * @param nSteps (integer)
     * @return the solution of the nonlinear equation at timestep \f$t_{n+1}\f$ for the BDF scheme with the specified number of steps.
     */
    double BDFSchemesNstep(int nSteps);

    ~BDFSchemes() override;


};

#endif //PROJECT_PCSC_BDFSCHEMES_H
