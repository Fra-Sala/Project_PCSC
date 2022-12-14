//
// Created by parallels on 12/4/22.
//

#ifndef PROJECT_PCSC_EXPLICITRUNGEKUTTA_H
#define PROJECT_PCSC_EXPLICITRUNGEKUTTA_H

#include "AbstractOdeSolver.h"

/*! \class ExplicitRungeKutta
    \brief Daughter class of AbstractOdeSolver: explicit method to solve an ODE.

    This class features the Runge-Kutta multistage method.
    Stages until 4 are implemented here. The number of stages corresponds with the order of accuracy of the method
    itself.
*/


class ExplicitRungeKutta : public AbstractOdeSolver {

private:
    unsigned int stages;                ///< number of stages [1, 4]

public:
    //! Customized constructor inherited from AbstractOdeSolver.
    /*!
      This customized constructor allows to initialize all the members contained in the mother class, apart from the
      standard map containing the solution. Here, the number of stages desired is to be specified too.
    */
    ExplicitRungeKutta(const double stepsize, const double initval, const double inittime, const double fintime,
                   AbstractParser* fun_obj, const unsigned int choice) : AbstractOdeSolver(stepsize, initval, inittime, fintime, fun_obj) {this->stages = choice;};


    /*! Here the virtual method from the mother class AbstractOdeSolver is overridden according
    *  to the desired algorithm. Here the algorithms that have been implemented (for every number of stages, one method
     *  have been chosen):
    *
    *  \f$s=1\f$: \f$y_{n + 1} = y_n + hK_1\f$, where \f$K_1 = f(t_n, y_n)\f$.
    *
    *  \f$s=2\f$: \f$y_{n + 1} = y_n + \frac{1}{2} h (K_1 + K_2)\f$, where \f$K_1 = f(t_n, y_n)\f$ and \f$K_2 =
     *  f(t_{n + 1}, y_n + hK_1)\f$.
    *
    *  \f$s=3\f$: \f$y_{n + 1} = y_n + \frac{1}{6}h(K_1 + K_2 + K_3)\f$,
     *  where \f$K_1 = f(t_n, y_n)\f$, \f$K_2 = f\left(t_n + h, y_n + hK_1)\f$ and
     *  \f$K_3 = f\left(t_n + \frac{h}{2}, y_n + \frac{h}{4}(K_1 + K_2)\right)\f$
    *
    *  \f$s=4\f$: \f$y_{n + 1} = y_n + h\left(\frac{1}{6}K_1 + \frac{1}{3}K_2 + \frac{1}{3}K_3 + \frac{1}{6}K_4\right)\f$,
     *  where \f$K_1 = f(t_n, y_n)\f$, \f$K_2 = f\left(t_n + \frac{h}{2}, y_n + \frac{h}{2}K_1\right)\f$,
     *  \f$K_3 = f\left(t_n + \frac{h}{2}, y_n + \frac{h}{2}K_2\right)\f$ and \f$K_4 = f(t_n + h, y_n + h K_3)\f$.
    */
    void solve() override;


    ~ExplicitRungeKutta() override;

};

#endif //PROJECT_PCSC_EXPLICITRUNGEKUTTA_H
