// Libraries and headers
#include <iostream>
#include <cassert>
#include <gtest/gtest.h>
#include "ManageInput.h"
#include "AbstractOdeSolver.h"


/** @brief
 *      This is the main
 *
 * @param[in] argc
 * @param[in] argv
 * @return
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

    return 0;
}


