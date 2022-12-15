//
// Created by parallels on 12/15/22.
//

#ifndef PROJECT_PCSC_BDFTEST_H
#define PROJECT_PCSC_BDFTEST_H

#include "AbstractMethodTest.h"

class BDFTest : public AbstractMethodTest {
protected:
    void SetUp() override {
        std::cout << "I am testing BDFSchemes with " << GetParam() << " steps." << std::endl;
        auto fparser_pointer = new Fparser(this->fun);
        Eq = new BDFSchemes(h, y0, t0, tf, fparser_pointer, GetParam());
        Eq->solve();
        solutionMap = Eq->GetSolution();
    }
};

#endif //PROJECT_PCSC_BDFTEST_H
