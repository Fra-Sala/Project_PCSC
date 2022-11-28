#ifndef PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H
#define PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H

#include <map>
#include <vector>
#include "fparser.hh"

class AbstractOdeSolver {
    // Members
protected:
    double h;                                                   // step-size
    double y0;                                                  // initial value
    double t0;                                                  // initial time
    double tf;                                                  // final time
    FunctionParser *rhs;                                        // pointer to rhs-function
    std::map<double, double> sol;                               // standard map containing the solution

    // Methods and constructors
public:
    // Constructors
    AbstractOdeSolver();
    AbstractOdeSolver(const double stepsize, const double initval, const double inittime, const double fintime,
                      FunctionParser *rhs);

    // solution visualization, flag is for file output
    void VisualizeSolution(bool flag);

    // Virtual method
    void solve();
};

#endif //PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H