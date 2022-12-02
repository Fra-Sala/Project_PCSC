//
// Created by francesco on 01/12/22.
//

#include "AbstractParser.h"
#include "fparser.hh"

#ifndef PROJECT_PCSC_FPARSER_H
#define PROJECT_PCSC_FPARSER_H

class Fparser : public AbstractParser {

private:
    FunctionParser *rhs = new FunctionParser;

public:
    Fparser(std::string fun_rhs);
    double EvaluateFun(double t, double y) override;

};


#endif //PROJECT_PCSC_FPARSER_H
