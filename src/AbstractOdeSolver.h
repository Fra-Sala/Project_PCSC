#ifndef PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H
#define PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H

#include <map>
#include <vector>
#include "fparser.hh"
#include "AbstractParser.h"

/*! \class AbstractOdeSolver
    \brief Mother abstract class for every implemented method to solve an ODE.

    This class is Abstract. It allows to initialize every field common to the different methods that will be
    implemented in daughter classes.
*/

class AbstractOdeSolver {

protected:
    double h;                                                   ///< step-size
    double y0;                                                  ///< initial value
    double t0;                                                  ///< initial time
    double tf;                                                  ///< final time
    AbstractParser* funObject;                                  ///< rhs of ODE
    std::map<double, double> sol;                               ///< standard map containing the solution

public:

    //! Default constructor overridden.
    /*!
      This constructor explicitly sets a specific default behavior (NOTE: no default behavior is set fot the
      std::map containing the solution).
    */
    AbstractOdeSolver();

    //! A customized constructor.
    /*!
      This customized constructor allows to initialize all the members contained in the class, apart from the
      standard map containing the solution.
    */
    AbstractOdeSolver(const double stepsize, const double initval, const double inittime, const double fintime,
                     AbstractParser* fun_object);


    //! This void method allows solution visualization.
    void VisualizeSolution();


    //! Pure virtual method to solve the ODE (it will be overridden in each daughter class).
    virtual void solve() = 0;

    /**
    * This method takes no arguments and returning a pointer of type std::map<double, double>.
    * @return A pointer to a map containing the solution
    */
    std::map<double,double>* GetSolution();
};

#endif //PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H
