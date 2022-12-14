//
// Created by parallels on 11/25/22.
//

#ifndef PROJECT_SALA_VISCUSI_ADAMSBASHFORTH_H
#define PROJECT_SALA_VISCUSI_ADAMSBASHFORTH_H

#include "AbstractOdeSolver.h"
#include <cmath>

/*! \class AdamsBashforth
    \brief Daughter class of AbstractOdeSolver: explicit method to solve an ODE.

    This class features the AdamsBashforth multistep method. Steps until 4 are implemented here.
*/


class AdamsBashforth : public AbstractOdeSolver {

private:
    int steps;              ///< number of steps [1, 4]

public:
    //! Customized constructor inherited from AbstractOdeSolver.
    /*!
      This customized constructor allows to initialize all the members contained in the mother class, apart from the
      standard map containing the solution. Here, the number of steps desired is to be specified too.
    */
    AdamsBashforth(const double stepsize, const double initval, const double inittime, const double fintime,
                   AbstractParser* fun_obj, unsigned int nSteps) : AbstractOdeSolver(stepsize, initval, inittime, fintime, fun_obj) {this->steps = nSteps;};

    /*! Here the virtual method from the mother class AbstractOdeSolver is overridden according
     *  to the desired algorithm. In this case, the first 'steps' solutions
     *  are computed with Forward Euler. Here the algorithms:
     *
     *  \f$s=1\f$: \f$y_{n + 1} = y_n + hf(t_n, y_n)\f$
     *
     *  \f$s=2\f$: \f$y_{n + 2} = y_{n + 1} + h\left(\frac{3}{2}f(t_{n + 1}, y_{n + 1})
     *  - \frac{1}{2}f(t_n, y_n)\right)\f$
     *
     *  \f$s=3\f$: \f$y_{n + 3} = y_{n + 2} + h\left(\frac{23}{12}f(t_{n + 2}, y_{n + 2})
     *  - \frac{16}{12}f(t_{n + 1}, y_{n + 1}) + \frac{5}{12}f(t_n, y_n)\right)\f$
     *
     *  \f$s=4\f$: \f$y_{n + 4} = y_{n + 3} + h\left(\frac{55}{24}f(t_{n + 3}, y_{n + 3})
     *  - \frac{59}{24}f(t_{n + 2}, y_{n + 2}) + \frac{37}{24}f(t_{n + 1}, y_{n + 1}) - \frac{9}{24}f(t_n, y_n)\right)\f$
     */
    void solve() override;

    //! Overridden destructor inherited from AbstractOdeSolver.
    /*!
       Frees the memory associated with the member @param funObject.
    */
    ~AdamsBashforth() override;
};

#endif //PROJECT_SALA_VISCUSI_ADAMSBASHFORTH_H
