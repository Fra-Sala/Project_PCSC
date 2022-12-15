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

// Test for ForwardEuler
TEST(forwardEuler, forwardEuler__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 0.03;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);
           // create a pointer to an object Fparser, which will be the function

    ForwardEuler* Eq = new ForwardEuler( h,y0, t0,  tf, fparser_pointer);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
    delete Eq;
}

// Tests for AdamsBashforth
TEST(AdamsBashforth, adamsBashforth1__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 1;
    AdamsBashforth* Eq = new AdamsBashforth ( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
    delete Eq;
}

TEST(AdamsBashforth, adamsBashforth2__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 2;
    AdamsBashforth* Eq = new AdamsBashforth ( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
    delete Eq;
}

TEST(AdamsBashforth, adamsBashforth3__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 3;
    AdamsBashforth* Eq = new AdamsBashforth ( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

TEST(AdamsBashforth, adamsBashforth4__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 4;
    AdamsBashforth* Eq = new AdamsBashforth ( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

// Test for BackwardEuler
TEST(backwardEuler, backwardEuler__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    BackwardEuler* Eq = new BackwardEuler( h,y0, t0,  tf, fparser_pointer);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
    delete Eq;
}

// Tests for ExplicitRungeKutta
TEST(rungeKutta, rungeKutta1__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int stages = 1;
    ExplicitRungeKutta*  Eq = new ExplicitRungeKutta( h,y0, t0,  tf, fparser_pointer, stages);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
    delete Eq;
}

TEST(rungeKutta, rungeKutta2__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int stages = 2;
    ExplicitRungeKutta*  Eq = new ExplicitRungeKutta( h,y0, t0,  tf, fparser_pointer, stages);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;

}

TEST(rungeKutta, rungeKutta3__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int stages = 3;
    ExplicitRungeKutta*  Eq = new ExplicitRungeKutta( h,y0, t0,  tf, fparser_pointer, stages);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

TEST(rungeKutta, rungeKutta4__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int stages = 4;
    ExplicitRungeKutta*  Eq = new ExplicitRungeKutta( h,y0, t0,  tf, fparser_pointer, stages);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

// Tests for AdamsMoulton
TEST(AdamsMoulton, adamsMoulton1__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 1;
    AdamsMoulton* Eq = new AdamsMoulton( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

TEST(AdamsMoulton, adamsMoulton2__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 2;
    AdamsMoulton* Eq = new AdamsMoulton( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

TEST(AdamsMoulton, adamsMoulton3__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 3;
    AdamsMoulton* Eq = new AdamsMoulton( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

TEST(AdamsMoulton, adamsMoulton4__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 4;
    AdamsMoulton* Eq = new AdamsMoulton( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

// Tests for BDFSchemes
TEST(BDF, BDF1__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 1;
    BDFSchemes* Eq = new BDFSchemes( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
    delete Eq;
}

TEST(BDF, BDF2__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 2;
    BDFSchemes* Eq = new BDFSchemes( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

TEST(BDF, BDF3__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 3;
    BDFSchemes* Eq = new BDFSchemes( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

TEST(BDF, BDF4__Test) {
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser* fparser_pointer = new Fparser(fun);

    int steps = 4;
    BDFSchemes* Eq = new BDFSchemes( h,y0, t0,  tf, fparser_pointer, steps);
    Eq->solve();
    std::map<double, double> *solutionMap = Eq->GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});
    delete Eq;
}

// Tests for the ManageInput class, given a mock string (as specified by the user from command line)
TEST(userInput, userInput__CommandLine) {
    int argc = 8;
    char **argv = new char *[argc];
    argv[0] = (char*) "nameExecutable";    //mock variable, which should is stored as 1st input
    argv[1] = (char*)"5";                 // method (5 -> multistep BDF schemes)
    argv[2] = (char*)"cos(t)";           // "f(t,y)"
    argv[3] = (char*)"0";                // t0
    argv[4] = (char*)"2";                // tf
    argv[5] = (char*) "0.01";            // h
    argv[6] = (char*)"0";                // y0
    argv[7] = (char*)"4";                // number of steps
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

 //Here we test the resolution of a dummy nonlinear equation to check the correctness of FixedPoint() method
 // A simple case is tested: a solution of the ODE y' = cos(t), using Backward Euler, which leads, at the only timestep
 // (given t0 = 0, tf = 0.5, and h = 0.5), the linear equation y + a+b*cos(t) = 0, whose solution is y = -a -b*cos(t).
TEST(nonlineareq, nonlineareq__FixedPoint) {
    std::string fun = "cos(t)";                                       // f(t,y) = cos(t)
    Fparser* fparser_pointer = new Fparser(fun);              // create a pointer to an object Fparser, which will be the function
    double h = 0.5;
    double y0 = 1.0;
    double t0 = 0.0;
    double tf = 0.5;
    BackwardEuler* Eq = new BackwardEuler( h,y0, t0,  tf, fparser_pointer);
    Eq->solve();
    std::map<double, double>* solMap = Eq->GetSolution();
    double y_fixedpoint = solMap->rbegin()->second;
    double y_ex = y0 +h*cos(tf);                      // a = -y0, b = -h
    ASSERT_NEAR(y_fixedpoint, y_ex , 1e-4);
    delete Eq;

}

//Here we test the resolution of a dummy nonlinear equation to check the correctness of Broyden() method
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