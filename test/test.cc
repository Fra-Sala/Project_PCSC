#include <cmath>
#include <gtest/gtest.h>
#include "../src/ExplicitRungeKutta.h"
#include "../src/Fparser.h"
#include "../src/BackwardEuler.h"
#include "../src/BDFSchemes.h"
#include "../src/AdamsMoulton.h"
#include "../src/AdamsBashforth.h"
#include "../src/ForwardEuler.h"
#include "../src/ManageInput.h"
#include <algorithm>

#include "FwdTest.h"
#include "AdamsBashTest.h"
#include "BkwTest.h"
#include "RKTest.h"
#include "BDFTest.h"
#include "AdamsMoulTest.h"

// Test for ForwardEuler
TEST_F(FwdTest, forward) {
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
}

// Tests for AdamsBashforth
TEST_P(AdamsBashTest, AdamsBash) {
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
}
INSTANTIATE_TEST_SUITE_P(AdamsBash, AdamsBashTest, ::testing::Values(1, 2, 3, 4));

// Test for BackwardEuler
TEST_F(BkwTest, backward) {
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
}

// Tests for ExplicitRungeKutta
TEST_P(RKTest, RK) {
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
}
INSTANTIATE_TEST_SUITE_P(RK, RKTest, ::testing::Values(1, 2, 3, 4));

// Tests for BDFSchemes
TEST_P(BDFTest, BDF) {
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
}
INSTANTIATE_TEST_SUITE_P(BDF, BDFTest, ::testing::Values(1, 2, 3, 4));

// Tests for AdamsMoulton
TEST_P(AdamsMoulTest, AdamsMoul) {
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
}
INSTANTIATE_TEST_SUITE_P(AdamsMoul, AdamsMoulTest, ::testing::Values(1, 2, 3, 4));

// Tests for the ManageInput class, given a mock string (as specified by the user from command line)
TEST(userInput, userInput__CommandLine) {
    int argc = 8;
    char **argv = new char *[argc];
    argv[0] = (char*) "nameExecutable";    // mock variable, which should is stored as 1st input
    argv[1] = (char*)"5";                  // method (5 -> multistep BDF schemes)
    argv[2] = (char*)"cos(t)";             // "f(t,y)"
    argv[3] = (char*)"0";                  // t0
    argv[4] = (char*)"2";                  // tf
    argv[5] = (char*) "0.01";              // h
    argv[6] = (char*)"0";                  // y0
    argv[7] = (char*)"4";                  // number of steps
    ManageInput ode(argc, argv);
    AbstractOdeSolver *ptr = ode.ConstructSolver();
    assert(ptr);

    std::map<double, double> *solutionMap = ptr->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
}

TEST(userInput, userInput__File) {
    // First a dummy file is created where all variables are contained
    std::ofstream write_file("test.txt");
    assert(write_file.is_open());
    write_file << 1 << "cos(t)" << 0 << 2 << 0.01 << 0;
    write_file.close();

    int argc = 3;
    char **argv = new char *[argc];
    argv[0] = (char*) "nameExecutable";    // mock variable, which should is stored as 1st input
    argv[1] = (char*)"FILE";               // this will tell the program that a file is to be read
    argv[2] = (char*)"test.txt";           // name of the file that has to be read

    ManageInput ode(argc, argv);
    AbstractOdeSolver *ptr = ode.ConstructSolver();
    assert(ptr);
    ptr->solve();
    std::map<double, double> *solutionMap = ptr->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
}

 // Here we test the resolution of a dummy nonlinear equation to check the correctness of FixedPoint() method
 // A simple case is tested: a solution of the ODE y' = cos(t), using Backward Euler, which leads, at the only timestep
 // (given t0 = 0, tf = 0.5, and h = 0.5), the linear equation y + a+b*cos(t) = 0, whose solution is y = -a -b*cos(t).
TEST(nonlineareq, nonlineareq__FixedPoint) {
    std::string fun = "cos(t)";                                       // f(t,y) = cos(t)
    Fparser* fparser_pointer = new Fparser(fun);              // create a pointer to an object Fparser, which will be the function
    double h = 0.5;
    double y0 = 1.0;
    double t0 = 0.0;
    double tf = 0.5;
    BackwardEuler* Eq = new BackwardEuler(h, y0, t0, tf, fparser_pointer);
    Eq->solve();
    std::map<double, double>* solMap = Eq->GetSolution();
    double y_fixedpoint = solMap->rbegin()->second;
    double y_ex = y0 +h*cos(tf);                      // a = -y0, b = -h
    ASSERT_NEAR(y_fixedpoint, y_ex , 1e-4);
    delete Eq;
}

// Here we test the resolution of a dummy nonlinear equation to check the correctness of Broyden() method
// A simple case is tested: a solution of the ODE y' = y, using Backward Euler, which leads, at the only timestep
// (given t0 = 0, tf = 0.5, and h = 0.5), the linear equation y + a+b*y = 0, whose solution is y = -a/(b+1).
// The choice of f(t,y) = y will let FixedPoint fail (see convergence properties of fixed point iterations), and
// consequently Broyden method will be called.
TEST(nonlineareq, nonlineareq__Broyden) {
    std::string fun = "y";                                       // f(t,y) = cos(t)
    Fparser* fparser_pointer = new Fparser(fun);              // create a pointer to an object Fparser, which will be the function
    double h = 0.5;
    double y0 = 1.0;
    double t0 = 0.0;
    double tf = 0.5;
    BackwardEuler* Eq = new BackwardEuler( h,y0, t0,  tf, fparser_pointer);
    Eq->solve();
    std::map<double, double>* solMap = Eq->GetSolution();
    double y_broyden = solMap->rbegin()->second;
    double y_ex = y0/(-h+1);                      // a = -y0, b = -h
    ASSERT_NEAR(y_broyden, y_ex , 1e-4);
    delete Eq;
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}