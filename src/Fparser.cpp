//
// Created by francesco on 01/12/22.
//

#include "Fparser.h"



Fparser::Fparser(std::string fun_string) {

    this->funString = fun_string;
    this->rhs->Parse(this->funString, "t,y");

}

double Fparser::EvaluateFun(double t, double y) {

    auto *v = new double[2] {t,y};
    double val = this->rhs->Eval(v);
    delete[] v;
    return val;
}


