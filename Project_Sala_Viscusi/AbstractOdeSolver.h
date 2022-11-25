#ifndef PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H
#define PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H

#include <map>

class AbstractOdeSolver {
    // Members
protected:
    double h;                                                   // step-size
    double y0;                                                  // initial value
    double t0;                                                  // initial time
    double tf;                                                  // final time
    double (*rhs)(const double y, const double t);              // pointer to rhs-function
    std::map<double, double> sol;                               // standard map containing the solution

    // Methods and constructors
public:
    // Constructors
    AbstractOdeSolver();
    AbstractOdeSolver(const double stepsize, const double initval, const double inittime, const double fintime,
                      double (*f)(const double y, const double t));

    // solution visualization, flag is for file output
    void VisualizeSolution(bool flag);

    // Virtual method
    virtual void solve() = 0;
};

#endif //PROJECT_SALA_VISCUSI_ABSTRACTODESOLVER_H
