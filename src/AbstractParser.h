//
// Created by francesco on 01/12/22.
//

#include "fparser.hh"

#ifndef PROJECT_PCSC_ABSTRACTPARSER_H
#define PROJECT_PCSC_ABSTRACTPARSER_H

class AbstractParser {

protected:
    std::string funString;

public:
    AbstractParser(std::string fun_rhs);
    virtual double EvaluateFun(double t, double y) = 0;

};
#endif //PROJECT_PCSC_ABSTRACTPARSER_H
