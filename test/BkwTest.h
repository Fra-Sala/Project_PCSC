//
// Created by parallels on 12/15/22.
//

#ifndef PROJECT_PCSC_BKWTEST_H
#define PROJECT_PCSC_BKWTEST_H

#include "AbstractMethodTest.h"

class BkwTest : public AbstractMethodTest {
protected:
    void SetUp() override {
        auto fparser_pointer = new Fparser(this->fun);
        Eq = new BackwardEuler(h, y0, t0, tf, fparser_pointer);
        Eq->solve();
        solutionMap = Eq->GetSolution();
    }
};

#endif //PROJECT_PCSC_BKWTEST_H
