
// Created by francesco on 15/12/22.
//

#ifndef PROJECT_PCSC_ABSTRACTMETHODTEST_H
#define PROJECT_PCSC_ABSTRACTMETHODTEST_H

#include <cmath>

class AbstractMethodTest : public ::testing::TestWithParam<int> {
protected:
    AbstractOdeSolver* Eq;
    std::map<double, double> *solutionMap;
    double h = 0.01;
    double y0 = 0.0;
    double t0 = 0.0;
    double tf = 1;
    std::string fun = "cos(t)";

    virtual void SetUp() override = 0;

    void TearDown() override {
        delete Eq;
    }
};
#endif //PROJECT_PCSC_ABSTRACTMETHODTEST_H

