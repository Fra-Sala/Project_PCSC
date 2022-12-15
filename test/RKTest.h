//
// Created by parallels on 12/15/22.
//

#ifndef PROJECT_PCSC_RKTEST_H
#define PROJECT_PCSC_RKTEST_H

#include "AbstractMethodTest.h"

class RKTest : public AbstractMethodTest {
protected:
    void SetUp() override {
        std::cout << "I am testing ExplicitRungeKutta with " << GetParam() << " stages." << std::endl;
        auto fparser_pointer = new Fparser(this->fun);
        Eq = new ExplicitRungeKutta(h, y0, t0, tf, fparser_pointer, GetParam());
        Eq->solve();
        solutionMap = Eq->GetSolution();
    }

};

#endif //PROJECT_PCSC_RKTEST_H
