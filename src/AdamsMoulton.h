//
// Created by francesco on 08/12/22.
//

#ifndef PROJECT_PCSC_ADAMSMOULTON_H
#define PROJECT_PCSC_ADAMSMOULTON_H



/*! \class AdamsMoulton class
    \brief Class derived from ImplicitOdeSolver. Implicit multistep method to solve ODE

    This class features the Adams-Moulton multistep method. Steps until 4 are implemented here.
*/


#include "ImplicitOdeSolver.h"

class AdamsMoulton : public ImplicitOdeSolver {

private:
    int steps;                                /// < number of steps for this multistep method [1,4]
public:
    //! Customized constructor inherited from ImplicitOdeSolver.
    /*!
      This customized constructor allows to initialize all the members contained in the mother class, apart from the
      standard map containing the solution. Here, the number of steps desired is to be specified too. The value of tolerance
      tol and maximum number of iterations max_iter can be either specified, or left as default values (tol = 1e-8, max_iter
      = 1000).
    */
    AdamsMoulton(const double stepsize, const double initval, const double inittime, const double fintime,
                  AbstractParser* fun_obj, int nSteps, const double tol = 1e-8, const double max_iter = 1000) : ImplicitOdeSolver(stepsize, initval, inittime, fintime, fun_obj, tol, max_iter) { this->steps = nSteps;};

    /*! Here the virtual method from the mother class AbstractOdeSolver is overridden according
    *  to the Adams-Moulton method. The method AdamsMoultonNstep() is called varying nSteps.
     *  The first (steps-1) number of steps are computed using an increasing number of steps
     *  then, at each timestep, the same method is called with nSteps = this->steps. The std::map of the solution is
     *  updated accordingly.
     * \see solve() method.
    */
    void solve() override;

    /*! This method applies the Adams-Moulton algorithm with a number of steps specified by nSteps.  Here the algorithm for steps s=1,2,3,4:
    *
    *  \f$s=1\f$: \f$y_{n + 1} = y_n + \frac{1}{2}h\left(f(t_{n+1}, y_{n+1}) + f(t_n, y_n)\right)\f$
    *
    *  \f$s=2\f$: \f$y_{n + 2} = y_{n+1} + h \left(\frac{5}{12} f (t_{n+2}, y_{n+2}) + \frac{8}{12} f(t_{n+1}, y_{n+1}) - \frac{1}{12} f(t_n, y_n)     \right)\f$
    *
     *
    *  \f$s=3\f$: \f$y_{n + 3} = y_{n + 2} + h\left(\frac{9}{24}f(t_{n + 3}, y_{n + 3})
    *  + \frac{19}{24}f(t_{n + 2}, y_{n + 2}) - \frac{5}{24}f(t_{n+1}, y_{n+1}) + \frac{1}{24} f(t_n, y_n)\right)\f$
    *
    *  \f$s=4\f$: \f$y_{n + 4} = y_{n+3} + h\left(\frac{251}{720}f(t_{n+4}, y_{n+4}) + \frac{646}{720}f(t_{n+3}, y_{n+3}) - \frac{264}{720} f(t_{n+2}, y_{n+2}) +
     *  \frac{106}{720}f(t_{n+1}, y_{n+1}) - \frac{19}{720} f(t_{n}, y_n)  \right)\f$,
    *
     * Since the nonlinear equation is in the form \f$g(y_{n+1}) = 0 = y_{n+1} + a + b f(t_{n+1}, y_{n+1})\f$, at each time step the members of the class
     * ImplicitOdeSolver \f$a \f$ and \f$b \f$ are set according to the above algorithm.
     * \see SolveNonLinearEquation()
     * @param nSteps (integer)
     * @return the solution of the nonlinear equation at timestep \f$t_{n+1}\f$ for Adams-Moulton with the specified number of steps.
     */
    double AdamsMoultonNstep(int nSteps);
};





#endif //PROJECT_PCSC_ADAMSMOULTON_H
