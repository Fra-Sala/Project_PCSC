//
// Created by francesco on 01/12/22.
//

#include "Fparser.h"

double Fparser::EvaluateFun(double t, double y) {

    double v[2] = {t,y};
    double val = this->rhs->Eval(v);

    return val;
}


