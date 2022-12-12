//
// Created by parallels on 12/4/22.
//


#ifndef PROJECT_PCSC_ABSTRACTIMPLICITODESOLVER_H
#define PROJECT_PCSC_ABSTRACTIMPLICITODESOLVER_H

#include "AbstractOdeSolver.h"

/*! \class AbstractImplicitOdeSolver
    \brief Daughter class of AbstractOdeSolver required for every implemented implicit method to solve an ODE.

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

    /** This method evaluates the \f$g(y_{n+1})\f$, LHS of the nonlinear equation \f$g(y)=0\f$. It takes two arguments
     * and returns a double value. We exploit the fact that the general \f$g(y) \f$ is in the form \f$g(y) = y_{n+1} + a + b \cdot f(t_{n+1}, y_{n+1})\f$.
     * @param t is the new timestep \f$ t_{n+1} \f$
     * @param y is the unknown of the non-linear equation.
     * @return a double variable containing the evaluation of the non-linear equation at current \f$ y\f$ and at \f$t = t_{n+1} \f$.
    */
    double NonLinearEquation(double t, double y) ;

    /** This method tries to solve the non-linear equation using the implemented algorithms. The first algorithm tried is fixed point iterations
     * and, if such method fails to converge, an exception is thrown and Broyden algorithm is used.
     * \see NonLinearEquation()
     * \see FixedPoint()
     * \see Broyden()
     * @param t is the new timestep corresponding with the \f$y\f$ value we are looking for.
     * @param y is the unknown of the non-linear equation.
     * @return the solution of the nonlinear equation \f$ySol\f$.
    */
    double SolveNonLinearEquation(double t, double y);


    /** \brief Algorithm of fixed point iterations.
     *
     * It is used in SolveNonLinearEquation. The method tries to solve the non-linear equation by
     * finding the fixed point of the iteration function \f$\phi(x) = x - f(x)\f$. Stopping criteria are:
     *
     * 1) max iterations allowed reached;
     *
     * 2) tolerance on the difference between two subsequent iterates is reached.
     *
     * Moreover, if the error is incresing, i.e. the algorithm is diverging, an exception is thrown and the algorithm
     * is interrupted.
     * \see SolveNonLinearEquation()
     * @param t is the new timestep corresponding with the \f$y\f$ value we are looking for.
     * @param y is the unknown of the non-linear equation.
     * @return the solution of the nonlinear equation \f$ySol\f$.
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
     * @param t is the new timestep corresponding with the \f$y\f$ value we are looking for.
     * @param y is the unknown of the non-linear equation.
     * @return the solution of the nonlinear equation \f$ySol\f$.
    */
    double Broyden(double t, double y);


};

#endif //PROJECT_PCSC_ABSTRACTIMPLICITODESOLVER_H
