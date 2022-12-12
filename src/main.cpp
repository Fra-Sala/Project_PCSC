// Libraries and headers
#include <cassert>
#include <gtest/gtest.h>
#include "ManageInput.h"
#include "AbstractOdeSolver.h"


/** @brief This is the main.
 *
 * @param argc number of arguments specified when the program is run.
 * @param argv actual arguments specified on the command line.
 */

int main(int argc, const char* argv[]) {

//    int flagTest = 1;
//
//    if (flagTest == 1) {
//        ::testing::InitGoogleTest(&argc, argv);
//        return RUN_ALL_TESTS();
//    }

    ManageInput ode(argc, argv);
    AbstractOdeSolver *ptr = ode.ConstructSolver();
    assert(ptr);
    ptr->solve();
    ptr->VisualizeSolution();
}


