#ifndef PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H
#define PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H

#include <map>
#include <vector>
#include "fparser.hh"
#include "AbstractParser.h"


class AbstractOdeSolver {
    // Members
protected:
    double h;                                                   // step-size
    double y0;                                                  // initial value
    double t0;                                                  // initial time
    double tf;                                                  // final time
    AbstractParser* funObject;
    std::map<double, double> sol;                               // standard map containing the solution

    // Methods and constructors
public:
    // Constructors
    AbstractOdeSolver();
    AbstractOdeSolver(const double stepsize, const double initval, const double inittime, const double fintime,
                     AbstractParser* fun_object);

    // solution visualization, flag is for file output
    void VisualizeSolution(bool flag);

    // fixed point algorithm for implicit
    double FixedPoint(double x0, FunctionParser *phi, int nmax, double tol);

    // Virtual method
    virtual void solve() = 0;
};

#endif //PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H
