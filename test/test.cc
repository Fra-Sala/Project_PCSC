#include <cmath>
#include <gtest/gtest.h>
#include "../src/ExplicitRungeKutta.h"
#include "../src/Fparser.h"
#include "../src/BackwardEuler.h"
#include "../src/BDFSchemes.h"
#include "../src/AdamsMoulton.h"
#include "../src/AdamsBashforth.h"
#include "../src/ForwardEuler.h"
#include <algorithm>


TEST(AdamsBashforth, adamsBashforth1__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 1;
    AdamsBashforth Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});

}

TEST(AdamsBashforth, adamsBashforth2__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 2;
    AdamsBashforth Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});

}

TEST(AdamsBashforth, adamsBashforth3__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 3;
    AdamsBashforth Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}

TEST(AdamsBashforth, adamsBashforth4__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 3;
    AdamsBashforth Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}


TEST(AdamsMoulton, adamsMoulton1__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 1;
    AdamsMoulton Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}


TEST(AdamsMoulton, adamsMoulton2__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 2;
    AdamsMoulton Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}

TEST(AdamsMoulton, adamsMoulton3__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 3;
    AdamsMoulton Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}

TEST(AdamsMoulton, adamsMoulton4__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 4;
    AdamsMoulton Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}



TEST(BDF, BDF1__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 1;
    BDFSchemes Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});

}
TEST(BDF, BDF2__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 2;
    BDFSchemes Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}

TEST(BDF, BDF3__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 3;
    BDFSchemes Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}

TEST(BDF, BDF4__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int steps = 4;
    BDFSchemes Eq( h,y0, t0,  tf, fparser_pointer, steps);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}



TEST(rungeKutta, rungeKutta4__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int stages = 4;
    ExplicitRungeKutta Eq( h,y0, t0,  tf, fparser_pointer, stages);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}

TEST(rungeKutta, rungeKutta3__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int stages = 3;
    ExplicitRungeKutta Eq( h,y0, t0,  tf, fparser_pointer, stages);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}

TEST(rungeKutta, rungeKutta2__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int stages = 2;
    ExplicitRungeKutta Eq( h,y0, t0,  tf, fparser_pointer, stages);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-3);});

}

TEST(rungeKutta, rungeKutta1__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    int stages = 1;
    ExplicitRungeKutta Eq( h,y0, t0,  tf, fparser_pointer, stages);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});

}


TEST(backwardEuler, backwardEuler__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    BackwardEuler Eq( h,y0, t0,  tf, fparser_pointer);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});



}


TEST(forwardEuler, forwardEuler__Test) {

    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1.0;
    std::string fun = "cos(t)";     // the solution of this Cauchy problem is sin(t)
    Fparser fparser_obj(fun);
    Fparser* fparser_pointer = &fparser_obj;       // create a pointer to an object Fparser, which will be the function

    ForwardEuler Eq( h,y0, t0,  tf, fparser_pointer);
    Eq.solve();
    std::map<double, double> *solutionMap = Eq.GetSolution();
    std::for_each(solutionMap->begin(), solutionMap->end(), [](auto& e) {ASSERT_NEAR(e.second, sin(e.first), 1e-2);});
    
}



