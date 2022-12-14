//
// Created by parallels on 11/25/22.
//

#ifndef PROJECT_SALA_VISCUSI_FORWARDEULER_H
#define PROJECT_SALA_VISCUSI_FORWARDEULER_H

#include "AbstractOdeSolver.h"
#include <cmath>

/*! \class ForwardEuler
    \brief Daughter class of AbstractOdeSolver: explicit method to solve an ODE.

    This class features the Forward Euler method to solve an ODE.
*/

class ForwardEuler : public AbstractOdeSolver {

public:
    //! Customized constructor inherited from AbstractOdeSolver.
    /*!
      This customized constructor allows to initialize all the members contained in the mother class, apart from the
      standard map containing the solution.
    */
    ForwardEuler(const double stepsize, const double initval, const double inittime, const double fintime,
                     AbstractParser* fun_obj) : AbstractOdeSolver(stepsize, initval, inittime, fintime, fun_obj) {};


    /*! Here the virtual method from the mother class AbstractOdeSolver is overridden, according
     *  to the desired algorithm. Here the algorithm:
    *
    *  \f$y_{n + 1} = y_n + hf(t_n, y_n)\f$
    */
    void solve() override;

    ~ForwardEuler() override;

};


#endif //PROJECT_SALA_VISCUSI_FORWARDEULER_H
