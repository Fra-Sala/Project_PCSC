// Libraries and headers
#include <cassert>
#include "ManageInput.h"
#include "AbstractOdeSolver.h"


/** @brief This is the main.
 *
 * @param argc number of arguments specified when the program is run.
 * @param argv actual arguments specified on the command line.
 */

int main(int argc, char* argv[]) {
    ManageInput ode(argc, argv);
    AbstractOdeSolver *ptr = ode.ConstructSolver();
    assert(ptr);
    ptr->solve();
    ptr->VisualizeSolution();
    delete ptr;
    return 0;
}


