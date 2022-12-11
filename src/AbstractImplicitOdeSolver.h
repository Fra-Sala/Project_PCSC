//
// Created by parallels on 12/4/22.
//

// this class inherits from AbstractOdeSolver and is required for all the implicit methods

#ifndef PROJECT_PCSC_ABSTRACTIMPLICITODESOLVER_H
#define PROJECT_PCSC_ABSTRACTIMPLICITODESOLVER_H

#include "AbstractOdeSolver.h"

/*! \class AbstractImplicitOdeSolver
    \brief Daughter class of AbstractOdeSolver for every implemented implicit method to solve an ODE.

    This class is Abstract. It allows to initialize every field common to the different implicit methods that will be
    implemented in daughter classes.
*/

class AbstractImplicitOdeSolver : public AbstractOdeSolver {

protected:
    double nmax;                ///< max number of iterations allowed to solve the non-linear equation
    double tol;                 ///< tolerance required to solve the non-linear equation
    double a;                   ///< known coefficient of the non-linear equation
    double b;                   ///< coefficient multiplying the unknown part of the non-linear equation


public:
    //! Customized constructor inherited from AbstractOdeSolver.
    /*!
      This customized constructor allows to initialize all the members contained in the class, apart from the
      standard map containing the solution. Additionally, it allows to specify the max number of iterations to
      solve the non-linear equation and the desired tolerance. If no argument is given, both variables take a default
      value.
    */
    AbstractImplicitOdeSolver(const double stepsize, const double initval, const double inittime, const double fintime,
                              AbstractParser* fun_obj, const double tolmax = 1e-8, const double max_iter = 1000) : AbstractOdeSolver(stepsize, initval, inittime, fintime, fun_obj) {this->tol = tolmax, this->nmax = max_iter, this->a = 0.0, this->b = 0.0;};

    /** This method sets the f(y) for which we look for y such that f(y)=0. It takes two arguments and returns a double value.
     * @param t is the new timestep corresponding with the 'y' value we are looking for.
     * @param y is the unknown of the non-linear equation.
     * @return a double variable containing the non-linear equation.
    */
    double NonLinearEquation(double t, double y) ;

    /** This method tries to solve the non-linear equation with the algorithms implemented. If it fails, it throws
     * an exception that switches the algorithm.
     * \see NonLinearEquation()
     * @param t is the new timestep corresponding with the 'y' value we are looking for.
     * @param y is the unknown of the non-linear equation.
     * @return the solution of the nonlinear equation ySol.
    */
    double SolveNonLinearEquation(double t, double y);


    /** \brief Algorithm of fixed point iterations.
     *
     * It is used in SolveNonLinearEquation. The method tries to solve the non-linear equation by
     * finding the fixed point of the iteration function \f$ \phi(x) = x - f(x) \f$. Stopping criteria are:
     *
     * 1) max iterations allowed reached;
     *
     * 2) tolerance on the difference between two subsequent iterates is reached.
     *
     * Moreover, if the error is incresing, i.e. the algorithm is diverging, an exception is thrown and the algorithm
     * is interrupted.
     * \see SolveNonLinearEquation()
     * @param t is the new timestep corresponding with the 'y' value we are looking for.
     * @param y is the unknown of the non-linear equation.
     * @return the solution of the nonlinear equation ySol.
    */
    double FixedPoint(double t, double y);

    /** \brief Broyden algorithm.
     *
     * It is used in SolveNonLinearEquation. The method tries to solve the non-linear equation by
     * finding approximating the derivative with finite difference. Stopping criteria are:
     *
     * 1) max iterations allowed reached;
     *
     * 2) tolerance on the difference between two subsequent iterates is reached.
     * \see SolveNonLinearEquation()
     * @param t is the new timestep corresponding with the 'y' value we are looking for.
     * @param y is the unknown of the non-linear equation.
     * @return the solution of the nonlinear equation ySol.
    */
    double Broyden(double t, double y);

};

#endif //PROJECT_PCSC_ABSTRACTIMPLICITODESOLVER_H
