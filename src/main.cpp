// Libraries and headers
#include <iostream>
#include <cassert>
#include <gtest/gtest.h>
#include "ManageInput.h"
#include "AbstractOdeSolver.h"
#include "ForwardEuler.h"
#include "AdamsBashforth.h"
#include "BackwardEuler.h"
#include "ExplicitRungeKutta.h"
#include "BDFSchemes.h"
#include "AdamsMoulton.h"


/////////////////////////
// REMEMBER TO RUN THE CODE, AFTER COMPILING, FROM THE TERMINAL!!!!!
/////////////////////////


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


