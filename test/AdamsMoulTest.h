//
// Created by parallels on 12/15/22.
//

#ifndef PROJECT_PCSC_ADAMSMOULTEST_H
#define PROJECT_PCSC_ADAMSMOULTEST_H

#include "AbstractMethodTest.h"

class AdamsMoulTest : public AbstractMethodTest {
protected:
    void SetUp() override {
        std::cout << "I am testing AdamsMoulton with " << GetParam() << " steps." << std::endl;
        auto fparser_pointer = new Fparser(this->fun);
        Eq = new AdamsMoulton(h, y0, t0, tf, fparser_pointer, GetParam());
        Eq->solve();
        solutionMap = Eq->GetSolution();
    }
};



#endif //PROJECT_PCSC_ADAMSMOULTEST_H



