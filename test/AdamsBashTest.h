//
// Created by parallels on 12/15/22.
//

#ifndef PROJECT_PCSC_ADAMSBASHTEST_H
#define PROJECT_PCSC_ADAMSBASHTEST_H

#include "AbstractMethodTest.h"

class AdamsBashTest : public AbstractMethodTest {
protected:
    void SetUp() override {
        std::cout << "I am testing AdamsBashforth with " << GetParam() << " steps." << std::endl;
        auto fparser_pointer = new Fparser(this->fun);
        Eq = new AdamsBashforth(h, y0, t0, tf, fparser_pointer, GetParam());
        Eq->solve();
        solutionMap = Eq->GetSolution();
    }
};

#endif //PROJECT_PCSC_ADAMSBASHTEST_H
