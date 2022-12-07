#include <cmath>
#include <gtest/gtest.h>
#include "../src/ExplicitRungeKutta.h"
#include "../src/Fparser.h"
#include "../src/BackwardEuler.h"
#include <algorithm>

//TEST(sqrt, integer) { EXPECT_EQ(2, std::sqrt(4)); }


TEST(rungeKutta, rungeKutta4) {

    double h = 0.1;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 5.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int stages = 4;
    ExplicitRungeKutta Eq( h,y0, t0,  tf, fparser_pointer, stages);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {EXPECT_EQ(std::fabs(e.second- sin(e.first)) < 1e-3, 1);});


//std::fabs(e.second- sin(e.first)) < 1e-12



}

TEST(backwardEuler, backwardEuler__Test) {

    double h = 0.1;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 5.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    BackwardEuler Eq( h,y0, t0,  tf, fparser_pointer);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {EXPECT_EQ(std::fabs(e.second- sin(e.first)) < 1e-3, 1);});


//std::fabs(e.second- sin(e.first)) < 1e-12



}



