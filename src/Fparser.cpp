//
// Created by francesco on 01/12/22.
//

#include "Fparser.h"



Fparser::Fparser(std::string fun_string) {

    this->funString = fun_string;
    this->rhs->Parse(this->funString, "t,y");

}

double Fparser::EvaluateFun(double t, double y) {

    double v[2] = {t,y};
    double val = this->rhs->Eval(v);
    return val;
}


